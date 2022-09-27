#include <Servo.h>

Servo myservo;
Servo myservo1;

int pos1 = 0;
int pos2 = 0;
int button = 9;

int buzzer1 = 10;

int ran1;
int ran2;

int correct = 0;
int total = 0;

int ButtonValue = 0;

int Button1 = 2;
int Button2 = 4;

int check = 3;

int checkvalue = 0;
int LED = 13;
int ButtonValue2 = 0;

int digit1 = 0;
int digit2 = 0;

void setup() {
  
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(Button1, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Button2, INPUT);
  pinMode(check, INPUT);
  myservo.attach(8);
  myservo.write(pos1);
  myservo1.attach(12);
  myservo1.write(pos2);
  Serial.begin(9600);


}

void loop() {
  ran1 = random(0,10);
  ran2 = random(0,10);
  showquestion(ran1, ran2);
  

  int checkvalue = digitalRead(check);
  
  while (checkvalue != 1) {
  
    
  int state = digitalRead(button);
  if (state == 1) {
  
  ButtonValue = digitalRead(Button1);
  
  if (ButtonValue == 1) {
  
    if (pos1 != 180){
    pos1 = pos1 + 20;
   tone(10, 1000);
    }
    delay(1000);
    noTone(10);
    leftservo(pos1);
  
    
  }

   ButtonValue2 = digitalRead(Button2);
  if (ButtonValue2 == 1) {
    
   
    if (pos1 != 0){
    pos1 = pos1 - 20;
    tone(10, 1000);
    }
    delay(1000);
    noTone(10);
    leftservo(pos1);
  
  
    
  }
  
    
}
else {
  
 ButtonValue = digitalRead(Button1);
  
  if (ButtonValue == 1) {
  
    if (pos2 != 180){
    pos2 = pos2 + 20;
    tone(10, 1000);
    }
    delay(1000);
    noTone(10);
    rightservo(pos2);
  
    
  }

   ButtonValue2 = digitalRead(Button2);
  if (ButtonValue2 == 1) {
    
   
    if (pos2 != 0){
    pos2 = pos2 - 20;
    tone(10, 1000);
    }
    delay(1000);
    noTone(10);
    rightservo(pos2); 
    }
   }
   
     int checkvalue = digitalRead(check);
     if (checkvalue == 1){
      break;}
    
  }
  Serial.println("check");
  checkanswer(pos1, pos2, ran1, ran2);
   
}
void leftservo( int pos1){
  
 // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos1);  // tell servo to go to position in variable 'pos'

   Serial.println(pos1/20);
    delay(15);                       // waits 15ms for the servo to reach the position
  
  
  }
  

  void rightservo(int pos2) {
    myservo1.write(pos2);              // tell servo to go to position in variable 'pos'
     Serial.println(pos2/20);
    delay(15);  
    }

void showquestion(int ran1, int ran2) {
  
  total = total + 1;
  String data = "what is " + String(ran1) + " * " + String(ran2) + " = " ;
  Serial.println(data);
  myservo.write(ran1*20);
  myservo1.write(ran2*20);
  delay(5000);
  myservo.write(0);
  myservo1.write(0);
  
  }


 void  checkanswer(int pos1, int pos2, int ran1, int ran2) {
    digit1 = pos1 / 20;
    digit2 = pos2 / 20;

    Serial.println(digit1*10 + digit2);
    Serial.println(ran1*ran2);
 
    if (digit1 * 10 + digit2 == ran1 * ran2)  {
      Serial.println("correct");
      correct = correct + 1 ;
      tone(10, 2000);
      delay(300);
      noTone(10);
     
    }
    else {
      Serial.println("incorrect");
      tone(10, 2000);
      delay(1000);
      noTone(10);
     }
    
     }
    

    


   
