// powered by r@m kumar

const int buz_pin = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(buz_pin, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(6,HIGH);  ///  turn on buzzer pin
 delay(1000);           /// delay of 1 sec
 digitalWrite(6,LOW);   /// turn off buzzer pin
 delay(1000);           /// delay of 1 sec
 

}
