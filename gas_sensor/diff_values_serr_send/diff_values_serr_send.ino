/// powered by r@m kumar
/// this program to get the sensor values and send it raspberry pi

/// input pins which ar connected to arduino
const int AOUT_2_pin = 0;
const int AOUT_7_pin = 1;
const int AOUT_135_pin = 2;

/// sensor inputs
int mq2;
int mq7;
int mq135;

/// output gases
// -- mq2 -- 
float propane;
float methane;
float benzine;

// -- mq7 -- 
float co;

// -- mq135 --
float co2;
float nox;
float nhx;


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
  readsensor();
  process();
  serialsend();
  delay(200);

}
void readsensor()
{
  mq2 = analogRead(AOUT_2_pin);
  mq7 = analogRead(AOUT_7_pin);
  mq135 = analogRead(AOUT_135_pin);
  return;
}
void process()
{
  // float value equals to 100 divide by propane range gap value
  // mq2 readings
  propane = (mq2 - 0)*0.667;    
  methane = (mq2  - 150)*0.4;
  benzine = (mq2  - 500)*0.5;

  // mq7 readings
  co = (mq7  - 200)*0.5882;

  // mq135 readings
  co2 = (mq135  - 50)*0.833;
  nox = (mq135  - 240)*0.625;
  nhx = (mq135  - 450)*0.454;
  return;
}

/// serialsend funtion send these value serially through raspberry pi
void serialsend()  
{
  Serial.print(per(propane));
  Serial.print(",");
  Serial.print(per(methane));
  Serial.print(",");
  Serial.print(per(benzine));
  Serial.print(",");
  Serial.print(per(co));
  Serial.print(",");
  Serial.print(per(co2));
  Serial.print(",");
  Serial.print(per(nox));
  Serial.print(",");
  Serial.print(per(nhx));
  Serial.print("\n");
  return;
}
int per(float value)
{
  if(value < 0)
  {
    return 0;
  }
  else if( value > 100 )
  {
    return 100;
  }
  else
  {
    return value;
  }
}











