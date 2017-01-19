#include <Servo.h>

Servo right;
Servo left;

int PIN_RIGHT = 13; // MUST be changed to pin
int PIN_LEFT = 14; // MUST be changed to pin
int PIN_LONG_IR = 15; // MUST be changed to pin
int PIN_SHORT_IR = 16; // MUST be changed to pin

// sometimes servos will be miscalibrated
// the screw on the servo must either be adjusted or the values 
// in the code must be adjusted
// modifying code is easier if the robot is already assembled
int RIGHT_FWD = 2000; // MUST be reviewed
int RIGHT_STOP = 1500; // MUST be reviewed
int RIGHT_BWD = 1000; // MUST be reviewed

int LEFT_FWD = 1000; // MUST be reviewed
int LEFT_STOP = 1500; // MUST be reviewed
int LEFT_BWD = 2000; // MUST be reviewed

int TURN_DELAY_90 = 1000; // in milliseconds; time that turn will run inorder to turn 90 degrees

void setup() {
  // put your setup code here, to run once:
  right.attach(PIN_RIGHT);
  left.attach(PIN_LEFT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //check wall ahead
  int wallAhead  = readLongIR();
   
  //if wall ahead
    int wallRight = readShortIR();
    //if no wall on right, turn right
    turnRight90();
    
    
    //else if wall on right, start turning left
    turnLeft90();
  //else
    forwardMilliseconds(1000);

}

void turnRight90() {
  right.writeMicroseconds(RIGHT_FWD);
  left.writeMicroseconds(LEFT_BWD);
  delay(TURN_DELAY_90); // in milliseconds; review above
  right.writeMicroseconds(RIGHT_STOP);
  left.writeMicroseconds(LEFT_STOP);
}

void forwardMilliseconds(int ms) {
  right.writeMicroseconds(RIGHT_FWD);
  left.writeMicroseconds(LEFT_FWD);
  delay(ms);
  right.writeMicroseconds(RIGHT_STOP);
  left.writeMicroseconds(LEFT_STOP);
}

void backwardMilliseconds(int ms) {
  right.writeMicroseconds(RIGHT_BWD);
  left.writeMicroseconds(LEFT_BWD);
  delay(ms);
  right.writeMicroseconds(RIGHT_STOP);
  left.writeMicroseconds(LEFT_STOP);
}


void turnLeft90() {
  right.writeMicroseconds(RIGHT_BWD);
  left.writeMicroseconds(LEFT_FWD);
  delay(TURN_DELAY_90); // in milliseconds; review above
  right.writeMicroseconds(RIGHT_STOP);
  left.writeMicroseconds(LEFT_STOP);
}

int scaleIR(int n) {
  // function stub use if desired
  return n;
}

int readLongIR() {
  return scaleIR(analogRead(PIN_LONG_IR));
}

int readShortIR() {
  return scaleIR(analogRead(PIN_SHORT_IR));
}

