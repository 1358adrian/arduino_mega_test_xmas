#include "notes_display.h"

const uint8_t buzzerPin = 13;
const uint8_t buttonPin = 12;

// Variable to hold the button state
bool buttonState = 0;
bool buttonStateInPlayMidi = 0;

unsigned long snapMemoryMillis = 0;
unsigned long loopMemoryMillis = 0;
bool buttonReleaseMem = false;

void buttonReleaseMemSetToTrue() {
  buttonStateInPlayMidi = digitalRead(buttonPin);
  if (buttonStateInPlayMidi == HIGH) {
    buttonReleaseMem = true;
  }
}

void playMidi(uint8_t pin, const uint16_t notes[][3], size_t len){
  for (uint16_t i = 0; i < len; i++) {
    buttonReleaseMemSetToTrue();
    if (buttonStateInPlayMidi == LOW && buttonReleaseMem == true) break;
    snapMemoryMillis = millis();
    do {
      buttonReleaseMemSetToTrue();
      if (buttonStateInPlayMidi == LOW && buttonReleaseMem == true) break;
      tone(pin, notes[i][0]);
      noteOnDisplay(notes[i][0]);
      loopMemoryMillis = millis();
    } while (loopMemoryMillis < (snapMemoryMillis + notes[i][1]));

    snapMemoryMillis = millis();
    do {
      buttonReleaseMemSetToTrue();
      if (buttonStateInPlayMidi == LOW && buttonReleaseMem == true) break;
      noTone(pin);
      noteOffDisplay();
      loopMemoryMillis = millis();
    } while (loopMemoryMillis < (snapMemoryMillis + notes[i][2]));
  }
  buttonReleaseMem = true;
}
void setup() {
  // put your setup code here, to run once:
  // play midi by passing pin no., midi, midi len

  pinMode(buzzerPin, OUTPUT);  // Set buzzer pin as output
  pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input with internal pull-up resistor
  
  // Initialize pin modes for DS, ST_CP, and SH_CP of 74HC595
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  // Initialize pin modes for D1, D2, D3
  for (uint8_t i = 0; i < 3; i++) {
    pinMode(digits[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // Read the state of the button
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW && buttonReleaseMem == false) {
    delay(4);
    playMidi(buzzerPin, midi1, ARRAY_LEN(midi1));
    noTone(buzzerPin);
    delay(4);
  } else if (buttonState == LOW && buttonReleaseMem == true || buttonReleaseMem == false) {
    stopDisplay();
  } else if (buttonState == HIGH && buttonReleaseMem == true) {
    stopDisplay();
    buttonReleaseMem = false;
  }
}
