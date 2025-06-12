/**
  * SPI1 Generated Driver File
  *
  * @file spi1.c
  *
  * @ingroup spi1
  *
  * @brief This file contains the driver code for the SPI1 module.
  *
  * @version SPI1 Driver Version v3.2.0.
  * 
  * @version SPI1 Package Version v5.2.0.
*/

/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#include <xc.h>
#include "../spi_interface.h"
#include "../spi1.h"
#include "../spi_polling_types.h"

/**
 * @ingroup spi1
 * @struct SPI_INTERFACE SPI1
 * @brief Defines an object for SPI_INTERFACE functions.
 */ 
 
const struct SPI_INTERFACE SPI1_Host = {
    .Initialize = SPI1_Initialize,
    .Deinitialize = SPI1_Deinitialize,
    .Open = SPI1_Open,
    .Close = SPI1_Close,
	.Transfer = SPI1_Transfer,
    .BufferExchange = SPI1_BufferExchange,
    .BufferWrite = SPI1_BufferWrite,
    .BufferRead = SPI1_BufferRead,	
    .ByteExchange = SPI1_ByteExchange,
    .ByteWrite = SPI1_ByteWrite,
    .ByteRead = SPI1_ByteRead,
    .IsTxReady = SPI1_IsTxReady,
    .IsRxReady = SPI1_IsRxReady,
    .RxCompleteCallbackRegister = NULL,
    .TxCompleteCallbackRegister = NULL
};

// con0 == SPI1CON0, con1 == SPI1CON1, con2 == SPI1CON2, baud == SPI1BAUD, clksel == SPI1CLKSEL
static const spi_configuration_t spi1_configuration[] = {   
    { 0x2, 0x40, 0x0, 0xff, 0x0 },
    { 0x2, 0x40, 0x0, 0x0, 0x0 }
};

void SPI1_Initialize(void)
{
    SPI1CON0bits.EN = 0U;

	// Disable the interrupts
    PIE3bits.SPI1IE 		= 0U;
    PIE3bits.SPI1TXIE 	= 0U;
    PIE3bits.SPI1RXIE 	= 0U;
	
    SPI1CON1 = (0 << _SPI1CON1_SDOP_POSITION)	/* SDOP active high(0) */
			|(0 << _SPI1CON1_SDIP_POSITION)	/* SDIP active high(0) */
			|(0 << _SPI1CON1_SSP_POSITION)	/* SSP active high(0) */
			|(0 << _SPI1CON1_FST_POSITION)	/* FST disabled(0) */
			|(0 << _SPI1CON1_CKP_POSITION)	/* CKP Idle:Low, Active:High(0) */
			|(1 << _SPI1CON1_CKE_POSITION)	/* CKE Active to idle(1) */
			|(0 << _SPI1CON1_SMP_POSITION);	/* SMP Middle(0) */
    SPI1CON2 = (0 << _SPI1CON2_RXR_POSITION)	/* RXR data is not stored in the FIFO(0) */
			|(0 << _SPI1CON2_TXR_POSITION)	/* TXR not required for a transfer(0) */
			|(0 << _SPI1CON2_SSET_POSITION);	/* SSET disabled(0) */
    SPI1BAUD = (0 << _SPI1BAUD_BAUD_POSITION);	/* BAUD 0x0(0) */
    SPI1CLK = (0 << _SPI1CLK_CLKSEL_POSITION);	/* CLKSEL FOSC(0) */
	SPI1TCNTL = (0 << _SPI1TCNTL_TCNTL_POSITION);	/* TCNTL 0x0(0) */
	SPI1TCNTH = (0 << _SPI1TCNTH_TCNTH_POSITION);	/* TCNTH 0x0(0) */
	SPI1STATUS = (0 << _SPI1STATUS_CLRBF_POSITION)	/* CLRBF no action(0) */
			|(0 << _SPI1STATUS_RXRE_POSITION)	/* RXRE no error(0) */
			|(0 << _SPI1STATUS_TXWE_POSITION);	/* TXWE no error(0) */
	SPI1TWIDTH = (0 << _SPI1TWIDTH_TWIDTH_POSITION);	/* TWIDTH 0x0(0) */
	SPI1INTE = (0 << _SPI1INTE_TXUIE_POSITION)	/* TXUIE disabled(0) */
			|(0 << _SPI1INTE_RXOIE_POSITION)	/* RXOIE disabled(0) */
			|(0 << _SPI1INTE_EOSIE_POSITION)	/* EOSIE disabled(0) */
			|(0 << _SPI1INTE_SOSIE_POSITION)	/* SOSIE disabled(0) */
			|(0 << _SPI1INTE_TCZIE_POSITION)	/* TCZIE disabled(0) */
			|(0 << _SPI1INTE_SRMTIE_POSITION);	/* SRMTIE disabled(0) */
	SPI1INTF = (0 << _SPI1INTF_TXUIF_POSITION)	/* TXUIF disabled(0) */
			|(0 << _SPI1INTF_RXOIF_POSITION)	/* RXOIF disabled(0) */
			|(0 << _SPI1INTF_EOSIF_POSITION)	/* EOSIF disabled(0) */
			|(0 << _SPI1INTF_SOSIF_POSITION)	/* SOSIF disabled(0) */
			|(0 << _SPI1INTF_TCZIF_POSITION)	/* TCZIF disabled(0) */
			|(0 << _SPI1INTF_SRMTIF_POSITION);	/* SRMTIF disabled(0) */
    
	SPI1STATUSbits.CLRBF = 1U;
	
	SPI1CON0 = (0 << _SPI1CON0_BMODE_POSITION)	/* BMODE last byte(0) */
			|(1 << _SPI1CON0_MST_POSITION)	/* MST bus host(1) */
			|(0 << _SPI1CON0_LSBF_POSITION)	/* LSBF MSb first(0) */
			|(0 << _SPI1CON0_EN_POSITION);	/* EN disabled(0) */
}

