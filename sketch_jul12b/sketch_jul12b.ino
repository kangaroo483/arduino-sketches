/*
Robotics with the BOE Shield – ServosOppositeDirections
Generate a servo full speed counterclockwise signal with pin 13 and
full speed clockwise signal with pin 12.
*/

#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left servo signal
Servo servoRight;                            // Declare right servo signal
int PIEZOPIN = 10;

// One octave of notes between A4 and A5
int note_A4 = 440;
int note_As4 = 466; int note_Bb4 = note_As4;
int note_B4 = 494;
int note_C5 = 523;
int note_Cs5 = 554; int note_Db5 = note_Cs5;
int note_D5 = 587;
int note_Ds5 = 622; int note_Eb5 = note_Ds5;
int note_E5 = 659;
int note_F5 = 698;
int note_Fs5 = 740; int note_Gb5 = note_Fs5;
int note_G5 = 784;
int note_Gs5 = 830; int note_Ab5 = note_Gs5;

int note_A5 = note_A4 * 2;
int note_As5 = note_As4 * 2; int note_Bb5 = note_As5;
int note_B5 = note_B4 * 2;

int note_rest = -1;

// note lengths defined here
long whole_note = 3000; // change tempo by changing duration of one measure
long half_note = whole_note / 2;
long quarter_note = whole_note / 4;
long eighth_note = whole_note / 8;
long sixteenth_note = whole_note / 16;

// song is stored as notes and duration of those notes
long worknotes[61][2] = {
  {note_A4, sixteenth_note}, {note_C5, sixteenth_note}, {note_D5, eighth_note}, {note_D5, eighth_note}, {note_D5, sixteenth_note}, 
  {note_E5, sixteenth_note}, {note_E5, sixteenth_note}, {note_F5, sixteenth_note}, {note_F5, sixteenth_note}, 
  {note_G5, sixteenth_note}, {note_E5, eighth_note}, {note_E5, sixteenth_note},{note_D5, sixteenth_note}, 
  {note_C5, sixteenth_note}, {note_C5, eighth_note}, {note_D5, half_note}, {note_A5, sixteenth_note}, {note_C5, sixteenth_note}, 
  {note_D5, eighth_note}, {note_D5, sixteenth_note}, {note_D5, sixteenth_note}, {note_E5, sixteenth_note}, {note_F5, eighth_note}, 
  {note_F5, sixteenth_note}, {note_F5, sixteenth_note},{note_G5, sixteenth_note}, {note_E5, eighth_note}, {note_E5, eighth_note}, 
  {note_D5, sixteenth_note}, {note_C5, sixteenth_note}, {note_D5, half_note}, {note_A4, eighth_note}, {note_C5, sixteenth_note}, 
  
  {note_D5, eighth_note}, {note_D5, sixteenth_note}, {note_D5, eighth_note}, {note_F5, eighth_note}, {note_G5, half_note}, {note_G5, sixteenth_note}, 
  {note_G5, eighth_note}, {note_A4, sixteenth_note}, {note_Bb5, eighth_note}, {note_Bb5, sixteenth_note}, {note_A4, sixteenth_note},
  {note_G5, sixteenth_note}, {note_A4, sixteenth_note}, {note_D5, half_note}, {note_D5, sixteenth_note}, {note_E5, sixteenth_note}, 
  {note_F5, eighth_note}, {note_F5, eighth_note}, {note_G5, sixteenth_note}, {note_A4, sixteenth_note}, {note_D5, half_note}, {note_D5, sixteenth_note}, 
  {note_F5, sixteenth_note}, {note_E5, eighth_note}, {note_E5, sixteenth_note}, {note_F5, sixteenth_note}, {note_D5, eighth_note},
  {note_E5, half_note}
  };

// Everything is Awesome
long awesome_notes[35][2] = {
  // Measure 0
  {note_rest, eighth_note * 4}, 
  {note_Ab5, eighth_note}, 
  {note_Ab5, eighth_note}, 
  {note_Ab5, eighth_note}, 
  {note_Ab5, eighth_note},
  // Measure 1
  {note_Ab5, eighth_note}, 
  {note_G5, eighth_note * 7},
  // Measure 2
  {note_rest, eighth_note * 4}, 
  {note_Ab5, eighth_note}, 
  {note_Ab5, eighth_note}, 
  {note_Ab5, eighth_note}, 
  {note_Ab5, eighth_note},
  // Measure 3
  {note_Ab5, quarter_note}, 
  {note_G5, eighth_note}, 
  {note_F5, eighth_note}, 
  {note_Eb5, eighth_note}, 
  {note_F5, eighth_note}, 
  {note_G5, eighth_note}, 
  {note_F5, eighth_note * 3},
  // Measure 4
  {note_rest, eighth_note}, 
  {note_Ab5, eighth_note * 2}, 
  {note_Ab5, eighth_note}, 
  {note_Ab5, eighth_note}, 
  {note_Ab5, eighth_note},
  // Measure 5
  {note_Ab5, eighth_note},
  {note_Bb5, eighth_note * 7},
  // Measure 6
  {note_rest, eighth_note},
  {note_Bb4, eighth_note},
  {note_Bb4, eighth_note},
  {note_G5, eighth_note * 2},
  {note_F5, eighth_note},
  {note_F5, eighth_note},
  {note_Eb5, eighth_note},
  // Measure 7
  {note_Eb5, quarter_note * 3},
  {note_rest, quarter_note}
};
  
// if you want there to be silence between notes,
//   staccato should be true
bool staccato = true;


void setup()                                 // Built in initialization block
{  
  pinMode(PIEZOPIN, OUTPUT);
 servoLeft.attach(13);                      // Attach left signal to pin 13
 servoRight.attach(12);                     // Attach right signal to pin 12
}

void loop()                                  // Main loop auto-repeats
{
  for(int i=0; i<62; i++){
 servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
 servoRight.writeMicroseconds(1700);        // 1.3 ms -> clockwise
 delay(500);
    int between = 0;
    if(staccato){
      between = 50;
    }
 servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
 servoRight.writeMicroseconds(1700);            // 1.3 ms -> clockwise
 delay(500);
    // Play tone, or play silence (for rest)
    if (worknotes[i][0] == note_rest) {
      noTone(PIEZOPIN);
    }
    else {
      tone(PIEZOPIN, worknotes[i][0]);
    }
      servoLeft.write(180);
  servoRight.write(180);
 delay(2000);
    delay(worknotes[i][1] - between);
    noTone(PIEZOPIN);
    delay(between);
  }


// servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
// servoRight.writeMicroseconds(1500);        // 1.3 ms -> clockwise
// delay(1000);


// servoLeft.writeMicroseconds(1300);         // 1.7 ms -> counterclockwise
// servoRight.writeMicroseconds(1300);        // 1.3 ms -> clockwise
// delay(500);
}
