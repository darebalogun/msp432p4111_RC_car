/*
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       MSP_EXP432P4111.h
 *
 *  @brief      MSP_EXP432P4111 Board Specific APIs
 *
 *  The MSP_EXP432P4111 header file should be included in an application as
 *  follows:
 *  @code
 *  #include <MSP_EXP432P4111.h>
 *  @endcode
 *
 *  ============================================================================
 */
#ifndef __MSP_EXP432P4111_H
#define __MSP_EXP432P4111_H

#ifdef __cplusplus
extern "C" {
#endif

/* LEDs on MSP_EXP432P4111 are active high. */
#define MSP_EXP432P4111_GPIO_LED_OFF (0)
#define MSP_EXP432P4111_GPIO_LED_ON  (1)

/*!
 *  @def    MSP_EXP432P4111_ADCName
 *  @brief  Enum of ADC channels on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_ADCName
{
    MSP_EXP432P4111_ADC0 = 0,
    MSP_EXP432P4111_ADC1,

    MSP_EXP432P4111_ADCCOUNT
} MSP_EXP432P4111_ADCName;

/*!
 *  @def    MSP_EXP432P4111_ADCBufName
 *  @brief  Enum of ADC hardware peripherals on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_ADCBufName
{
    MSP_EXP432P4111_ADCBUF0 = 0,

    MSP_EXP432P4111_ADCBUFCOUNT
} MSP_EXP432P4111_ADCBufName;

/*!
 *  @def    MSP_EXP432P4111_ADCBuf0ChannelName
 *  @brief  Enum of ADCBuf channels on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_ADCBuf0ChannelName
{
    MSP_EXP432P4111_ADCBUF0CHANNEL0 = 0,
    MSP_EXP432P4111_ADCBUF0CHANNEL1,

    MSP_EXP432P4111_ADCBUF0CHANNELCOUNT
} MSP_EXP432P4111_ADCBuf0ChannelName;

/*!
 *  @def    MSP_EXP432P4111_CaptureName
 *  @brief  Enum of Capture timer names on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_CaptureName
{
    MSP_EXP432P4111_CAPTURE_TA1 = 0,
    MSP_EXP432P4111_CAPTURE_TA2,
    MSP_EXP432P4111_CAPTURE_TA3,

    MSP_EXP432P4111_CAPTURECOUNT
} MSP_EXP432P4111_CaptureName;

/*!
 *  @def    MSP_EXP432P4111_GPIOName
 *  @brief  Enum of GPIO names on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_GPIOName
{
    MSP_EXP432P4111_GPIO_S1 = 0,
    MSP_EXP432P4111_GPIO_S2,
    MSP_EXP432P4111_HOST_IRQ,
    MSP_EXP432P4111_GPIO_LED1,
    MSP_EXP432P4111_GPIO_LED_RED,
    MSP_EXP432P4111_GPIO_LED_GREEN,
    MSP_EXP432P4111_GPIO_LED_BLUE,
    MSP_EXP432P4111_nHIB_pin,
    MSP_EXP432P4111_CS_pin,
    MSP_EXP432P4111_SPI_CS1,
    MSP_EXP432P4111_SPI_CS2,

    MSP_EXP432P4111_GPIOCOUNT
} MSP_EXP432P4111_GPIOName;

/*!
 *  @def    MSP_EXP432P4111_I2CName
 *  @brief  Enum of I2C names on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_I2CName
{
    MSP_EXP432P4111_I2CB0 = 0,
    MSP_EXP432P4111_I2CB1,

    MSP_EXP432P4111_I2CCOUNT
} MSP_EXP432P4111_I2CName;

/*!
 *  @def    MSP_EXP432P4111_I2CSlaveName
 *  @brief  Enum of I2CSlave names on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_I2CSlaveName
{
    MSP_EXP432P4111_I2CSLAVEB0 = 0,

    MSP_EXP432P4111_I2CSLAVECOUNT
} MSP_EXP432P4111_I2CSlaveName;

/*!
 *  @def    MSP_EXP432P4111_NVSName
 *  @brief  Enum of NVS names on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_NVSName
{
    MSP_EXP432P4111_NVSMSP4320 = 0,

    MSP_EXP432P4111_NVSCOUNT
} MSP_EXP432P4111_NVSName;

/*!
 *  @def    MSP_EXP432P4111_PWMName
 *  @brief  Enum of PWM names on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_PWMName
{
    MSP_EXP432P4111_PWM_TA1_1 = 0,
    MSP_EXP432P4111_PWM_TA1_2,

    MSP_EXP432P4111_PWMCOUNT
} MSP_EXP432P4111_PWMName;

/*!
 *  @def    MSP_EXP432P4111_SPIName
 *  @brief  Enum of SPI names on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_SPIName
{
    MSP_EXP432P4111_SPIB0 = 0,
    MSP_EXP432P4111_SPIB2,
    MSP_EXP432P4111_SPIB3,
    MSP_EXP432P4111_SPIB4,

    MSP_EXP432P4111_SPICOUNT
} MSP_EXP432P4111_SPIName;

/*!
 *  @def    MSP_EXP432P4111_TimerName
 *  @brief  Enum of Timer names on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_TimerName
{
    MSP_EXP432P4111_TIMER_T32_0 = 0,
    MSP_EXP432P4111_TIMER_T32_1,
    MSP_EXP432P4111_TIMER_TA_1,
    MSP_EXP432P4111_TIMER_TA_2,
    MSP_EXP432P4111_TIMER_TA_3,

    MSP_EXP432P4111_TIMERCOUNT
} MSP_EXP432P4111_TimerName;

/*!
 *  @def    MSP_EXP432P4111_UARTName
 *  @brief  Enum of UART names on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_UARTName
{
    MSP_EXP432P4111_UARTA0 = 0,
    MSP_EXP432P4111_UARTA2,

    MSP_EXP432P4111_UARTCOUNT
} MSP_EXP432P4111_UARTName;

/*!
 *  @def    MSP_EXP432P4111_WatchdogName
 *  @brief  Enum of Watchdog names on the MSP_EXP432P4111 dev board
 */
typedef enum MSP_EXP432P4111_WatchdogName
{
    MSP_EXP432P4111_WATCHDOG = 0,

    MSP_EXP432P4111_WATCHDOGCOUNT
} MSP_EXP432P4111_WatchdogName;

/*!
 *  @brief  Initialize the general board specific settings
 *
 *  This function initializes the general board specific settings.
 */
extern void MSP_EXP432P4111_initGeneral(void);

#ifdef __cplusplus
}
#endif

#endif /* __MSP_EXP432P4111_H */
