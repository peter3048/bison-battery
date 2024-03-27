

const int rs = 12, en = 13, d0 = A0, d1 = A1, d2 = A2, d3 = A3;
const int analogPin = A4;
float analogValue;
float input_voltage;
float max_voltage = 5;
float step = max_voltage/5;

int ledPins[] = {2, 3, 4, 5, 6}; // an array of pin numbers to which LEDs are attached
int pinCount = 10;           // the number of pins (i.e. the length of the array)

void setup()
{
   Serial.begin(9600);     //  opens serial port, sets data rate to 9600 bps
   pinMode(A0,OUTPUT);
   pinMode(A1,OUTPUT);
   pinMode(A2,OUTPUT);
   pinMode(A3,OUTPUT);
   pinMode(A4,INPUT);

}

void LED_function(int stage)
{
    for (int j=2; j<=6; j++)
    {
    digitalWrite(j,LOW);
    }
    for (int i=1, l=2; i<=stage; i++,l++)
    {
    digitalWrite(l,HIGH);  //delay(30);
    Serial.print("x");
    }
    Serial.println();
   
}
void loop()
{
//  Conversion formula for voltage
  analogValue = analogRead (A4);
  delay (1000); 
  input_voltage = (analogValue * 5.0) / 1024.0;
  
  Serial.println(input_voltage);
  delay(100);

  if (input_voltage < step && input_voltage > 0.00 )
    {
    LED_function(1);
    }
  else if (input_voltage < (2*step) && input_voltage >= (step))
    {
    LED_function(2);
    }
  else if (input_voltage < (3*step) && input_voltage >= (2*step))
    {
    LED_function(3);
    }
  else if (input_voltage < (4*step) && input_voltage >= (3*step))
    {
    LED_function(4);
    }
  else if (input_voltage >= (4*step))
    {
    LED_function(5);
    }
}
