/***********************************************************************//**
 * @file	: lpc17xx_qei.h
 * @brief	: Contains all macro definitions and function prototypes
 * 				support for QEI firmware library on LPC17xx
 * @version	: 1.0
 * @date	: 26. May. 2009
 * @author	: HieuNguyen
 **************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 **************************************************************************/

/* Peripheral group ----------------------------------------------------------- */
/** @defgroup QEI
 * @ingroup LPC1700CMSIS_FwLib_Drivers
 * @{
 */

#ifndef __QEI_H
#define __QEI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lpc17xx.h"
#include "lpc_types.h"

#define 		ENC_RES  2048UL  /**< Encoder resolution (PPR) */

volatile int ENCODER1 __attribute__((weak)) = 0;

/************************** PRIVATE MACROS *************************/
/** Signal Mode setting:
 * - When = 0, PhA and PhB function as quadrature encoder inputs.
 * - When = 1, PhA functions as the direction signal and PhB functions
 * as the clock signal
 */
#define SIGNAL_MODE             0

/** Capture Mode setting:
 * - When = 0, only PhA edges are counted (2X).
 * - When = 1, BOTH PhA and PhB edges are counted (4X), increasing
 * resolution but decreasing range
 */
#define CAP_MODE                        1

/** Velocity capture period definition (in microsecond) */
#define CAP_PERIOD                      250000UL

/** Delay time to Read Velocity Accumulator and display (in microsecond)*/
#define DISP_TIME                       3000000UL
/** Max velocity capture times calculated */
#define MAX_CAP_TIMES           		(DISP_TIME/CAP_PERIOD)


/* Private Macros ------------------------------------------------------------- */
/** @defgroup QEI_Private_Macros
 * @{
 */

/** @defgroup QEI_REGISTER_BIT_DEFINITIONS
 * @{
 */

/* Quadrature Encoder Interface Control Register Definition --------------------- */
/* QEI Control register */
#define QEI_CON_RESP		((uint32_t)(1<<0))		/**< Reset position counter */
#define QEI_CON_RESPI		((uint32_t)(1<<1))		/**< Reset Posistion Counter on Index */
#define QEI_CON_RESV		((uint32_t)(1<<2))		/**< Reset Velocity */
#define QEI_CON_RESI		((uint32_t)(1<<3))		/**< Reset Index Counter */
#define QEI_CON_BITMASK		((uint32_t)(0x0F))		/**< QEI Control register bit-mask */

/* QEI Configuration register */
#define QEI_CONF_DIRINV		((uint32_t)(1<<0))		/**< Direction Invert */
#define QEI_CONF_SIGMODE	((uint32_t)(1<<1))		/**< Signal mode */
#define QEI_CONF_CAPMODE	((uint32_t)(1<<2))		/**< Capture mode */
#define QEI_CONF_INVINX		((uint32_t)(1<<3))		/**< Invert index */
#define QEI_CONF_BITMASK	((uint32_t)(0x0F))		/**< QEI Configuration register bit-mask */

/* QEI Status register */
#define QEI_STAT_DIR		((uint32_t)(1<<0))		/**< Direction bit */
#define QEI_STAT_BITMASK	((uint32_t)(1<<0))		/**< QEI status register bit-mask */

/* Quadrature Encoder Interface Position, index and timer Register Definitions --- */
/* QEI Position register */

/* QEI Maximum Position register */

/* QEI Position Compare register 0 */

/* QEI Position Compare register 1 */

/* QEI Position Compare register 2 */

/* QEI Index Count register */

/* QEI Index Compare register */

/* QEI Timer Reload register */

/* QEI Timer register */

/* QEI Velocity register */

/* QEI Velocity Capture register */

/* QEI Velocity Compare register */

/* QEI Digital Filter register */

