int count;
int x;
void setup() {
  // put your setup code here, to run once:
 // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(2,INPUT);
 pinMode(3,INPUT);
 attachInterrupt(digitalPinToInterrupt(2), add,RISING);
 //attachInterrupt(digitalPinToInterrupt(3), misn,CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(count);

  while(true){
    Serial.print("angular speed : ");
    Serial.println((2 * 3.14 * count)/(7.0 * 0.2));
    count = 0;
    delay(200);
    //Serial.println(count);
  }
}
void add(){
  count++;
}
void misn(){
  count--;
}

