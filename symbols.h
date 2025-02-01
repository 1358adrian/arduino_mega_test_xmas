const int pins[] = {2, 3, 4, 5, 6, 7, 8}; // A, B, C, D, E, F, G
const int digits[] = {9, 10, 11}; // D1, D2, D3
const int delayTime = 1;

void setDigitState(int D1State, int D2State, int D3State) {
  digitalWrite(digits[0], D1State);
  digitalWrite(digits[1], D2State);
  digitalWrite(digits[2], D3State);
}

void setSegmentState(int A, int B, int C, int D, int E, int F, int G) {
  digitalWrite(pins[0], A);
  digitalWrite(pins[1], B);
  digitalWrite(pins[2], C);
  digitalWrite(pins[3], D);
  digitalWrite(pins[4], E);
  digitalWrite(pins[5], F);
  digitalWrite(pins[6], G);
}

void clearSegments() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(pins[i], LOW);
  }
}

void delayAndClearSegments() {
  delay(delayTime);
  clearSegments();
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


void letterC() {
  setSegmentState(HIGH, LOW, LOW, HIGH, HIGH, HIGH, LOW);
}

void letterD() {
  setSegmentState(LOW, HIGH, HIGH, HIGH, HIGH, LOW, HIGH);
}

void letterE() {
  setSegmentState(HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH);
}

void letterF() {
  setSegmentState(HIGH, LOW, LOW, LOW, HIGH, HIGH, HIGH);
}

void letterG() {
  setSegmentState(HIGH, LOW, HIGH, HIGH, HIGH, HIGH, LOW);
}

void letterA() {
  setSegmentState(HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH);
}

void letterBorFlatSymbol() {
  setSegmentState(LOW, LOW, HIGH, HIGH, HIGH, HIGH, HIGH);
}

void letterN() {
  setSegmentState(LOW, LOW, HIGH, LOW, HIGH, LOW, HIGH);
}

void letterO() {
  setSegmentState(LOW, LOW, HIGH, HIGH, HIGH, LOW, HIGH);
}

void letterT() {
  setSegmentState(LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH);
}

void letterP() {
  setSegmentState(HIGH, HIGH, LOW, LOW, HIGH, HIGH, HIGH);
}

void symbolDashCenter() {
  setSegmentState(LOW, LOW, LOW, LOW, LOW, LOW, HIGH);
}

void symbolBlank() {
  setSegmentState(LOW, LOW, LOW, LOW, LOW, LOW, LOW);
}

void numberNeg1() {
  setSegmentState(LOW, HIGH, HIGH, LOW, LOW, LOW, HIGH);
}

void number0() {
  setSegmentState(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW);  // 0: ABCDEF
}

void number1() {
  setSegmentState(LOW, HIGH, HIGH, LOW, LOW, LOW, LOW);  // 1: BC
}

void number2() {
  setSegmentState(HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH);  // 2: ABDEG
}

void number3() {
  setSegmentState(HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH);  // 3: ABDEG
}

void number4() {
  setSegmentState(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH);  // 4: BCFG
}

void number5() {
  setSegmentState(HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH);  // 5: ADEF
}

void number6() {
  setSegmentState(HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH);  // 6: ADEF
}

void number7() {
  setSegmentState(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);  // 7: ABC
}

void number8() {
  setSegmentState(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH);  // 8: ABCDEFG
}

void number9() {
  setSegmentState(HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH);  // 9: ABCDEFG
}

