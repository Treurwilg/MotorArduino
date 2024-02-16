/************
* Deze sketch wordt opgezet om de O2-sensor
* van de Morris te onderzoeken, los van Speeduino.
* De sensor, l2 van Innovate, wordt aangesloten via de controler:
* zwart =  ground
* rood = 12V, tevens de voeding van de Arduino op Vin:
* bruin = output 0 - 5 volt naar A0;
* geel = output (nog niet gebruikt)
* Plan: zelfstandig instrument maken met eigen display.
* 
*************/


void setup() {
  Serial.begin(115200);

}

void loop() {
O2 = analogRead(A0);
Serial.println(O2);
delay(1000);

}
