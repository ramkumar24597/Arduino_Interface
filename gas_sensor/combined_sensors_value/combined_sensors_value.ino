/// powered y r@mkumar
// this program is for gettting three different sensors value through arduino
const int AOUT_2_pin = 0;
const int AOUT_7_pin = 1;
const int AOUT_135_pin = 2;


int mq2;
int mq7;
int mq135;
int valve;

void setup() {
  Serial.begin(9600);
  pinMode(AOUT_2_pin, INPUT);
  pinMode(AOUT_7_pin, INPUT);
  pinMode(AOUT_135_pin, INPUT);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(13,HIGH);
  digitalWrite(12,HIGH); 
}
void loop()
{
  mq2 = analogRead(AOUT_2_pin);
  mq7 = analogRead(AOUT_7_pin);
  mq135 = analogRead(AOUT_135_pin);
  Serial.print("Hydrocarbons : ");
  Serial.println(mq2+",");
  Serial.print("Carbon Monoxide :");
  Serial.println(mq7);
  Serial.print("Nitrous Oxide :");
  Serial.println(mq135);
  delay(100);

}