/* Quadrature Encoder Interface Interrupt registers definitions --------------------- */
/* QEI Interrupt Status register */
#define QEI_INTSTAT_INX_Int			((uint32_t)(1<<0))	/**< Indicates that an index pulse was detected */
#define QEI_INTSTAT_TIM_Int			((uint32_t)(1<<1))	/**< Indicates that a velocity timer overflow occurred */
#define QEI_INTSTAT_VELC_Int		((uint32_t)(1<<2))	/**< Indicates that capture velocity is less than compare velocity */
#define QEI_INTSTAT_DIR_Int			((uint32_t)(1<<3))	/**< Indicates that a change of direction was detected */
#define QEI_INTSTAT_ERR_Int			((uint32_t)(1<<4))	/**< Indicates that an encoder phase error was detected */
#define QEI_INTSTAT_ENCLK_Int		((uint32_t)(1<<5))	/**< Indicates that and encoder clock pulse was detected */
#define QEI_INTSTAT_POS0_Int		((uint32_t)(1<<6))	/**< Indicates that the position 0 compare value is equal to the
														current position */
#define QEI_INTSTAT_POS1_Int		((uint32_t)(1<<7))	/**< Indicates that the position 1compare value is equal to the
														current position */
#define QEI_INTSTAT_POS2_Int		((uint32_t)(1<<8))	/**< Indicates that the position 2 compare value is equal to the
														current position */
#define QEI_INTSTAT_REV_Int			((uint32_t)(1<<9))	/**< Indicates that the index compare value is equal to the current
														index count */
#define QEI_INTSTAT_POS0REV_Int		((uint32_t)(1<<10))	/**< Combined position 0 and revolution count interrupt. Set when
														both the POS0_Int bit is set and the REV_Int is set */
#define QEI_INTSTAT_POS1REV_Int		((uint32_t)(1<<11))	/**< Combined position 1 and revolution count interrupt. Set when
														both the POS1_Int bit is set and the REV_Int is set */
#define QEI_INTSTAT_POS2REV_Int		((uint32_t)(1<<12))	/**< Combined position 2 and revolution count interrupt. Set when
														both the POS2_Int bit is set and the REV_Int is set */
#define QEI_INTSTAT_BITMASK			((uint32_t)(0x1FFF))	/**< QEI Interrupt Status register bit-mask */

/* QEI Interrupt Set register */
#define QEI_INTSET_INX_Int			((uint32_t)(1<<0))	/**< Set Bit Indicates that an index pulse was detected */
#define QEI_INTSET_TIM_Int			((uint32_t)(1<<1))	/**< Set Bit Indicates that a velocity timer overflow occurred */
#define QEI_INTSET_VELC_Int			((uint32_t)(1<<2))	/**< Set Bit Indicates that capture velocity is less than compare velocity */
#define QEI_INTSET_DIR_Int			((uint32_t)(1<<3))	/**< Set Bit Indicates that a change of direction was detected */
#define QEI_INTSET_ERR_Int			((uint32_t)(1<<4))	/**< Set Bit Indicates that an encoder phase error was detected */
#define QEI_INTSET_ENCLK_Int		((uint32_t)(1<<5))	/**< Set Bit Indicates that and encoder clock pulse was detected */
#define QEI_INTSET_POS0_Int			((uint32_t)(1<<6))	/**< Set Bit Indicates that the position 0 compare value is equal to the
														current position */
#define QEI_INTSET_POS1_Int			((uint32_t)(1<<7))	/**< Set Bit Indicates that the position 1compare value is equal to the
														current position */
#define QEI_INTSET_POS2_Int			((uint32_t)(1<<8))	/**< Set Bit Indicates that the position 2 compare value is equal to the
														current position */
#define QEI_INTSET_REV_Int			((uint32_t)(1<<9))	/**< Set Bit Indicates that the index compare value is equal to the current
														index count */
#define QEI_INTSET_POS0REV_Int		((uint32_t)(1<<10))	/**< Set Bit that combined position 0 and revolution count interrupt */
#define QEI_INTSET_POS1REV_Int		((uint32_t)(1<<11))	/**< Set Bit that Combined position 1 and revolution count interrupt */
#define QEI_INTSET_POS2REV_Int		((uint32_t)(1<<12))	/**< Set Bit that Combined position 2 and revolution count interrupt */
#define QEI_INTSET_BITMASK			((uint32_t)(0x1FFF))	/**< QEI Interrupt Set register bit-mask */

