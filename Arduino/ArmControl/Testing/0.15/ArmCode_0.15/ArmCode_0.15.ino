const int gnd = 22;
const int latch = 24;
const int a0=32;
const int a1=26;
const int a2=34;
const int motorA=38;
const int motorB=30;
const int motorC=36;
const int motorD=28;

const int input1=40;
const int input2=42;
const int input3=44;
const int input4=46;
const int input5=48;
const int input6=50;
const int dir=52;

int boo;
void setup() {
  // setups the arduino pins
  pinMode(22,LOW);
  
  pinMode(24,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(30,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(36,OUTPUT);
  pinMode(38,OUTPUT);
  
  pinMode(40,INPUT);
  pinMode(42,INPUT);
  pinMode(44,INPUT);
  pinMode(46,INPUT);
  pinMode(48,INPUT);
  pinMode(50,INPUT);
  pinMode(52,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int del=1;
  int posi[5][2];
  int change=0;
  int state[5];//possible multi axis movement array
  pos(posi,state(),&change);
  axis(state());
  pmotor(digitalRead(dir),boo,&del,&change);
  
}
int state(){ //takes the state of an input to determine which axis to move
  if(digitalRead(input1)==1){
    return 1; 
  }
  if(digitalRead(input2)==1){
    return 2;
  }
  if(digitalRead(input3)==1){
    return 3;
  }
  if(digitalRead(input4)==1){
    return 4;
  }
  if(digitalRead(input5)==1){
    return 5;
  }
  if(digitalRead(input6)==1){
    return 6;
  }
  else{
    return 0;
  }
}
void pos(int pos[][2], int state, int *change){//take in a pos and an array to know where the arm is at any given time
  pos[state-1][1]=  pos[state-1][1]+ *change;
  Serial.println(pos[state-1][1]);
}
void axis(int axis){//converts button push into binary output for the serial 
  switch(axis){
    case 1:
    digitalWrite(a0,HIGH);
    digitalWrite(a1,LOW);
    digitalWrite(a2,LOW);
    boo=1;
    break;
    case 2:
    digitalWrite(a0,LOW);
    digitalWrite(a1,HIGH);
    digitalWrite(a2,LOW);
    boo=1;
    break;
    case 3:
    digitalWrite(a0,LOW);
    digitalWrite(a1,LOW);
    digitalWrite(a2,HIGH);
    boo=1;
    break;
    case 4:
    digitalWrite(a0,LOW);
    digitalWrite(a1,HIGH);
    digitalWrite(a2,HIGH);
    boo=1;
    break;
    case 5:
    digitalWrite(a0,HIGH);
    digitalWrite(a1,LOW);
    digitalWrite(a2,HIGH);
    boo=1;
    break;
    case 6:
    digitalWrite(a0,LOW);
    digitalWrite(a1,HIGH);
    digitalWrite(a2,HIGH);
    default:
    boo=0;
    break;
  }
}
void pmotor(int d, int boo,int *del, int *change){//outputs the binary necessary to run the motor through the phases
  digitalWrite(latch,LOW);
  if(boo==1&&d==1){
      *change= *change+1;
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(*del);
  }
  if(d==0&&boo==1){
      *change = *change-1;
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(*del);
      digitalWrite(latch, LOW);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
      delay(*del);
  }
}
/*void aspeed(int *del){ //will program speed control in later if I can
  *del= 
}*/
