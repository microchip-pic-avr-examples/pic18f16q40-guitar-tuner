 /*
     (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#include "../mcc_generated_files/system/system.h"
#include <stdbool.h>
#include "expander.h"
#include "digipot.h"

#define HD44780_INSTRUCTION 0
#define HD44780_DATA 1

void lcd_sendNibble(uint8_t nibble, uint8_t RSbit){
    uint8_t packet = (uint8_t)((nibble << 4) | (RSbit << 2));
    expander_setOutput(packet);
    expander_setOutput(packet | (1<<3));
    __delay_us(1);
    expander_setOutput(packet);
}

void lcd_sendByte(uint8_t byte, uint8_t RSbit){
    uint8_t nibbleHigh = byte >> 4;
    uint8_t nibbleLow = byte & 0xF;
    uint8_t packetHigh = (uint8_t)((nibbleHigh << 4) | (RSbit << 2));
    uint8_t packetLow = (uint8_t)((nibbleLow << 4) | (RSbit << 2));
    
    expander_setOutput(packetHigh);
    expander_setOutput(packetHigh | (1<<3));
    __delay_us(1);
    expander_setOutput(packetLow);
    __delay_us(1);
    expander_setOutput(packetLow | (1<<3));
}

void lcd_returnHome(void){
    lcd_sendByte(0b10, false);
}

void lcd_clearDisplay(void){
    lcd_sendByte(0b1, false);
}

void lcd_setAddr(uint8_t row, uint8_t character){
    lcd_sendByte(0x80 | (character + (row*40)), false);
}

void lcd_writeChar(uint8_t character){
    lcd_sendByte(character, HD44780_DATA);
}

void lcd_writeString(char * string, uint8_t len, uint8_t row) {
    lcd_setAddr(row, 0);
    __delay_us(60);
    uint8_t i = 0;
    for (i = 0; i < len; i++) {
        lcd_writeChar(string[i]);
        __delay_us(60);
    }
}

void lcd_setContrast(uint8_t contrast){
    digipot_setWiper(contrast);
}

void lcd_setup(){
    LCDMini_nCS_SetHigh(); 
    LCDMini_nCS2_SetHigh();
    LCDMini_nReset_SetHigh();
    expander_setup();
    expander_setOutput(0);
    __delay_ms(40);
    lcd_sendNibble(0x3, HD44780_INSTRUCTION);
    __delay_ms(5);
    lcd_sendNibble(0x3, HD44780_INSTRUCTION);
    __delay_us(100);
    lcd_sendNibble(0x3, HD44780_INSTRUCTION);
    __delay_ms(10);
    lcd_sendNibble(0x2,HD44780_INSTRUCTION);
    lcd_sendByte(0x2C, HD44780_INSTRUCTION);
    __delay_ms(5);
    lcd_sendByte(0xC, HD44780_INSTRUCTION);
    __delay_ms(5);
    lcd_sendByte(0x06, HD44780_INSTRUCTION);
    __delay_ms(5);
    lcd_sendByte(0x0C, HD44780_INSTRUCTION);
    __delay_ms(5);
    lcd_returnHome();
    __delay_ms(5);
    lcd_clearDisplay();
    __delay_ms(5);
}
