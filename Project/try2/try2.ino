#include <Pattern.h>

Pattern pattern;

int state;
int newData;
void setup() {
  // put your setup code here, to run once:
      //Data Pins Setup     
      Serial.begin(9600);

        Serial.print("Memory Testing");
        Serial.println("1. Background Zero");
        Serial.println("2. Background One");
        Serial.println("3. Checker Board");
        Serial.println("4. Diagonal");
        Serial.println("5. Column Bar");
        Serial.println("6. Row Bar");
        Serial.println("7. Read");
           
}

void loop() {

 recvOneChar();
 delay(1);
 main_loop();
}



void recvOneChar() {
 if (Serial.available() > 0) {
 state = Serial.read();
 newData = true;
 }
}


void main_loop()
{

if (newData == true) 
{
  switch(state){
        case 1:
      
        
        break;

        case '2': // Background Zero
              pattern.background_zero();
              delay(1000);
              //state = 1;
        break;

        case '3': // Background One
              pattern.background_one();
              delay(1000);
             // state = 1;
        break;

        case '4': // CheckerBoard
              pattern.checkerboard();
              delay(1000);
              //state = 1;
        break;

        case '5': // Diagonal
              pattern.diagonal(0);
              delay(1000);
              //state = 1;
        break;
        
        case '6': // Column Bar
              pattern.column_bar();
              delay(1000);
              //state = 1;
        break;      

        case '7': // Row Bar
              pattern.row_bar();
              delay(1000);
              //state = 1;
        break; 

        case '8': // Row Bar
              pattern.read();
              delay(1000);
              //state = 1;
        break; 
  }
}

newData = false;
}
  
  
