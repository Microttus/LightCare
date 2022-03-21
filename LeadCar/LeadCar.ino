// Martin Økter
// IceCube Solutions
// 21.08.2022
// LeadCar

int motorRPin = 6;
int motorLPin = 5;

void setup() {
  pinMode(motorRPin, OUTPUT);
  pinMode(motorLPin, OUTPUT);

}

void loop() {
  delay(10000);

  // Accelerate up
  for (int i = 0; i < 255; ++i){
    analogWrite(motorRPin, i);
    analogWrite(motorLPin, i);

    delay(10);
  }

  // Break test
  analogWrite(motorRPin, 100);
  analogWrite(motorLPin, 100);

  delay(2000);

  // Turn right
  analogWrite(motorRPin, 120);
  analogWrite(motorLPin, 100);

  delay(2000);

  // Turn left
  analogWrite(motorRPin, 100);
  analogWrite(motorLPin, 120);

  delay(2000);

  // Slow forvard
  analogWrite(motorRPin, 30);
  analogWrite(motorLPin, 30);

  delay(2000);

  // Stop
  analogWrite(motorRPin, 0);
  analogWrite(motorLPin, 0);

  delay(10);
}
