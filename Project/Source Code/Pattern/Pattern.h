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
		
		void write_diagonal(int index_number);
		
		
};

#endif