#define led 2
#define button 15
int status;
int lastStatus=HIGH;
int ledStatus=LOW;
int currentTime;
int pressTime=0;
int openTime=0;
int blinkTime;
bool isPressing;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  openTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  status = digitalRead(button);

  if(status != lastStatus)
  {
    Serial.println(status);
    lastStatus = status;
    delay(100);
    isPressing = false;

    if(status == LOW)
    {
      isPressing = true;
      currentTime = millis();
      ledStatus = !ledStatus;
    }
    else
    {
      openTime = millis();
    }
    
    
    //放这里还是要等松手才会触发闪烁
    // pressTime = millis() - currentTime;
    // Serial.print("按键按下时间：");
    // Serial.println(currentTime);
    // Serial.print("按键松手时间：");
    // Serial.println(openTime);
    // Serial.print("按键时长：");
    // Serial.println(pressTime);
  }
  //放这里一端时间不按按钮自动触发闪烁
  // pressTime = millis() - currentTime;

  if(isPressing==true)
  {
    pressTime = millis() - currentTime;
    // pressTime = openTime - currentTime;
  }

  if(pressTime > 2000)
    {
      //灯闪烁
      // Serial.println(pressTime);
      // digitalWrite(led,HIGH);
      // delay(2000);
      // digitalWrite(led,LOW);
      // delay(2000);
      if(millis() - blinkTime > 200)
      {
        ledStatus = !ledStatus;
        blinkTime = millis();
      }
      // digitalWrite(led,ledStatus);
      // delay(10);
    }

  else if(pressTime > 500 && pressTime < 2000)
  {
    if(millis() - blinkTime > 1000)
    {
      ledStatus = !ledStatus;
      blinkTime = millis();
    }
  }

  // Serial.println("常态");
  digitalWrite(led,ledStatus);
  delay(10);
}
