// Basicly this is taken from the Arduino Forum:
// https://forum.arduino.cc/t/simple-stepper-program/268292
// Testing a stepper motor with a Polulu A4988
// driver board on a Nano;
// It is made to controle the idlevalve of the RIDEX
// throttlebody 158T0040
// It is determined in a different sketch that the 
// total nummber of steps from idle valve opened to
// closed is 90 (we did not have data on the valve).
// In the setup of this sketch first the valve is positioned fully
// open: position 90. Than it is positioned at step 80.
// as the upper operational open limit. 
// The lower operational close limit is 10 when closing. 
// For the sake of measuring the step pulses by means of an 
// occilloscope this sketch closes and opens the valve
// continuously step by step.  
// Als de steel van de motor helemaal uitgeschroefd is met 
// direction = HIGH, is de klep 
// gesloten, valvePosition = 0. Als de steel helemaal ingeschroefd
// is met direction = LOW, is de klep maximaal geopend, valvePosition = 90;

byte directionPin = 8;
byte stepPin = 9;
byte valvePosition; // aantal stappen vanaf de gesloten positie 0
byte bovengrens = 55;
byte ondergrens = 35;
bool direction;
int increment;
unsigned long curMillis;
unsigned long prevStepMillis = 0;
unsigned long pulseLengthMillis = 5;
unsigned long millisBetweenSteps = 20;

void moveSingleStep() {
  while ((millis() - prevStepMillis) < millisBetweenSteps ) {}
  prevStepMillis = millis();
  digitalWrite(stepPin, HIGH);
  digitalWrite(stepPin, LOW);   
}

void printValvePosition() {
    Serial.print("Valve position: ");
    Serial.println(valvePosition);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting idle valve control test");
  Serial.println("Sketch: continuouslyClosingAndOpeningIdleValve");                          
  Serial.println("Het eerste traject is voor de bepaling van het nulpunt");
  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  digitalWrite(stepPin, LOW);
  direction = HIGH;
  int i;

  // initieer klep in gesloten (valvePosition 0) 
  // Dan weten we de uiterste gesloten positie.
  // Ga vervolgens naar de operationele startpositie: 
  // 80 van de 90 stappen
  digitalWrite( directionPin, HIGH); // is: sluiten
  i = 0;
  while ( i < 93 ) {
    moveSingleStep();
    i++;
  }
  valvePosition = 0; 

  digitalWrite( directionPin, LOW); // is: openen
  i = 0;
  while ( i < 80) {
    moveSingleStep();
    i++;
    valvePosition++;
    printValvePosition();
  }  
}

void loop() {
// start with closing valve, then reverse direction and 
// increment so it opens, then again reverse, and so on.
  millisBetweenSteps = 500;
  increment = -1;
  while ( valvePosition > ondergrens ) { 
    digitalWrite( directionPin, HIGH);
    moveSingleStep();
    valvePosition = valvePosition + increment;
    printValvePosition();
  }
  

  increment = -increment;
  while ( valvePosition < bovengrens ) { 
    digitalWrite( directionPin, LOW);
    moveSingleStep();
    valvePosition = valvePosition + increment;
    printValvePosition();
  }
}
