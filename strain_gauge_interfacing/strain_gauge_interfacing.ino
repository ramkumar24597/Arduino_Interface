/*
powered by r@mkumar
in this program where we actually interfae the strain gauge 
arduino to get the difference in voltage

*/

// initialization
float a;
int a_val;
float strain;
float stress;
float load;
float j;
float k;

// defined values
int rg;         // output resistance form strain gauge
float vout;       // output voltage
int vin = 5;      // input voltage
int r = 120;     // resistance
long int E = 69000; // young's modulus value for aluminium

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(E);
}

void loop() {
  // put your main code here, to run repeatedly:
  a_val = analogRead(0);
  vout = (a_val * 0.004887);
  Serial.println(vout);
  a = (vout / vin);
  Serial.println(a);
  j = 14400*((2*a)-1);
  Serial.println(j);
  k = 120*(1-(2*a));
  Serial.println(k);  
  rg = (14400 * ((2 * a) - 1)) / (120 * (1-(2 * a)));
  Serial.println(rg);
  strain = rg / r;
  Serial.println(strain);
  stress = (strain * E);
  Serial.println(stress);
  load = (stress*0.01442);
  Serial.println(load);

  delay(20000);
  
}
