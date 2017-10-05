/*
powered by r@m kumar 
this is spi master control program which actually send a string to the slave
through spi communication
*/

#include <SPI.h>

void setup()
{
  Serial.begin(115200);
  digitalWrite(SS,HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}
void loop()
{
  char c;
  digitalWrite(SS,LOW);
  for (const char *p = "Hello, World!\r";c=*p;p++)
  {
    SPI.transfer(c);
    Serial.print(c);
  }
  digitalWrite(SS,HIGH);
  delay(2000);
}
