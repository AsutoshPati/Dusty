/*
 * Title       - Automatic Duster
 * Author      - Mr. Asutosh Pati (https://www.linkedin.com/in/asutoshpati) 
 * Co-Author   - Ms. Vandana Kumari
 * Created On  - 15-04-2019
 */


#define motor_pin1 11   // connect to pin number 11
#define motor_pin2 12   // connect to pin number 12
#define sensor_pin 9    // connect sensor output to pin number 09

int path = 1;           // (motion key): 1 - left to right; 2 - right to left;
int delayTime = 500;    // set delay time as per your requirement in milliseconds


void setup(){
  
  pinMode(motor_pin1,OUTPUT);
  pinMode(motor_pin2,OUTPUT);
  pinMode(sensor_pin,INPUT);
  
  Serial.begin(9600);

  Serial.println("initializing AUTOMATIC DUSTER");
  for(int i=0;i<=10;i++){
    Serial.print(". ");
    delay(100);
  }
  Serial.println("100%\n AUTOMATIC DUSTER program initialized\n\n\n\n");

  Serial.println("Dusty: Hello Vandana ...");
  Serial.println("Dusty: I am your own BOARD CLEANING BOT.");
  Serial.println("Dusty: Ready to serve you.");
  Serial.println("Dusty: command me.....");
  
}

void loop(){
  
  if(digitalRead(sensor_pin) == LOW){
    
    Serial.println("Dusty: Gesture Detected !!!");
    Serial.println("Dusty: Cleaning Board....");
    
    Start(path);
    delay(delayTime);
    Stop();
    path = ToggleDirection(path);
    Start(path);
    delay(delayTime);
    Stop();
    path = ToggleDirection(path);
    
    Serial.println("Dusty: Board is cleaned.\n\n\n\n");
    
  }
  
}


/* Start - gives motion according to the current path left to right or vice versa */
void Start(int path){

  if(path == 1){
    digitalWrite(motor_pin1,HIGH);
    digitalWrite(motor_pin2,LOW);
  }
  else if(path == 2){
    digitalWrite(motor_pin2,HIGH);
    digitalWrite(motor_pin1,LOW);
  }
}


/* Stop - stops the duster motion */
void Stop(){
  
  digitalWrite(motor_pin1,LOW);
  digitalWrite(motor_pin2,LOW);
  
}


/* ToggleDirection - 
   changes direction from left to right or vice versa when it reaches to the end */
int ToggleDirection(int path){
  if(path == 1){ path = 2; }
  else if(path == 2){ path = 1; }
}



/* EmergencyStop - helps to stop bot from motion in tedious situation */
void EmergencyStop(){
  
  digitalWrite(motor_pin1,HIGH);
  digitalWrite(motor_pin2,HIGH);
  
}
