//Variables Encoder

const byte encoderPin[12] = {
  42, 43 , 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};

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
}

void loop(){

  boolean encoderActual = digitalRead(encoderPin[p*2]);

  if((encoderLast[p] == HIGH) && ( encoderActual== LOW)){
    if(digitalRead[p*2+1] == LOW){
      encoderPos[p]--;
      Serial.println ("L"+(p+1));
    }
    else{
      encoderPos[p]++;
      Serial.println ("R"+(p+1));
    }

  }
  encoderLast[p] = encoderActual;
  p++; if (p> 6) p = 0;
}




