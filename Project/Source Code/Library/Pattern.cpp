
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
	//Address Pins Setup
	pinMode(22, OUTPUT);
	pinMode(24, OUTPUT);
	pinMode(26, OUTPUT);
	pinMode(28, OUTPUT);
	pinMode(30, OUTPUT);
	pinMode(32, OUTPUT);
	pinMode(34, OUTPUT);
	pinMode(36, OUTPUT);
	pinMode(38, OUTPUT);
	pinMode(40, OUTPUT);
	pinMode(42, OUTPUT);
	pinMode(44, OUTPUT);
	pinMode(46, OUTPUT);
	pinMode(48, OUTPUT);
	pinMode(50, OUTPUT);
	pinMode(52, OUTPUT);
	pinMode(54, OUTPUT);

	//Data Pins Setup 		
	pinMode(25, OUTPUT);	//D0
	pinMode(27, OUTPUT);	//D1
	pinMode(29, OUTPUT);	//D2
	pinMode(31, OUTPUT);	//D3
	pinMode(33, OUTPUT);	//D4
	pinMode(35, OUTPUT);	//D5
	pinMode(37, OUTPUT);	//D6
	pinMode(39, OUTPUT);	//D7	
	
	
	
			// Setting up the address
			uint8_t mem_address;
	
			uint8_t memory_address[16];
			// address for x column
			uint8_t	memory_address_x[8];
			for(i=0; i<8; i++){
				memory_address_x[i] = bitread(mem_address,i);
				memory_address[i]	= bitread(mem_address,i);
			}
			
			// address for y column
			uint8_t	memory_address_y[8];
			for(i=0; i<8; i++){
				memory_address_x[i] = bitread(mem_address,i);
				memory_address[i+8]	= bitread(mem_address,i);
			}
			
	

	// writing zeroes to the memory locations
	for(int i; i<65536; i++)
	{
			//address
			int x=22;
			for(int j; j<16;j++)
			{
				
				digitalWrite((x+j),memory_address[j]);
				
			}
	}

	
	
	
	/*
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
	*/
	
	
	
	

	
	// Write enable control
	write_control();
	
	
	
}


				

}


#endif



