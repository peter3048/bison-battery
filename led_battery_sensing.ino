/*
  Showing number 0-9 on a Common Anode 7-segment LED display (plus the eigth decimal poit)
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---        X Decimal
    D
 */


// for the four leds.
int led1 = 2; 
int led2 = 3;
int led3 = 4;
int led4 = 5;
// for the 7 segment display
int pinA = A1;
int pinB = 8;                                                                                                                                                                                                                                                                            ; //fix this guy
int pinC = 11;
int pinD = 10;
int pinE = 9;
int pinF = 6;
int pinG = 12;
// for choosing which digit
int D1 = 13;
int D2 = 7;
// inputs for the switches, one for the tens place and one for the ones place
int down = A3;
int up = A2;
// starting states for the switches
int sdown = LOW;
int sup = LOW;
// this is the number displayed
int number = 00;

int del = 5; //used for fine tuning the display code

void setup() {
  // initialize everything
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
 
  pinMode(down, INPUT_PULLUP);
  pinMode(up, INPUT_PULLUP);

}

void loop() {
  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber((number/10));// get the value of thousand
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d2
  pickNumber(number%10);// get the value of hundred
  delay(del);//delay 5ms


  
  if (number>100){
    number = 0;
  }
  if (number<0){
    number = 100;
  }

  if(sup != digitalRead(up)){
    number += 1;
    sup = digitalRead(up);
  }

   if(sdown != digitalRead(down)){
     number -= 1;
     sdown = digitalRead(down);
   }


  turnonleds();


}


void turnonleds(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);


  if(number >= 25){
    digitalWrite(led1, HIGH);
  }
  if(number >= 50){
    digitalWrite(led2, HIGH);
  }
  if(number >= 75){
    digitalWrite(led3, HIGH);
  }
  if(number >= 95){
    digitalWrite(led4, HIGH);
  }
  

}

void pickNumber(int x)
{
  switch(x)
  {
    default: 
    zero(); 
    break;
    case 1: 
    one(); 
    break;
    case 2: 
    two(); 
    break;
    case 3: 
    three(); 
    break;
    case 4: 
    four(); 
    break;
    case 5: 
    five(); 
    break;
    case 6: 
    six(); 
    break;
    case 7: 
    seven(); 
    break;
    case 8: 
    eight(); 
    break;
    case 9: 
    nine(); 
    break;
  }
}

void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
//  digitalWrite(pinDP, LOW);
}

void zero() //the 7-segment led display 0
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
//  digitalWrite(pinDP, LOW);
}

void one() //the 7-segment led display 1
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
 // digitalWrite(pinDP, LOW);
}

void two() //the 7-segment led display 2
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
// digitalWrite(pinDP, LOW);
}
void three() //the 7-segment led display 3
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void four() //the 7-segment led display 4
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void five() //the 7-segment led display 5
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void six() //the 7-segment led display 6
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
 // digitalWrite(pinDP, LOW);
}

void seven() //the 7-segment led display 7
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
//  digitalWrite(pinDP, LOW);
}

void eight() //the 7-segment led display 8
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}
void nine() //the 7-segment led display 9
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}
void pickDigit(int x) //
{
  //first, turn them all on high. Then we'll push the one we want low (if I have a common anode this will need to be backwards?

  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  //digitalWrite(D3, HIGH);
  //digitalWrite(D4, HIGH);

  switch(x)
  {
    case 0:
    digitalWrite(D1, LOW);
    break;
    case 1:
    digitalWrite(D2, LOW);
    break;
    /*case 2:
    digitalWrite(D3, LOW);
    break;
    case 3:
    digitalWrite(D4, LOW);
    break;
    */
  }
}
