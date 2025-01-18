#include <Servo.h>
Servo servo;
unsigned long int currentTime = 0;

const int ledPin_1 = 6;   //red led
const int ledPin_2 = 9;   //yellow led
int i = 0;
int u = 0;


unsigned long int LEDprevTime = 0;
unsigned long int LEDtriggTime = 300;
unsigned long int LEDriseTime = 400;

unsigned long int yellPrevTime = 0;  //previous time for yellow led

unsigned long int servoPrevTime = 0;
unsigned long int servoTriggTime = 1000;

void setup() {
  servo.attach(11);
  pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  currentTime = millis();
  
  //led red
  if((currentTime - LEDprevTime) >= LEDtriggTime){
    digitalWrite(ledPin_1, HIGH);
    if(currentTime - LEDprevTime >= LEDriseTime){
      LEDprevTime = currentTime;
    }
  }
  else{
    digitalWrite(ledPin_1, LOW);
  }

  //yellow led
  if(currentTime - yellPrevTime >= LEDtriggTime){
    analogWrite(ledPin_2, u);

    if(u >= 255){
      yellPrevTime = currentTime;
      u = 0;
    }
    u++;

  }
  else{
    analogWrite(ledPin_2, 0);
  }





  //led servo
  if((currentTime - servoPrevTime) >= servoTriggTime){
    servo.write(i);

    if(i >= 180){
      i=0;
      servoPrevTime = currentTime;
    }


    i++;
  }
  else{
    servo.write(0);
  }
  Serial.println(u);
  // put your main code here, to run repeatedly:

}
