#include "symbols.h"
#include "pitches_netlify.h"

struct NoteDisplay {
    unsigned long note;
    void (*digit1Func)();
    void (*digit2Func)();
    void (*digit3Func)();
};

// Define an array of note-display mappings
const NoteDisplay noteMappings[] = {
    {C1, symbolBlank, letterC, number1},
    {Cb1, letterD, letterBorFlatSymbol, number1},
    {D1, symbolBlank, letterD, number1},
    {Db1, letterE, letterBorFlatSymbol, number1},
    {E1, symbolBlank, letterE, number1},
    {F1, symbolBlank, letterF, number1},
    {Fb1, letterG, letterBorFlatSymbol, number1},
    {G1, symbolBlank, letterG, number1},
    {Gb1, letterA, letterBorFlatSymbol, number1},
    {A1, symbolBlank, letterA, number1},
    {Ab1, letterBorFlatSymbol, letterBorFlatSymbol, number1},
    {B1, symbolBlank, letterBorFlatSymbol, number1},
    {C2, symbolBlank, letterC, number2},
    {Cb2, letterD, letterBorFlatSymbol, number2},
    {D2, symbolBlank, letterD, number2},
    {Db2, letterE, letterBorFlatSymbol, number2},
    {E2, symbolBlank, letterE, number2},
    {F2, symbolBlank, letterF, number2},
    {Fb2, letterG, letterBorFlatSymbol, number2},
    {G2, symbolBlank, letterG, number2},
    {Gb2, letterA, letterBorFlatSymbol, number2},
    {A2, symbolBlank, letterA, number2},
    {Ab2, letterBorFlatSymbol, letterBorFlatSymbol, number2},
    {B2, symbolBlank, letterBorFlatSymbol, number2},
    {C3, symbolBlank, letterC, number3},
    {Cb3, letterD, letterBorFlatSymbol, number3},
    {D3, symbolBlank, letterD, number3},
    {Db3, letterE, letterBorFlatSymbol, number3},
    {E3, symbolBlank, letterE, number3},
    {F3, symbolBlank, letterF, number3},
    {Fb3, letterG, letterBorFlatSymbol, number3},
    {G3, symbolBlank, letterG, number3},
    {Gb3, letterA, letterBorFlatSymbol, number3},
    {A3, symbolBlank, letterA, number3},
    {Ab3, letterBorFlatSymbol, letterBorFlatSymbol, number3},
    {B3, symbolBlank, letterBorFlatSymbol, number3},
    {C4, symbolBlank, letterC, number4},
    {Cb4, letterD, letterBorFlatSymbol, number4},
    {D4, symbolBlank, letterD, number4},
    {Db4, letterE, letterBorFlatSymbol, number4},
    {E4, symbolBlank, letterE, number4},
    {F4, symbolBlank, letterF, number4},
    {Fb4, letterG, letterBorFlatSymbol, number4},
    {G4, symbolBlank, letterG, number4},
    {Gb4, letterA, letterBorFlatSymbol, number4},
    {A4, symbolBlank, letterA, number4},
    {Ab4, letterBorFlatSymbol, letterBorFlatSymbol, number4},
    {B4, symbolBlank, letterBorFlatSymbol, number4},
    {C5, symbolBlank, letterC, number5},
    {Cb5, letterD, letterBorFlatSymbol, number5},
    {D5, symbolBlank, letterD, number5},
    {Db5, letterE, letterBorFlatSymbol, number5},
    {E5, symbolBlank, letterE, number5},
    {F5, symbolBlank, letterF, number5},
    {Fb5, letterG, letterBorFlatSymbol, number5},
    {G5, symbolBlank, letterG, number5},
    {Gb5, letterA, letterBorFlatSymbol, number5},
    {A5, symbolBlank, letterA, number5},
    {Ab5, letterBorFlatSymbol, letterBorFlatSymbol, number5},
    {B5, symbolBlank, letterBorFlatSymbol, number5},
    {C6, symbolBlank, letterC, number6},
    {Cb6, letterD, letterBorFlatSymbol, number6},
    {D6, symbolBlank, letterD, number6},
    {Db6, letterE, letterBorFlatSymbol, number6},
    {E6, symbolBlank, letterE, number6},
    {F6, symbolBlank, letterF, number6},
    {Fb6, letterG, letterBorFlatSymbol, number6},
    {G6, symbolBlank, letterG, number6},
    {Gb6, letterA, letterBorFlatSymbol, number6},
    {A6, symbolBlank, letterA, number6},
    {Ab6, letterBorFlatSymbol, letterBorFlatSymbol, number6},
    {B6, symbolBlank, letterBorFlatSymbol, number6},
    {C7, symbolBlank, letterC, number7},
    {Cb7, letterD, letterBorFlatSymbol, number7},
    {D7, symbolBlank, letterD, number7},
    {Db7, letterE, letterBorFlatSymbol, number7},
    {E7, symbolBlank, letterE, number7},
    {F7, symbolBlank, letterF, number7},
    {Fb7, letterG, letterBorFlatSymbol, number7},
    {G7, symbolBlank, letterG, number7},
    {Gb7, letterA, letterBorFlatSymbol, number7},
    {A7, symbolBlank, letterA, number7},
    {Ab7, letterBorFlatSymbol, letterBorFlatSymbol, number7},
    {B7, symbolBlank, letterBorFlatSymbol, number7},
    {C8, symbolBlank, letterC, number8},
    {Cb8, letterD, letterBorFlatSymbol, number8},
    {D8, symbolBlank, letterD, number8},
    {Db8, letterE, letterBorFlatSymbol, number8},
    {E8, symbolBlank, letterE, number8},
    {F8, symbolBlank, letterF, number8},
    {Fb8, letterG, letterBorFlatSymbol, number8},
    {G8, symbolBlank, letterG, number8},
    {Gb8, letterA, letterBorFlatSymbol, number8},
    {A8, symbolBlank, letterA, number8},
    {Ab8, letterBorFlatSymbol, letterBorFlatSymbol, number8},
    {B8, symbolBlank, letterBorFlatSymbol, number8},
    {C9, symbolBlank, letterC, number9},
    {Cb9, letterD, letterBorFlatSymbol, number9},
    {D9, symbolBlank, letterD, number9},
    {Db9, letterE, letterBorFlatSymbol, number9},
    {E9, symbolBlank, letterE, number9},
    {F9, symbolBlank, letterF, number9},
    {Fb9, letterG, letterBorFlatSymbol, number9},
    {G9, symbolBlank, letterG, number9},
};

void noteOnDisplay(unsigned long note) {
    for (const auto& entry : noteMappings) {
        if (entry.note == note) {
            digit1();
            entry.digit1Func();
            delayAndClearSegments();
            digit2();
            entry.digit2Func();
            delayAndClearSegments();
            digit3();
            entry.digit3Func();
            delayAndClearSegments();
            return;
        }
    }

    // If note not found, display "ntE"
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
