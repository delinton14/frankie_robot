#include <Adafruit_MotorShield.h>


// Create the motor shield object
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *LMotor = AFMS.getMotor(1);
Adafruit_DCMotor *RMotor = AFMS.getMotor(2);

// Global variables to use
const int Sideping = 8;
const int Frontping = 7;
int Side;
int Front;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
}

void loop() {

 long Front = readPing(Frontping);
  Serial.print(Front);
  Serial.print("mm   ");
  Serial.println();
  delay(100);

 long Side = readPing(Sideping);
  Serial.print(Side);
  Serial.print("mm");
  Serial.println();
  delay(100);

  if (Front >= 55) {
  

      if (Side <= 60) {
      Serial.print("tick");
      // Set the speed to start, from 0 (off) to 255 (max speed)
  
      LMotor->run(FORWARD);
      LMotor->setSpeed(90); 

      RMotor->run(FORWARD);
      RMotor->setSpeed(105);
  
 
      }

      else {
        Serial.print("tock");
   
        LMotor->run(FORWARD);
        LMotor->setSpeed(0);
    
        RMotor->run(FORWARD);
        RMotor->setSpeed(105);
  
  
        }
  }

  else {

    //  LMotor->run(RELEASE);
    //  RMotor->run(RELEASE);
    //  delay(1000);

      if (Side <= 70) {
        LMotor->run(FORWARD);
        LMotor->setSpeed(110);

        RMotor->run(BACKWARD);
        RMotor->setSpeed(110);
     
      }

      else {
        LMotor->run(BACKWARD);
        LMotor->setSpeed(110);

        RMotor->run(FORWARD);
        RMotor->setSpeed(110);
     
      }
        
  }
  
}


long readPing(int PingSensor) {
  
  // establish variable for duration of the ping
  long duration;
  
  pinMode(PingSensor, OUTPUT);
  digitalWrite(PingSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(PingSensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(PingSensor, LOW);

  pinMode(PingSensor,  INPUT);
  duration = pulseIn(PingSensor, HIGH);
   
  return duration/2.9/2;
  
  
}
