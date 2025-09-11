// Basicly this is taken from the Arduino Forum:
// https://forum.arduino.cc/t/simple-stepper-program/268292
// Testing a stepper motor with a Polulu A4988
// driver board on a Nano; the onboard led will 
// flash with each step. This version uses delay 
// to manage timing.

byte directionPin = 8;
byte stepPin = 9;
int numberOfSteps = 90;
byte ledPin  = 13;
int pulseWidthMicros = 2000;
int millisBetweenSteps = 10;

void setup() {

  Serial.begin(9600);
  Serial.println("Starting Steppertest");
  

  delay(1000);

  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  
}

void loop() {
  digitalWrite(ledPin, LOW);
  digitalWrite(directionPin, HIGH);
  for (int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros); 
    // this line is probably unnecessary
    digitalWrite(stepPin, LOW);
    delay(millisBetweenSteps);
  }
  
  // delay(3000);
  
  digitalWrite(ledPin, HIGH);
  digitalWrite(directionPin, LOW);
  for (int n = 0; n < numberOfSteps; n++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pulseWidthMicros); 
    // this line is probably unnecessary
    digitalWrite(stepPin, LOW);
    delay(millisBetweenSteps);
    
  }
}
