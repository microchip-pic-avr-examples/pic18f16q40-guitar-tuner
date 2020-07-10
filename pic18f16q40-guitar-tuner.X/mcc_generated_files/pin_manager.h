/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
        Device            :  PIC18F16Q40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LCDMini_nReset aliases
#define LCDMini_nReset_TRIS                 TRISAbits.TRISA4
#define LCDMini_nReset_LAT                  LATAbits.LATA4
#define LCDMini_nReset_PORT                 PORTAbits.RA4
#define LCDMini_nReset_WPU                  WPUAbits.WPUA4
#define LCDMini_nReset_OD                   ODCONAbits.ODCA4
#define LCDMini_nReset_ANS                  ANSELAbits.ANSELA4
#define LCDMini_nReset_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LCDMini_nReset_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LCDMini_nReset_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LCDMini_nReset_GetValue()           PORTAbits.RA4
#define LCDMini_nReset_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LCDMini_nReset_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LCDMini_nReset_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LCDMini_nReset_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LCDMini_nReset_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LCDMini_nReset_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LCDMini_nReset_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define LCDMini_nReset_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSELB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB6 procedures
#define RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define RB6_GetValue()              PORTBbits.RB6
#define RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define RB6_SetPullup()             do { WPUBbits.WPUB6 = 1; } while(0)
#define RB6_ResetPullup()           do { WPUBbits.WPUB6 = 0; } while(0)
#define RB6_SetAnalogMode()         do { ANSELBbits.ANSELB6 = 1; } while(0)
#define RB6_SetDigitalMode()        do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set MIC_Input aliases
#define MIC_Input_TRIS                 TRISBbits.TRISB7
#define MIC_Input_LAT                  LATBbits.LATB7
#define MIC_Input_PORT                 PORTBbits.RB7
#define MIC_Input_WPU                  WPUBbits.WPUB7
#define MIC_Input_OD                   ODCONBbits.ODCB7
#define MIC_Input_ANS                  ANSELBbits.ANSELB7
#define MIC_Input_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define MIC_Input_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define MIC_Input_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define MIC_Input_GetValue()           PORTBbits.RB7
#define MIC_Input_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define MIC_Input_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define MIC_Input_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define MIC_Input_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define MIC_Input_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define MIC_Input_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define MIC_Input_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define MIC_Input_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set LCDMini_nCS2 aliases
#define LCDMini_nCS2_TRIS                 TRISCbits.TRISC2
#define LCDMini_nCS2_LAT                  LATCbits.LATC2
#define LCDMini_nCS2_PORT                 PORTCbits.RC2
#define LCDMini_nCS2_WPU                  WPUCbits.WPUC2
#define LCDMini_nCS2_OD                   ODCONCbits.ODCC2
#define LCDMini_nCS2_ANS                  ANSELCbits.ANSELC2
#define LCDMini_nCS2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LCDMini_nCS2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LCDMini_nCS2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LCDMini_nCS2_GetValue()           PORTCbits.RC2
#define LCDMini_nCS2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LCDMini_nCS2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LCDMini_nCS2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LCDMini_nCS2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LCDMini_nCS2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LCDMini_nCS2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LCDMini_nCS2_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define LCDMini_nCS2_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set LCDMini_nCS aliases
#define LCDMini_nCS_TRIS                 TRISCbits.TRISC6
#define LCDMini_nCS_LAT                  LATCbits.LATC6
#define LCDMini_nCS_PORT                 PORTCbits.RC6
#define LCDMini_nCS_WPU                  WPUCbits.WPUC6
#define LCDMini_nCS_OD                   ODCONCbits.ODCC6
#define LCDMini_nCS_ANS                  ANSELCbits.ANSELC6
#define LCDMini_nCS_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LCDMini_nCS_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LCDMini_nCS_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LCDMini_nCS_GetValue()           PORTCbits.RC6
#define LCDMini_nCS_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LCDMini_nCS_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LCDMini_nCS_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LCDMini_nCS_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LCDMini_nCS_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define LCDMini_nCS_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define LCDMini_nCS_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define LCDMini_nCS_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/