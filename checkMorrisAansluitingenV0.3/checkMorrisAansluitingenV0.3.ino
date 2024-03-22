/*
    Dit is versioe 0.3 dd 15-2-2023
    Hiermee moeten alle sensoren en actuatoren verbonden
    aan Speeduino NO2c getest kunnen worden. Van de pulsteller
    worden het aantal overgangen HIG LOW weergegeven voor het
    draaien van het pulswiel met de hand,

    Dit is versie 0.2 dd 2-2-2023
    T.o.v. versie 0.1 is de aansturing van de
    injectoren gewijzigd, zodanig dat de openingstijd
    van de injectoren beperkt is.
    Dit is versie 0.1 dd 2-2-2023
    Hier mee kan gecheckt worden of de sensors
    doorverbonden zijn met Speeduino processor
    via het NO2c Speeduino shield. (behalve de
    Hall-sensor, die geeft een ongewenste effecten
    op het shield.)
    Ook de aansturing van de injectoren kan getest
    worden.
    Tot zover functioneert deze sketch.
*/
const byte pinFP = 4;
const byte pinIDLE = 5;
const byte pinINJ1 = 8;
const byte pinINJ2 = 9;
const byte pinIGN2 = 22;
const byte pinIGN1 = 23;
const byte pinTACH = 19;

int TPS;
int CLT;
int IAT;
int O2;
int BAT;
int MAP;
int TACH;
byte printTeller;

void setup() {
  Serial.begin(115200);
  pinMode(pinFP, OUTPUT);
  pinMode(pinIDLE, OUTPUT);
  pinMode(pinINJ1, OUTPUT);
  pinMode(pinINJ2, OUTPUT);
  pinMode(pinIGN2, OUTPUT);
  pinMode(pinIGN1, OUTPUT);

  digitalWrite(pinFP, LOW);
  digitalWrite(pinIDLE, LOW);
  digitalWrite(pinINJ1, LOW);
  digitalWrite(pinINJ2, LOW);
  digitalWrite(pinIGN2, LOW);
  digitalWrite(pinIGN1, LOW);

  printTeller = 0;
  Serial.println();
  printKop();
}

void loop() {
 digitalWrite(pinIGN1, HIGH);
 //digitalWrite(pinINJ1, HIGH);
  //digitalWrite(pinFP, HIGH);
  //digitalWrite(pinIDLE, HIGH);
  delay(2);
  //digitalWrite(pinINJ1, LOW);
  digitalWrite(pinIGN1, LOW);
  delay(50);
  //digitalWrite(pinINJ2, HIGH);
  digitalWrite(pinIGN2, HIGH);
  delay(2);
  //digitalWrite(pinINJ2, LOW);
  digitalWrite(pinIGN2, LOW);
  digitalWrite(pinIDLE, LOW);
  delay(50);

  Serial.println();

  TPS = analogRead(A3);
  Serial.print(TPS);
  Serial.print("     ");

  CLT = analogRead(A4);
  Serial.print(CLT);
  Serial.print("     ");

  IAT = analogRead(A5);
  Serial.print(IAT);
  Serial.print("     ");

  O2  = analogRead(A2);
  Serial.print(O2);
  Serial.print("     ");

  BAT = analogRead(A1);
  Serial.print(BAT);
  Serial.print("     ");

  MAP = analogRead(A0);
  Serial.print(MAP);
  Serial.print("     ");

  TACH = digitalRead(pinTACH);
  Serial.print(TACH);
  Serial.print("     ");

  printTeller++;
  if (printTeller == 8) {
    printKop();
    printTeller = 0;
  }
}

void printKop() {
  Serial.println();
  Serial.println();
  Serial.print("TPS");
  Serial.print("     ");
  Serial.print("CLT");
  Serial.print("     ");
  Serial.print("IAT");
  Serial.print("     ");
  Serial.print("O2 ");
  Serial.print("     ");
  Serial.print("BAT");
  Serial.print("     ");
  Serial.print("MAP");
  Serial.print("    ");
  Serial.print("TACH"); /* pulsen/seconde) */
  Serial.print("     ");
  Serial.println();
}
