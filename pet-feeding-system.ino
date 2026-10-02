#include <Servo.h>

Servo myServo;

int buttonPin = 2;
int ldrPin = A0;

int feedCount = 0;

void setup() {

  pinMode(buttonPin, INPUT_PULLUP);

  myServo.attach(9);
  myServo.write(0);

  Serial.begin(9600);
}

void loop() {

  int lightValue = analogRead(ldrPin);

  if (lightValue < 500) {   

    if (digitalRead(buttonPin) == LOW) {

      if (feedCount < 2) {

        myServo.write(90);
        delay(1000);

        myServo.write(0);
        delay(1000);

        feedCount++;

        Serial.print("Food portions given: ");
        Serial.println(feedCount);

        delay(500);
      }
    }
  }
}