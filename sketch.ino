#include "notes_display.h"
#include <avr/pgmspace.h>

const uint8_t buzzerPin = 13;
const uint8_t buttonPin = 12;

// Button state tracking
bool buttonReleaseMem = false;

// Timer tracking
unsigned long snapMemoryMillis = 0;
unsigned long loopMemoryMillis = 0;

// Song list (fixed declaration)
const uint16_t (*songs[])[3] = {midi1, midi2, midi3, midi4};
const size_t songLengths[] = {ARRAY_LEN(midi1), ARRAY_LEN(midi2), ARRAY_LEN(midi3), ARRAY_LEN(midi4)};
uint8_t currentSongIndex = 0;

// Reads button state and updates buttonReleaseMem
void updateButtonState() {
    if (digitalRead(buttonPin) == HIGH) {
        buttonReleaseMem = true;
    }
}

// Plays MIDI sequence
void playMidi(uint8_t pin, const uint16_t notes[][3], size_t len) {
    for (uint16_t i = 0; i < len; i++) {
        updateButtonState();
        if (digitalRead(buttonPin) == LOW && buttonReleaseMem) break;

        snapMemoryMillis = millis();
        while (millis() < snapMemoryMillis + pgm_read_word_near(&notes[i][1])) {
            updateButtonState();
            if (digitalRead(buttonPin) == LOW && buttonReleaseMem) break;
            tone(pin, pgm_read_word_near(&notes[i][0]));
            noteOnDisplay(pgm_read_word_near(&notes[i][0]));
        }

        snapMemoryMillis = millis();
        while (millis() < snapMemoryMillis + pgm_read_word_near(&notes[i][2])) {
            updateButtonState();
            if (digitalRead(buttonPin) == LOW && buttonReleaseMem) break;
            noTone(pin);
            noteOffDisplay();
        }
    }
    buttonReleaseMem = true;
}

// Setup function
void setup() {
    pinMode(buzzerPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
    
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);

    for (uint8_t i = 0; i < 3; i++) {
        pinMode(digits[i], OUTPUT);
    }
}

// Main loop
void loop() {
    if (digitalRead(buttonPin) == LOW && !buttonReleaseMem) {
        delay(4);
        playMidi(buzzerPin, songs[currentSongIndex], songLengths[currentSongIndex]);
        noTone(buzzerPin);

        // Cycle to the next song
        currentSongIndex = (currentSongIndex + 1) % 4;
        delay(4);
    } else {
        stopDisplay();
        if (digitalRead(buttonPin) == HIGH && buttonReleaseMem) {
            buttonReleaseMem = false;
        }
    }
}



// #include "notes_display.h"
// #include <avr/pgmspace.h>

// const uint8_t buzzerPin = 13;
// const uint8_t buttonPin = 12;

// // Variable to hold the button state
// bool buttonState = 0;
// bool buttonStateInPlayMidi = 0;

// unsigned long snapMemoryMillis = 0;
// unsigned long loopMemoryMillis = 0;
// bool buttonReleaseMem = false;

// void buttonReleaseMemSetToTrue() {
//   buttonStateInPlayMidi = digitalRead(buttonPin);
//   if (buttonStateInPlayMidi == HIGH) {
//     buttonReleaseMem = true;
//   }
// }

// void playMidi(uint8_t pin, const uint16_t notes[][3], size_t len) {
//   for (uint16_t i = 0; i < len; i++) {
//     buttonReleaseMemSetToTrue();
//     if (buttonStateInPlayMidi == LOW && buttonReleaseMem == true) break;
//     snapMemoryMillis = millis();
//     do {
//       buttonReleaseMemSetToTrue();
//       if (buttonStateInPlayMidi == LOW && buttonReleaseMem == true) break;
//       tone(pin, pgm_read_word_near(&notes[i][0])); // Read note from PROGMEM
//       noteOnDisplay(pgm_read_word_near(&notes[i][0])); // Read note from PROGMEM
//       loopMemoryMillis = millis();
//     } while (loopMemoryMillis < (snapMemoryMillis + pgm_read_word_near(&notes[i][1]))); // Read duration from PROGMEM

//     snapMemoryMillis = millis();
//     do {
//       buttonReleaseMemSetToTrue();
//       if (buttonStateInPlayMidi == LOW && buttonReleaseMem == true) break;
//       noTone(pin);
//       noteOffDisplay();
//       loopMemoryMillis = millis();
//     } while (loopMemoryMillis < (snapMemoryMillis + pgm_read_word_near(&notes[i][2]))); // Read silence time from PROGMEM
//   }
//   buttonReleaseMem = true;
// }
// void setup() {
//   // put your setup code here, to run once:
//   // play midi by passing pin no., midi, midi len

//   pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as output
//   pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input with internal pull-up resistor
  
//   // Initialize pin modes for DS, ST_CP, and SH_CP of 74HC595
//   pinMode(latchPin, OUTPUT);
//   pinMode(clockPin, OUTPUT);
//   pinMode(dataPin, OUTPUT);
  
//   // Initialize pin modes for D1, D2, D3
//   for (uint8_t i = 0; i < 3; i++) {
//     pinMode(digits[i], OUTPUT);
//   }
// }

// uint16_t song = midi1;
// size_t songLen = ARRAY_LEN(midi1);

// void loop() {
//   // put your main code here, to run repeatedly:
//   // Read the state of the button
//   buttonState = digitalRead(buttonPin);
  
//   if (buttonState == LOW && buttonReleaseMem == false) {
//     delay(4);
//     playMidi(buzzerPin, song, songLen);
//     noTone(buzzerPin);
//     if (song == midi1 && songLen == ARRAY_LEN(midi1)) 
//     {
//       song = midi2;
//       songLen = ARRAY_LEN(midi2);
//     }
//     else if (song == midi2 && songLen == ARRAY_LEN(midi2)) 
//     {
//       song = midi3;
//       songLen = ARRAY_LEN(midi3);
//     }
//     else if (song == midi3 && songLen == ARRAY_LEN(midi3)) 
//     {
//       song = midi4;
//       songLen = ARRAY_LEN(midi4);
//     }
//     else if (song == midi4 && songLen == ARRAY_LEN(midi4)) 
//     {
//       song = midi1;
//       songLen = ARRAY_LEN(midi1);
//     }
//     delay(4);
//   } else if (buttonState == LOW && buttonReleaseMem == true || buttonReleaseMem == false) {
//     stopDisplay();
//   } else if (buttonState == HIGH && buttonReleaseMem == true) {
//     stopDisplay();
//     buttonReleaseMem = false;
//   }
// }