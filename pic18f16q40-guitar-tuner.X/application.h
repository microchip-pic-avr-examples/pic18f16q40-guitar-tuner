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
#include "mcc_generated_files/system/system.h"
#include "LCDMiniDrivers/lcd.h"
#include <stdint.h>
#include <stdbool.h>

    /*
     Section: Variable Definitions
     */

    uint8_t rawData[512];

    /**
     *Summary
      This routine is used to setup the LCD and and display the initial text on the LCD.
     */
    void Display_Splash(void);

    /**
      @Summary
        This routine is used to calculate the frequency of the musical note that is being played and print it on the LCD.
     */
    void Note_Read(void);



#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */

