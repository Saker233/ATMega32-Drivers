#include <avr/io.h>
#include <avr/delay.h>
#include "STD_TYPES.h"


#define ZERO   	 0b00111111
#define ONE    	 0b00000110
#define TWO   	 0b01011011
#define THREE    0b01001111
#define FOUR   	 0b01100110
#define FIVE   	 0b01101101
#define SIX   	 0b01111101
#define SEVEN    0b00000111
#define EIGHT    0b01111111
#define NINE   	 0b01101111



int main()
{
	u8 seven[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
	DDRD = 0b11111111;
	while(1)
	{
		for(u8 i = 0; i < 10; i++)
		{
			PORTD = seven[i];
			_delay_ms(100);
		}
		/*
		PORTD = ZERO;  //0  //ABCDEF
				_delay_ms(100);

		PORTD = ONE;   //1  //BC
				_delay_ms(100);

		PORTD = TWO;		//2  //ABDEG
				_delay_ms(100);

		PORTD = THREE;  //	3 //ABCDG
				_delay_ms(100);

		PORTD = FOUR;		//4  //BCFG
				_delay_ms(100);

		PORTD = FIVE;		//5  // ACDFG
				_delay_ms(100);

		PORTD = SIX;  //6  //ACDEFG
				_delay_ms(100);

		PORTD = SEVEN; //7 // ABC
				_delay_ms(100);

		PORTD = EIGHT;		//8 //ABCDEGF
				_delay_ms(100);

		PORTD = NINE;		//9 //ABCDFG
				_delay_ms(100);
	*/
	}


}
