import re

def parse_rtttl(rtttl_str):
    header, notes_str = rtttl_str.split(':')[1:]
    
    # Extract default settings
    default_d = int(re.search(r'd=(\d+)', header).group(1)) if re.search(r'd=(\d+)', header) else 4
    default_o = int(re.search(r'o=(\d+)', header).group(1)) if re.search(r'o=(\d+)', header) else 5
    default_bpm = int(re.search(r'b=(\d+)', header).group(1)) if re.search(r'b=(\d+)', header) else 120

    # Define note duration mapping
    base_duration = 60000 / default_bpm  # Duration of a whole note in ms
    duration_map = {
        1: base_duration * 4,
        2: base_duration * 2,
        4: base_duration,
        8: base_duration / 2,
        16: base_duration / 4,
    }
    
    # Parse notes
    notes = notes_str.split(',')
    result = []
    rest_time = 0  # Tracks accumulated rest duration

    for note in notes:
        match = re.match(r'(\d*)([a-gpA-G#]+)(\.?)(\d*)', note)
        if not match:
            continue
        
        duration, name, dotted, octave = match.groups()
        duration = int(duration) if duration else default_d
        octave = int(octave) if octave else default_o
        
        if name.lower() == 'p':  # It's a pause
            rest_time += duration_map.get(duration, base_duration) * (1.5 if dotted else 1)
            result.append(f"{{{0}, {int(0)}, {int(rest_time)}}}")
            #result.append(f"{{{formatted_note}, {int(note_duration)}, {int(rest_time)}}}")
            continue
        
        # Compute note duration
        note_duration = duration_map.get(duration, base_duration)
        if dotted:
            note_duration *= 1.5
        
        # Format note name
        formatted_note = f"{name[0].upper() + name[1:]}{octave}"
        
        # Reset rest_time
        rest_time = 0

        # Append result with the correct rest_time
        result.append(f"{{{formatted_note}, {int(note_duration)}, {int(rest_time)}}}")
        
    return ',\n'.join(result)

# Example usage
rtttl = "SongTest:d=4,o=5,b=120:c,d,4e.,8f,g,4p,8p,a,b,2c6,c#"
replace_rtttl = rtttl.replace('#', 'b')
print(parse_rtttl(replace_rtttl))