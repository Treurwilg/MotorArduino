// This sketch tests the the range of the valve potmeters while 
// the valve cruises the range from closed to open.
// The DC voltage of the powersupply with which the 
// valve is "controlled" also will be measured and 
// printed. Not implemented in this version.

// Gebruik van de caansluitingen van de gasklep:
// rood:  + accu
// groen: - accu
// geel:  loper pot2
// zwart: loper pot1
// wit:   +5V van de Arduino
// grijs: - van de Arduino\\\\\\\\\\

const int pinPot1Voltage = A0; // on test system: black wire 
const int pinPot2Voltage = A2; // yellow wire
const int pinValveSteeringVoltage = A4;
unsigned long tijd, tijdOud; // for timing prints
int pot1Voltage;
int pot2Voltage;
int valveSteeringVoltage;
String progress;

void setup() {
  Serial.begin(115200);
  Serial.println("Output from  sketch testRangeValvePots");
  Serial.println(" ");
  progress = "";
  tijdOud = millis();
}

void loop() {
  tijd = millis();
  
  pot1Voltage = analogRead(pinPot1Voltage);
  pot2Voltage = analogRead(pinPot2Voltage);
  valveSteeringVoltage = analogRead(pinValveSteeringVoltage);

  if ((tijd - tijdOud) > 1000) { 
    
    // values are in the ADC range of 0 to 1023
    Serial.println(" ");
    Serial.println(progress);
    Serial.println("Output from  sketch testRangeValvePots");
    Serial.print("pot1Voltage:   ");
    Serial.println( pot1Voltage );
    Serial.print("pot2Voltage:   ");
    Serial.println( pot2Voltage );
    // Serial.print("valveSteeringVoltage:   ");
    // Serial.println( valveSteeringVoltage );

    tijdOud = tijd;
    progress = progress + "*";
    if (progress.length() > 40) { progress = "*";}
  }
}