/* QEI Interrupt Clear register */
#define QEI_INTCLR_INX_Int			((uint32_t)(1<<0))	/**< Clear Bit Indicates that an index pulse was detected */
#define QEI_INTCLR_TIM_Int			((uint32_t)(1<<1))	/**< Clear Bit Indicates that a velocity timer overflow occurred */
#define QEI_INTCLR_VELC_Int			((uint32_t)(1<<2))	/**< Clear Bit Indicates that capture velocity is less than compare velocity */
#define QEI_INTCLR_DIR_Int			((uint32_t)(1<<3))	/**< Clear Bit Indicates that a change of direction was detected */
#define QEI_INTCLR_ERR_Int			((uint32_t)(1<<4))	/**< Clear Bit Indicates that an encoder phase error was detected */
#define QEI_INTCLR_ENCLK_Int		((uint32_t)(1<<5))	/**< Clear Bit Indicates that and encoder clock pulse was detected */
#define QEI_INTCLR_POS0_Int			((uint32_t)(1<<6))	/**< Clear Bit Indicates that the position 0 compare value is equal to the
														current position */
#define QEI_INTCLR_POS1_Int			((uint32_t)(1<<7))	/**< Clear Bit Indicates that the position 1compare value is equal to the
														current position */
#define QEI_INTCLR_POS2_Int			((uint32_t)(1<<8))	/**< Clear Bit Indicates that the position 2 compare value is equal to the
														current position */
#define QEI_INTCLR_REV_Int			((uint32_t)(1<<9))	/**< Clear Bit Indicates that the index compare value is equal to the current
														index count */
#define QEI_INTCLR_POS0REV_Int		((uint32_t)(1<<10))	/**< Clear Bit that combined position 0 and revolution count interrupt */
#define QEI_INTCLR_POS1REV_Int		((uint32_t)(1<<11))	/**< Clear Bit that Combined position 1 and revolution count interrupt */
#define QEI_INTCLR_POS2REV_Int		((uint32_t)(1<<12))	/**< Clear Bit that Combined position 2 and revolution count interrupt */
#define QEI_INTCLR_BITMASK			((uint32_t)(0x1FFF))	/**< QEI Interrupt Clear register bit-mask */

/* QEI Interrupt Enable register */
#define QEI_INTEN_INX_Int			((uint32_t)(1<<0))	/**< Enabled Interrupt Bit Indicates that an index pulse was detected */
#define QEI_INTEN_TIM_Int			((uint32_t)(1<<1))	/**< Enabled Interrupt Bit Indicates that a velocity timer overflow occurred */
#define QEI_INTEN_VELC_Int			((uint32_t)(1<<2))	/**< Enabled Interrupt Bit Indicates that capture velocity is less than compare velocity */
#define QEI_INTEN_DIR_Int			((uint32_t)(1<<3))	/**< Enabled Interrupt Bit Indicates that a change of direction was detected */
#define QEI_INTEN_ERR_Int			((uint32_t)(1<<4))	/**< Enabled Interrupt Bit Indicates that an encoder phase error was detected */
#define QEI_INTEN_ENCLK_Int			((uint32_t)(1<<5))	/**< Enabled Interrupt Bit Indicates that and encoder clock pulse was detected */
#define QEI_INTEN_POS0_Int			((uint32_t)(1<<6))	/**< Enabled Interrupt Bit Indicates that the position 0 compare value is equal to the
														current position */
#define QEI_INTEN_POS1_Int			((uint32_t)(1<<7))	/**< Enabled Interrupt Bit Indicates that the position 1compare value is equal to the
														current position */
#define QEI_INTEN_POS2_Int			((uint32_t)(1<<8))	/**< Enabled Interrupt Bit Indicates that the position 2 compare value is equal to the
														current position */
#define QEI_INTEN_REV_Int			((uint32_t)(1<<9))	/**< Enabled Interrupt Bit Indicates that the index compare value is equal to the current
														index count */
