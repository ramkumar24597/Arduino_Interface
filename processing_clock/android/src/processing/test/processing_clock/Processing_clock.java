package processing.test.processing_clock;

import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class Processing_clock extends PApplet {

int sat, bright;
float startSecond, degree;
int h, m, s;

public void setup()
{
  
  
  sat = 280;
  bright =360;
  frameRate(25);
  colorMode(HSB, 360);
  noFill();
  startSecond = PApplet.parseFloat(second())*1000.0f;
  strokeWeight(16.0f);
  strokeCap(ROUND);
}
public void draw()
{
  background(255);
  translate(300, 150);
  rotate(radians(-90));
  noFill();
  degree = lerp(0, 360, norm((startSecond+millis())%60000, 0, 60000));
  stroke(degree, sat, bright);
  arc(0, 0, 220, 220, radians(0), radians(degree));

  degree = lerp(0, 360, norm((minute()*60+second())%3600, 0, 3600));
  stroke(degree, sat, bright);
  arc(0, 0, 180, 180, radians(0), radians(degree));

  degree = lerp(0, 360, norm((hour()*60+minute())%1440, 0, 1440));
  stroke(degree, sat, bright);
  arc(0, 0, 140, 140, radians(0), radians(degree));

  h=hour();
  m=minute();
  s=second();

  translate(0, 0);
  rotate(radians(90));
  textSize(30);
  fill(80, 102, 53);
  text(h, -60, 200);
  fill(0, 156, 253);
  text(":", -20, 200);
  fill(60, 22, 23);
  text(m, -10, 200);
  fill(0, 156, 253);
  text(":", 30, 200);
  fill(275, 59, 67);
  text(s, 40, 200);
}
  public void settings() {  size(600, 400);  smooth(); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--present", "--window-color=#666666", "--hide-stop", "Processing_clock" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
