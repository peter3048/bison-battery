//these are the inputs and outputs

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int flashlight = 7;
int crank = A1;


int power = 0;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(crank, INPUT);
}

void loop() {
  if (digitalRead(crank) == HIGH){
    power++;
  }
  // add some delay

  // make button that turns on light,  and drains power and leds go down
  setLights();
  

}
void setLights(){
  if(power >= 20){
    digitalWrite(led1, HIGH);
  }
  if(power >= 40){
    digitalWrite(led2, HIGH);
  }
  if(power >= 60){
    digitalWrite(led3, HIGH);
  }
  if(power >= 80){
    digitalWrite(led4, HIGH);
  }
  if(power >= 100){
    digitalWrite(led5, HIGH);
  }


  if(power>100){
    power = 100;
  }

}
