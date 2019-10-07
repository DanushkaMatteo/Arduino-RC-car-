
#define threeway_pin 39
#define RX_pin 31
#define RY_pin 33
#define LX_pin 37
#define LY_pin 35
#define VarA_pin 41

#define L1 4
#define L2 2
#define LPWM 7
#define R1 5
#define R2 3
#define RPWM 6

int servomax = 175;
int servomin = 5;

int threeway;
int RX;
int RY;
int LX;
int LY;
int VarA;

int SpeedValue;
int LeftMotor;
int RightMotor;

void setup() {
  Serial.begin(9600);
  pinMode(RY_pin,INPUT);
  pinMode(RX_pin,INPUT);
  pinMode(LY_pin,INPUT);
  pinMode(LX_pin,INPUT);
  pinMode(threeway_pin,INPUT);
  pinMode(VarA_pin,INPUT);

  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(LPWM,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(RPWM,OUTPUT);
}

void loop() {//y 180  100 down x 85 175
  getreadings();
if(threeway>190){
  drive();
}else if(threeway<100){
  wait();
}else{
  arm();
}
}                                                                                                                                                                                                                                                                                                                                                                                          

void getreadings(){
  
 RX=map(pulseIn(RX_pin,HIGH),1060,1749,0,255);//1050
 RY=map(pulseIn(RY_pin,HIGH),1168,1787,0,255);
 LY=map(pulseIn(LY_pin,HIGH),1000,2000,0,255);
 LX=map(pulseIn(LX_pin,HIGH),990,2000,0,255);
 threeway=map(pulseIn(threeway_pin,HIGH),960,2000,0,255);
 VarA=map(pulseIn(VarA_pin,HIGH),980,2000,0,255);
 
}

void forward(int LSPEED,int RSPEED){
  analogWrite(LPWM,LSPEED);
  analogWrite(RPWM,RSPEED);
  digitalWrite(L1,1);
  digitalWrite(L2,0);
  digitalWrite(R1,1);
  digitalWrite(R2,0);
}
void backward(int LSPEED,int RSPEED){
  analogWrite(LPWM,LSPEED);
  analogWrite(RPWM,RSPEED);
  digitalWrite(L1,0);
  digitalWrite(L2,1);
  digitalWrite(R1,0);
  digitalWrite(R2,1);
}

void wait(){
  analogWrite(LPWM,0);
  analogWrite(RPWM,0);
  digitalWrite(L1,0);
  digitalWrite(L2,0);
  digitalWrite(R1,0);
  digitalWrite(R2,0);
}

void right(int LSPEED,int RSPEED){
  analogWrite(LPWM,LSPEED);
  analogWrite(RPWM,RSPEED);
  digitalWrite(L1,1);
  digitalWrite(L2,0);
  digitalWrite(R1,0);
  digitalWrite(R2,1);
}

void left(int LSPEED,int RSPEED){
  analogWrite(LPWM,LSPEED);
  analogWrite(RPWM,RSPEED);
  digitalWrite(L1,0);
  digitalWrite(L2,1);
  digitalWrite(R1,1);
  digitalWrite(R2,0);
}

void drive(){
  /**************************************/

  if(RY>180){
   if(RX>175){
    forward(0,RY);
   }else if(RX<85){
    forward(RY,0);
   }else{
    forward(RY,RY);
    }
  }
  
 /**************************************/
  
  else if(RY<100){
    if(RX>175){
    backward(255-RY,0);
    }else if(RX<85){
     backward(0,255-RY);
    }else{
     backward(255-RY,255-RY);
    }
  }u

/**************************************/
  
  else{
   if(RX>175){
    left(255,255);
    }else if(RX<85){
    right(255,255);
    }else{
       wait();
    }
  }
}


void arm(){
}
