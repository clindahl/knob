#include "Mouse.h"

// Variables for Potentiometer
int potVal;
int mappedSense;
int mappedLed;

// Definition of pins
const int PinBtnLED = 5;
// Encoder CLK signal
const int PinA = 2;
// Encoder DT signal
const int PinB = 3;
// Encoder push button switch
const int PinSW = 8;
// Sensitivity from Potentiomenter
const int PinSPot = 0;

// Interupt Function  
void encoderTurning ()  {
  static unsigned long lastInterruptTime = 0;
  unsigned long interruptTime = millis();

  // If interrupts come faster than 5ms, assume it's a bounce and ignore
  if (interruptTime - lastInterruptTime > 5) {
    if (digitalRead(PinB) == LOW)
    {
      Mouse.move(0, +mappedSense);  
    }
    else {
      Mouse.move(0, -mappedSense);
    }
  }
  // Keep track of timing (no more than every 5ms)
  lastInterruptTime = interruptTime;
}

void setup() {
  // Just then debugging, view output on serial monitor
  Serial.begin(115200);

  // Rotary pulses are INPUTs
  pinMode(PinA, INPUT);
  pinMode(PinB, INPUT);

  // Switch is floating so use the in-built PULLUP so we don't need a resistor
  pinMode(PinSW, INPUT_PULLUP);

  // Attach the isr-function to run at the interrupts in pinA of the Encoder.
  attachInterrupt(digitalPinToInterrupt(PinA), encoderTurning, LOW);

  // Ready to start!
  Serial.println("Start");
  Mouse.begin();
}

void loop() {
  // Checking if button is pressed on the encoder
  if ((!digitalRead(PinSW))) {
      if (Mouse.isPressed()) {
        Mouse.release();
        analogWrite(PinBtnLED, 0);
        Serial.println("Mousebutton Released");        
      }
      else {
        Mouse.press();
        analogWrite(PinBtnLED, map(potVal, 0, 1024, 20,200));
        Serial.println("Mousebutton Pressed and hold!");        
      }
    while (!digitalRead(PinSW))
      delay(10);
    Serial.print("Sensitivity: ");
    Serial.println(mappedSense);
  }  
  
  potVal = analogRead(PinSPot);
  mappedSense = map(potVal, 0, 1023, 1, 10);
  mappedLed = map(potVal, 0, 1023, 20,200);

  if (Mouse.isPressed()) { 
    analogWrite(PinBtnLED, mappedLed);
  }
}