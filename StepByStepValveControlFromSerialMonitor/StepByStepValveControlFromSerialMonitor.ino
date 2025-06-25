// Basicly this is taken from the Arduino Forum:
// https://forum.arduino.cc/t/simple-stepper-program/268292
// Testing a stepper motor with a Polulu A4988
// driver board on a Nano;
// It is made to controle the idlevalve of the RIDEX
// throttlebody 158T0040
// It is determined in a different sketch that the 
// total nummber of steps from idle valve opened to
// closed is 90 (we did not have data on the valve).
// In this sketch first the valve is positioned fully
// open: position 90. Than it is positioned at step 80.
// as the upper operational open limit. 
// The lower operational close limit is 10 when closing. 
// Than at increasing temperature of the coolant it 
// it will be steered in closing direction so that the 
// idling RPM ends somewhere at 800, or the coolant 
// temperature at ??. This we still have to investigate 
// with the aid of TunerStudio.

byte directionPin = 8;
byte stepPin = 9;
byte valvePosition; // aantal stappen
// vanaf de gesloten positie 0

unsigned long curMillis;
unsigned long prevStepMillis = 0;
unsigned long pulseLengthMillis = 5;
unsigned long millisBetweenSteps = 500;

void moveSingleStep() {
  while ((millis() - prevStepMillis) < millisBetweenSteps ) {}
  prevStepMillis = millis();
  digitalWrite(stepPin, HIGH);
  digitalWrite(stepPin, LOW);   
}

void printSituation() {
    Serial.print("Valve position: ");
    Serial.println(valvePosition);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Starting idle valve control test");
  Serial.println("Sketch: StepByStepValveControlFromSerialMonitor");                          
  pinMode(directionPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  digitalWrite(stepPin, LOW);
  int i;
  valvePosition = 100;

  // initieer klep in gesloten (valvePosition 0) 
  // resp geopende positie (valvePosition 90)
  // Dan weten we de uiterste open startpositie.
  // 
  digitalWrite( directionPin, HIGH); // is: sluiten
  i = 0;
  while ( i < 90 ) {
    moveSingleStep();
    i++;
    valvePosition--;
    Serial.println(valvePosition);
  }
  valvePosition = 0;

  digitalWrite( directionPin, LOW); // is: openen
  i = 0;
  while ( i < 90) {
    moveSingleStep();
    i++;
    valvePosition++;
    Serial.println(valvePosition);
  }  
  valvePosition = 90;

  Serial.println(valvePosition);
  // zet nu de klep op zijn operationele uiterste 
  // openstand, valvePosition 80;
  digitalWrite( directionPin, HIGH );
  i = 0;
  while ( i < 10 ) {
    moveSingleStep();
    i++;
    valvePosition--;
    Serial.println("setup klein beetje sluiten: ");
    Serial.println(valvePosition);
  }
}

void loop() {
  Serial.println("Geef het aantal stappen op, '-' = sluiten, '+' = openen"); 
  // - = sluitrichting, + = openrichting
  while ( Serial.available() == 0){}
  int stappen = Serial.parseInt();
  Serial.print("Stappen: ");
  Serial.println(stappen);
  while (Serial.available() > 0) { // maak serial buffer leeg
    char t = Serial.read();
  }
  if ( stappen != 0) {
    for (int i = 0; i < abs(stappen); i++) {
      if ((stappen > 0) && (valvePosition < 80 )) {
        digitalWrite( directionPin, LOW);
        moveSingleStep();
        valvePosition++;
        Serial.println(valvePosition);
      }
      if (( stappen < 0) && (valvePosition > 10 )) {
        digitalWrite( directionPin, HIGH);
        moveSingleStep();
        valvePosition--;
        Serial.println(valvePosition);        
      }
    }
  printSituation();
  }
}




