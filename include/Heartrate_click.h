/**
 * \file
 *
 *
 (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

#ifndef _HEARTRATE_H
#define _HEARTRATE_H

/**
  Section: Included Files
 */

#include "max30100.h"

/**
  Section: Macro Declarations
 */

#define DEFAULT_MODE MAX30100_SPO2_EN

#define DEFAULT_HIRES_SET ENABLED

#define DEFAULT_SAMP_RATE MAX30100_SR200

#define DEFAULT_PWIDTH MAX30100_PW400

#define DEFAULT_IR_CURRENT MAX30100_I7

#define DEFAULT_RED_CURRENT MAX30100_I7

#define SPO2_INTERRUPT_EN ENABLED

#define HR_INTERRUPT_EN ENABLED

#define TEMP_INTERRUPT_EN ENABLED

#define FIFO_INTERRUPT_EN ENABLED

#define HeartRate_setMode(mode) MAX30100_setMode(mode)
#define HeartRate_setHiResEnabled(hiResEnable) MAX30100_setHiResEnabled(hiResEnable)
#define HeartRate_setSampleRate(sampRate) MAX30100_setSampleRate(sampRate)
#define HeartRate_setPulseWidth(pWidth) MAX30100_setPulseWidth(pWidth)
#define HeartRate_setLEDCurrent(irCurrent, redCurrent) MAX30100_setLEDCurrent(irCurrent, redCurrent)
#define HeartRate_updateSensorConfig() MAX30100_updateSensorConfig()
#define HeartRate_updateLedCurrent() MAX30100_updateLEDCurrent()
#define HeartRate_updateEnabledInterrupt() MAX30100_updateEnabledInterrupt()

/**
  Section: Driver APIs
 */

void     HeartRate_readSensors(void);
uint16_t HeartRate_getIRdata(void);
uint16_t HeartRate_getREDdata(void);
float    HeartRate_getTemperature(void);

#endif // _HEARTRATE_H
