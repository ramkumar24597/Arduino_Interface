/*
powered by r@mkumar
here in this program it actually monitors the series of  character, i mean a string 
from the keypad
keypad type - 4x3

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

char read_char()
{
  /// first column
  digitalWrite(col1,HIGH);
  digitalWrite(col2,LOW);
  digitalWrite(col3,LOW);
  r1 = digitalRead(row1);
  r2 = digitalRead(row2);
  r3 = digitalRead(row3);
  r4 = digitalRead(row4);
  if(r1 == 1)
  {
    return '1';
  }
  else if(r2 == 1)
  {
    return '4';
  }
  else if(r3 == 1)
  {
    return '7';
  }
  else if(r4 == 1)
  {
    return '*';
  }

  /// second column
  digitalWrite(col1,LOW);
  digitalWrite(col2,HIGH);
  digitalWrite(col3,LOW);
  r1 = digitalRead(row1);
  r2 = digitalRead(row2);
  r3 = digitalRead(row3);
  r4 = digitalRead(row4);
  if(r1 == 1)
  {
    return '2';
  }
  else if(r2 == 1)
  {
    return '5';
  }
  else if(r3 == 1)
  {
    return '8';
  }
  else if(r4 == 1)
  {
    return '0';
  }

  /// third column
  digitalWrite(col1,LOW);
  digitalWrite(col2,LOW);
  digitalWrite(col3,HIGH);
  r1 = digitalRead(row1);
  r2 = digitalRead(row2);
  r3 = digitalRead(row3);
  r4 = digitalRead(row4);
  if(r1 == 1)
  {
    return '3';
  }
  else if(r2 == 1)
  {
    return '6';
  }
  else if(r3 == 1)
  {
    return '9';
  }
  else if(r4 == 1)
  {
    return '#';
  }
  delay(100);
  return 't';
}


/*
void strcat(char string[], char character)
{
  int string_size = 0;
  
  while( string[string_size] != "\0")
  {
    string_size++;
  }
  
  a[string_size] = character;
  string_size++;
  a[string_size] = "\0";
  
  return;
}
*/

void strcat(char string[],int location ,char character)
{
  string[location] = character;
  return;
}

void collecting_data()
{
  char str[10]= "#";
  char ch;
  int i = 0;
  while(true)
  {
    ch = read_char();
    Serial.println(ch);
    delay(100);
    if( ch != 't')
    {
      i++;
      if(ch == '#')
      {
        strcat(str,i,ch);
        Serial.println(str);
        break;
      }
      else
      {
        strcat(str,i,ch);
        Serial.println(str);
        delay(100);
      }
    }
  }
  return;
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
  collecting_data();
  
  Serial.println("Collected the data successfully");
  delay(100);
  Serial.println("Sending data to the database");
  delay(100);
}



