/*
  HC-SR04 Basic Demonstration
  HC-SR04-Basic-Demo.ino
  Demonstrates functions of HC-SR04 Ultrasonic Range Finder
  Displays results on Serial Monitor
*/

// This uses Serial Monitor to display Range Finder distance readings

// Hook up HC-SR04 with Trig to Arduino Pin 10, Echo to Arduino pin 13

#define trigPin 10
#define echoPin 13
#define soundPin 9
#define beattime 50

float duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(soundPin, OUTPUT);
}

void loop() {
   
  // Write a pulse to the HC-SR04 Trigger Pin
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
 
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  
  distance = (duration / 2) * 0.0343;
  
  // Send results to Serial Monitor

  Serial.print("Distance = ");
  noTone(12);
  if (100 < distance){
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  else if ((90 < distance)&&(distance < 100)){
    tone(soundPin, 294, beattime);
    Serial.print(distance);
    Serial.println(" cm");
    delay(455);
  }
  else if ((80 < distance)&&(distance < 90)){
    tone(soundPin, 294, beattime);
    Serial.print(distance);
    Serial.println(" cm");
    delay(410);
  }
  else if ((70 < distance)&&(distance < 80)){
    tone(soundPin, 294, beattime);
    Serial.print(distance);
    Serial.println(" cm");
    delay(365);
  }
  else if ((60 < distance)&&(distance < 70)){
    tone(soundPin, 294, beattime);
    Serial.print(distance);
    Serial.println(" cm");
    delay(320);
  }
  else if ((50 < distance)&&(distance < 60)){
    tone(soundPin, 294, beattime);
    Serial.print(distance);
    Serial.println(" cm");
    delay(275);
  }
  else if ((40 < distance)&&(distance < 50)){
    tone(soundPin, 294, beattime);
    Serial.print(distance);
    Serial.println(" cm");
    delay(230);
  }
  else if ((30 < distance)&&(distance < 40)){
    tone(soundPin, 294, beattime);
    Serial.print(distance);
    Serial.println(" cm");
    delay(185);
  }
  else if ((20 < distance)&&(distance < 30)){
    tone(soundPin, 294, beattime);
    Serial.print(distance);
    Serial.println(" cm");
    delay(140);
  }
  else if ((10 < distance)&&(distance < 20)) {
    tone(soundPin, 294, beattime);
    Serial.print(distance);
    Serial.println(" cm");
    delay(100);
  }
  else{
    tone(soundPin, 294, beattime);
    Serial.print(distance);
    Serial.println(" cm");
  }
}
