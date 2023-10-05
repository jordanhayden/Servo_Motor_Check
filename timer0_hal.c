/*
 * timer0_hal.c
 *
 * Created: 10/5/2023 2:57:05 PM
 *  Author: Jordan
 */ 

#include "timer0_hal.h"


volatile static uint32_t millis_c = 0;

ISR(TIMER0_COMPA_vect){
	millis_c++;
}



void timer0_init(void){
	TCCR0A |= (0b10 << WGM00);
	OCR0A = 249; // TOP value
	TIMSK0 |= (1 << OCIE0A);
	TCCR0B |= (0b011<< CS00);
}


uint32_t millis(void){
	return millis_c;
}


uint8_t millis_end(uint32_t start_time,uint32_t delay_time){
	
	return ((millis() - start_time) >= delay_time);
	
}