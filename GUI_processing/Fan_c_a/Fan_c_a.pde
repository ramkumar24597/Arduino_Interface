// importing
import processing.serial.*; 

// definitions
Serial port;   
int text1X, text1Y;
int text2X, text2Y;
int rect1X, rect1Y, rect2X, rect2Y;
color rect1color, rect2color;
color rect1highlight, rect2highlight;
boolean rect1Over = false;
boolean rect2Over = false;
int rectb = 200;
int recth = 50;
String s= "Turning ON and OFF the Fan";
String t= "Press Left Button to ON & Press Right Button to OFF";

void setup() { 
  size(800, 800); 
  noStroke(); 
  port = new Serial(this, "COM3", 9600);
  text1X=200;
  text1Y= 100;
  text2X=30;
  text2Y= 300;
  rect1X = 100;
  rect1Y = 400;
  rect2X = 500;
  rect2Y = 400;
  rect1color = 100;
  rect2color = 100;
  rect1highlight = 70;
  rect2highlight = 70;
} 

// drawing the logic
void draw() { 
  background(255);
  update( mouseX, mouseY);
  textSize(30);
  text(s, text1X, text1Y);
  text(t, text2X, text2Y);
  if (rect1Over)
    fill(rect1highlight);
  else
    fill(rect1color);

  rect(rect1X, rect1Y, 200, 50);

  if (rect2Over)
    fill(rect2highlight);
  else
    fill(rect2color);

  rect(rect2X, rect2Y, 200, 50);
}
 
void update(int X, int Y)
{
  if (overrect1 (rect1X, rect1Y, rectb, recth) )
  {
    rect1Over = true;
    rect2Over = false;
  } else if (overrect2 (rect2X, rect2Y, rectb, recth) ) {
    rect2Over = true;
    rect1Over = false;
  } else {
    rect1Over = false;
    rect2Over = false;
  }
}
boolean overrect1( int X, int Y, int width, int height )
{  
  if ( mouseX>= X && mouseX <= X+width && mouseY >= Y && mouseY <= Y+height )
    return true;
  else 
  return false;
}
boolean overrect2( int X, int Y, int width, int height )
{  
  if ( mouseX>= X && mouseX <= X+width && mouseY >= Y && mouseY <= Y+height )
    return true;
  else 
  return false;
}
void mousePressed()
{
  if (rect1Over)
    port.write('H');
  if (rect2Over)
    port.write('L');
}
