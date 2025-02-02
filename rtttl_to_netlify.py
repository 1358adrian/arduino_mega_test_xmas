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
        32: base_duration / 8,
        64: base_duration / 16,
    }
    
    # Parse notes
    notes = notes_str.split(',')
    result = []
    rest_time = 0  # Tracks accumulated rest duration

    for note in notes:
        match = re.match(r'(\d*)([a-gpA-G#]+)(\d*)(\.?)', note)
        if not match:
            continue
        
        duration, name, octave, dotted = match.groups()
        duration = int(duration) if duration else default_d
        octave = int(octave) if octave else default_o
        
        if name.lower() == 'p':  # It's a pause
            note_duration = duration_map.get(duration, base_duration)
            if dotted:
                note_duration *= 1.5
            result.append(f"{{{0}, {int(0)}, {int(note_duration)}}}")
            continue
        
        # Compute note duration
        note_duration = duration_map.get(duration, base_duration)
        if dotted:
            note_duration *= 1.5
        
        # Format note name
        formatted_note = f"{name[0].upper() + name[1:]}{octave}"

        # Append result with the correct rest_time
        result.append(f"{{{formatted_note}, {int(note_duration)}, {int(rest_time)}}}")
        
    return ',\n'.join(result)

# Example usage
rtttl = "Toreador:d=16,o=4,b=80,l=15:8c5,d5.,32c5,a.,32p,a.,32p,a.,32g,a.,32a#,8a.,p,8a#,g.,32c5,8a.,p,8f,d.,32g,8c.,p,4g,g,d5,c5,a#,a,g,a,a#,8a.,p,8e,a.,32p,8a,g#.,32b,8e5.,e5,8e5,8e5,p,d5,c#5,d5,g,a,8a#,p,a,f,d5,4c5,p,f,c,a#,8a,8g,8f.,p,4p,8c5,d5.,32c5,a.,32p,a.,32p,a.,32g,a.,32a#,8a.,p,8a#,g.,32c5,8a.,p,8f,d.,32g,8c."
replace_rtttl = rtttl.replace('#', 'b')
print(parse_rtttl(replace_rtttl))
