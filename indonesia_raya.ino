// Can be moved in header file i.e notes.h
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Ab4 466
#define B4 494
#define Cb5 554
#define Ab5 932
#define Gb5 831
#define Fb5 740
#define Db5 622
#define Gb4 415
#define F5 698
#define B5 988
#define Cb6 1109
#define Db6 1245

const int midi1[149][3] = {
 {Ab4, 400, 0},
 {B4, 200, 0},
 {Cb5, 600, 0},
 {Ab5, 925, 75},
 {Ab5, 200, 0},
 {Gb5, 325, 75},
 {Gb5, 200, 0},
 {Fb5, 600, 0},
 {Cb5, 800, 400},
 {Cb5, 325, 75},
 {Cb5, 200, 0},
 {Db5, 600, 0},
 {Cb5, 600, 0},
 {B4, 600, 0},
 {Ab4, 600, 0},
 {Gb4, 1350, 450},
 {Gb4, 400, 0},
 {Ab4, 200, 0},
 {B4, 600, 0},
 {Gb5, 925, 75},
 {Gb5, 200, 0},
 {Fb5, 325, 75},
 {Fb5, 200, 0},
 {F5, 600, 0},
 {Db5, 800, 400},
 {Cb5, 325, 75},
 {Cb5, 200, 0},
 {F5, 600, 0},
 {Db5, 600, 0},
 {Cb5, 600, 0},
 {B4, 600, 0},
 {Ab4, 1350, 450},
 {Ab4, 400, 0},
 {B4, 200, 0},
 {Cb5, 600, 0},
 {Ab5, 925, 75},
 {Ab5, 200, 0},
 {Gb5, 325, 75},
 {Gb5, 200, 0},
 {Fb5, 600, 0},
 {Cb5, 800, 400},
 {Cb5, 325, 75},
 {Cb5, 200, 0},
 {Db5, 600, 0},
 {Cb5, 600, 0},
 {Fb5, 600, 0},
 {Gb5, 600, 0},
 {F5, 1200, 0},
 {Db5, 275, 325},
 {Db5, 325, 75},
 {Db5, 200, 0},
 {B5, 525, 75},
 {B5, 600, 0},
 {Ab5, 600, 0},
 {Gb5, 600, 0},
 {Cb6, 1200, 0},
 {Fb5, 250, 350},
 {F5, 400, 0},
 {Db5, 200, 0},
 {Cb5, 600, 0},
 {B5, 600, 0},
 {Ab5, 600, 0},
 {Gb5, 600, 0},
 {Fb5, 1350, 450},
 {Cb5, 325, 75},
 {Cb5, 200, 0},
 {Db5, 600, 0},
 {B5, 325, 75},
 {B5, 125, 75},
 {B5, 525, 75},
 {B5, 325, 75},
 {B5, 200, 0},
 {Ab5, 600, 0},
 {Fb5, 325, 75},
 {Fb5, 125, 75},
 {Fb5, 275, 325},
 {F5, 400, 0},
 {Fb5, 200, 0},
 {Gb5, 600, 0},
 {Cb6, 325, 75},
 {Cb6, 125, 75},
 {Cb6, 600, 0},
 {B5, 325, 75},
 {B5, 200, 0},
 {Ab5, 1200, 0},
 {Fb5, 275, 325},
 {Cb5, 325, 75},
 {Cb5, 200, 0},
 {Db5, 600, 0},
 {B5, 325, 75},
 {B5, 125, 75},
 {B5, 525, 75},
 {B5, 325, 75},
 {B5, 200, 0},
 {Ab5, 600, 0},
 {Fb5, 325, 75},
 {Fb5, 125, 75},
 {Fb5, 275, 325},
 {F5, 400, 0},
 {Fb5, 200, 0},
 {Gb5, 600, 0},
 {Cb6, 525, 75},
 {Cb6, 600, 0},
 {Ab5, 400, 0},
 {Gb5, 200, 0},
 {Fb5, 1350, 450},
 {Fb5, 325, 75},
 {Fb5, 200, 0},
 {B5, 600, 0},
 {Db6, 325, 75},
 {Db6, 125, 75},
 {Db6, 525, 75},
 {Db6, 325, 75},
 {Db6, 200, 0},
 {Cb6, 600, 0},
 {Ab5, 325, 75},
 {Ab5, 125, 75},
 {Ab5, 275, 325},
 {Cb6, 325, 75},
 {Cb6, 200, 0},
 {B5, 600, 0},
 {Gb5, 325, 75},
 {Gb5, 125, 75},
 {Gb5, 600, 0},
 {Cb6, 400, 0},
 {B5, 200, 0},
 {Ab5, 1200, 0},
 {Fb5, 275, 325},
 {Fb5, 325, 75},
 {Fb5, 200, 0},
 {B5, 600, 0},
 {Db6, 325, 75},
 {Db6, 125, 75},
 {Db6, 525, 75},
 {Db6, 325, 75},
 {Db6, 200, 0},
 {Cb6, 600, 0},
 {Ab5, 325, 75},
 {Ab5, 125, 75},
 {Ab5, 275, 325},
 {Cb6, 336, 78},
 {Cb6, 129, 78},
 {Cb6, 647, 0},
 {B5, 441, 0},
 {Ab5, 221, 0},
 {Gb5, 721, 0},
 {Ab5, 568, 0},
 {Gb5, 408, 0},
 {Fb5, 4068, 0},
};

void playMidi(int pin, const int notes[][3], size_t len){
 for (int i = 0; i < len; i++) {
    // tone(pin, notes[i][0]);
    // delay(notes[i][1]);
    for (int j = 0; j < notes[i][1]; j++) {
      digitalWrite(pin, HIGH);
      delayMicroseconds(250000 / notes[i][0]);
      
      digitalWrite(pin, LOW);
      delayMicroseconds(750000 / notes[i][0]);
    }
    // noTone(pin);
    digitalWrite(pin, LOW);
    delay(notes[i][2]);
  }
}
// Generated using https://github.com/ShivamJoker/MIDI-to-Arduino

// main.ino or main.cpp
void setup() {
  // put your setup code here, to run once:
  // play midi by passing pin no., midi, midi len
  playMidi(13, midi1, ARRAY_LEN(midi1));
}

void loop() {
  // put your main code here, to run repeatedly:
}
