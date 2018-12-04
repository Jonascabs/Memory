
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
	

	//Data Pins Setup 		
	pinMode(38, OUTPUT);	//D0
	pinMode(39, OUTPUT);	//D1
	pinMode(40, OUTPUT);	//D2
	pinMode(41, OUTPUT);	//D3
	pinMode(42, OUTPUT);	//D4
	pinMode(43, OUTPUT);	//D5
	pinMode(44, OUTPUT);	//D6
	pinMode(45, OUTPUT);	//D7	
	
	
	
			// Setting up the address
			uint8_t mem_address;	
			uint8_t memory_address[16];
	
	
		
			// address for x column
			uint8_t	memory_address_x[8];
	
	
			for(int i=0; i<8; i++)
			{
				memory_address_x[i] = bitread(mem_address,i);
				memory_address[i]	= bitread(mem_address,i);
			}
			
			// address for y column
			uint8_t	memory_address_y[8];
	
			for(int i=0; i<8; i++)
			{
				memory_address_x[i] = bitread(mem_address,i);
				memory_address[i+8]	= bitread(mem_address,i);
			}
			
			
			//setting up data pins
			uint8_t data_out;
			uint8_t data_pins[8];
			for(int i; i<8; i++)
			{
				data_pins[i] = 0x00;
			}
			
			
	

	// writing zeroes to the memory locations
	for(int i; i<65536; i++)
	{
			//address
			for(int j; j<16;j++)
			{	
			digitalWrite((22+j),memory_address[j]);				
			}
		
			//writing zero to data pins
			for(int k; k<8; k++){
			digitalWrite((38+k), data_pins[k]);
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



