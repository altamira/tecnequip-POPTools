/*----------------------------------------------------------------------------
 * Name:    Serial.h
 * Purpose: MCB1700 Low level serial definitions
 * Version: V1.00
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------
 * History:
 *          V1.00 Initial Version
 *----------------------------------------------------------------------------*/

#ifndef __SERIAL_H
#define __SERIAL_H

#define SERIAL_BUFFER_SIZE 64

extern void serial_init      (int uart);
extern int  serial_getChar   (int uart);
extern int  serial_getChar_nb(int uart);
extern int  serial_putChar   (int uart, int c);
extern void serial_putString (int uart, unsigned char *s);

unsigned char CRC(unsigned char * buffer, unsigned int size);

#endif
