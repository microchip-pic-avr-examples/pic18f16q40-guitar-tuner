/*
 * File:   application.c
 * Author: C50931
 *
 * Created on June 22, 2020, 3:22 PM
 */

#include "application.h"

/*
 Section: Variable Definitions
 */
#define E4 329.63
#define EL4 E4 - 5
#define EH4 E4 + 5

#define B3 246.94
#define BL3 B3 - 5
#define BH3 B3 + 5

#define G3 196
#define GL3 G3 - 5
#define GH3 G3 + 5

#define D3 146.83
#define DL3 D3 - 5
#define DH3 D3 + 5

#define A2 110
#define AL2 A2 - 5
#define AH2 A2 + 5

#define E2 82.41
#define EL2 E2 - 5
#define EH2 E2 + 5

#define NOTE_POSITION 6

#define LENGTH 512

extern uint8_t rawData[512];

const float sample_freq = 9137; // The sampling frequency is around 8900, considering the CPU and other peripheral, this number can be changed to optimize the calculation for the best result.

int16_t period = 0;
uint8_t p_status_chk = 0;
int32_t new_sum;
int32_t prev_sum;
int16_t thld = 0;
float frequency = 0;

/*
 Section: Driver APIs
 */

Display_Print_Splash(void) {
    PWM1_16BIT_SetSlice1Output1DutyCycleRegister(70); // Setting LCD Brightness to 70%
    PWM1_16BIT_LoadBufferRegisters();
    lcd_setContrast(0x40); // LCD Contrast
    lcd_writeString("  PIC18F16Q40   ", 0);
    lcd_writeString("  Guitar Tuner  ", 1);
    __delay_ms(3000); // Hold Splash Screen;
    lcd_returnHome();
    lcd_clearDisplay(); // Clear the LCD
    lcd_writeString("Play a string! ", 0);
}

void Note_Print(void) {
    Note_Read();
    samplingDone = false;
    DMA1_StartTransferWithTrigger(); //Start the next set of DMA transfer
}

void Note_Read(void) {
    new_sum = 0;
    p_status_chk = 0;
    period = 0;
    for (uint16_t i = 0; i < LENGTH; i++) {
        // Autocorrelation
        prev_sum = new_sum;
        new_sum = 0;
        for (uint16_t k = 0; k < LENGTH - i; k++) {
            new_sum += ((rawData[k] - 128)*(rawData[k + i] - 128)) >> 8;
        }
        // Peak Detect State Machine
        if ((p_status_chk == 2) && (new_sum <= prev_sum)) {
            period = i;
            p_status_chk = 3;
        }
        if ((p_status_chk == 1) && (new_sum > thld) && (new_sum > prev_sum)) {
            p_status_chk = 2;
        }
        if (i == 0) {
            thld = new_sum >> 1;
            p_status_chk = 1;
        }
    }
    // Frequency identified in Hz
    if (thld > 100) {
        frequency = sample_freq / period;
        Note_Display(frequency); // Call Note Display function
    }
}

void Note_Display(float input_freq) {
    bool note_flag = true;
    char freq_str[16];
    char note_str[] = "Note:           ";

    if (EL4 < input_freq && input_freq <= EH4) {
        note_str[NOTE_POSITION] = 'E';
    } else if (BL3 < input_freq && input_freq <= BH3) {
        note_str[NOTE_POSITION] = 'B';
    } else if (GL3 < input_freq && input_freq <= GH3) {
        note_str[NOTE_POSITION] = 'G';
    } else if (DL3 < input_freq && input_freq <= DH3) {
        note_str[NOTE_POSITION] = 'D';
    } else if (AL2 < input_freq && input_freq <= AH2) {
        note_str[NOTE_POSITION] = 'A';
    } else if (EL2 < input_freq && input_freq <= EH2) {
        note_str[NOTE_POSITION] = 'E';
    } else {
        note_flag = false;
    }
    if (note_flag) {
        lcd_writeString(note_str, 0);
        printf("%s \r\n", note_str);

        sprintf(freq_str, "F= %.2f Hz    ", input_freq);
        lcd_writeString(freq_str, 1);
        printf("%s \r\n\n", freq_str);
    } else {
        lcd_clearDisplay(); // Clear the LCD
        lcd_writeString("Play a string! ", 0);
    }
}

void DMA1_CustomISR() {
    samplingDone = true;
}