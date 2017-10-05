
#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {0x90, 0xA2, 0xDA, 0x0D, 0x48, 0xD3 };

IPAddress ip(10,1,75,254);
IPAddress gateway(10,1,75,1);
IPAddress subnet(255, 0, 0, 0);

EthernetServer server(80);
String readString;

int led = 8;

void setup()
{

  pinMode(led, OUTPUT); 

  Serial.begin(9600);

  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());

}

void loop()
{
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client)

  {
    Serial.println("new client");

    while (client.connected())
    {
      if (client.available())

      {
        char c = client.read();

        if (readString.length() < 100)

        {

          readString += c;
          Serial.print(c);


          Serial.write(c);
     
          if (c == '\n') {
            Serial.println(readString); 
            
            client.println("HTTP/1.1 200 OK"); 
            client.println("Content-Type: text/html");
            client.println();
            client.println("<HTML>");
            client.println("<HEAD>");
        
            client.println("<TITLE>Led Controlling</TITLE>");
            client.println("<center>");
            client.println("</HEAD>");
            client.println("<BODY>");
            client.println("<H1>led controlling</H1>");
            client.println("<hr />");
            client.println("<center>");

            client.println("<a href=\"/?lighton\"\">Turn On Light</a>");
            client.println("<br />");
            client.println("<br />");
            client.println("<a href=\"/?lightoff\"\">Turn Off Light</a><br />");     

            client.println("</BODY>");
            client.println("</HTML>");

            delay(1);
            client.stop();

            if(readString.indexOf("?lighton") >0)
            {
              digitalWrite(8, HIGH);   
              Serial.println("Led On");
            }
            else{
              if(readString.indexOf("?lightoff") >0)
              {
                digitalWrite(8, LOW);   
                Serial.println("Led Off");
              }
            }
            
            readString="";

            
            delay(1);
            
            client.stop();
            Serial.println("client disonnected");

          }
        }
      }
    }
  }
}
