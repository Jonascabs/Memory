#ifndef Pattern_cpp
#define Pattern_cpp


#include <Pattern.h> //include the declaration for this class
#include <Arduino.h>



//<<constructor>>
Pattern::Pattern()
{
	Serial.begin(9600);
}

//<<destructor>>

//Read Initialize
void Pattern::read_init()
{
	digitalWrite(46,HIGH);
	digitalWrite(47, LOW);
	digitalWrite(49, HIGH);
	digitalWrite(48, LOW);	
	;
}

//Read Control
void Pattern::read_control()
{
	

	
	digitalWrite(46,LOW);
	digitalWrite(47, HIGH);
	digitalWrite(49, HIGH);
	digitalWrite(48, LOW);
	
	
}

// Write Initialize
void Pattern::write_init()
{

	digitalWrite(46,HIGH);
	digitalWrite(47, LOW);
	digitalWrite(48, HIGH)
	digitalWrite(49, HIGH);
	
}


// Write Control
void Pattern::write_control()
{


	digitalWrite(46,LOW);
	digitalWrite(47, HIGH);
	digitalWrite(48, LOW);
	digitalWrite(49, LOW);

}

void write_addr(int mem_address)
{
			for(int i=22; i<38;i++)
              { 
              digitalWrite(i, mem_address%2); 
              //Serial.print(mem_address%2);
              mem_address = mem_address/2;
              }
}
	

//write Zero
void Pattern::background_zero()	  
{
	
	Serial.println("Writing Background Zero");
	write_init();

	//Data Pins Setup 		
	pinMode(38, OUTPUT);	//D0
	pinMode(39, OUTPUT);	//D1
	pinMode(40, OUTPUT);	//D2
	pinMode(41, OUTPUT);	//D3
	pinMode(42, OUTPUT);	//D4
	pinMode(43, OUTPUT);	//D5
	pinMode(44, OUTPUT);	//D6
	pinMode(45, OUTPUT);	//D7	
	
	
	
			
	// writing zeroes to the memory location in ascending address order
	for(uint8_t mem_address_y=0; mem_address_y <256; mem_address_y++)
	{
			
			
					for(uint8_t mem_address_x=0; mem_address_x <256; mem_address_x++)
					{
						uint16_t memory_address = (mem_address_y<<8)|(memory_address_x);
						write_addr(memory_address);

							
						//Serial.print(" ");
						write_control();

						//writing ones to data pins
						for(int i=38; i<46; i++)
							{
							digitalWrite(i, LOW);	
							}
							
					//delay(1);
						
						write_init();				
					
						
									if(mem_address_x==255) 
									{
										break;
									}
					
					}
					
					
					if(mem_address_y==255) 
					{
					break;
					}
					
	}
	Serial.println("Write Done");
}	
	


void Pattern::background_one()    // writing ones in ascending address order
{
	
	Serial.println("Writing Background 1");
	write_init();
	


	//Data Pins Setup 		
	pinMode(38, OUTPUT);	//D0
	pinMode(39, OUTPUT);	//D1
	pinMode(40, OUTPUT);	//D2
	pinMode(41, OUTPUT);	//D3
	pinMode(42, OUTPUT);	//D4
	pinMode(43, OUTPUT);	//D5
	pinMode(44, OUTPUT);	//D6
	pinMode(45, OUTPUT);	//D7	
	
	
	
			
	

			
	// writing ones to the memory location in ascending address order
	for(uint8_t mem_address_y=0; mem_address_y <256; mem_address_y++)
	{
			
			
					for(uint8_t mem_address_x=0; mem_address_x <256; mem_address_x++)
					{
						uint16_t memory_address = (mem_address_y<<8)|(memory_address_x);
						write_addr(memory_address);
					
							
			
						write_control();
						
						
						//writing ones to data pins
						for(int i=38; i<46; i++)
							{
							digitalWrite(i, HIGH);
							
							}

						write_init();
						
									if(mem_address_x==255) 
									{
										break;
									}
					

					}
	
					if(mem_address_y==255) 
					{
					break;
					}
	}

	Serial.println("Write Done");
}				



