#include <PID_v1.h>

double kP = 1;
double kI = 1;
double kD = 1;
double reference = 50;
double currentSpeed = 1;
double outputSpeed = 1;


int counter = 0;
int lastState;
int currentState;
int lastTime;
int rpmCounter = 0;
double rpmStartTime;
double rpmEndTime;
double rpm = 1;
double elapsedTime = 0;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(2,INPUT);
 pinMode(3,INPUT);
 attachInterrupt(digitalPinToInterrupt(2), add,RISING);
 lastTime = millis()/1000;
}

void loop() {


  while(e() != 0){
/*
  if(lastTime != millis()/1000){
 
   lastTime = millis()/1000;

  }
   */
   Serial.print("Timer: ");
   Serial.print(millis());
   Serial.print(" ms");
   Serial.print(" | ");
   Serial.print("Position: ");
   Serial.print(counter);
   Serial.print(" | ");
   Serial.print("RPM Time: ");
   Serial.print((elapsedTime/ 1000));
   Serial.print(" | ");
   Serial.print("RPM: ");
   if(elapsedTime != 0){
    rpm = (1/(elapsedTime/ 1000))* 60;
   }
   
   Serial.print(rpm);
   Serial.print(" | ");
   Serial.print("Rotations: ");
   Serial.println(counter/7.0);  
   
u();

}
   
}

double e(){
  currentSpeed = (1/(elapsedTime/ 1000))* 60;
  double error = reference - currentSpeed;
  return error;
}
double u(){
  double output = (kP * e());
   Serial.print("OUTPUT:");
  Serial.print(output);
  return output;
 
}
void add(){
  counter++;
}
