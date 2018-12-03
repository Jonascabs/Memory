
#ifndef Pattern
#define Pattern


#include <Pattern.h> //include the declaration for this class
#include <Arduino.h>
const int Chip_Enable1 = 41
const int Chip_Enable2 = 43
const int Write_enable = 45
const int Read_enable  = 47


//<<constructor>>
Pattern::Pattern()
{

}

//<<destructor>>

//Read
void Pattern:: read_control()
{
	
	pinMode(Chip_Enable1, OUTPUT);
	pinMode(Chip_Enable2, OUTPUT);
	pinMode(Write_enable, OUTPUT);
	pinMode(Read_enable, OUTPUT);
	
	digitalWrite(Chip_Enable1,LOW);
	digitalWrite(Chip_Enable2, HIGH);
	digitalWrite(Write_enable, LOW);
	digitalWrite(Read_enable, HIGH);
	
}


void Pattern:: write_control()
{
	
	
	pinMode(Chip_Enable1, OUTPUT);
	pinMode(Chip_Enable2, OUTPUT);
	pinMode(Write_enable, OUTPUT);
	pinMode(Read_enable, OUTPUT);
	
	digitalWrite(Chip_Enable1,LOW);
	digitalWrite(Chip_Enable2, HIGH);
	digitalWrite(Write_enable, LOW);
	digitalWrite(Read_enable, LOW);
}


//write Zero
void Pattern::write_zero()
{
	uint32_t memory_adress[32];
	
	uint32_t A_0 = 22;
	uint32_t A_1 = 24;
	uint32_t A_2 = 26;
	uint32_t A_3 = 28;
	uint32_t A_4 = 30;
	uint32_t A_5 = 32;
	uint32_t A_6 = 34;
	uint32_t A_7 = 36;
	uint32_t A_8 = 38;
	uint32_t A_9 = 40;
	uint32_t A_10 = 42;
	uint32_t A_11 = 44;
	uint32_t A_12 = 46;
	uint32_t A_13 = 48;
	uint32_t A_14 = 50;
	uint32_t A_15 = 52;
	uint32_t A_16 = 23;
	
	
	
	//Address Setup
	pinMode(A_0, OUTPUT);
	pinMode(A_1, OUTPUT);
	pinMode(A_2, OUTPUT);
	pinMode(A_3, OUTPUT);
	pinMode(A_4, OUTPUT);
	pinMode(A_5, OUTPUT);
	pinMode(A_6, OUTPUT);
	pinMode(A_7, OUTPUT);
	pinMode(A_8, OUTPUT);
	pinMode(A_9, OUTPUT);
	pinMode(A_10, OUTPUT);
	pinMode(A_11, OUTPUT);
	pinMode(A_12, OUTPUT);
	pinMode(A_13, OUTPUT);
	pinMode(A_14, OUTPUT);
	pinMode(A_15, OUTPUT);
	pinMode(A_16, OUTPUT);
	pinMode(A_17, OUTPUT);

	
	// Write enable control
	write_control();
	
	
	
}


				

}


#endif



