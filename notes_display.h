#include "symbols.h"
#include "pitches.h"

void noteOnDisplay(unsigned long note) {
  if (note == c5) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterC();
    delayAndClearSegments();
    digit3();
    number5();
    delayAndClearSegments();
  }
  else if (note == d5) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterD();
    delayAndClearSegments();
    digit3();
    number5();
    delayAndClearSegments();
  }
  else if (note == e5) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterE();
    delayAndClearSegments();
    digit3();
    number5();
    delayAndClearSegments();
  }
  else if (note == f5) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterF();
    delayAndClearSegments();
    digit3();
    number5();
    delayAndClearSegments();
  }
  else if (note == g5) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterG();
    delayAndClearSegments();
    digit3();
    number5();
    delayAndClearSegments();
  }
  else if (note == a5) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterA();
    delayAndClearSegments();
    digit3();
    number5();
    delayAndClearSegments();
  }
  else if (note == bb5) {
    digit1();
    letterBorFlatSymbol();
    delayAndClearSegments();
    digit2();
    letterBorFlatSymbol();
    delayAndClearSegments();
    digit3();
    number5();
    delayAndClearSegments();
  }
  else if (note == b5) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterBorFlatSymbol();
    delayAndClearSegments();
    digit3();
    number5();
    delayAndClearSegments();
  }
  else if (note == c6) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterC();
    delayAndClearSegments();
    digit3();
    number6();
    delayAndClearSegments();
  }
  else if (note == d6) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterD();
    delayAndClearSegments();
    digit3();
    number6();
    delayAndClearSegments();
  }
  else if (note == e6) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterE();
    delayAndClearSegments();
    digit3();
    number6();
    delayAndClearSegments();
  }
  else if (note == f6) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterF();
    delayAndClearSegments();
    digit3();
    number6();
    delayAndClearSegments();
  }
  else if (note == gb6) {
    digit1();
    letterG();
    delayAndClearSegments();
    digit2();
    letterBorFlatSymbol();
    delayAndClearSegments();
    digit3();
    number6();
    delayAndClearSegments();
  }
  else if (note == g6) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterG();
    delayAndClearSegments();
    digit3();
    number6();
    delayAndClearSegments();
  }
  else if (note == a6) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterA();
    delayAndClearSegments();
    digit3();
    number6();
    delayAndClearSegments();
  }
  else if (note == bb6) {
    digit1();
    letterBorFlatSymbol();
    delayAndClearSegments();
    digit2();
    letterBorFlatSymbol();
    delayAndClearSegments();
    digit3();
    number6();
    delayAndClearSegments();
  }
  else if (note == b6) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterBorFlatSymbol();
    delayAndClearSegments();
    digit3();
    number6();
    delayAndClearSegments();
  }
  else if (note == c7) {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    letterC();
    delayAndClearSegments();
    digit3();
    number7();
    delayAndClearSegments();
  }
  else {
    digit1();
    letterN();
    delayAndClearSegments();
    digit2();
    letterT();
    delayAndClearSegments();
    digit3();
    letterE();
    delayAndClearSegments();
  }
}

void noteOffDisplay() {
    digit1();
    symbolBlank();
    delayAndClearSegments();
    digit2();
    symbolBlank();
    delayAndClearSegments();
    digit3();
    symbolBlank();
    delayAndClearSegments();
}

void stopDisplay() {
    digit1();
    symbolDashCenter();
    delayAndClearSegments();
    digit2();
    symbolDashCenter();
    delayAndClearSegments();
    digit3();
    symbolDashCenter();
    delayAndClearSegments();
}