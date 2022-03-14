//Martin Økter
//12.03.2022
//Photocar

int photoRPin = A1;
int photoLPin = A0;
int motorRPin = 6;
int motorLPin = 5;


void setup() {
  //Setup of the pinmodes, and other code which are only to be run ones
  
  pinMode(photoRPin, INPUT);
  pinMode(photoLPin, INPUT);
  pinMode(motorRPin, OUTPUT);
  pinMode(motorLPin, OUTPUT);
}

void loop() {
  //Main loop for your code which is suposed to be ran for as long as the Arduino have power
  
  int lightR = analogRead(photoRPin); //Read value of photoresistor 1
  int lightL = analogRead(photoLPin); //Read value og photoresistor 2

  int lightSum = (lightR + lightL)/2; //Find mean vaue of the two sensores
  int lightDiff = lightR - lightL;      //Find the differance form the two sensores

  int motorBaseSpeed = constrain(map(lightSum, 2000, 4095, 200, 0),0,200);             //Invert the sum for use to speed and allow for turn at max speeed
  int corrSpeed = map(lightDiff, -4095, 4095, -100, 100);
  
  int motorRSpeed = constrain(motorBaseSpeed - corrSpeed, 0, 255);  //Calcualte speed for right motor and constrain for PWM
  int motorLSpeed = constrain(motorBaseSpeed + corrSpeed, 0, 255);  //Calcualte speed for left motor and constrain for PWM

  analogWrite(motorRPin, motorRSpeed);  //Write to motorcontroller
  analogWrite(motorLPin, motorLSpeed);  //-||-

  delay(10); //Constrict the motor for running to fast
}
