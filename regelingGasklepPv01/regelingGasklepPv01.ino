// regelingGasklepPv01
// 27-6-2022: Transistor vervangen door een nieuwe. Diode vervangen door SB560.
// Schottky kan de snelle puls van de tegenEMK beter aan. Zener weggelaten. Nu geen 
// hoge temperatuur meer.
// 21-6-2022: Deze versie werkt nu, praktisch gezien. De klep laat zich over het hele 
// bereik regelen. De pieken zitten nog steeds in het PWM signaal. De schakeltransistor
// wordt bloedheet. De gemeten waarde kloppen nog niet. 
// 20-6-2022: meetwaarde float gemaakt, anders wordt ie bij deling door
// 1023 gelijk nul. Meting van de potmeterwaarde van de gasklep ingevoerd voor
// regeling. Dit wordt vastgelegd in de variabele 'meting', de waarde die wordt 
// vergeleken met 'setpoint'. Proportionele regeling gemaakt. 
// 
int pinMeting = A6;
int pinSetpoint = A0; //pin voor 0 tot 5 volt input
int pinOnderwaarde = A4; //pin voor de middenspanning op de onderwaardepotmeter
int pinStuurwaarde = 5; // pin voor de PWM output
int meting;   // waarde gemeten van de potmeter van de gasklep (0 - 1023)
int onderwaarde; // waarde gelezen van de onderwaardepotmeter (0 - 1023)
float setpoint; // waarde gelezen uit de input van 0 tot 5 volt omgezet naar 0 - 1023
int stuurwaarde; // dutycycle voor de PWMpin (0 - 255)
unsigned long tijd, tijdOud; // om print te timen.
float Kp; //factor voor de proportionele regeling (alleen de P van PID)
int error; // is setpoint - meting

  
void setup() {
  Serial.begin(115200);
  pinMode(pinStuurwaarde, OUTPUT);
  tijdOud = millis();
  Kp = 0.9;
}

void loop() {
  tijd = millis();
  meting = analogRead(pinMeting);
  setpoint = analogRead(pinSetpoint);
  error = setpoint - meting;
  onderwaarde = analogRead(pinOnderwaarde);
  stuurwaarde = onderwaarde + Kp * error;
  if (stuurwaarde < onderwaarde/2.) {stuurwaarde = 0;}
  if (stuurwaarde > 1023) {stuurwaarde = 1023;}
  stuurwaarde = stuurwaarde / 4.; // analogWrite() heeft ingangsbereik van 0 - 255.
  analogWrite(pinStuurwaarde, stuurwaarde);
  if ((tijd - tijdOud) > 1000) {
    Serial.print("setpoint:    ");
    Serial.println((int)setpoint);
    Serial.print("onderwaarde: ");
    Serial.println(onderwaarde); 
    Serial.print("stuurwaarde: ");
    Serial.println(stuurwaarde);
    Serial.print("meting:      ");
    Serial.println(meting);
    Serial.println(" ");
    tijdOud = tijd;
  }
}