//write diagonal
void Pattern::diagonal(uint8_t index_number)
{
	Serial.println("Writing Diagonal");
	
	
	write_init();

	//Data Pins Setup 		
	pinMode(38, OUTPUT);	//D0
	pinMode(39, OUTPUT);	//D1
	pinMode(40, OUTPUT);	//D2
	pinMode(41, OUTPUT);	//D3
	pinMode(42, OUTPUT);	//D4
	pinMode(43, OUTPUT);	//D5
	pinMode(44, OUTPUT);	//D6
	pinMode(45, OUTPUT);	//D7	
	
	
	
			
			

		



	for(uint8_t mem_address_y=0; mem_address_y <256; mem_address_y++)
	{
			
			
					for(uint8_t mem_address_x=0; mem_address_x <256; mem_address_x++)
					{
					
						
						uint16_t memory_address = (mem_address_y<<8)|(memory_address_x);
						write_addr(memory_address);

						
						
						write_control();

						//writing diagonal to data pins
						uint8_t compare = mem_address_y + index_number;
						
						if(mem_address_x == compare)
						{
							for(int i=38; i<46; i++)
							{
							digitalWrite(i, HIGH);
							//Serial.print(1);
							
							}	
						
						}else{
							
							for(int i=38; i<46; i++)
							{
							digitalWrite(i, LOW);		
							//Serial.print(0);							
							}
						
							

						}

						write_init();
						
						
									if(mem_address_x==255) 
									{
										break;
									}
	
					}
					

					if(mem_address_y==255) 
					{
					break;
					}
	
	}
	Serial.println("Write Done");
}				


