int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int power = A7;
int red = 7;
int button = 10;

float val;
float analogValue;
float input_voltage;
float max_voltage = 5;
float step = max_voltage/5;



void setup() {
  
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  digitalWrite(A7, INPUT);

  pinMode(red, INPUT); //taking in power from battery

  
 //makes the black a ground


}

void loop() {

  float analogValue = analogRead (A4);
  float input_voltage = (analogValue * 5.0) / 1024.0; //this stuff is all for conversion
  
  Serial.println(input_voltage);
  

  if(digitalRead(button) == HIGH){ //make sure this is set right, might need to make it a pull up 
    while(digitalRead(button) == HIGH){
      powerSense();
    }
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    
  }
  else if(powerIn()){
     powerPowered();
  }
  else{
    batteryPowered();
  }        
}


void batteryPowered(){

  pinMode(red, INPUT); //taking in power from battery
 //makes the black a ground


}

void powerPowered(){

   //taking in power from battery
  pinMode(red, OUTPUT);
  

  digitalWrite(red, HIGH); //makes the black a ground

  chargeSequence();
}



boolean powerIn(){ // determines if power is coming in 
  //see if power is greater than zero, probably need a tie down to keep it zero if no power is coming in. 
  val = analogRead (power);
  val = (val * 5.0) / 1024.0;
  return val > 2;
}

void chargeSequence(){ //blinks the lights to show that the battery is being charged
 
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
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  delay(500);

}

void powerSense(){ //reads the power
 //reads the power
  analogValue = analogRead (A4);
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
