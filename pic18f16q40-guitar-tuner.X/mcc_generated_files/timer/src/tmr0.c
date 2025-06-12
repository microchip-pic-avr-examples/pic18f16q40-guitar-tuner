/**
 * TMR0 Generated Driver File
 * 
 * @file tmr0.c
 * 
 * @ingroup tmr08bit
 * 
 * @brief  Driver implementation for the TMR0 driver
 *
 * @version TMR0 Driver Version 3.0.0
 *
 * @version Package Version 5.0.0
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
#include "../tmr0.h"

static void (*TMR0_PeriodMatchCallback)(void);
static void TMR0_DefaultCallback(void);

/**
  Section: TMR0 APIs
*/ 

void TMR0_Initialize(void)
{
    TMR0H = 0x37;                    // Period 112us; Frequency 500000 Hz; Count 55
    TMR0L = 0x0;
    
    T0CON1 = (5 << _T0CON1_T0CS_POSN)   // T0CS MFINTOSC
        | (0 << _T0CON1_T0CKPS_POSN)   // T0CKPS 1:1
        | (1 << _T0CON1_T0ASYNC_POSN);  // T0ASYNC not_synchronised
    
    TMR0_PeriodMatchCallback = TMR0_DefaultCallback;

    PIR3bits.TMR0IF = 0;

    T0CON0 = (0 << _T0CON0_T0OUTPS_POSN)   // T0OUTPS 1:1
        | (1 << _T0CON0_T0EN_POSN)   // T0EN enabled
        | (0 << _T0CON0_T0MD16_POSN);  // T0MD16 8-bit
}

void TMR0_Deinitialize(void)
{
    T0CON0bits.T0EN = 0;
    
    PIR3bits.TMR0IF = 0;	   
    PIE3bits.TMR0IE = 0;		
    
    T0CON0 = 0x0;
    T0CON1 = 0x0;
    TMR0H = 0xFF;
    TMR0L =0x0;
}

void TMR0_Start(void)
{
    T0CON0bits.T0EN = 1;
}

void TMR0_Stop(void)
{
    T0CON0bits.T0EN = 0;
}

uint8_t TMR0_CounterGet(void)
{
    uint8_t counterValue;

    counterValue = TMR0L;

    return counterValue;
}

void TMR0_CounterSet(uint8_t counterValue)
{
    TMR0L = counterValue;
 }

void TMR0_PeriodSet(uint8_t periodValue)
{
   TMR0H = periodValue;
}

uint8_t TMR0_PeriodGet(void)
{
    return TMR0H;
}

uint8_t TMR0_MaxCountGet(void)
{
    return TMR0_MAX_COUNT;
}

bool TMR0_PeriodMatchStatusGet(void)
{
    return PIR3bits.TMR0IF;
}

void TMR0_PeriodMatchStatusClear(void)
{
    PIR3bits.TMR0IF = 0;
}

void TMR0_Tasks(void)
{
    if(1U == PIR3bits.TMR0IF)
    {
        if(NULL != TMR0_PeriodMatchCallback)
        {
            TMR0_PeriodMatchCallback();
        }
        PIR3bits.TMR0IF = 0;
    }
}

void TMR0_PeriodMatchCallbackRegister(void (* callbackHandler)(void))
{
    TMR0_PeriodMatchCallback = callbackHandler;
}

static void TMR0_DefaultCallback(void)
{
    // Default callback
}