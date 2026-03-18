#define LED_BUILTIN 2
#define BUTTON_PIN 15
int status ;
int lastStatus = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(BUTTON_PIN,INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(LED_BUILTIN,HIGH);
  // delay(1000);
  // Serial.println("串口...");
  // digitalWrite(LED_BUILTIN,LOW);
  // delay(1000);
  status = digitalRead(BUTTON_PIN);
  if(status != lastStatus)
  {
    Serial.println(status);
    lastStatus = status;
    }
  //这里不能是BUTTON_PIN因为它始终是15
  if(status == LOW)
  {
    digitalWrite(LED_BUILTIN,HIGH);
    Serial.print("BUTTON_PIN=");
    Serial.println(BUTTON_PIN);
  }
  else
  {
    digitalWrite(LED_BUILTIN,LOW);
    // Serial.print("BUTTON_PIN=");
    // Serial.println(BUTTON_PIN);
  }
}
