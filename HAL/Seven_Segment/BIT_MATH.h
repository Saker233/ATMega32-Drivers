#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
 
 
#define SET_BIT(NUM, MASK)    (NUM |= (1<<MASK))

#define CLEAR_BIT(NUM, MASK)    (NUM &= ~(1<<MASK))

#define TOGGLE_BIT(NUM, MASK)    (NUM = (NUM ^ (1<<MASK))

#define GET_BIT(NUM, MASK)        (NUM >> MASK)& 1)
 


int main()
{
	int res;
	
	res = SET_BIT(5,1);
	
	printf("%d", res);
}
