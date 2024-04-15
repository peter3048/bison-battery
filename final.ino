int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int usb = 7;
int usbc1 = 8;
int usbc2 = 9;
int sensing = A1;
int powertest = A2;
int button = 10;

float val;
float analogValue;
float input_voltage;
float max_voltage = 5;
float step = max_voltage/5;


int power = 100;


void setup() {
  
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(usb, OUTPUT);
  pinMode(usbc1, OUTPUT);
  pinMode(usbc2, OUTPUT);
  pinMode(button, INPUT);
  pinMode(sensing, INPUT);
  pinMode(powertest, INPUT);


  digitalWrite(usb, HIGH);
  digitalWrite(usbc1, HIGH);
  digitalWrite(usbc2, HIGH);

}

void loop() {
  
  if(digitalRead(button) == HIGH){ //make sure this is set right, might need to make it a pull up 
    powerSense();
     //keep lights on for 5 seconds
  }
  else if(powerIn()){
    chargeSequence();
  }
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  }        
}

boolean powerIn(){ // determines if power is coming in 
  //see if power is greater than zero, probably need a tie down to keep it zero if no power is coming in. 
  val = analogRead (powertest);
  val = (val * 5.0) / 1024.0;
  return val > 1;
}

void chargeSequence(){ //blinks the lights to show that the battery is being charged
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, LOW);
  delay(500);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  delay(500);
}

void LED_function(int stage) //this sets the leds based on the ouput of power sense
{
    for (int j=2; j<=6; j++)
    {
    digitalWrite(j,LOW);
    }
    for (int i=1, l=2; i<=stage; i++,l++)
    {
    digitalWrite(l,HIGH);
    }
   
}

void powerSense(){ //reads the power
  analogValue = analogRead (sensing);
  input_voltage = (analogValue * 5.0) / 1024.0; //this stuff is all for conversion
  
  Serial.println(input_voltage);

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
