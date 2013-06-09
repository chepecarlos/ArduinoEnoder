const byte encoderPin[12] = {
  42, 43 , 44, 45, 46, 47, 48, 49, 50, 51, 52, 53};

void setup(){
 for(byte i=0;i<12;i++){
  pinMode(encoderPin[i], INPUT);
  digitalWrite(encoderPin[i], INPUT);
 }
}

void loop(){

}

