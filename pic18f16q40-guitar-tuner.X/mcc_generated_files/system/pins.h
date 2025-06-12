/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 aliases
#define DEBUG_TRIS                 TRISAbits.TRISA2
#define DEBUG_LAT                  LATAbits.LATA2
#define DEBUG_PORT                 PORTAbits.RA2
#define DEBUG_WPU                  WPUAbits.WPUA2
#define DEBUG_OD                   ODCONAbits.ODCA2
#define DEBUG_ANS                  ANSELAbits.ANSELA2
#define DEBUG_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define DEBUG_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define DEBUG_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define DEBUG_GetValue()           PORTAbits.RA2
#define DEBUG_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define DEBUG_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define DEBUG_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define DEBUG_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define DEBUG_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define DEBUG_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define DEBUG_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define DEBUG_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA4 aliases
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

// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_OD                   ODCONBbits.ODCB6
#define IO_RB6_ANS                  ANSELBbits.ANSELB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RB6_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set RB7 aliases
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

// get/set RC2 aliases
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

// get/set RC4 aliases
#define IO_RC4_TRIS                 TRISCbits.TRISC4
#define IO_RC4_LAT                  LATCbits.LATC4
#define IO_RC4_PORT                 PORTCbits.RC4
#define IO_RC4_WPU                  WPUCbits.WPUC4
#define IO_RC4_OD                   ODCONCbits.ODCC4
#define IO_RC4_ANS                  ANSELCbits.ANSELC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_RC4_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define IO_RC4_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSELC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 aliases
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

// get/set RC7 aliases
#define IO_RC7_TRIS                 TRISCbits.TRISC7
#define IO_RC7_LAT                  LATCbits.LATC7
#define IO_RC7_PORT                 PORTCbits.RC7
#define IO_RC7_WPU                  WPUCbits.WPUC7
#define IO_RC7_OD                   ODCONCbits.ODCC7
#define IO_RC7_ANS                  ANSELCbits.ANSELC7
#define IO_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_RC7_GetValue()           PORTCbits.RC7
#define IO_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_RC7_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define IO_RC7_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define IO_RC7_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define IO_RC7_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define IO_RC7_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define IO_RC7_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/