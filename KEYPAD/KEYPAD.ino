#include <Keypad.h>

  // declare row and cols
  const byte ROWS = 4;
  const byte COLS = 3;
  int number = random(0, 9);
  int num = 0;
  
  char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'#', '0', '*'}
};

//connect to row and columns pins
byte rowPins[ROWS] = {12, 11, 10, 9 };
byte colPins[COLS] = {8, 7, 6 };

//create keypad
Keypad myKeyPad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


void setup() {
  Serial.begin(9600);
  } 
  
void loop() {
  char key = myKeyPad.getKey();
   
  if(key) {
   // Serial.println(key);
    num = key - '0';
    if(number == num) {
      Serial.println("YES");
    }
    else {
      Serial.println("NO");
    }
    }
}
