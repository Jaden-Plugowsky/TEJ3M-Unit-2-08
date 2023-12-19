// Created by: Jaden Plugowsky
// Created on: Nov 2023
//
// This is a circuit with a potentiometer that
//   moves a servo variably.

#include <Servo.h>

Servo servoNumber1;

int pin3 = 3;
int potPin = A1;
double mapThing = 1023.0 / 180.0;
double readValue;
double mappedValue;

void setup() {
    // Setup servo
    servoNumber1.attach(pin3);
    servoNumber1.write(0); // Default servo position
    Serial.begin(9600);
}

void loop() {
    // Read and map potentiometer input
    readValue = analogRead(potPin);
    mappedValue = readValue / mapThing;

    // Update serial monitor
    Serial.print("readValue is: ");
    Serial.println(readValue);
    Serial.print("mappedValue is: ");
    Serial.println(mappedValue);
    Serial.println();

    // Move servo
    servoNumber1.write(mappedValue);

    delay(100);
}
