int led8 = 8;
int led9 = 9;
int led10 = 10;
int led11 = 11;
int led12 = 12;
int button = 2;
int i, n, k=0;
bool cat = 0;

bool push;
void switch1();
void setup()
{
  attachInterrupt(digitalPinToInterrupt(button) , switch1, CHANGE);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  for (i = 50; i > 0 ; i--) {
    for (n = 0 ; n < 50 - i  ; ) {

      if (cat == 1) {
        Serial.println("cat = 1 ");
        Serial.println(i);
        digitalWrite(led8, HIGH);
        delay(i);
        digitalWrite(led8, LOW);
        digitalWrite(led9, HIGH);
        delay(i);
        digitalWrite(led9, LOW);
        digitalWrite(led10, HIGH);
        delay(i);
        digitalWrite(led10, LOW);
        digitalWrite(led11, HIGH);
        delay(i);
        digitalWrite(led11, LOW);
        digitalWrite(led12, HIGH);
        delay(i);
        digitalWrite(led12, LOW);
        n++;
      }
      else{
        digitalWrite(LED_BUILTIN, HIGH);
        delay(1000);
        digitalWrite(LED_BUILTIN, LOW);
        cat = 1;
        }
      //          digitalWrite(LED_BUILTIN, HIGH);
      delay(i * 5);
    }
  }

}

void switch1()
{
  k++;
  
  if(k == 2){
    Serial.println("change cat");
    cat = !cat;
    k=0;
    }
  


}
