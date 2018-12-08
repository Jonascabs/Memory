#ifndef Pattern_H
#define TPattern_H


#include <Arduino.h>

class Pattern
{ 
	
	public:
		Pattern();
		
		
		void write_init();
		
		void write_control();
		
		void read_init();
		
		void read_control();
		
		void background_zero();
		
		void background_one();
		
		void diagonal(uint8_t index_number);
		
		void read();
		
		void checkerboard();
};

#endif