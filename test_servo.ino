#include <Servo.h>

Servo s;

void test_writeMicrosecond(){
  
  s.writeMicroseconds(500);
  Serial.print(500);
  Serial.print('\n');
  delay(2000);
  
  s.writeMicroseconds(1000);
  Serial.print(1000);
  Serial.print('\n');
  delay(2000);
  
  s.writeMicroseconds(1500);
  Serial.print(1500);
  Serial.print('\n');
  delay(2000);
  
  s.writeMicroseconds(2000);
  Serial.print(2000);
  Serial.print('\n');
  delay(2000);
  
  s.writeMicroseconds(2400);
  Serial.print(2400);
  Serial.print('\n');
  delay(2000);
  
  s.writeMicroseconds(2000);
  Serial.print(2000);
  Serial.print('\n');
  delay(2000);
  
  s.writeMicroseconds(1500);
  Serial.print(1500);
  Serial.print('\n');
  delay(2000);
  
  s.writeMicroseconds(1000);
  Serial.print(1000);
  Serial.print('\n');
  delay(2000);
  
}

void test_write(){
  s.write(0);
  delay(500);
  s.write(90);
  delay(500);
  s.write(180);
  delay(500);
  s.write(90);
  delay(500);  
}

void Stop(){
  while(true){
    s.write(0);
    delay(1000);
  }
    
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s.attach(9, 500, 2400);
}

void loop() {
  // put your main code here, to run repeatedly:
  // stop
  Stop();
  
  //write
  //test_write();

  //write ms
  //test_writeMicrosecond();

}
