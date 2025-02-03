#include <Servo.h>

Servo baseMov;
Servo heightClaw;
Servo claw;
Servo distClaw;

void setup(){

  distClaw.attach(2, 500, 2600);
  heightClaw.attach(3, 500, 2600);
  claw.attach(4, 500, 2600);
  baseMov.attach(5, 500, 2600);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  // Serial.begin(9600);

}

void loop(){
  
  int clawPot = analogRead(A0);
  int angleClaw = map(clawPot, 0, 1023, 0, 87);

  int heightClawPot = analogRead(A1);
  int angleHeightClaw = map(heightClawPot, 0, 1023, 80, 135);

  int distClawPot = analogRead(A2);
  int angleDistClaw = map(distClawPot, 0, 1023, 80, 157);

  int baseMovPot = analogRead(A3);
  int angleBaseMov = map(baseMovPot, 0, 1023, 0, 180);

  // Serial.print("CLAW: ");
  // Serial.println(angleClaw);

  int clawAverage = 0, heightClawAverage = 0, distClawAverage = 0, baseMovAverage = 0;

  for (int i = 0; i <= 100; i++) {

    clawAverage += angleClaw; 
    heightClawAverage += angleHeightClaw;
    distClawAverage += angleDistClaw;
    baseMovAverage += angleBaseMov;

  }

  claw.write(clawAverage / 100);
  heightClaw.write(heightClawAverage / 100);
  distClaw.write(distClawAverage / 100);
  baseMov.write(baseMovAverage / 100);

}