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
int D1 = 7; 
int D2 = 2;
int D3 = 7;
int D4 = 11;
// for the 7 segment display
int pinA = 2;
int pinB = 5;                                                                                                                                                                                                                                                                            ; //fix this guy
int pinC = 10;
int pinD = 9;
int pinE = 8;
int pinF = A1;
int pinG = 13;
// for choosing which digit
// inputs for the switches, one for the tens place and one for the ones place
int down = A3;
int up = A2;
// starting states for the switches
int sdown = LOW;
int sup = LOW;
// this is the number displayed
int number = 2222;

int del = 5; //used for fine tuning the display code

void setup() {
  // initialize everything


  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  pinMode(down, INPUT_PULLUP);
  pinMode(up, INPUT_PULLUP);

}

void loop() {
  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber((number%10));// get the value of thousand
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d2
  pickNumber(number%100/10);// get the value of hundred
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d2
  pickNumber(number%1000/100);// get the value of hundred
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(3);//Light up 7-segment display d2
  pickNumber(number%10000/1000);// get the value of hundred
  delay(del);//delay 5ms


  
  


  turnonleds();


}


void turnonleds(){



  
  

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
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

  switch(x)
  {
    case 0:
    digitalWrite(D1, LOW);
    break;
    case 1:
    digitalWrite(D2, LOW);
    break;
    case 2:
    digitalWrite(D3, LOW);
    break;
    case 3:
    digitalWrite(D4, LOW);
    break;
    
  }
}
