/*
 * MOISTIUER.c
 *
 * Created: 2/12/2024 2:54:07 AM
 *  Author: MUSTAFA MAHMOUD
 */ 
#include "std_macros.h"
#include "LCD 8BIT.h"
#include "ADC.h"
#include "button.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include  "LED.h"
// #define port_led  (unsigned char)'B'
// #define port_pin1  (unsigned char)0 
// #define port_pin2 (unsigned char)1
// #define port_pin3 (unsigned char)2
int main(void)
{
	
// 	SET_BIT(DDRB,0);
// 	SET_BIT(DDRB,1);
// 	SET_BIT(DDRB,2);
	LCD_INIT();
	ADC_vINIT();
	LCD_SEND_CMD(0X0C);
	LCD_SEND_STRING("Soil Moisture...");
	_delay_ms(100);
	LCD_clear_screen();
	LCD_SEND_STRING("Percent:");
	 int ADC_value;
	 int moisture;
	 int val;
    while(1)
    {
     	    ADC_value = ADC_u16READ();
		    moisture = (ADC_value*100.00)/1023.00;
			val=100-moisture;
			if ( val>=0 && val<=30)
			{
				LCD_MOVE_CURSOR(1,9);
				LCD_SEND_CHAR((val/10)+48);
				LCD_SEND_CHAR((val%10)+48);
				LCD_SEND_STRING("%");
				LCD_MOVE_CURSOR(2,1);
				LCD_SEND_STRING("The Soil is Dry  ");
// 				SET_BIT(PORTB,0);
// 				CLEAR_BIT(PORTB,2);
// 			   CLEAR_BIT(PORTB,1);
				
				
			}
		    else if(val>30 && val<=70)
			{
				LCD_MOVE_CURSOR(1,9);
				LCD_SEND_CHAR((val/10)+48);
				LCD_SEND_CHAR((val%10)+48);
				LCD_SEND_STRING("%");
				LCD_MOVE_CURSOR(2,1);
				LCD_SEND_STRING("Soil is Suitable");
// 				SET_BIT(PORTB,1);
// 				CLEAR_BIT(PORTB,2);
// 				CLEAR_BIT(PORTB,0);
			}
	        else if (val>70 && val<=99)
			{
				LCD_MOVE_CURSOR(1,9);
				LCD_SEND_CHAR((val/10)+48);
				LCD_SEND_CHAR((val%10)+48);
				LCD_SEND_STRING("%");
				LCD_MOVE_CURSOR(2,1);
				LCD_SEND_STRING("The Soil is Wet  ");
// 			     SET_BIT(PORTB,2);
// 			     CLEAR_BIT(PORTB,0);
// 			     CLEAR_BIT(PORTB,1);
			}
			else
			{
				
			}			
						
							
    }
}