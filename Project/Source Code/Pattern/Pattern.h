#ifndef Pattern_H
#define TPattern_H


#include <Arduino.h>

class Pattern
{ 
	
	public:
		Pattern();
		
		void write_control();
		
		void read_control();
		
		void write_zero();
		
		void write_one();
		
		void diagonal(uint8_t index_number);
		
		void read();
};

#endif