#include <Servo.h>

Servo thumb;
Servo index;
Servo major;
Servo ring;
Servo annular;

int i;
int j;
Servo wrist;

Servo hand[]={thumb, index, major, ring, annular};

void setup() {

    for(i=0; i<5;i++){
        hand[i].attach(i+3);
    }
    wrist.attach(8);
    wrist.write(20);
}

void loop() {
 
    for (i=0;i<5;i++){
      hand[i].write(170);
      delay(100);
    }
    delay(2000);
    
    for (i=0;i<5;i++){
        hand[i].write(70);
        delay(100);
    }  
    delay(2000);
    fuxx();

    delay(2000);
    like();

    delay(2000);
    coucou();

    delay(2000);
  }

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