#define QEI_INTEN_POS0REV_Int		((uint32_t)(1<<10))	/**< Enabled Interrupt Bit that combined position 0 and revolution count interrupt */
#define QEI_INTEN_POS1REV_Int		((uint32_t)(1<<11))	/**< Enabled Interrupt Bit that Combined position 1 and revolution count interrupt */
#define QEI_INTEN_POS2REV_Int		((uint32_t)(1<<12))	/**< Enabled Interrupt Bit that Combined position 2 and revolution count interrupt */
#define QEI_INTEN_BITMASK			((uint32_t)(0x1FFF))	/**< QEI Interrupt Enable register bit-mask */

/* QEI Interrupt Enable Set register */
#define QEI_IESET_INX_Int			((uint32_t)(1<<0))	/**< Set Enable Interrupt Bit Indicates that an index pulse was detected */
#define QEI_IESET_TIM_Int			((uint32_t)(1<<1))	/**< Set Enable Interrupt Bit Indicates that a velocity timer overflow occurred */
#define QEI_IESET_VELC_Int			((uint32_t)(1<<2))	/**< Set Enable Interrupt Bit Indicates that capture velocity is less than compare velocity */
#define QEI_IESET_DIR_Int			((uint32_t)(1<<3))	/**< Set Enable Interrupt Bit Indicates that a change of direction was detected */
#define QEI_IESET_ERR_Int			((uint32_t)(1<<4))	/**< Set Enable Interrupt Bit Indicates that an encoder phase error was detected */
#define QEI_IESET_ENCLK_Int			((uint32_t)(1<<5))	/**< Set Enable Interrupt Bit Indicates that and encoder clock pulse was detected */
#define QEI_IESET_POS0_Int			((uint32_t)(1<<6))	/**< Set Enable Interrupt Bit Indicates that the position 0 compare value is equal to the
														current position */
#define QEI_IESET_POS1_Int			((uint32_t)(1<<7))	/**< Set Enable Interrupt Bit Indicates that the position 1compare value is equal to the
														current position */
#define QEI_IESET_POS2_Int			((uint32_t)(1<<8))	/**< Set Enable Interrupt Bit Indicates that the position 2 compare value is equal to the
														current position */
#define QEI_IESET_REV_Int			((uint32_t)(1<<9))	/**< Set Enable Interrupt Bit Indicates that the index compare value is equal to the current
														index count */
#define QEI_IESET_POS0REV_Int		((uint32_t)(1<<10))	/**< Set Enable Interrupt Bit that combined position 0 and revolution count interrupt */
#define QEI_IESET_POS1REV_Int		((uint32_t)(1<<11))	/**< Set Enable Interrupt Bit that Combined position 1 and revolution count interrupt */
#define QEI_IESET_POS2REV_Int		((uint32_t)(1<<12))	/**< Set Enable Interrupt Bit that Combined position 2 and revolution count interrupt */
#define QEI_IESET_BITMASK			((uint32_t)(0x1FFF))	/**< QEI Interrupt Enable Set register bit-mask */

/* QEI Interrupt Enable Clear register */
#define QEI_IECLR_INX_Int			((uint32_t)(1<<0))	/**< Clear Enabled Interrupt Bit Indicates that an index pulse was detected */
#define QEI_IECLR_TIM_Int			((uint32_t)(1<<1))	/**< Clear Enabled Interrupt Bit Indicates that a velocity timer overflow occurred */
#define QEI_IECLR_VELC_Int			((uint32_t)(1<<2))	/**< Clear Enabled Interrupt Bit Indicates that capture velocity is less than compare velocity */
#define QEI_IECLR_DIR_Int			((uint32_t)(1<<3))	/**< Clear Enabled Interrupt Bit Indicates that a change of direction was detected */
#define QEI_IECLR_ERR_Int			((uint32_t)(1<<4))	/**< Clear Enabled Interrupt Bit Indicates that an encoder phase error was detected */
#define QEI_IECLR_ENCLK_Int			((uint32_t)(1<<5))	/**< Clear Enabled Interrupt Bit Indicates that and encoder clock pulse was detected */
#define QEI_IECLR_POS0_Int			((uint32_t)(1<<6))	/**< Clear Enabled Interrupt Bit Indicates that the position 0 compare value is equal to the
														current position */
