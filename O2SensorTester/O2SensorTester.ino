/************
* Deze sketch wordt opgezet om de AFR-sensor
* van onze Morris te onderzoeken, los van Speeduino.
* De O2-sensor (Bosch) wordt aangesloten via de LC-2 controller van Innovate:
* zwart =  ground
* rood = 12V, tevens de voeding van de Arduino op Vin:
* geel = output1: 0 volt = 7.35AFR en 5 volt = 22.39 AFR naar A0;
* bruin = output2: 1.1 volt = 14 AFR en 0.1 volt = 15 AFR volt (nog niet gebruikt)
* Doel: zelfstandig instrument maken met eigen display.
* Deze versie getest op 27-02-2024 met spiritusdoek op de sensor en 
* daarmee het verdampingsverloop gevolgd mbv serial plotter. Dat 
* duurde wel een minuut of 12.
*************/
float AFR;
float AFRc;
float O2; // for full range
float O2c; // for central range
float factor;
float ondergrens; // in digitale waarde van 0 tot 1023
float bovengrens; // idem
int lines; // telt aantal geprinte regels

void setup() {
  Serial.begin(115200);
  /* For output 1: */
  factor = (23.39 - 7.35)/1023;
  /* For output 2: */
  ondergrens = 1023.0f * 0.1f / 5.0f;
  bovengrens = 1023.0f * 1.1f / 5.0f;
  Serial.println("AFR     AFRc");
  lines = 0;
}
void loop() { 
if (lines > 7) {
  Serial.println("AFR     AFRc");
  lines = 0;
}
/* For full range */
O2 = analogRead(A0);
AFR = 7.35 + O2 * factor;
Serial.print(AFR);
Serial.print("   ");

/* For central range */

if (AFR < 14) {
  AFRc = 23.39;
}
if (AFR >= 14 && AFR <= 15) {
  O2c = analogRead(A2);
  AFRc = 15 - 5 * (O2c / 1023) + 0.1;
} 
if (AFR > 15) {
  AFRc = 0;
}
Serial.println(AFRc);
lines++;
delay(1000);
}
