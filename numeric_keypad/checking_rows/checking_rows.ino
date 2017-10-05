/*
powered by r@mkumar
in this program is for reading all the rows of the numeric keypad
keypad type (4x3)

*/


const int col1 = 10;
const int col2 = 2;
const int col3 = 4;
const int row1 = 9;
const int row2 = 5;
const int row3 = 6;
const int row4 = 7;

int r1;
int r2;
int r3;
int r4;

char c;

char read_char()
{
  /// first column
  Serial.println("first column");
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
  delay(300);
  
  /// second column
  Serial.println("second column");
  digitalWrite(col1,LOW);
  digitalWrite(col2,HIGH);
  digitalWrite(col3,LOW);
  r1 = digitalRead(row1);
  r2 = digitalRead(row2);
  r3 = digitalRead(row3);
  r4 = digitalRead(row4);
  Serial.println(r1);
  Serial.println(r2);
  Serial.println(r3);
  Serial.println(r4);
  delay(300);
  
  /// third column
  Serial.println("third column");
  digitalWrite(col1,LOW);
  digitalWrite(col2,LOW);
  digitalWrite(col3,HIGH);
  r1 = digitalRead(row1);
  r2 = digitalRead(row2);
  r3 = digitalRead(row3);
  r4 = digitalRead(row4);
  Serial.println(r1);
  Serial.println(r2);
  Serial.println(r3);
  Serial.println(r4);
  delay(300);
  
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
  Serial.println("reading_values");
  delay(100);
  read_char();
  delay(100);
}


