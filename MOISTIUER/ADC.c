
#include <avr/io.h>
#include "std_macros.h"
void ADC_vINIT(void)
{
// 	/*DDRA=0X0;*/
// 	//ADCSRA=0X87;
	//SET_BIT(DDRA,0);
	SET_BIT(ADMUX,REFS0);
	//SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
      //SET_BIT(ADCSRA,ADPS0);
}
unsigned int ADC_u16READ(void)
{
	ADMUX=0X40;
	ADCSRA|=(1<<ADSC);
	while((ADCSRA & (1<<ADIF))==0);
	SET_BIT(ADCSRA,ADIF);
	return (ADCW);
// 	unsigned short val;
// 	SET_BIT(ADCSRA,ADSC);
// 	while(IS_BIT_CLR(ADCSRA,ADSC));
// 	SET_BIT(ADCSRA,ADIF);
//     val=(ADCL);
// 	val|=(ADCH<<8);
// 	return val;
	
	
}