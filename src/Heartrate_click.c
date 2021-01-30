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
#include "heartrate_click.h"

/**
  Section: Variable Definitions
 */

uint8_t heartrate_initialized = 0;

/**
  Section: Private function prototypes
 */

void HeartRate_initializeClick(void);

/**
  Section: Driver APIs
 */

void HeartRate_readSensors(void)
{
	if (!heartrate_initialized) {
		HeartRate_initializeClick();
	}
	MAX30100_readSensors();
}

uint16_t HeartRate_getIRdata(void)
{
	return MAX30100_getIRdata();
}

uint16_t HeartRate_getREDdata(void)
{
	return MAX30100_getREDdata();
}

float HeartRate_getTemperature(void)
{
	if (!heartrate_initialized) {
		HeartRate_initializeClick();
	}

	MAX30100_readTemp();
	return MAX30100_getTemp();
}

void HeartRate_initializeClick(void)
{
	MAX30100_setSpo2RdyInterrupt(SPO2_INTERRUPT_EN);
	MAX30100_setHrRdyInterrupt(HR_INTERRUPT_EN);
	MAX30100_setTempRdyInterrupt(TEMP_INTERRUPT_EN);
	MAX30100_setFifoAfullInterrupt(FIFO_INTERRUPT_EN);

	MAX30100_setMode(DEFAULT_MODE);
	MAX30100_setHiResEnabled(DEFAULT_HIRES_SET);
	MAX30100_setSampleRate(DEFAULT_SAMP_RATE);
	MAX30100_setPulseWidth(DEFAULT_PWIDTH);
	MAX30100_setIRLEDCurrent(DEFAULT_IR_CURRENT);
	MAX30100_setREDLEDCurrent(DEFAULT_RED_CURRENT);

	MAX30100_initializeSensor();

	heartrate_initialized = 1;
}
