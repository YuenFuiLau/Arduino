class PinReader{
  private:
    
  public:
    long lastState{0};
    long pin{};
    PinReader(long pin_num=1): pin{pin_num} 
    { 
      pinMode(this->pin, INPUT); 
      lastState = 0;
    }

    bool rising()
    {
      long currState{digitalRead(this->pin)};

      if( (currState==1) && (this->lastState != 1) )
      {
        this->lastState = currState;
        return true;
      }
      else
      {
        this->lastState = currState;
        return false;
      }

    }

    bool falling()
    {
      long currState{digitalRead(this->pin)};
      if( (currState == 0) && (this->lastState != 0) )
      {
        this->lastState = currState;
        return true;
      }
      else
      {
        this->lastState = currState;
        return false;
      }

      
    }

    bool changing()
    {
      long currState{digitalRead(this->pin)};

      if( (currState!=this->lastState) )
      {
        this->lastState = currState;
        return true;
      }
      else
      {
        this->lastState = currState;
        return false;
      }

    }



};

const int ENC_A_L = 2;
PinReader a{ENC_A_L};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(HIGH);
  // delay(500);
  // Serial.println(LOW);
  // delay(500);
  if(a.rising())
  {
    Serial.println("Rise!");
  }
  
}