void Pattern::read()
{
	Serial.println("Reading");
	
	read_init();
	
	

	//Data Pins Setup 		
	pinMode(38, INPUT);	//D0
	pinMode(39, INPUT);	//D1
	pinMode(40, INPUT);	//D2
	pinMode(41, INPUT);	//D3
	pinMode(42, INPUT);	//D4
	pinMode(43, INPUT);	//D5
	pinMode(44, INPUT);	//D6
	pinMode(45, INPUT);	//D7	
	
	
	
			
	Serial.print("   ");
	
	
	for (int header=0; header <256; header++)
	{
		Serial.print(header, HEX);
		Serial.print("   ");
	}

	Serial.print("\n");
			
			
	
	for(uint8_t mem_address_y=0; mem_address_y <256; mem_address_y++)
	{
			
			Serial.print(mem_address_y, HEX);
			Serial.print("  ");
			
					for(uint8_t mem_address_x=0; mem_address_x <256; mem_address_x++)
					{
						
						uint16_t memory_address = (mem_address_y<<8)|(memory_address_x);	
						write_addr(memory_address);
						
						
						
						uint8_t read_data;
						read_control();	
						//Reading data pins
						for(int i=38; i<46; i++)
							{
	
								
								if(digitalRead(i) == 1){
									
									bitWrite(read_data,(i-38),1);
									//Serial.print(1);
									
								}
								
								else 
								{
									
									bitWrite(read_data,(i-38),0);
									//Serial.print(0);
								}								
							}
						
						Serial.print(read_data, HEX);
						
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


void Pattern::checkerboard()
{
	Serial.println("Writing Checkerboard");
	
	write_init();
	

	//Data Pins Setup 		
	pinMode(38, OUTPUT);	//D0
	pinMode(39, OUTPUT);	//D1
	pinMode(40, OUTPUT);	//D2
	pinMode(41, OUTPUT);	//D3
	pinMode(42, OUTPUT);	//D4
	pinMode(43, OUTPUT);	//D5
	pinMode(44, OUTPUT);	//D6
	pinMode(45, OUTPUT);	//D7	
	
	
	
			
			
			
	

			
	// writing ones to the memory location in ascending address order
	for(uint8_t mem_address_y=0; mem_address_y <256; mem_address_y++)
	{
			
			
					for(uint8_t mem_address_x=0; mem_address_x <256; mem_address_x++)
					{
						uint16_t memory_address = (mem_address_y<<8)|(memory_address_x);
						write_addr(memory_address);
						
							

						write_control();
						
						uint8_t compare_x = mem_address_x & B00000001;
						uint8_t compare_y = mem_address_y & B00000001;
						uint8_t compare_result = compare_x ^ compare_y;
						
						if(compare_result == 1)
						{ 
							for(int i=38; i<46; i++)
							{
							digitalWrite(i, HIGH);
							
							}		
						}	
						else
						{							
							for(int i=38; i<46; i++)
							{
							digitalWrite(i, LOW);	
							}
						}
						write_init();
						
												
					if(mem_address_x==255) 
					{
					break;
					}
			
					
					}
					
					
					if(mem_address_y==255) 
					{
					break;
					}
	}

		Serial.println("Writing Done");
}		


void Pattern::column_bar()
{
	
	Serial.print("Writing Column Bar");
	write_init();
	
	

	//Data Pins Setup 		
	pinMode(38, OUTPUT);	//D0
	pinMode(39, OUTPUT);	//D1
	pinMode(40, OUTPUT);	//D2
	pinMode(41, OUTPUT);	//D3
	pinMode(42, OUTPUT);	//D4
	pinMode(43, OUTPUT);	//D5
	pinMode(44, OUTPUT);	//D6
	pinMode(45, OUTPUT);	//D7	
	
	
	
			
			


		
	// writing ones to the memory location in ascending address order
	for(uint8_t mem_address_y=0; mem_address_y <256; mem_address_y++)
	{
			
			
					for(uint8_t mem_address_x=0; mem_address_x <256; mem_address_x++)
					{
						uint16_t memory_address = (mem_address_y<<8)|(memory_address_x);
						write_addr(memory_address);
						
							
						
						write_control();
						
						
						uint8_t columnBar = mem_address_x &B00000001;
						
						if(columnBar == 0)
						{ 
							for(int i=38; i<46; i++)
							{
							digitalWrite(i, HIGH);
							}
							
							//Serial.print(0xFF, HEX);
							
						}else{
							
								for(int i=38; i<46; i++)
							{
							digitalWrite(i, LOW);							
							}
							
							//Serial.print(00, HEX);
							
							
						}
						write_init();
						
							//Serial.print("   ");	// provide spaces for each memory cell
						
						
									if(mem_address_x==255) 
									{
										break;
									}
		
					}
					
					if(mem_address_y==255) 
					{
					break;
					}
	}	
		Serial.println("Writing Done");
	
}		

void Pattern::row_bar()
{
	
	Serial.print("Writing Row Bar");
	write_init();
	


	//Data Pins Setup 		
	pinMode(38, OUTPUT);	//D0
	pinMode(39, OUTPUT);	//D1
	pinMode(40, OUTPUT);	//D2
	pinMode(41, OUTPUT);	//D3
	pinMode(42, OUTPUT);	//D4
	pinMode(43, OUTPUT);	//D5
	pinMode(44, OUTPUT);	//D6
	pinMode(45, OUTPUT);	//D7	
	
	
	
			
	for(uint8_t mem_address_y=0; mem_address_y <256; mem_address_y++)
	{
			
			
					for(uint8_t mem_address_x=0; mem_address_x <256; mem_address_x++)
					{
						uint16_t memory_address = (mem_address_y<<8)|(memory_address_x);
						write_addr(memory_address);

							
						
						write_control();
						
						
						uint8_t rowBar = mem_address_y &B00000001;
						
						if(rowBar == 0)
						{ 
							for(int i=38; i<46; i++)
							{
							digitalWrite(i, HIGH);
							}
							
						
							
						}else{
							
								for(int i=38; i<46; i++)
							{
							digitalWrite(i, LOW);							
							}
							
							
							
						}
						write_init();
						

						
						
									if(mem_address_x==255) 
									{
										break;
									}
			
					}
					
					if(mem_address_y==255) 
					{
					break;
					}
	}	
		Serial.println("Writing Done");
	
}	

void write_manual(uint16_t memory_address,uint8_t data)
{
	

	//Write Init
	digitalWrite(46,HIGH);
	digitalWrite(47, LOW);
	digitalWrite(49, HIGH);
	digitalWrite(48, HIGH);

	//Data Pins Setup 		
	pinMode(38, OUTPUT);	//D0
	pinMode(39, OUTPUT);	//D1
	pinMode(40, OUTPUT);	//D2
	pinMode(41, OUTPUT);	//D3
	pinMode(42, OUTPUT);	//D4
	pinMode(43, OUTPUT);	//D5
	pinMode(44, OUTPUT);	//D6
	pinMode(45, OUTPUT);	//D7	
	
						
						uint16_t memory_address_var;
				
							write_addr(memory_address);
					
							
							//Write Control
							digitalWrite(46,LOW);
							digitalWrite(47, HIGH);
							digitalWrite(49, LOW);
							digitalWrite(48, HIGH);
	
						
						uint8_t data_var;
					
						//writing ones to data pins
						for(int i=38; i<46; i++)
							{
							data_var = data % 2;
							digitalWrite(i, HIGH);
							data = data/2;
							}
						//Serial.print(0xFF, HEX);
						
						//	Serial.print("   ");	// provide spaces for each memory cell
						
						
}






#endif