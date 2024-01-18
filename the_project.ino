//these are the inputs and outputs

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int flashlight = 7;
int crank = A1;
int button = A2;


int power = 0;


void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(flashlight, OUTPUT);
  pinMode(crank, INPUT);
  pinMode(button, INPUT_PULLUP);

}

void loop() {
  if (digitalRead(crank) == HIGH){
    power++;
    delay(50);
  }
  
  //this stuff happens when the button is pressed
  if((digitalRead(button) == LOW) && (power > 0)){
    digitalWrite(flashlight, LOW);
    power--;
    delay(50);
    
  }


  else{
    digitalWrite(flashlight,HIGH);
  }
  setLights();





  // make button that turns on light,  and drains power and leds go down
  setLights();
}
void setLights(){

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);



  if(power >= 1){
    digitalWrite(led1, HIGH);
  }
  if(power >= 20){
    digitalWrite(led2, HIGH);
  }
  if(power >= 40){
    digitalWrite(led3, HIGH);
  }
  if(power >= 60){
    digitalWrite(led4, HIGH);
  }
  if(power >= 80){
    digitalWrite(led5, HIGH);
  }


  if(power>100){
    power = 100;
  }
  if(power<0){
    power=0;
  }

}
