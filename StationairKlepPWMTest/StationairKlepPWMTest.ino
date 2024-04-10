/* 
 *  2023-08-20
 *  Deze sketch is bedoeld als simpel hulpmiddel om een PWM stationairklep op
 *  het werkingsbereik te testen. De uitgang schakelt mosfet zodanign dat
 *  de minkant van de klepspoel wel of niet met aarde verbonden wordt. Aan de 
 *  A5 is een potmeter van 10kOhm verbonden met de loper. Het systeem gaat uit
 *  van een PWM frequentie van 200 Hz.
 *  
 */

 int dutyCycle; // percentage
 int potMeting; // 0 - 1023
 int hoog;
 int intPeriod;
 unsigned long hoogTijd; // 0 - 5000 microseconds
 unsigned long tijd; // doorlopende tijd in microseonden sinds begin van 
 // programma. Na plm 70 minuten reset naar nul!!!
 
 unsigned long oudeTijd;
 unsigned long oudePrintTijd;
 unsigned long printPeriod = 1000000; // microseconds
 int pinOut = 5;
 int pinIn = A6;
 unsigned long period = 5000; // microseconds voor 200 Hz
 
void setup() {
  Serial.begin(115200);
  pinMode(pinOut, OUTPUT);
  oudeTijd = micros();
  oudePrintTijd = micros();
  digitalWrite(pinOut, HIGH);
}

void loop() {
  potMeting = analogRead(pinIn);
  intPeriod = (int)period;
  hoog = map(potMeting, 0, 1023, 0, intPeriod);
  hoogTijd = (unsigned long)hoog;
  dutyCycle = (100 * hoogTijd)/period;
  tijd = micros();
  while (tijd < (oudeTijd + hoogTijd)) {
    tijd = micros();
  }
  digitalWrite(pinOut, LOW);
  while (tijd < (oudeTijd + period)) {
    tijd = micros();
  }
  digitalWrite(pinOut, HIGH);
  oudeTijd = tijd;
  
 if (tijd >= oudePrintTijd + printPeriod) {
    Serial.println(dutyCycle);
    oudePrintTijd = tijd;    
  } 
}
