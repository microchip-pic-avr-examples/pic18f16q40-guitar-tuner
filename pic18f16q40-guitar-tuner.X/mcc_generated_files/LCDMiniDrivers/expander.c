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

#include <stdint.h>
#include "../pin_manager.h"
#include "../drivers/spi_master.h"


#define IODIRB 0x01
#define OLATB 0x15
#define WRITE_BYTE 0b01000000

void expander_sendByte(uint8_t addr, uint8_t byte){
    spi_master_open(LCD);
    LATCbits.LATC6 = 0; /* set LCDMini_nCS output low */
    uint8_t cmd[3];
    cmd[0] = WRITE_BYTE;
    cmd[1] = addr;
    cmd[2] = byte;
    SPI1_WriteBlock(cmd, 3);
    LATCbits.LATC6 = 1; /* set LCDMini_nCS output high */
    SPI1_Close();
}

void expander_setup(void){
    expander_sendByte(IODIRB, 0);
}

void expander_setOutput(uint8_t output){
    expander_sendByte(OLATB, output);
}
