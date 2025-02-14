/*****************************************************************************
 *   i2c.c:  I2C C file for NXP LPC17xx Family Microprocessors
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.05.26  ver 1.00    Prelimnary version, first Release
 *
*****************************************************************************/
#include "chip.h"
#include "i2c.h"

#include <string.h>

#define TRUE	1
#define FALSE	0

unsigned char I2CMasterBuffer[BUFSIZE];
unsigned int I2CReadLength;
unsigned int I2CWriteLength;

/*****************************************************************************
** Function name:		I2CInit
**
** Descriptions:		Initialize I2C controller
**
** parameters:			I2c mode is either MASTER or SLAVE
** Returned value:		true or false, return false if the I2C
**				interrupt handler was not installed correctly
**
*****************************************************************************/
unsigned int I2C_Init()
{
	uint32_t freq = 100000;

	Chip_I2C_Init(I2C0);
	Chip_I2C_Init(I2C2);

	// Valor de configuracao dos GPIOs: com pull-up e histerese
	uint32_t gpio_mode = 0; // Os pinos P0.27, P0.28, P5.3 e P5.4 sao especializados para I2C e nao possuem os bits de pull-up e histerese.

	// Configuracao dos I/Os - I2C0
	Chip_IOCON_PinMux(LPC_IOCON, 0, 27, gpio_mode, IOCON_FUNC1); // P0.27: SDA
	Chip_IOCON_PinMux(LPC_IOCON, 0, 28, gpio_mode, IOCON_FUNC1); // P0.28: SCL

	// Configuracao dos I/Os - I2C2
	gpio_mode = IOCON_MODE_PULLUP;// IOCON_OPENDRAIN_EN; // Os pinos P0.10 e P0.11 nao sao especializados para I2C. Portanto devemos configurar para open drain
	Chip_IOCON_PinMux(LPC_IOCON, 0, 10, gpio_mode, IOCON_FUNC2); // P0.10: SDA
	Chip_IOCON_PinMux(LPC_IOCON, 0, 11, gpio_mode, IOCON_FUNC2); // P0.11: SCL

	// P1.28 - 5V Enable (Nivel Alto)
	Chip_IOCON_PinMux    (LPC_IOCON, 1, 28, gpio_mode, IOCON_FUNC0);
	Chip_GPIO_SetDir     (LPC_GPIO , 1, 28, 1); // Define pino como Saida
	Chip_GPIO_SetPinState(LPC_GPIO , 1, 28, TRUE);

	Chip_I2C_SetClockRate(I2C0, freq); // 100 kHz
	Chip_I2C_SetClockRate(I2C2, freq); // 100 kHz

	return( TRUE );
}

/*****************************************************************************
** Function name:		I2CEngine
**
** Descriptions:		The routine to complete a I2C transaction
**				from start to stop. All the intermitten
**				steps are handled in the interrupt handler.
**				Before this routine is called, the read
**				length, write length, I2C master buffer,
**				and I2C command fields need to be filled.
**				see i2cmst.c for more details.
**
** parameters:			None
** Returned value:		true or false, return false only if the
**				start condition can never be generated and
**				timed out.
**
*****************************************************************************/
unsigned int I2C_Engine(int channel)
{
	uint8_t rxbuf[BUFSIZE], txbuf[BUFSIZE];

	I2C_XFER_T xfer;

	xfer.slaveAddr = I2CMasterBuffer[0] >> 1;

	xfer.txBuff = txbuf;
	xfer.txSz   = I2CWriteLength - 1;

	xfer.rxBuff = rxbuf;
	xfer.rxSz   = I2CReadLength;

	memcpy(txbuf, I2CMasterBuffer + 1, xfer.txSz);

	Chip_I2C_MasterTransfer(channel, &xfer);

	memcpy(I2CMasterBuffer, rxbuf, I2CReadLength);

	return ( TRUE );
}

/******************************************************************************
**                            End Of File
******************************************************************************/

