//Variables Encoder

const byte encoderPin[6] = {
  42, 44, 46, 48, 50,  52};
const byte encoderPinD[6] = {
  43, 45, 46, 47, 48, 51};

int encoderPos[6] ={
  0,0,0,0,0,0};

boolean encoderLast[6] = { 
  LOW, LOW, LOW, LOW, LOW,LOW};
byte p= 0;



void setup(){
  for(byte i=0;i<12;i++){
    pinMode(encoderPin[i], INPUT);
    digitalWrite(encoderPin[i], INPUT);
  }
  Serial.begin(9600);

}

void loop(){

  boolean encoderActual = digitalRead(encoderPin[p]);

  if((encoderLast[p] == HIGH) && ( encoderActual== LOW)){
    if(digitalRead(encoderPinD[6]) == LOW){
      encoderPos[p]--;
      Serial.print ("L");
      Serial.println(p+1);
    }
    else{
      encoderPos[p]++;
      Serial.println("R");
      Serial.println(p+1);
    }

  }
  encoderLast[p] = encoderActual;
  p++; 
  if (p>= 6) p = 0;
}





