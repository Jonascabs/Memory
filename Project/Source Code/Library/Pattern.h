
#ifndef Pattern
#define Pattern


#include <Pattern.h> //include the declaration for this class
#include <Arduino.h>

const int Chip_Enable1 = 41
const int Chip_Enable2 = 43
const int Write_enable = 45
const int Read_enable  = 47


class Pattern{
	
	public:
	
		Pattern();
		
		void read_control();
		
		void write_control();
		
		void write_zero();
		
	
	
	
	
	
};

#endif