#define QEI_IECLR_POS1_Int			((uint32_t)(1<<7))	/**< Clear Enabled Interrupt Bit Indicates that the position 1compare value is equal to the
														current position */
#define QEI_IECLR_POS2_Int			((uint32_t)(1<<8))	/**< Clear Enabled Interrupt Bit Indicates that the position 2 compare value is equal to the
														current position */
#define QEI_IECLR_REV_Int			((uint32_t)(1<<9))	/**< Clear Enabled Interrupt Bit Indicates that the index compare value is equal to the current
														index count */
#define QEI_IECLR_POS0REV_Int		((uint32_t)(1<<10))	/**< Clear Enabled Interrupt Bit that combined position 0 and revolution count interrupt */
#define QEI_IECLR_POS1REV_Int		((uint32_t)(1<<11))	/**< Clear Enabled Interrupt Bit that Combined position 1 and revolution count interrupt */
#define QEI_IECLR_POS2REV_Int		((uint32_t)(1<<12))	/**< Clear Enabled Interrupt Bit that Combined position 2 and revolution count interrupt */
#define QEI_IECLR_BITMASK			((uint32_t)(0x1FFF))	/**< QEI Interrupt Enable Clear register bit-mask */


/**
 * @}
 */

/**
 * @}
 */


/* Public Types --------------------------------------------------------------- */
/** @defgroup QEI_Public_Types
 * @{
 */

/**
 * @brief QEI Configuration structure type definition
 */
typedef struct {
	unsigned int DirectionInvert	:1; 	/**< Direction invert option:
										- QEI_DIRINV_NONE: QEI Direction is normal
										- QEI_DIRINV_CMPL: QEI Direction is complemented
										*/
	unsigned int SignalMode			:1; 	/**< Signal mode Option:
										- QEI_SIGNALMODE_QUAD: Signal is in Quadrature phase mode
										- QEI_SIGNALMODE_CLKDIR: Signal is in Clock/Direction mode
										*/
	unsigned int CaptureMode		:1;		/**< Capture Mode Option:
										- QEI_CAPMODE_2X: Only Phase-A edges are counted (2X)
										- QEI_CAPMODE_4X: BOTH Phase-A and Phase-B edges are counted (4X)
										*/
	unsigned int InvertIndex		:1; 	/**< Invert Index Option:
										- QEI_INVINX_NONE: the sense of the index input is normal
										- QEI_INVINX_EN: inverts the sense of the index input
										*/
} QEI_CFG_Type;

/**
 * @brief Timer Reload Configuration structure type definition
 */
typedef struct {

	unsigned char ReloadOption;		/**< Velocity Timer Reload Option, should be:
								- QEI_TIMERRELOAD_TICKVAL: Reload value in absolute value
								- QEI_TIMERRELOAD_USVAL: Reload value in microsecond value
								*/
	unsigned char Reserved[3];
	unsigned int ReloadValue;		/**< Velocity Timer Reload Value, 32-bit long, should be matched
								with Velocity Timer Reload Option
								*/
} QEI_RELOADCFG_Type;

/**
 * @}
 */


/* Public Macros -------------------------------------------------------------- */
/** @defgroup QEI_Public_Macros
 * @{
 */

#define PARAM_QEIx(n)	((n==QEI))

/* QEI Reset types */
#define QEI_RESET_POS			QEI_CON_RESP		/**< Reset position counter */
#define QEI_RESET_POSOnIDX		QEI_CON_RESPI		/**< Reset Posistion Counter on Index */
#define QEI_RESET_VEL			QEI_CON_RESV		/**< Reset Velocity */
#define QEI_RESET_IDX			QEI_CON_RESI		/**< Reset Index Counter */

#define PARAM_QEI_RESET(n)	((n==QEI_CON_RESP) \
|| (n==QEI_RESET_POSOnIDX) \
|| (n==QEI_RESET_VEL) \
|| (n==QEI_RESET_IDX))

