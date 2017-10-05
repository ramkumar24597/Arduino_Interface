/*
powered by r@mkumar
in this program  i created a clock using processing software
*/

int sat, bright;
float startSecond, degree;
int h, m, s;

void setup()
{
  smooth();
  size(600, 400);
  sat = 280;
  bright =360;
  frameRate(25);
  colorMode(HSB, 360);
  noFill();
  startSecond = float(second())*1000.0;
  strokeWeight(16.0);
  strokeCap(ROUND);
}
void draw()
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
