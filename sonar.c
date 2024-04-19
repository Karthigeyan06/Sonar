#include <Servo.h>

#define trigPin 7
#define echoPin 6
#define ledPin 13

Servo servoMotor;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  servoMotor.attach(9);
}

void loop() {
  
  for (int angle = 0; angle <= 180; angle++) {
    servoMotor.write(angle);
    delay(15);
    checkDistance();
  }

  
  for (int angle = 180; angle >= 0; angle--) {
    servoMotor.write(angle);
    delay(15);
    checkDistance();
  }
}

void checkDistance() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  
  if (distance < 10) { 
    digitalWrite(ledPin, HIGH); 
    delay(500);
    digitalWrite(ledPin, LOW); 
  }
}
