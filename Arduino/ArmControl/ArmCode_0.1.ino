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

const int del=1;
int boo;
void setup() {
  // put your setup code here, to run once:
  pinMode(22,LOW);
  
  pinMode(24,HIGH);
  pinMode(26,HIGH);
  pinMode(28,HIGH);
  pinMode(30,HIGH);
  pinMode(32,HIGH);
  pinMode(34,HIGH);
  pinMode(36,HIGH);
  pinMode(38,HIGH);
  
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
  
  axis(state());
  pmotor(digitalRead(dir),boo);
  
}
int state(){
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
void axis(int axis){
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
void pmotor(int d, int boo){
  digitalWrite(latch,LOW);
  if(boo==1&&d==1){
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(del);
  }
  if(d==0&&boo==1){
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,HIGH);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,LOW);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,HIGH);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, HIGH);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,HIGH);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
      digitalWrite(latch, LOW);
      delay(del);
      digitalWrite(latch, LOW);
      digitalWrite(motorA,HIGH);
      digitalWrite(motorB,LOW);
      digitalWrite(motorC,LOW);
      digitalWrite(motorD,LOW);
      delay(del);
  }
}
