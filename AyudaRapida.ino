
#include <Encoder.h>
#include <digitalWriteFast.h>


int VA=0,VB=0,VC=0;
int sensorValue1, sensorValue2, sensorValue3;
int LandingGear = 33; /* Landing gear*/

int LG=0,AV=0,PS=0;
int LG2=0,VA2=0;

int lednose = 35;
int ledright = 36;
int ledleft = 37;
int ledtran = 38;
int ledfap = 39;
int ledfup = 40;
int ledfdw = 41;
int dato;

Encoder En1(42, 43); //Autopilot
Encoder En2(44, 45); //Nav 2
Encoder En3(46, 47); //Freq Abajo
Encoder En4(48, 49); //Barometro
Encoder En5(50, 51); //Nav 1
Encoder En6(52, 53); //Freq Arriba

void setup() {
  Serial.begin(9600);

  pinModeFast(LandingGear, INPUT);
  pinModeFast(lednose, OUTPUT);
  pinModeFast(ledright, OUTPUT);
  pinModeFast(ledleft, OUTPUT);
  pinModeFast(ledtran, OUTPUT);
  pinModeFast(ledfap, OUTPUT);
  pinModeFast(ledfup, OUTPUT);
  pinModeFast(ledfdw, OUTPUT);

}

long O1  = -999,O2  = -999,O3  = -999,O4  = -999,O5  = -999,O6  = -999;


void loop() {


  sensorValue2 = analogRead(A1);
  if((VB > (sensorValue2+10))||(VB < (sensorValue2-10))){
    Serial.print("VB: ");
    Serial.println((int)((sensorValue2-26)*20.5416)-4096);
  }
  VB=sensorValue2;




  if (Serial.available() > 0){ 
    dato = Serial.read();
    if (dato == '1') {
      digitalWriteFast(lednose, LOW);
    }
    else if (dato == '2') {
      digitalWriteFast(lednose, HIGH);
    }
    else if (dato == '3') {
      digitalWriteFast(ledright, LOW);
    }
    else if (dato == '4') {
      digitalWriteFast(ledright, HIGH);
    }
    else if (dato == '5') {
      digitalWriteFast(ledleft, LOW);
    }
    else if (dato == '6') {
      digitalWriteFast(ledleft, HIGH);
    }
    else if (dato == '7') {
      digitalWriteFast(ledtran, LOW);
    }
    else if (dato == '8') {
      digitalWriteFast(ledtran, HIGH);
    }
    else if (dato == 'E') {
      digitalWriteFast(ledfap, LOW);
    }
    else if (dato == 'F') {
      digitalWriteFast(ledfap, HIGH);
    }
    else if (dato == 'C') {
      digitalWriteFast(ledfup, LOW);
    }
    else if (dato == 'D') {
      digitalWriteFast(ledfup, HIGH);
    }
    else if (dato == 'A') {
      digitalWriteFast(ledfdw, LOW);
    }
    else if (dato == 'B') {
      digitalWriteFast(ledfdw, HIGH);
    }
  }







  long N1 = En1.read(),N2 = En2.read(),N3 = En3.read(),N4 = En4.read(),N5 = En5.read(),N6 = En6.read();

  if (N1 < O1) {
    O1 = N1;
    Serial.println ("R1");
  }
  else if (N1 > O1) {
    O1 = N1;
    Serial.println ("L1");
  }

  if (N2 < O2) {
    O2 = N2;
    Serial.println ("R2");
  }
  else if (N2 > O2) {
    O2 = N2;
    Serial.println ("L2");
  }

  if (N3 < O3) {
    O3 = N3;
    Serial.println ("R3");
  }
  else if (N3 > O3) {
    O3 = N3;
    Serial.println ("L3");
  }

  if (N4 < O4) {
    O4 = N4;
    Serial.println ("R4");
  }
  else if (N4 > O4) {
    O4 = N4;
    Serial.println ("L4");
  }

  if (N5 < O5) {
    O5 = N5;
    Serial.println ("R5");
  }
  else if (N5 > O5) {
    O5 = N5;
    Serial.println ("L5");
  }

  if (N6 < O6) {
    O6 = N6;
    Serial.println ("R6");
  }
  else if (N6 > O6) {
    O6 = N6;
    Serial.println ("L6");
  }






  if (digitalReadFast(LandingGear) == HIGH){ 
    LG=1;
  } 
  else{
    LG=0;
  }
  if(LG != LG2){
    if(LG == 0){
      Serial.print("GEAR0");
    }
    else{
      Serial.print("GEAR1");
    }
    Serial.println();
    LG2 = LG;
  }

}