/* QEI Direction Invert Type Option */
#define QEI_DIRINV_NONE		((uint32_t)(0))		/**< Direction is not inverted */
#define QEI_DIRINV_CMPL		((uint32_t)(1))		/**< Direction is complemented */

#define PARAM_QEI_DIRINV(n)	((n==QEI_DIRINV_NONE) || (n==QEI_DIRINV_CMPL))

/* QEI Signal Mode Option */
#define QEI_SIGNALMODE_QUAD		((uint32_t)(0))		/**< Signal operation: Quadrature phase mode */
#define QEI_SIGNALMODE_CLKDIR	((uint32_t)(1))		/**< Signal operation: Clock/Direction mode */

#define PARAM_QEI_SIGNALMODE(n)	((n==QEI_SIGNALMODE_QUAD) || (n==QEI_SIGNALMODE_CLKDIR))

/* QEI Capture Mode Option */
#define QEI_CAPMODE_2X			((uint32_t)(0))		/**< Capture mode: Only Phase-A edges are counted (2X) */
#define QEI_CAPMODE_4X			((uint32_t)(1))		/**< Capture mode: BOTH PhA and PhB edges are counted (4X)*/

#define PARAM_QEI_CAPMODE(n)	((n==QEI_CAPMODE_2X) || (n==QEI_CAPMODE_4X))

/* QEI Invert Index Signal Option */
#define QEI_INVINX_NONE			((uint32_t)(0))		/**< Invert Index signal option: None */
#define QEI_INVINX_EN			((uint32_t)(1))		/**< Invert Index signal option: Enable */

#define PARAM_QEI_INVINX(n)		((n==QEI_INVINX_NONE) || (n==QEI_INVINX_EN))

/* QEI timer reload option */
#define QEI_TIMERRELOAD_TICKVAL	((uint8_t)(0))	/**< Reload value in absolute value */
#define QEI_TIMERRELOAD_USVAL	((uint8_t)(1))	/**< Reload value in microsecond value */
#define PARAM_QEI_TIMERRELOAD(n)	((n==QEI_TIMERRELOAD_TICKVAL) || (n==QEI_TIMERRELOAD_USVAL))

/* QEI Flag Status type */
#define QEI_STATUS_DIR			((uint32_t)(1<<0))	/**< Direction status */
#define PARAM_QEI_STATUS(n)		((n==QEI_STATUS_DIR))

/* QEI Compare Position channel option */
#define QEI_COMPPOS_CH_0			((uint8_t)(0))		/**< QEI compare position channel 0 */
#define QEI_COMPPOS_CH_1			((uint8_t)(1))		/**< QEI compare position channel 1 */
#define QEI_COMPPOS_CH_2			((uint8_t)(2))		/**< QEI compare position channel 2 */
#define PARAM_QEI_COMPPOS_CH(n)		((n==QEI_COMPPOS_CH_0) || (n==QEI_COMPPOS_CH_1) || (n==QEI_COMPPOS_CH_2))

/* QEI interrupt flag type */
#define QEI_INTFLAG_INX_Int			((uint32_t)(1<<0))	/**< index pulse was detected interrupt */
#define QEI_INTFLAG_TIM_Int			((uint32_t)(1<<1))	/**< Velocity timer over flow interrupt */
#define QEI_INTFLAG_VELC_Int		((uint32_t)(1<<2))	/**< Capture velocity is less than compare interrupt */
#define QEI_INTFLAG_DIR_Int			((uint32_t)(1<<3))	/**< Change of direction interrupt */
#define QEI_INTFLAG_ERR_Int			((uint32_t)(1<<4))	/**< An encoder phase error interrupt */
#define QEI_INTFLAG_ENCLK_Int		((uint32_t)(1<<5))	/**< An encoder clock pulse was detected interrupt */
#define QEI_INTFLAG_POS0_Int		((uint32_t)(1<<6))	/**< position 0 compare value is equal to the
														current position interrupt */
