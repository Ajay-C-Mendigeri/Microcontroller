/* 
 * File:   header.h
 * Author: lenovo
 *
 * Created on 9 October, 2026, 5:23 PM
 */

#ifndef HEADER_H
#define	HEADER_H

unsigned char read_digital_keypad(unsigned char trigger);
void init_timer0(void);


#define ALL_RELEASED 0X0F
#define EDGE  0

#endif	/* HEADER_H */

