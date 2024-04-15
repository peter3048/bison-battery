int led1 = 2;
int power = A7;
int red = 3;
int black = 4;

float val;
float analogValue;
float input_voltage;
float max_voltage = 5;
float step = max_voltage/5;



void setup() {
  
  Serial.begin(9600);
  pinMode(led1, OUTPUT);

  digitalWrite(A7, INPUT);

  pinMode(red, INPUT); //taking in power from battery
  pinMode(black, OUTPUT);
  
  digitalWrite(black, LOW); //makes the black a ground


}


void batteryPowered(){
  digitalWrite(led1,LOW);

  pinMode(red, INPUT); //taking in power from battery
  pinMode(black, OUTPUT);
  
  digitalWrite(black, LOW); //makes the black a ground
}

void powerPowered(){
  digitalWrite(led1,HIGH);

  pinMode(black, INPUT); //taking in power from battery
  pinMode(red, OUTPUT);
  
  digitalWrite(red, HIGH); //makes the black a ground
}

void loop() {
  
  if(powerIn()){
     powerPowered();
  }
  else{
    batteryPowered();
  }        
}

boolean powerIn(){ // determines if power is coming in 
  //see if power is greater than zero, probably need a tie down to keep it zero if no power is coming in. 
  val = analogRead (power);
  val = (val * 5.0) / 1024.0;
  return val > 3;
}

void chargeSequence(){ //blinks the lights to show that the battery is being charged
 
}

void LED_function(int stage) //this sets the leds based on the ouput of power sense
{
    
   
}

void powerSense(){ //reads the power
  
}
