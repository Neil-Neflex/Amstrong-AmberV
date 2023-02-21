#include <Servo.h>

Servo thumb;
Servo index;
Servo major;
Servo ring;
Servo annular;

Servo hand[]={thumb, index, major, ring, annular};

void setup() {

  int i;
  for(i=0; i<4;i++){
    hand[i].attach(i+3);
  }
  
  for(i=0;i<4;i++){
    hand[i].write(90);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}