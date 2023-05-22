#include <AccelStepper.h>

const int StepPin = 54;
const int dirPin = 55;
const int Enable = 38;

void run(long freq=10000);
void runLong();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // x axis
  pinMode(StepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(Enable, OUTPUT);
  digitalWrite(Enable, LOW);
  digitalWrite(dirPin,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  // runLong();
  // digitalWrite(dirPin,HIGH);
  // runLong();
  // digitalWrite(dirPin,LOW);
}


void run(long freq=10000)
{
  long period = long(1E6/freq);

  digitalWrite(StepPin,HIGH);
  delayMicroseconds(period);
  digitalWrite(StepPin,LOW);
  delayMicroseconds(period);
}

void runLong()
{
  for(long i=0; i<10000; i++){
    run(10000);
  }
}