/*

Author - r@mkumar

in this program, i have monitored the pins of the first rows from numeric keypad
i concluded that i missed the hardware pull down in the circuit 

*/


const int col1 = 10;
const int col2 = 2;
const int col3 = 4;
const int row1 = 9;
const int row2 = 5;
const int row3 = 6;
const int row4 = 7;

int r1 = 0;
int r2 = 0;
int r3 = 0;
int r4 = 0;

void read_char()
{
  /// first column
  digitalWrite(col1,HIGH);
  digitalWrite(col2,LOW);
  digitalWrite(col3,LOW);
  r1 = digitalRead(row1);
  r2 = digitalRead(row2);
  r3 = digitalRead(row3);
  r4 = digitalRead(row4);
  Serial.println(r1);
  Serial.println(r2);
  Serial.println(r3);
  Serial.println(r4);
}

void setup()
{
  Serial.begin(9600);
  pinMode(col1,OUTPUT);
  pinMode(col2,OUTPUT);
  pinMode(col3,OUTPUT);
  pinMode(row1,INPUT);
  pinMode(row2,INPUT);
  pinMode(row3,INPUT);
  pinMode(row4,INPUT);
}

void loop()
{
  Serial.println("reading_values"); // pull down resistor
  read_char();
}


