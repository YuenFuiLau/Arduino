#define servo_pin 9

String check_type(int x){
  return "Integer";
}

String check_type(char* x){
  return "String";
}

String check_type(char x){
  return "Char";
}

String check_type(float x){
  return "Float";
}

int angleToPWMdutySignal(float angle){
  int out = (angle/180)*1900+450;
  return out;
}


void pwm(int pin, float angle){

  digitalWrite(pin,HIGH); // 0:500, 180:2400
  delayMicroseconds(angleToPWMdutySignal(angle));
  digitalWrite(pin,LOW);
  delayMicroseconds(1000);
}

void test_pwm(int pin){

  digitalWrite(pin,HIGH); // 0:500, 180:2350
  delayMicroseconds(500);
  digitalWrite(pin,LOW);
  delayMicroseconds(1000);
}

void test_case1(){
  float angle = 0;
  pwm(servo_pin, angle);
  Serial.print(angleToPWMdutySignal(angle));
  Serial.print('\n');
  delay(2000);
}

void test_case2(){

  for(float i{0.0}; i<=180.0; i+=10.0){
    pwm(servo_pin,i);
    delay(1000);
  }

  delay(2000);

  for(float i{180.0}; i>=0; i-=10.0){
    pwm(servo_pin,i);
    delay(1000);
  }

  delay(2000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print(check_type(servo_pin));
  pinMode(servo_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // test_pwm(servo_pin);

  test_case1();
  //test_case2();
}
