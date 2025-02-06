#include <avr/pgmspace.h>
#include <Tone.h>

#include "note_define.h"
#include "pitches.h"
#include "note_define2.h"
#include "pitches2.h"
#include "note_define3.h"
#include "pitches3.h"
#include "note_define4.h"
#include "pitches4.h"

#define NUM_CHANNELS 4  // Define number of channels

struct BuzzerChannel {
    Tone buzzer;
    const uint32_t (*notes)[3];  // Pointer to note array
    size_t len;  // Length of notes array
    uint32_t count;
    uint32_t countNote;
    uint32_t countRest;
};

BuzzerChannel channels[NUM_CHANNELS] = {
    {Tone(), midi1, ARRAY_LEN(midi1), 0, 0, 0},
    {Tone(), midi2, ARRAY_LEN2(midi2), 0, 0, 0},
    {Tone(), midi3, ARRAY_LEN3(midi3), 0, 0, 0},
    {Tone(), midi4, ARRAY_LEN4(midi4), 0, 0, 0}
};

void playMidi() {
    bool playing = true;
    
    while (playing) {
        playing = false;
        
        for (uint8_t i = 0; i < NUM_CHANNELS; i++) {
            BuzzerChannel &ch = channels[i];

            if (ch.count >= ch.len) continue; // Skip if channel is done

            playing = true; // At least one channel is still playing

            uint32_t note = pgm_read_word_near(&ch.notes[ch.count][0]);
            uint32_t duration = pgm_read_dword_near(&ch.notes[ch.count][1]);
            uint32_t rest = pgm_read_dword_near(&ch.notes[ch.count][2]);

            if (ch.countNote < duration) {
                if (note != 0) ch.buzzer.play(note);
                else ch.buzzer.stop();
                ch.countNote++;
            } else if (ch.countRest < rest) {
                ch.buzzer.stop();
                ch.countRest++;
            } else {
                ch.countNote = 0;
                ch.countRest = 0;
                ch.count++;
            }
        }

        delayMicroseconds(400); // Tempo adjustment in case of simulation lag
    }

    // Stop all buzzers
    for (uint8_t i = 0; i < NUM_CHANNELS; i++) {
        channels[i].buzzer.stop();
    }
}

void setup() {
    uint8_t pins[NUM_CHANNELS] = {13, 5, 4, 3};

    for (uint8_t i = 0; i < NUM_CHANNELS; i++) {
        channels[i].buzzer.begin(pins[i]);
    }

    playMidi();
}

void loop() {
    // Nothing to loop
}


// #include <avr/pgmspace.h>
// #include <Tone.h>

// #include "note_define.h"
// #include "pitches.h"
// #include "note_define2.h"
// #include "pitches2.h"
// #include "note_define3.h"
// #include "pitches3.h"
// #include "note_define4.h"
// #include "pitches4.h"

// Tone buzzerChannel1;
// Tone buzzerChannel2;
// Tone buzzerChannel3;
// Tone buzzerChannel4;

// void playMidi(const uint32_t notes[][3], size_t len,
//               const uint32_t notes2[][3], size_t len2,
//               const uint32_t notes3[][3], size_t len3,
//               const uint32_t notes4[][3], size_t len4
//               ){
//   uint32_t channel1Count = 0;
//   uint32_t countNote = 0;
//   uint32_t countRest = 0;

//   uint32_t channel2Count = 0;
//   uint32_t countNote2 = 0;
//   uint32_t countRest2 = 0;

//   uint32_t channel3Count = 0;
//   uint32_t countNote3 = 0;
//   uint32_t countRest3 = 0;

//   uint32_t channel4Count = 0;
//   uint32_t countNote4 = 0;
//   uint32_t countRest4 = 0;

//   do {
//     if (countNote < pgm_read_dword_near(&notes[channel1Count][1])) {
//       if (pgm_read_word_near(&notes[channel1Count][0]) != 0)
//       buzzerChannel1.play(pgm_read_word_near(&notes[channel1Count][0]));
//       else buzzerChannel1.stop();
//       countNote++;
//     }
//     else if (countRest < pgm_read_dword_near(&notes[channel1Count][2])) {
//       buzzerChannel1.stop();
//       countRest++;
//     }
//     else {
//       countNote = 0;
//       countRest = 0;
//       channel1Count++;
//     }

//     if (countNote2 < pgm_read_dword_near(&notes2[channel2Count][1])) {
//       if (pgm_read_word_near(&notes2[channel2Count][0]) != 0)
//       buzzerChannel2.play(pgm_read_word_near(&notes2[channel2Count][0]));
//       else buzzerChannel2.stop();
//       countNote2++;
//     }
//     else if (countRest2 < pgm_read_dword_near(&notes2[channel2Count][2])) {
//       buzzerChannel2.stop();
//       countRest2++;
//     }
//     else {
//       countNote2 = 0;
//       countRest2 = 0;
//       channel2Count++;
//     }

//     if (countNote3 < pgm_read_dword_near(&notes3[channel3Count][1])) {
//       if (pgm_read_word_near(&notes3[channel3Count][0]) != 0)
//       buzzerChannel3.play(pgm_read_word_near(&notes3[channel3Count][0]));
//       else buzzerChannel3.stop();
//       countNote3++;
//     }
//     else if (countRest3 < pgm_read_dword_near(&notes3[channel3Count][2])) {
//       buzzerChannel3.stop();
//       countRest3++;
//     }
//     else {
//       countNote3 = 0;
//       countRest3 = 0;
//       channel3Count++;
//     }

//     if (countNote4 < pgm_read_dword_near(&notes4[channel4Count][1])) {
//       if (pgm_read_word_near(&notes4[channel4Count][0]) != 0)
//       buzzerChannel4.play(pgm_read_word_near(&notes4[channel4Count][0]));
//       else buzzerChannel4.stop();
//       countNote4++;
//     }
//     else if (countRest4 < pgm_read_dword_near(&notes4[channel4Count][2])) {
//       buzzerChannel4.stop();
//       countRest4++;
//     }
//     else {
//       countNote4 = 0;
//       countRest4 = 0;
//       channel4Count++;
//     }
//     delayMicroseconds(400); // Tempo adjustment in case of simulation lag
//   } while (channel1Count < len && channel2Count < len2
//           && channel3Count < len3 && channel4Count < len4);

//   buzzerChannel1.stop();
//   buzzerChannel2.stop();
//   buzzerChannel3.stop();
//   buzzerChannel4.stop();
// }
// // Generated using https://github.com/ShivamJoker/MIDI-to-Arduino

// // main.ino or main.cpp
// void setup() {
//   // put your setup code here, to run once:
//   // play midi by passing pin no., midi, midi len
//   buzzerChannel1.begin(13);
//   buzzerChannel2.begin(5);
//   buzzerChannel3.begin(4);
//   buzzerChannel4.begin(3);

//   playMidi(midi1, ARRAY_LEN(midi1), midi2, ARRAY_LEN2(midi2),
//   midi3, ARRAY_LEN3(midi3), midi4, ARRAY_LEN4(midi4));
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }
