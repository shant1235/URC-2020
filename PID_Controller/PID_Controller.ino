#include <PID_v1.h>

double kP = 5;
double kI = 0.5;
double kD = 0;
double reference;
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

PID myPID(&currentSpeed,&outputSpeed,&reference,kP,kI,kD,DIRECT);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 reference = 675;
 myPID.SetMode(AUTOMATIC);
 myPID.SetTunings(kP,kI,kD);
 pinMode(2,INPUT);
 pinMode(3,INPUT);
 attachInterrupt(digitalPinToInterrupt(2), add,RISING);
 lastTime = millis()/1000;
 pinMode(6,OUTPUT);
}

void loop() {


/*
  if(lastTime != millis()/1000){
 
   lastTime = millis()/1000;

  }
   */
   //Serial.print("Timer: ");
   //Serial.print(millis());
   //Serial.print(" ms");
   //Serial.print(" | ");
   Serial.print("Position: ");
   Serial.print(counter);
   Serial.print(" | ");
   //Serial.print("RPM Time: ");
   //Serial.print((elapsedTime/ 1000));
   //Serial.print(" | ");
    myPID.Compute();
   delay(100);
    rpm = (( 10 * 60 * counter)/(7.0));
    counter = 0;
   
  
   currentSpeed = rpm;
  
   Serial.print("RPM: ");
   Serial.print(currentSpeed);
   Serial.print(" | ");
   Serial.print("Output: ");
   Serial.print(outputSpeed);
   Serial.print(" | ");
   Serial.print("Refrence ");
   Serial.println(reference);
   
  // Serial.print(" | ");
  // Serial.print("Rotations: ");
  // Serial.println(counter/7.0);  
   

   
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
