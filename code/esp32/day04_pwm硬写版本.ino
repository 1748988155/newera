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
int clickCount=0;
int light = 0;

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
      clickCount = clickCount + 1;
    }
  }

  if(isPressing==true)
  {
    pressTime = millis() - currentTime;
    // pressTime = openTime - currentTime;
  }

  if(pressTime > 2000)
  {
    //灯闪烁
    if(millis() - blinkTime > 200)
    {
      ledStatus = !ledStatus;
      blinkTime = millis();
    }
    digitalWrite(led,ledStatus);
    delay(10);
    clickCount = 0;
  }

  else if(pressTime > 500 && pressTime < 2000)
  {
    if(millis() - blinkTime > 1000)
    {
      ledStatus = !ledStatus;
      blinkTime = millis();
    }
    digitalWrite(led,ledStatus);
    delay(10);
    clickCount = 0;
  }

  else if(pressTime < 100 && clickCount == 2)
  {
    Serial.println("双击了");
    //灯从亮变暗再变亮并重复这一过程
    for(light = 255;light > 0;light--)
    {
      analogWrite(led,light);
      delay(10);
    }
    for(light = 0;light < 255;light++)
    {
      analogWrite(led,light);
      delay(10);
    }
    analogWrite(led,0);
    digitalWrite(led,HIGH);
    clickCount = 0;
    pressTime = 0;
    isPressing = false;
    return;
  }

  else if(pressTime < 100)
  {
    digitalWrite(led,ledStatus);
    delay(10);
  }

  if(millis()-openTime>200)
  {
    clickCount = 0;
    delay(10);
  }
}
