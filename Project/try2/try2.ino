#include <Pattern.h>

Pattern pattern;

int state;
int newData;





void setup() {
  // put your setup code here, to run once:
      //Data Pins Setup     
      Serial.begin(9600);

	//Address Pins Setup
	pinMode(22, OUTPUT);	//A0	
	pinMode(23, OUTPUT);	//A1	
	pinMode(24, OUTPUT);	//A2	
	pinMode(25, OUTPUT);	//A3	
	pinMode(26, OUTPUT);	//A4	
	pinMode(27, OUTPUT);	//A5	
	pinMode(28, OUTPUT);	//A6	
	pinMode(29, OUTPUT);	//A7	
	pinMode(30, OUTPUT);	//A8	
	pinMode(31, OUTPUT);	//A9	
	pinMode(32, OUTPUT);	//A10	
	pinMode(33, OUTPUT);	//A11	
	pinMode(34, OUTPUT);	//A12	
	pinMode(35, OUTPUT);	//A13	
	pinMode(36, OUTPUT);	//A14	
	pinMode(37, OUTPUT);	//A15	 
	  

	  
	  
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
        case '1':
		          pattern.background_zero();
              delay(1000);
              //state = 1;
      
        
        break;

        case '2': 
               // Background One
              pattern.background_one();
              delay(1000);
 
        break;

        case '3': 
              // CheckerBoard
              pattern.checkerboard();
              delay(1000);
              //state = 1;
        break;

        case '4': // Diagonal
                 pattern.diagonal(0);
                 delay(1000);
  
        break;

        case '5': 
               // Column Bar
              pattern.column_bar();
              delay(1000);
              //state = 1;
        break;
        
        case '6': 
               // Row Bar
              pattern.row_bar();
              delay(1000);
              //state = 1;
        break;      

        case '7': 
              // Read
              pattern.read();
              delay(1000);
              //state = 1;
        break; 

  }
}

newData = false;
}
  
  
