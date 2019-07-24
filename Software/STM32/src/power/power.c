/*-------------------------------------------------------------------------------------------------------------------------------------------
 * power.c - power routines for LED stripes
 *
 * Copyright (c) 2016-2018 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *-------------------------------------------------------------------------------------------------------------------------------------------
 */

#if defined (STM32F10X)
#include "stm32f10x.h"
#elif defined (STM32F4XX)
#include "stm32f4xx.h"
#endif
#include "power.h"
#include "io.h"
#include "log.h"
#include "delay.h"
#include "wclock24h-config.h"
#include "display.h"

#if defined (STM32F4XX)                                         // STM32F4xx Nucleo Board PC8
#define POWER_PERIPH_CLOCK_CMD  RCC_AHB1PeriphClockCmd
#define POWER_PERIPH            RCC_AHB1Periph_GPIOC
#define POWER_PORT              GPIOC
#define POWER_PIN               GPIO_Pin_8
#define POWER_PIN_ALL           POWER_PIN

#elif defined (STM32F103)
#define POWER_PERIPH_CLOCK_CMD  RCC_APB2PeriphClockCmd          // STM32F103 PB0
#define POWER_PERIPH            RCC_APB2Periph_GPIOB
#define POWER_PORT              GPIOB
//#define POWER_PIN               GPIO_Pin_0
#define POWER_PIN1              GPIO_Pin_3
#define POWER_PIN2              GPIO_Pin_4
#define POWER_PIN3              GPIO_Pin_15
#define POWER_PIN4              GPIO_Pin_13
#define POWER_PIN5              GPIO_Pin_12
#define POWER_PIN6              GPIO_Pin_14
#define POWER_PIN_ALL           POWER_PIN1|POWER_PIN2|POWER_PIN3|POWER_PIN4|POWER_PIN5|POWER_PIN6

#else
#error STM32 unknown
#endif

#define POWER_ON_DELAY          42

POWER_GLOBALS                   power =
{
    0xFF                                                        // power.is_on
};

/*-------------------------------------------------------------------------------------------------------------------------------------------
 * initialize power port
 *-------------------------------------------------------------------------------------------------------------------------------------------
 */
void
power_init (void)
{
    GPIO_InitTypeDef gpio;

    GPIO_StructInit (&gpio);
    POWER_PERIPH_CLOCK_CMD (POWER_PERIPH, ENABLE);     // enable clock for power port

    GPIO_RESET_BIT(POWER_PORT, POWER_PIN_ALL);  //set output register low before init

    gpio.GPIO_Pin   = POWER_PIN_ALL;
    gpio.GPIO_Speed = GPIO_Speed_2MHz;

#if defined (STM32F10X)
    gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
#elif defined (STM32F4XX)
    gpio.GPIO_Mode  = GPIO_Mode_OUT;
    gpio.GPIO_OType = GPIO_OType_PP;
    gpio.GPIO_PuPd  = GPIO_PuPd_NOPULL;
#endif

    GPIO_Init(POWER_PORT, &gpio);
    log_message ("power_init() called");
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
 * switch power on
 *-------------------------------------------------------------------------------------------------------------------------------------------
 */
void
power_on (void)
{
    if (power.is_on != 1)
    {
        //all at the same time
        //GPIO_SET_BIT(POWER_PORT, POWER_PIN_ALL);

        //step by step with delay
        delay_init(0);
        GPIO_SET_BIT(POWER_PORT, POWER_PIN1);
        led_refresh(DSP_DISPLAY_LED_OFFSET+3*WC_ROWS);
        delay_msec(POWER_ON_DELAY);
        GPIO_SET_BIT(POWER_PORT, POWER_PIN2);
        led_refresh(DSP_DISPLAY_LED_OFFSET+6*WC_ROWS);
        delay_msec(POWER_ON_DELAY);
        GPIO_SET_BIT(POWER_PORT, POWER_PIN3);
        led_refresh(DSP_DISPLAY_LED_OFFSET+9*WC_ROWS);
        delay_msec(POWER_ON_DELAY);
        GPIO_SET_BIT(POWER_PORT, POWER_PIN4);
        led_refresh(DSP_DISPLAY_LED_OFFSET+13*WC_ROWS);
        delay_msec(POWER_ON_DELAY);
        GPIO_SET_BIT(POWER_PORT, POWER_PIN5);
        led_refresh(DSP_DISPLAY_LED_OFFSET+16*WC_ROWS);
        delay_msec(POWER_ON_DELAY);
        GPIO_SET_BIT(POWER_PORT, POWER_PIN6);
        led_refresh(DSP_DISPLAY_LED_OFFSET+19*WC_ROWS);

        log_message ("switching power on");
        power.is_on = 1;
    }
}

/*-------------------------------------------------------------------------------------------------------------------------------------------
 * switch power off
 *-------------------------------------------------------------------------------------------------------------------------------------------
 */
void
power_off (void)
{
    if (power.is_on != 0)
    {
        GPIO_RESET_BIT(POWER_PORT, POWER_PIN_ALL);//POWER_PIN);
        log_message ("switching power off");
        power.is_on = 0;
    }
}
