#include <Ultrasonic.h>



Ultrasonic f_ultrasonic(4, 7);
Ultrasonic l_ultrasonic(3, 2);
Ultrasonic r_ultrasonic(12, 13);
int frontdistance;
int leftdistance;
int rightdistance;
int tention_mot1 = 11;
int in1 = 10;
int in2 = 9;
int in3 = 8;
int in4 = 7;
int tention_mot2 = 6;
int DIST ;
int DIS ;
void setup() {
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (tention_mot1, OUTPUT);
  pinMode (tention_mot2, OUTPUT);
  DIS = 18;
  DIST = 10;
  Serial.begin(9600);
  // put your setup code here, to run once:
}
void read_u() {
  frontdistance = f_ultrasonic.read();
  leftdistance = l_ultrasonic.read();
  rightdistance = r_ultrasonic.read();
  Serial.print( leftdistance);
  Serial.print("    ");
  Serial.print( frontdistance);
  Serial.print("    ");
  Serial.println( rightdistance);

}
void forward() {
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  analogWrite(tention_mot1 , 60);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
  analogWrite(tention_mot2, 100);
}
void turn_right() {
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  analogWrite(tention_mot1 , 110);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
  analogWrite(tention_mot2, 70 );
}
void turn_left() {
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  analogWrite(tention_mot1 , 60);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
  analogWrite(tention_mot2, 160);
}
void correct() {
  read_u();
 
  if ( rightdistance < 7 ) {
    turn_left();
  }
  else if (rightdistance > 10 ) {
    turn_right();
  }
  else if (frontdistance < 30  && leftdistance >  15 && rightdistance <20  ) {
    while ( leftdistance > 11 ) {
      turn_left();
      read_u();
    }
  }
  else {
   
      forward();
    
  }


}

void loop() {
  read_u();

  correct();



}
