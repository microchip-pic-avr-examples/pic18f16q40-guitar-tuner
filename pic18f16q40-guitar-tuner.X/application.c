/*
 * File:   application.c
 * Author: C50931
 *
 * Created on June 22, 2020, 3:22 PM
 */

#include "application.h"
#include "frequencyTable.h"
#include "noteTable.h"
#include <string.h>

/*
 Section: Variable Definitions
 */

#define NUM_ADC_SAMPLES 512
#define NUM_AUTOCORRELATION_SAMPLES 128


struct dv_struct_t {
    uint8_t trigger;
    int8_t sample;
    int32_t correlationSample;
};


int8_t offsetCorrectedData[NUM_ADC_SAMPLES] = { 0 };
int32_t autocorrelation_buffer[NUM_ADC_SAMPLES] =  { 0 };
struct dv_struct_t dv_data;


void autocorrelation(int8_t * data, int32_t * autocorrelation_values, uint16_t len);
uint16_t find_highest_peak(int32_t * values, uint16_t len, int32_t peakThreshold);
void offsetCorrectData(uint8_t * data, int8_t * correctedData, uint8_t average, uint16_t len);
uint8_t averageData(uint8_t * data, uint16_t len );
void sendDebugData(void);
void DV_Send(struct dv_struct_t * dv_data, uint8_t len);



void Display_Splash(void) {
    PWM1_16BIT_SetSlice1Output1DutyCycleRegister(70); // Setting LCD Brightness to 70%
    PWM1_16BIT_LoadBufferRegisters();
    lcd_writeString("  PIC18F16Q40   ",16, 0);    
    lcd_writeString("  Guitar Tuner  ",16, 1);
    __delay_ms(3000); // Hold Splash Screen;
    lcd_returnHome();
    __delay_ms(2);
    lcd_clearDisplay(); 
    __delay_ms(2);
    lcd_writeString("Play a string! ",15, 0);
}

void Note_Read(void) {
    
    /* 
     * The average is calculated for the entire array of samples and this value
     * is subtracted from each sample. This removes any DC offset that could 
     * cause inaccuracies in the autocorrelation calculation. The offset corrected
     * data is saved in a different array in memory
     */
    uint8_t average = averageData(rawData, NUM_ADC_SAMPLES);
    offsetCorrectData(rawData, offsetCorrectedData, average, NUM_ADC_SAMPLES);    
    
    /* 
     * Once the offset corrected data has been saved, DMA can be used to get
     * another set of samples while the autocorrelation is calculated
     */
    DMA1_TransferWithTriggerStart(); 
    
    autocorrelation(offsetCorrectedData, autocorrelation_buffer, NUM_AUTOCORRELATION_SAMPLES); 
    
#ifdef DEBUG
    sendDebugData();
#endif   
    
    uint16_t period = find_highest_peak(autocorrelation_buffer, NUM_AUTOCORRELATION_SAMPLES, 2000);
    
    char noteString[16];
    char freqString[16];
    
    if( period == 0 ) {
        lcd_writeString("Play a string! ", 15, 0);
        lcd_writeString("               ",15,1);
    }
    else {
        // make the string to display the current note being played
        strcpy(noteString, "Note: ");
        strcat(noteString, noteTable[period]);
        strcat(noteString, "       ");

        // make the string to display the frequency of the current note
        strcpy(freqString,"f= ");
        strcat(freqString, frequencyTable[period]);
        strcat(freqString, "Hz  ");

        lcd_writeString(noteString,15,0);
        lcd_writeString(freqString,15, 1);
    }    
}


uint16_t find_highest_peak(int32_t * values, uint16_t len, int32_t peakThreshold ) {
    
    
    uint16_t peak = 0;
    int32_t amplitude = 0;    

    for(uint16_t i=1; i < (len -1); i++) {
        
        if( (values[i] > values[i-1]) && (values[i] > values[i+1]) ) {
            if ( values[i] > amplitude ){
                peak = i;
                amplitude = values[i];
            }
        }
    }
    
    if( amplitude < peakThreshold ) {
        peak = 0;
    }
    
    return peak;
}

void autocorrelation(int8_t * data, int32_t * autocorrelation_values, uint16_t len) {
    for (uint16_t i = 0; i < len; i++) {
        
        int32_t sum = 0;
        
        for (uint16_t k = 0; k < NUM_ADC_SAMPLES - i; k++) {
            sum += (int32_t)( data[k] * data[k + i] );
        }
        
        autocorrelation_values[i] = sum;
    }
}

void offsetCorrectData(uint8_t * data, int8_t * correctedData, uint8_t average, uint16_t len) {
    
    uint16_t i = 0;
    while( i < len){ 
        correctedData[i] = (int8_t)( data[i] - average );
        i++;
    }    
}

uint8_t averageData(uint8_t * data, uint16_t len) {
    uint32_t accumulator = 0;
    
    for( uint16_t i=0; i<len; i++) {
        accumulator += data[i];
    }
    
    return (uint8_t)( accumulator / len );   
}

void DV_Send( struct dv_struct_t * dv_data, uint8_t len) {
    
    uint8_t * ptr = (uint8_t *)(dv_data);
    uint8_t i = 0;
    
    putch(0x33);
    while( i++ < len ) {
        putch(*ptr++);
    }
    putch(0xcc);
}

void sendDebugData(void) {
    uint8_t trigger = 0;
    for(uint16_t i=0; i<NUM_ADC_SAMPLES; i++) {
        if( i == 0) trigger = 1;
        else trigger = 0;
        dv_data.trigger = trigger;
        dv_data.sample = offsetCorrectedData[i];
        dv_data.correlationSample = autocorrelation_buffer[i];
        DV_Send(&dv_data, sizeof(dv_data));
    }
}