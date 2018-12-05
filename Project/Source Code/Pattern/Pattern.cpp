
#ifndef Pattern_cpp
#define Pattern_cpp


#include <Pattern.h> //include the declaration for this class
#include <Arduino.h>
const int Chip_Enable1 = 41;
const int Chip_Enable2 = 43;
const int Output_enable = 45;
const int Write_enable  = 47;


//<<constructor>>
Pattern::Pattern()
{
	Serial.begin(9600);
}

//<<destructor>>

//Read
void Pattern:: read_control()
{
	
	pinMode(Chip_Enable1, OUTPUT);
	pinMode(Chip_Enable2, OUTPUT);
	pinMode(Output_enable, OUTPUT);
	pinMode(Write_enable, OUTPUT);
	
	digitalWrite(Chip_Enable1,LOW);
	digitalWrite(Chip_Enable2, HIGH);
	digitalWrite(Output_enable, LOW);
	digitalWrite(Write_enable, HIGH);
	
}


void Pattern:: write_control()
{
	
	
	pinMode(Chip_Enable1, OUTPUT);
	pinMode(Chip_Enable2, OUTPUT);
	pinMode(Output_enable, OUTPUT);
	pinMode(Write_enable, OUTPUT);
	
	digitalWrite(Chip_Enable1,LOW);
	digitalWrite(Chip_Enable2, HIGH);
	digitalWrite(Output_enable, LOW);
	digitalWrite(Write_enable, LOW);
}


//write Zero
void Pattern::write_zero()
{
	
	
	write_control();
	
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
	
	
	
			
			
			//setting up data pins
			
			uint8_t data_pins[8];
			
			// writing zeroes in the data pin array
			
			
			
	
	
	
	
	// writing ones to the memory location in ascending address order
	for(uint8_t mem_address_y; mem_address_y <256; mem_address_y++)
	{
			
			
			for(uint8_t mem_address_x; mem_address_x <256; mem_address_x++){
				
			// Setting up the address
				
			uint8_t memory_address[16];
	
	
		
			// address for x column
			uint8_t	memory_address_x[8];
	
	
			for(int i=0; i<8; i++)
			{
				memory_address_x[i] = bitRead(mem_address_x,i);
				memory_address[i]	= bitRead(mem_address_x,i);
			}
			
			// address for y column
			uint8_t	memory_address_y[8];
	
			for(int i=0; i<8; i++)
			{
				memory_address_y[i] = bitRead(mem_address_y,i);
				memory_address[i+8]	= bitRead(mem_address_y,i);
			}
			
			//writing into the address pins
			for(int j; j<16;j++)
				{	
				digitalWrite((22+j),memory_address[j]);				
				}
			
			
			
			for(int i; i<8; i++)
			{
				data_pins[i] = 0x00;
			}
			
			
			
			
			//writing zero to data pins
			for(int k; k<8; k++)
				{
				digitalWrite((38+k), data_pins[k]);
				Serial.print(data_pins[k], BIN);
				}
			
			
			Serial.print("  ");	// provide spaces for each memory cell
			

				
			
			}
			Serial.print('\n');
		
	}
}	
	


void Pattern::write_one()    // writing ones in ascending address order
{
	
	
	write_control();
	
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
	
	
	
			
			
			//setting up data pins
			
			int data_pins[8];
			
			// writing zeroes in the data pin array
			
			uint8_t memory_address[16];
				
			// address for x column
			int8_t	memory_address_x[8];
			
			// address for y column
			uint8_t	memory_address_y[8];
	
			
			Serial.print("\n");
			
	// writing ones to the memory location in ascending address order
	for(uint8_t mem_address_y=0; mem_address_y <256; mem_address_y++)
	{
			
			
					for(uint8_t mem_address_x=0; mem_address_x <256; mem_address_x++)
					{
						
						// Setting up the address
							
					
						for(int i=0; i<8; i++)
						{
							memory_address_y[7-i] = bitRead(mem_address_y,i);
							memory_address[7-i]	= bitRead(mem_address_y,i);
							//Serial.print(memory_address[i]);
							//Serial.print(memory_address_y[i]);
						}
						//Serial.print(mem_address_y, HEX);
						
						
						Serial.print(" ");
						
						for(int i=0; i<8; i++)
						{
							memory_address_x[7-i] = bitRead(mem_address_x,i);
							memory_address[15-i]	= bitRead(mem_address_x,i);
							//Serial.print(memory_address[i+7]);
							//Serial.print(memory_address_x[i]);
						}
						
						//Serial.print(mem_address_x, HEX);
						
				
						
						
						
						
						
						
						//writing into the address pins
						for(int i=22; i<38;i++)
							{	
							digitalWrite((i),memory_address[i-22]);	
							//Serial.print(memory_address[j]);
							}
						
						
						
						for(int i; i<8; i++)
						{
							data_pins[i] = 1;
						}
						
						
						
						
						//writing ones to data pins
						for(int i=38; i<46; i++)
							{
							digitalWrite(i, HIGH);
							Serial.print(1);
							}
						
						
							Serial.print("   ");	// provide spaces for each memory cell
						
						
									if(mem_address_x==255) 
									{
										break;
									}
					}
					
			
		
					Serial.print('\n');
					
					if(mem_address_y==255) 
					{
					break;
					}
	}	
}				



//write Zero
void Pattern::write_diagonal(int index_number)
{
	
	
	write_control();
	
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
	
	
	
			
			
			//setting up data pins
			
			uint8_t data_pins[8];
			
			// writing zeroes in the data pin array
			
			
			
	
	
	
	
	// writing ones to the memory location in ascending address order
	for(uint8_t mem_address_y; mem_address_y <256; mem_address_y++)
	{
			
			
					for(uint8_t mem_address_x; mem_address_x <256; mem_address_y++)
					{
						
							// Setting up the address
								
							uint8_t memory_address[16];
			
			
				
							// address for x column
							uint8_t	memory_address_x[8];
			
			
							for(int i=0; i<8; i++)
							{
								memory_address_x[i] = bitRead(mem_address_x,i);
								memory_address[i]	= bitRead(mem_address_x,i);
							}
					
							// address for y column
							uint8_t	memory_address_y[8];
			
							for(int i=0; i<8; i++)
							{
								memory_address_y[i] = bitRead(mem_address_y,i);
								memory_address[i+8]	= bitRead(mem_address_y,i);
							}
					
								//writing into the address pins
								for(int j; j<16;j++)
									{	
									digitalWrite((22+j),memory_address[j]);				
									}
					
					
					
								if(mem_address_x==mem_address_y )
								{
										for(int i; i<8; i++)
										{
											data_pins[i] = 0xFF;
										}
								}else{
										for(int i; i<8; i++)
										{
											data_pins[i] = 0x00;
										}
								}
					
					

								//writing data to data pins
								for(int k; k<8; k++)
									{
									digitalWrite((38+k), data_pins[k]);
									Serial.print(data_pins[k], BIN);
									}
								
								
								Serial.print("  ");	// provide spaces for each memory cell
					

						
					
						}			
			
						Serial.print('\n');
		
	}
	
	

}


#endif



