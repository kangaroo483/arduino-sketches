#include <Servo.h>

Servo servoRight;
Servo servoLeft;

void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(12);
  servoRight.attach(13);
}

void loop() {
  turnwalkR(1000);
  turnRight(2000);
  turnwalkL(1000);
  stopnow();
  backward(1000);
  turnRight(2000);
  stopnow();
  //forward(1000);
  //turnLeft(500);
  delay(2000);
}

void stopnow(){
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

void turnLeft(int time)                      // Left turn function
{
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(time);                               // Maneuver for time ms
}


void turnRight(int time)                     // Right turn function
{
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(time);                               // Maneuver for time ms
}

void backward(int time)                      // Backward function
{
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(time);                               // Maneuver for time ms
}

void forward(int time)                     // Forward function
{
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(time);                               // Maneuver for time ms
}

void turnwalkR(int time)
{
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1500);
  delay(time);
}

  
void turnwalkL(int time)
 {
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1300);
  delay(time);
 }

