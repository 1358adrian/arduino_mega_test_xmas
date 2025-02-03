#include <avr/pgmspace.h>

const uint8_t dataPin = 8;     // DS of 74HC595
const uint8_t latchPin = 7;    // ST_CP of 74HC595
const uint8_t clockPin = 6;    // SH_CP of 74HC595

const uint8_t digits[] = {9, 10, 11}; // D1, D2, D3
const uint8_t delayTime = 1;

// 7-segment symbol patterns (common cathode display) stored in PROGMEM
const uint8_t symbols[20] PROGMEM = {
  0b00000000,  // symbolBlank or clearSegments
  0b10000110,  // 1
  0b01011011,  // 2
  0b01001111,  // 3
  0b01100110,  // 4
  0b01101101,  // 5
  0b01111101,  // 6
  0b00000111,  // 7
  0b01111111,  // 8
  0b01101111,  // 9
  0b01000000,  // -
  0b00111001,  // C
  0b01011110,  // D
  0b01111001,  // E
  0b01110001,  // F
  0b00111101,  // G
  0b01110111,  // A
  0b01111100,  // B
  0b01010100,  // n
  0b01111000   // t
};

void setDigitState(bool D1State, bool D2State, bool D3State) {
  digitalWrite(digits[0], D1State);
  digitalWrite(digits[1], D2State);
  digitalWrite(digits[2], D3State);
}

void digit1() {
  setDigitState(LOW, HIGH, HIGH);
}

void digit2() {
  setDigitState(HIGH, LOW, HIGH);
}

void digit3() {
  setDigitState(HIGH, HIGH, LOW);
}

void latchPinHighLow() {
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
}

void clearSegments() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 0));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void delayAndClearSegments() {
  delay(delayTime);
  clearSegments();
}

void letterC() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 11));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void letterD() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 12));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void letterE() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 13));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void letterF() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 14));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void letterG() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 15));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void letterA() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 16));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void letterBorFlatSymbol() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 17));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void letterN() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 18));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void letterT() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 19));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void symbolDashCenter() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 10));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void symbolBlank() {
  clearSegments();
}

void number1() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 1));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void number2() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 2));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void number3() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 3));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void number4() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 4));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void number5() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 5));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void number6() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 6));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void number7() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 7));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void number8() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 8));  // Read symbol from PROGMEM
  latchPinHighLow();
}

void number9() {
  shiftOut(dataPin, clockPin, MSBFIRST, pgm_read_byte_near(symbols + 9));  // Read symbol from PROGMEM
  latchPinHighLow();
}
