/* 
 * File:   application.h
 * Author: C50931
 *
 * Created on June 22, 2020, 3:23 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pwm1_16bit.h"
#include "mcc_generated_files/LCDMiniDrivers/lcd.h"
#include <stdint.h>
#include <stdbool.h>

    /*
     Section: Variable Definitions
     */

    bool samplingDone = false;


    /*
     Section: Macro Declaration
     */

    /**
     *Summary
      This routine is used to setup the LCD and and display the initial text on the LCD.
     */
    Display_Print_Splash(void);

    /**
      @Summary
        This routine is used to read and print the note on LCD and setup the DMA for the next set of transfer.
     */
    void Note_Print(void);

    /**
      @Summary
        This routine is used to calculate the frequency of the musical note that is being played and print it on the LCD.
     */
    void Note_Read(void);

    /**
      @Summary
        This routine is used to display the musical note representing the measured frequency on the LCD.
     
      @param
        input_freq
     */
    void Note_Display(float input_freq);

    /**
      @Summary
        This routine is used to control what happens at the time of the DMA interrupt.
     */
    void DMA1_CustomISR(void);

#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */

