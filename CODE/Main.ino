
#include <Servo.h>

// The forarm
Servo thumb;
Servo index;
Servo major;
Servo ring;
Servo annular;

Servo wrist;

//The biceps
Servo elbow;
Servo rotShoulder;
Servo upShoulder;

//The speed action button 
const short int LED = 12;
const short int BUTTON = 13; 

unsigned long currentTime;
boolean ETA = 0;
int button;
int i;
int j;

// The list of all the fingers
Servo hand[]={thumb, index, major, ring, annular};

void setup() {
    for(i=2; i<7;i++){
        hand[i].attach(i);
    }
    wrist.attach(7);
    wrist.write(20); // to initialize the write who's fragile
    pinMode(LED, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  button = digitalRead(BUTTON);
  if (millis() - currentTime > 500){
         currentTime = millis();
         ETA =! ETA;
         digitalWrite(LED,ETA);
      }
  if (button== LOW){
    digitalWrite(LED, LOW);
    demo();
    }
  }

 void demo(){
    style();
    delay(2000); 
    fuxx();
    delay(2000);
    like();
    delay(2000);
    coucou();
    delay;
  }
 void style(){
  for (i=0;i<5;i++){
      hand[i].write(170);
      delay(100);
    }
    delay(2000);
    for (i=0;i<5;i++){
        hand[i].write(70);
        delay(100);
    } }

 void fuxx(){
    for(i=0;i<5;i++){
        hand[i].write(175);
        delay(100);
    }
    major.write(60);
 }

void like(){
    for (i=0;i<5;i++){
        hand[i].write(60);
        delay(100);
    }
    major.write(180);
    ring.write(180);  
}

void okay(){
    //revoir angle pouce index + retendre les cables
    for (i=0;i<5;i++){
        hand[i].write(60);
        delay(100);
    }
    thumb.write(170);
    index.write(140);
}

void coucou(){
    for (i=0;i<5;i++){
        hand[i].write(60);
        delay(100);
    }
    for (i=0;i<4;i++){
        wrist.write(0);
        delay(500);
        wrist.write(40);
        delay(500);
    }
    wrist.write(20);
}