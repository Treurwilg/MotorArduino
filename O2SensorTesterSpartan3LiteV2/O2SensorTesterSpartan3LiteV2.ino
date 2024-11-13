/************
* Deze sketch wordt opgezet om de O2-sensor
* van onze Morris te onderzoeken, los van Speeduino.
* De sensor, LSU49B0 van Spartan3LiteV2, wordt aangesloten via de controller
* (14POINT7):
* zwart =  ground
* wit = ground, voor de verwarming van de sensor
* rood = 12V:
* groen = output1 0 (=10AFR)- 5 (20AFR) volt naar A0;
* bruin = simulated narrowband (niet aangesloten)
* blauw = Sensor Temperature led output (led los van arduino)
* Deze versie getest op 12-11-2024 met spiritusdoek op de sensor en 
* daarmee het verdampingsverloop gevolgd mbv serial plotter. Dat 
* duurde een minuut of 20. Er was een consistent verloop 
* tussen de minimum (10) en maximum (20) AFR waarde.
*************/
char sketch[] = "O2SensorTesterSpartan3LiteV2.ino";
const float AFRtop = 20.0;
const float AFRbottom = 10.0;
float O2sensor;
float O2AFR;
float factor;
int printregel;
const int O2InputPin = A0;

void setup() {
  Serial.begin(115200);
  factor = (AFRtop - AFRbottom)/1023.0;
  printHeader();
  printregel = 0;
}

void loop() {
  O2sensor = analogRead(O2InputPin);
  O2AFR = AFRbottom + O2sensor * factor;
  Serial.print(O2sensor);
  Serial.print("   ");
  Serial.print(factor);
  Serial.print("   ");
  Serial.println(O2AFR);
  printregel++;
  if (printregel == 10) {
    printHeader();
    printregel = 0;
  }
  delay(1000);
}

void printHeader() {
  Serial.print("Sketch: ");
  Serial.println(sketch);
  Serial.println("O2sensor  factor O2AFR");
}
