#include "symbols.h"
#include "pitches.h"

struct NoteDisplay {
    uint16_t note;
    void (*digit1Func)();
    void (*digit2Func)();
    void (*digit3Func)();
};

// Define an array of note-display mappings
const NoteDisplay noteMappings[] = {
    {c1, symbolBlank, letterC, number1},
    {db1, letterD, letterBorFlatSymbol, number1},
    {d1, symbolBlank, letterD, number1},
    {eb1, letterE, letterBorFlatSymbol, number1},
    {e1, symbolBlank, letterE, number1},
    {f1, symbolBlank, letterF, number1},
    {gb1, letterG, letterBorFlatSymbol, number1},
    {g1, symbolBlank, letterG, number1},
    {ab1, letterA, letterBorFlatSymbol, number1},
    {a1, symbolBlank, letterA, number1},
    {bb1, letterBorFlatSymbol, letterBorFlatSymbol, number1},
    {b1, symbolBlank, letterBorFlatSymbol, number1},
    {c2, symbolBlank, letterC, number2},
    {db2, letterD, letterBorFlatSymbol, number2},
    {d2, symbolBlank, letterD, number2},
    {eb2, letterE, letterBorFlatSymbol, number2},
    {e2, symbolBlank, letterE, number2},
    {f2, symbolBlank, letterF, number2},
    {gb2, letterG, letterBorFlatSymbol, number2},
    {g2, symbolBlank, letterG, number2},
    {ab2, letterA, letterBorFlatSymbol, number2},
    {a2, symbolBlank, letterA, number2},
    {bb2, letterBorFlatSymbol, letterBorFlatSymbol, number2},
    {b2, symbolBlank, letterBorFlatSymbol, number2},
    {c3, symbolBlank, letterC, number3},
    {db3, letterD, letterBorFlatSymbol, number3},
    {d3, symbolBlank, letterD, number3},
    {eb3, letterE, letterBorFlatSymbol, number3},
    {e3, symbolBlank, letterE, number3},
    {f3, symbolBlank, letterF, number3},
    {gb3, letterG, letterBorFlatSymbol, number3},
    {g3, symbolBlank, letterG, number3},
    {ab3, letterA, letterBorFlatSymbol, number3},
    {a3, symbolBlank, letterA, number3},
    {bb3, letterBorFlatSymbol, letterBorFlatSymbol, number3},
    {b3, symbolBlank, letterBorFlatSymbol, number3},
    {c4, symbolBlank, letterC, number4},
    {db4, letterD, letterBorFlatSymbol, number4},
    {d4, symbolBlank, letterD, number4},
    {eb4, letterE, letterBorFlatSymbol, number4},
    {e4, symbolBlank, letterE, number4},
    {f4, symbolBlank, letterF, number4},
    {gb4, letterG, letterBorFlatSymbol, number4},
    {g4, symbolBlank, letterG, number4},
    {ab4, letterA, letterBorFlatSymbol, number4},
    {a4, symbolBlank, letterA, number4},
    {bb4, letterBorFlatSymbol, letterBorFlatSymbol, number4},
    {b4, symbolBlank, letterBorFlatSymbol, number4},
    {c5, symbolBlank, letterC, number5},
    {db5, letterD, letterBorFlatSymbol, number5},
    {d5, symbolBlank, letterD, number5},
    {eb5, letterE, letterBorFlatSymbol, number5},
    {e5, symbolBlank, letterE, number5},
    {f5, symbolBlank, letterF, number5},
    {gb5, letterG, letterBorFlatSymbol, number5},
    {g5, symbolBlank, letterG, number5},
    {ab5, letterA, letterBorFlatSymbol, number5},
    {a5, symbolBlank, letterA, number5},
    {bb5, letterBorFlatSymbol, letterBorFlatSymbol, number5},
    {b5, symbolBlank, letterBorFlatSymbol, number5},
    {c6, symbolBlank, letterC, number6},
    {db6, letterD, letterBorFlatSymbol, number6},
    {d6, symbolBlank, letterD, number6},
    {eb6, letterE, letterBorFlatSymbol, number6},
    {e6, symbolBlank, letterE, number6},
    {f6, symbolBlank, letterF, number6},
    {gb6, letterG, letterBorFlatSymbol, number6},
    {g6, symbolBlank, letterG, number6},
    {ab6, letterA, letterBorFlatSymbol, number6},
    {a6, symbolBlank, letterA, number6},
    {bb6, letterBorFlatSymbol, letterBorFlatSymbol, number6},
    {b6, symbolBlank, letterBorFlatSymbol, number6},
    {c7, symbolBlank, letterC, number7},
    {db7, letterD, letterBorFlatSymbol, number7},
    {d7, symbolBlank, letterD, number7},
    {eb7, letterE, letterBorFlatSymbol, number7},
    {e7, symbolBlank, letterE, number7},
    {f7, symbolBlank, letterF, number7},
    {gb7, letterG, letterBorFlatSymbol, number7},
    {g7, symbolBlank, letterG, number7},
    {ab7, letterA, letterBorFlatSymbol, number7},
    {a7, symbolBlank, letterA, number7},
    {bb7, letterBorFlatSymbol, letterBorFlatSymbol, number7},
    {b7, symbolBlank, letterBorFlatSymbol, number7},
    {c8, symbolBlank, letterC, number8},
    {db8, letterD, letterBorFlatSymbol, number8},
    {d8, symbolBlank, letterD, number8},
    {eb8, letterE, letterBorFlatSymbol, number8},
    {e8, symbolBlank, letterE, number8},
    {f8, symbolBlank, letterF, number8},
    {gb8, letterG, letterBorFlatSymbol, number8},
    {g8, symbolBlank, letterG, number8},
    {ab8, letterA, letterBorFlatSymbol, number8},
    {a8, symbolBlank, letterA, number8},
    {bb8, letterBorFlatSymbol, letterBorFlatSymbol, number8},
    {b8, symbolBlank, letterBorFlatSymbol, number8},
    {c9, symbolBlank, letterC, number9},
    {db9, letterD, letterBorFlatSymbol, number9},
    {d9, symbolBlank, letterD, number9},
    {eb9, letterE, letterBorFlatSymbol, number9},
    {e9, symbolBlank, letterE, number9},
    {f9, symbolBlank, letterF, number9},
    {gb9, letterG, letterBorFlatSymbol, number9},
    {g9, symbolBlank, letterG, number9},
};

void noteOnDisplay(uint16_t note) {
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