void SPI1_Deinitialize(void)
{
    SPI1CON0 = 0x0;
    SPI1CON1 = 0x4;
    SPI1CON2 = 0x0;
    SPI1BAUD = 0x0;
    SPI1CLK = 0x0; 
	SPI1TCNTL = 0x0;
	SPI1TCNTH = 0x0;
	SPI1STATUS = 0x20;
	SPI1TWIDTH = 0x0;
	SPI1INTE = 0x0;
	SPI1INTF = 0x0 ;
}

bool SPI1_Open(uint8_t spiConfigIndex)
{
	bool returnValue = false; 
	if(false == SPI1CON0bits.EN)
	{
        SPI1CON0 = spi1_configuration[spiConfigIndex].con0;
        SPI1CON1 = spi1_configuration[spiConfigIndex].con1;
        SPI1CON2 = spi1_configuration[spiConfigIndex].con2 & ~(_SPI1CON2_SPI1RXR_MASK) & ~(_SPI1CON2_SPI1TXR_MASK);
        SPI1BAUD = spi1_configuration[spiConfigIndex].baud;        
        SPI1CLK = spi1_configuration[spiConfigIndex].clksel;        
		TRISCbits.TRISC3 = 0;
        SPI1CON0bits.EN = 1U;
		returnValue = true;
	}
	else
	{
		returnValue = false;
	}
	return returnValue;
}

void SPI1_Close(void)
{
	SPI1CON0bits.EN = 0U;
	PIE3bits.SPI1IE 		= 0U;
    PIE3bits.SPI1TXIE 	= 0U;
    PIE3bits.SPI1RXIE 	= 0U;
}

void SPI1_Transfer(const void * txBuffer, void * rxBuffer, size_t bufferSize)
{
	uint8_t* bufferReceive = rxBuffer;
	const uint8_t* bufferTransmit = (const uint8_t *)txBuffer;

    SPI1STATUSbits.CLRBF = 1U;

	// Clear the TCZIF interrupt flag
	SPI1INTFbits.TCZIF = 0U;

	// Set as full duplex mode for buffer exchange operation
    SPI1CON2 = (SPI1CON2 | _SPI1CON2_SPI1RXR_MASK) | _SPI1CON2_SPI1TXR_MASK;
	
	// Load the transfer count registers
	SPI1TCNTH = (uint8_t)(bufferSize>>8);
	SPI1TCNTL = (uint8_t)(bufferSize);	
	
	while(0U == SPI1INTFbits.TCZIF)
	{
		// Write input data to SPI transmit buffer register
		SPI1TXB = *bufferTransmit;
		while(!PIR3bits.SPI1RXIF)
		{
			// Wait on receive interrupt flag to be set
        };
		
		// Store received data  from receive buffer register 
		*bufferReceive = SPI1RXB;		
		bufferReceive++;
		bufferTransmit++;
	}
}
void SPI1_BufferExchange(void *bufferData, size_t bufferSize)
{
	uint8_t* bufferInput = bufferData;

    SPI1STATUSbits.CLRBF = 1U;

	// Clear the TCZIF interrupt flag
	SPI1INTFbits.TCZIF = 0U;

	// Set as full duplex mode for buffer exchange operation
    SPI1CON2 = (SPI1CON2 | _SPI1CON2_SPI1RXR_MASK) | _SPI1CON2_SPI1TXR_MASK;
	
	// Load the transfer count registers
	SPI1TCNTH = (uint8_t)(bufferSize>>8);
	SPI1TCNTL = (uint8_t)(bufferSize);	
	
	while(0U == SPI1INTFbits.TCZIF)
	{
		// Write input data to SPI transmit buffer register
		SPI1TXB = *bufferInput;
		while(!PIR3bits.SPI1RXIF)
		{
			// Wait on receive interrupt flag to be set
        };
		
		// Store received data  from receive buffer register 
		*bufferInput = SPI1RXB;		
		bufferInput++;
	}
}

