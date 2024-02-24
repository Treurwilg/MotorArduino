/************
* Deze sketch wordt opgezet om de O2-sensor
* van onze Morris te onderzoeken, los van Speeduino.
* De sensor, LC-2 van Innovate, wordt aangesloten via de controller:
* zwart =  ground
* rood = 12V, tevens de voeding van de Arduino op Vin:
* geel = output1 0 (=7.35AFR)- 5 (22.39AFR) volt naar A0;
* bruin = output2 1.1 (=14AFR) en 0.1 (=15AFR) volt (nog niet gebruikt)
* Doel: zelfstandig instrument maken met eigen display.
* Deze versie getest op 23-02-2024 met spiritusdoek op de sensor en 
* daarmee het verdampingsverloop gevolgd mbv serial plotter. Dat 
* duurde wel een minuut of 12.
*************/
float O2;
float factor;
float ondergrens; // in digitale waarde van 0 tot 1023
float bovengrens; // idem

void setup() {
  Serial.begin(115200);
  factor = (23.39 - 7.35)/1023;
  /* Voor bruine draad van de analoge output 
  * dwz het bereik van 0.1 tot 1.1 volt =
  * AFR 15 tot AFR 14 
  */
  ondergrens = 1023.0 * 0.1 / 5.0;
  bovengrens = 1023.0 * 1.1 / 5.0;
}

void loop() {
O2 = analogRead(A0);
O2 = 7.35 + O2 * factor;
Serial.println(O2);
/* Voor het kleine bereik */
O2 = analogRead(A2);
if (O2 >= ondergrens && O2 <= bovengrens) {
  O2 = 15 - 4.5 * O2 / 1023;
  Serial.println(O2);
} else {
  Serial.println("****");
}
delay(1000);
}
