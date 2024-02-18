/************
* Deze sketch wordt opgezet om de O2-sensor
* van onze Morris te onderzoeken, los van Speeduino.
* De sensor, LC-2 van Innovate, wordt aangesloten via de controller:
* zwart =  ground
* rood = 12V, tevens de voeding van de Arduino op Vin:
* geel = output 0 (=7.35AFR)- 5 (22.39AFR) volt naar A0;
* bruin = output 1.1 (=14AFR) en 0.1 (=15AFR) volt (nog niet gebruikt)
* Doel: zelfstandig instrument maken met eigen display.
* 
*************/
int O2;

void setup() {
  Serial.begin(115200);

}

void loop() {
O2 = analogRead(A0);
Serial.println(O2);
delay(1000);

}