void SPI1_BufferWrite(void *bufferData, size_t bufferSize)
{
	uint8_t* bufferInput = bufferData;

	SPI1STATUSbits.CLRBF = 1U;

	// Clear the TCZIF interrupt flag
	SPI1INTFbits.TCZIF = 0U;

	// Set as transmit only mode for buffer write operation
    SPI1CON2 = (SPI1CON2 & ~_SPI1CON2_SPI1RXR_MASK) | _SPI1CON2_SPI1TXR_MASK;
   
	// Load the transfer count registers
	SPI1TCNTH = (uint8_t)(bufferSize>>8);
	SPI1TCNTL = (uint8_t)(bufferSize);

	
	while(0U == SPI1INTFbits.TCZIF)
	{
		// Write input data to SPI transmit buffer register
		SPI1TXB = *bufferInput;
		while(!PIR3bits.SPI1TXIF)
		{
			// Wait on transmit interrupt flag to be set
        };
		bufferInput++;
	}
}

void SPI1_BufferRead(void *bufferData, size_t bufferSize)
{
	uint8_t* bufferInput = bufferData;

	SPI1STATUSbits.CLRBF = 1U;

	// Clear the TCZIF interrupt flag
	SPI1INTFbits.TCZIF = 0U;

	// Set as receive only mode for buffer read operation
    SPI1CON2 = (SPI1CON2 & ~_SPI1CON2_SPI1TXR_MASK) | _SPI1CON2_SPI1RXR_MASK;
	
	// Load the transfer count registers
	SPI1TCNTH = (uint8_t)(bufferSize>>8);
	SPI1TCNTL = (uint8_t)(bufferSize);

	while(0U == SPI1INTFbits.TCZIF)
	{
		while(!PIR3bits.SPI1RXIF)
		{
            // Wait on receive interrupt flag to be set
        };

		// Store received data  from receive buffer register 
		*bufferInput = SPI1RXB;
		bufferInput++;
	}
}

uint8_t SPI1_ByteExchange(uint8_t byteData)
{
	uint8_t returnValue = 0U;
    
	SPI1STATUSbits.CLRBF = 1U;

	// Set as full duplex mode
	SPI1CON2 = SPI1CON2 | _SPI1CON2_SPI1RXR_MASK | _SPI1CON2_SPI1TXR_MASK;
	
	// Load the transfer count registers
	SPI1TCNTH = 0U;
	SPI1TCNTL = 1U;

	SPI1TXB = byteData;

	while(!PIR3bits.SPI1RXIF)
	{
		// Wait on receive interrupt flag to be set
    };
	returnValue = SPI1RXB;
	return returnValue;
}

void SPI1_ByteWrite(uint8_t byteData)
{	
	// Set as full duplex mode
	SPI1CON2 = SPI1CON2 | _SPI1CON2_SPI1RXR_MASK | _SPI1CON2_SPI1TXR_MASK;
	
	// Load the transfer count registers
	SPI1TCNTH = 0;
	SPI1TCNTL = 1;
	
	SPI1TXB = byteData;
}

uint8_t SPI1_ByteRead(void)
{
	uint8_t returnValue = 0x00U;
	
	// Set as full duplex mode
    SPI1CON2 = SPI1CON2 | _SPI1CON2_SPI1RXR_MASK | _SPI1CON2_SPI1TXR_MASK;
	
	// Store received data from receive buffer register 
	returnValue = SPI1RXB;	
	return returnValue;
}

bool SPI1_IsTxReady(void)
{
	bool returnValue = false;
	if(true == SPI1CON0bits.EN)
	{
		returnValue = PIR3bits.SPI1TXIF;
	}
	else 
	{
		returnValue = false;
	}
	return returnValue;
}

bool SPI1_IsRxReady(void)
{
	bool returnValue = false;
	
	if(true == SPI1CON0bits.EN)
    {
		returnValue = PIR3bits.SPI1RXIF;
    }
    else 
    {
        returnValue = false;
    }
    return returnValue;
}