#include <Ultrasonic.h>

Ultrasonic ultrasonicL(A8, A9);
Ultrasonic ultrasonicR(A12, A13);
Ultrasonic ultrasonicF(A14 , A15);

int vitesseA = 8;//Left
int pinA1 = 48;
int pinA2 = 46;
int pinB2 = 42;
int pinB1 = 44;
int vitesseB = 10;//Right
int disL ;
int disF ;
int disR ;

void setup() {
  Serial.begin(9600);
  pinMode(vitesseA , OUTPUT);
  pinMode(pinA1 , OUTPUT);
  pinMode(pinA2 , OUTPUT);
  pinMode(pinB2 , OUTPUT);
  pinMode(pinB1 , OUTPUT);
  pinMode(vitesseB , OUTPUT);
  pinMode(vitesseB , OUTPUT);
  pinMode(A1 , INPUT);
  pinMode(A0 , INPUT);

}

void READ() {
  disL = ultrasonicL.read();
  disF = ultrasonicF.read();
  disR = ultrasonicR.read();
  Serial.print("  SensorF: ");
  Serial.print(disF);
  Serial.print("  SensorR: ");
  Serial.print(disR);
  Serial.print("  SensorL: ");
  Serial.println(disL);

}
void forward() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2, HIGH);
  analogWrite(vitesseB , 255); //RIGHT
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);
  analogWrite(vitesseA , 235); //LEFT
}

void left() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2 , HIGH);
  analogWrite(vitesseB , 255); //R
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);//L
  analogWrite(vitesseA , 140 );
  }
void right() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2 , HIGH);
  analogWrite(vitesseB , 155); //R
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);
  analogWrite(vitesseA , 255);//L
}


void Moveright() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2 , HIGH);
  analogWrite(vitesseB , 0);//R
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);//L
  analogWrite(vitesseA , 255);
}

void Moveleft() {
  digitalWrite(pinA1 , LOW);
  digitalWrite(pinA2 , HIGH);
  analogWrite(vitesseB , 255);//R
  digitalWrite(pinB1 , LOW);
  digitalWrite(pinB2 , HIGH);//L
  analogWrite(vitesseA , 0);
}

void straight() {
  if (disL <= 8) {
    right();
    Serial.println("right");
  }

  else if (disR <= 8) {
    left();
     Serial.println("left");
  }
  else if(disL >= 8 && disR >= 8){
    forward();
  }
}

void loop() {
  
  READ();
  if (disF <= 28  ) {
    if (disL <= 30) {
      if (disR <= 30) {
      } else {
        Moveright();
        delay(600);
        forward();
        delay(80);
      }
    } else {
      Moveleft();
      delay(490);
      forward();
      delay(80);
    }
  } else {
    straight();
  }
}