#define QEI_INTFLAG_POS1_Int		((uint32_t)(1<<7))	/**< position 1 compare value is equal to the
														current position interrupt */
#define QEI_INTFLAG_POS2_Int		((uint32_t)(1<<8))	/**< position 2 compare value is equal to the
														current position interrupt */
#define QEI_INTFLAG_REV_Int			((uint32_t)(1<<9))	/**< Index compare value is equal to the current
														index count interrupt */
#define QEI_INTFLAG_POS0REV_Int		((uint32_t)(1<<10))	/**< Combined position 0 and revolution count interrupt */
#define QEI_INTFLAG_POS1REV_Int		((uint32_t)(1<<11))	/**< Combined position 1 and revolution count interrupt */
#define QEI_INTFLAG_POS2REV_Int		((uint32_t)(1<<12))	/**< Combined position 2 and revolution count interrupt */

#define PARAM_QEI_INTFLAG(n)	((n==QEI_INTFLAG_INX_Int) \
|| (n==QEI_INTFLAG_TIM_Int) \
|| (n==QEI_INTFLAG_VELC_Int) \
|| (n==QEI_INTFLAG_DIR_Int) \
|| (n==QEI_INTFLAG_ERR_Int) \
|| (n==QEI_INTFLAG_ENCLK_Int) \
|| (n==QEI_INTFLAG_POS0_Int) \
|| (n==QEI_INTFLAG_POS1_Int) \
|| (n==QEI_INTFLAG_POS2_Int) \
|| (n==QEI_INTFLAG_REV_Int) \
|| (n==QEI_INTFLAG_POS0REV_Int) \
|| (n==QEI_INTFLAG_POS1REV_Int) \
|| (n==QEI_INTFLAG_POS2REV_Int))

/**
 * @}
 */


/* Public Functions ----------------------------------------------------------- */
/** @defgroup QEI_Public_Functions
 * @{
 */

void QEI_Reset(QEI_TypeDef *QEIx, unsigned int ulResetType);
void QEI_Init(void);
void QEI_Initialize(QEI_TypeDef *QEIx, QEI_CFG_Type *QEI_ConfigStruct);
void QEI_ConfigStructInit(QEI_CFG_Type *QIE_InitStruct);
void QEI_DeInit(QEI_TypeDef *QEIx);
FlagStatus QEI_GetStatus(QEI_TypeDef *QEIx, unsigned int ulFlagType);
unsigned int QEI_GetPosition(QEI_TypeDef *QEIx);
void QEI_SetMaxPosition(QEI_TypeDef *QEIx, unsigned int ulMaxPos);
void QEI_SetPositionComp(QEI_TypeDef *QEIx, unsigned char bPosCompCh, unsigned int ulPosComp);
unsigned int QEI_GetIndex(QEI_TypeDef *QEIx);
void QEI_SetIndexComp(QEI_TypeDef *QEIx, unsigned int ulIndexComp);
void QEI_SetTimerReload(QEI_TypeDef *QEIx, QEI_RELOADCFG_Type *QEIReloadStruct);
unsigned int QEI_GetTimer(QEI_TypeDef *QEIx);
unsigned int QEI_GetVelocity(QEI_TypeDef *QEIx);
unsigned int QEI_GetVelocityCap(QEI_TypeDef *QEIx);
void QEI_SetVelocityComp(QEI_TypeDef *QEIx, unsigned int ulVelComp);
void QEI_SetDigiFilter(QEI_TypeDef *QEIx, unsigned int ulSamplingPulse);
FlagStatus QEI_GetIntStatus(QEI_TypeDef *QEIx, unsigned int ulIntType);
void QEI_IntCmd(QEI_TypeDef *QEIx, unsigned int ulIntType, FunctionalState NewState);
void QEI_IntSet(QEI_TypeDef *QEIx, unsigned int ulIntType);
void QEI_IntClear(QEI_TypeDef *QEIx, unsigned int ulIntType);
unsigned int QEI_CalculateRPM(QEI_TypeDef *QEIx, unsigned int ulVelCapValue, unsigned int ulPPR);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* LPC17XX_QEI_H_ */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
