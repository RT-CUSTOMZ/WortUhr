#if 0 // fm: later
/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * functions.c - internal functions of nic runtime system
 *
 * Copyright (c) 2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *---------------------------------------------------------------------------------------------------------------------------------------------------
 */
#include <stdio.h>
#include "nicstrings.h"
#include "nic.h"
#include "nici.h"
#include "functions.h"
#include "base.h"

#if defined (unix)
#include <time.h>
#include <sys/time.h>
#elif defined (WIN32)
#include <windows.h>
#include <time.h>
#else
#include "console.h"
#include "delay.h"
#endif

#define BIN     2
#define DEC     10
#define HEX     16

static int
printbin (uint32_t number, int tabulate)
{
    int     i;
    char    buf[32 + 1];
    int     len = 0;
    int     first_1 = 32;
    int     rtc = 0;

    buf[32] = '\0';

    for (i = 0; i < 32; i++)
    {
        if (number & 0x01)
        {
            buf[31 - i] = '1';
            first_1 = 31 - i;
            len = i + 1;
        }
        else
        {
            buf[31 - i] = '0';
        }

        number >>= 1;
    }

    while (tabulate > len)
    {
        con_putc ('0');
        tabulate--;
        rtc++;
    }

    con_puts (buf + first_1);
    rtc += 32 - first_1;

    return rtc;
}

static int
nici_console_print (FIP_RUN * fip)
{
    if (fip->argc >= 1 && fip->argc <= 3)
    {
        int             result;
        int             format;
        int             tabulation = 0;
        unsigned char * resultstr;
        int             type = get_argument (fip, 0, &resultstr, &result);

        if (type == RESULT_INT)                                             // argument is integer
        {
            format = DEC_FORMAT;                                            // default format is decimal
        }
        else if (type == RESULT_BYTE_ARRAY)
        {
            format = DEC_FORMAT;                                            // default format is decimal
        }
        else                                                                // argument is string
        {
            format = STR_FORMAT;                                            // default format is string
        }

        if (fip->argc >= 2)
        {
            format = get_argument_int (fip, 1);                             // overwrite format

            if (fip->argc >= 3)
            {
                tabulation = get_argument_int (fip, 2);                     // overwrite tabulation
            }
        }

        if (format == STR_FORMAT && type == RESULT_INT)                     // print an integer as string
        {
            resultstr = get_argument_string (fip, 0);                       // get int argument as string
            type = RESULT_CSTRING;                                          // patch type
        }
        else if (format != STR_FORMAT && type == RESULT_CSTRING)            // print a string as integer
        {
            result = get_argument_int (fip, 0);                             // get string argument as int
            type = RESULT_INT;                                              // patch type
        }

        if (type == RESULT_INT)
        {
            char    fmt[32];

            if (format == DEC_FORMAT)
            {
                sprintf (fmt, "%%%dd", tabulation);
                fip->reti = con_printf (fmt, result);
            }
            else if (format == DEC0_FORMAT)
            {
                sprintf (fmt, "%%0%dd", tabulation);
                fip->reti = con_printf (fmt, result);
            }
            else if (format == HEX_FORMAT)
            {
                sprintf (fmt, "%%0%dX", tabulation);
                fip->reti = con_printf (fmt, result);
            }
            else // if (format == BIN_FORMAT)
            {
                fip->reti = printbin (result, tabulation);
            }
        }
        else if (type == RESULT_BYTE_ARRAY)
        {
            char        fmt[32];
            uint8_t *   ptr;
            int         idx;

            if (format == DEC_FORMAT)
            {
                sprintf (fmt, "%%%dd", tabulation);

                for (idx = 0, ptr = resultstr; idx < result; idx++, ptr++)
                {
                    fip->reti = con_printf (fmt, *ptr);

                    if (idx < result - 1)
                    {
                        con_putc (' ');
                    }
                }
            }
            else if (format == DEC0_FORMAT)
            {
                sprintf (fmt, "%%0%dd", tabulation);

                for (idx = 0, ptr = resultstr; idx < result; idx++, ptr++)
                {
                    fip->reti = con_printf (fmt, *ptr);

                    if (idx < result - 1)
                    {
                        con_putc (' ');
                    }
                }
            }
            else if (format == HEX_FORMAT)
            {
                sprintf (fmt, "%%0%dX", tabulation);

                for (idx = 0, ptr = resultstr; idx < result; idx++, ptr++)
                {
                    fip->reti = con_printf (fmt, *ptr);

                    if (idx < result - 1)
                    {
                        con_putc (' ');
                    }
                }
            }
            else // if (format == BIN_FORMAT)
            {
                for (idx = 0, ptr = resultstr; idx < result; idx++, ptr++)
                {
                    fip->reti = printbin (result, tabulation);

                    if (idx < result - 1)
                    {
                        con_putc (' ');
                    }
                }
            }
        }
        else if (type == RESULT_CSTRING)
        {
            if (fip->argc >= 2)
            {
                format = get_argument_int (fip, 1);
            }

            if (fip->argc >= 3)
            {
                char    fmt[32];
                int     ltab = get_argument_int (fip, 2);

                sprintf (fmt, "%%%ds", ltab);
                fip->reti = con_printf (fmt, resultstr);
            }
            else
            {
                fip->reti = con_printf ("%s", resultstr);
            }
        }
    }
    else
    {
        fip->reti = 0;
    }

    return FUNCTION_TYPE_INT;
}

static int
nici_console_println (FIP_RUN * fip)
{
    int rtc;

    rtc = nici_console_print (fip);
    con_puts ("\r\n");
    fip->reti += 2;

    return rtc;
}

static int
nici_string_substring (FIP_RUN * fip)
{
    int slot;

    if (fip->argc >= 2 && fip->argc <= 3)
    {
        unsigned char * str = get_argument_string (fip, 0);
        int             pos = get_argument_int (fip, 1);
        int             len;
        unsigned char * s;

        len = ustrlen (str);

        if (pos < 0)
        {
            pos = len + pos;                                        // pos < 0: position from right!
        }

        if (pos < len)
        {
            s = str + pos;

            if (fip->argc == 3)
            {
                int n = get_argument_int (fip, 2);

                len = ustrlen (s);

                if (n < 0)                                          // n < 0: cut n chars from end
                {
                    n = len + n;
                }

                if (n < 0)
                {
                    slot = new_tmp_stringslot ((const unsigned char *) "");
                }
                else if (n < len)
                {
                    unsigned char ch = s[n];
                    s[n] = '\0';
                    slot = new_tmp_stringslot (s);
                    s[n] = ch;
                }
                else
                {
                    slot = new_tmp_stringslot (s);
                }
            }
            else
            {
                slot = new_tmp_stringslot (s);
            }
        }
        else
        {
            slot = new_tmp_stringslot ((const unsigned char *) "");
        }
    }
    else
    {
        slot = new_tmp_stringslot ((const unsigned char *) "");
    }

    fip->reti = slot;
    return FUNCTION_TYPE_STRING;
}


static int
nici_string_length (FIP_RUN * fip)
{
    int len = 0;

    if (fip->argc == 1)
    {
        unsigned char * str = get_argument_string (fip, 0);

        len = ustrlen (str);
    }

    fip->reti = len;
    return FUNCTION_TYPE_INT;
}

#if 000

#define MAX_ALARM_SLOTS     8
static int alarm_slots[MAX_ALARM_SLOTS];
static int alarm_start[MAX_ALARM_SLOTS];
static int alarm_functions[MAX_ALARM_SLOTS];
static int alarm_cnt[MAX_ALARM_SLOTS];
int alarm_slots_used = 0;

#if defined (unix) || defined (WIN32)

unsigned long       start_millis;

static unsigned long get_millis (void)
{
    unsigned long msec;
#if defined (unix)
    struct timeval tv;

    if (gettimeofday(&tv, NULL) != 0)
    {
        return 0;
    }

    msec = (unsigned long) ((tv.tv_sec * 1000ul) + (tv.tv_usec / 1000ul));

    if (start_millis == 0)
    {
        start_millis = msec;
    }
#else // if defined (WIN32)
    SYSTEMTIME time;
    GetSystemTime(&time);
    msec = (time.wSecond * 1000) + time.wMilliseconds;
#endif

    if (start_millis == 0)
    {
        start_millis = msec;
    }

    return msec - start_millis;
}
#endif

static int
nici_time_millis (FIP_RUN * fip)
{
#if defined (unix) || defined (WIN32)
    fip->reti = get_millis ();
#else
    fip->reti = millis;
#endif
    return FUNCTION_TYPE_INT;
}

static int
nici_time_reset (FIP_RUN * fip)
{
    if (fip->argc == 0)
    {
#if defined (unix) || defined (WIN32)
        start_millis = 0;
        get_millis ();                          // force setting of start_millis
#else
        millis = 0;
#endif
    }
    return FUNCTION_TYPE_VOID;
}

static int
nici_time_set (FIP_RUN * fip)
{
    if (fip->argc == 1)
    {
        int msec = get_argument_int (fip, 0);
#if defined (unix) || defined (WIN32)
        start_millis += get_millis() - msec;
#else
        millis = msec;
#endif
    }
    return FUNCTION_TYPE_VOID;
}

static int
nici_time_delay (FIP_RUN * fip)
{
    if (fip->argc == 1)
    {
#if defined (unix) || defined (WIN32)
        unsigned int msec = (unsigned int) get_argument_int (fip, 0) + get_millis ();

        while (get_millis () < msec)
        {
            ;
        }
#else
        int msec = get_argument_int (fip, 0);
        delay_msec (msec);
#endif
    }
    return FUNCTION_TYPE_VOID;
}

static int
nici_alarm_init (FIP_RUN * fip)
{
    int     slot = -1;

    if (fip->argc >= 1 && fip->argc <= 2)
    {
        if (alarm_slots_used < MAX_ALARM_SLOTS - 1)
        {
            int msec = get_argument_int (fip, 0);
            slot = alarm_slots_used;
            alarm_slots[slot] = msec;
#if defined (unix) || defined (WIN32)
            alarm_start[slot] = get_millis ();
#else
            alarm_start[slot] = alarm_millis;
#endif
            alarm_slots_used++;
        }

        if (fip->argc == 2)
        {
            alarm_functions[slot] = get_argument_int (fip, 1) + 1;
        }
        else
        {
            alarm_functions[slot] = 0;
        }
    }
    fip->reti = slot;
    return FUNCTION_TYPE_INT;
}

static int
check_alarms (int slot)
{
    int rtc = 0;

    if (alarm_cnt[slot] > alarm_slots[slot])
    {
        alarm_cnt[slot] -= alarm_slots[slot];
#if defined (unix) || defined (WIN32)
        alarm_start[slot] = get_millis ();
#else
        alarm_start[slot] = alarm_millis;
#endif
        rtc = 1;
    }

    return rtc;
}

void
update_alarm_timers ()
{
    int slot;

    if (alarm_slots_used)
    {
#if defined (unix) || defined (WIN32)
        unsigned long m = get_millis ();
#else
        unsigned long m = alarm_millis;
#endif

        for (slot = 0; slot < alarm_slots_used; slot++)
        {
            alarm_cnt[slot] = m - alarm_start[slot];

            if (alarm_functions[slot] > 0 && check_alarms (slot))           // execute only check_alarms(), if we have an alarm function in NIC script!
            {
                nici (alarm_functions[slot] - 1, (FIP_RUN *) NULL);
            }
        }
    }
}

static int
nici_alarm (FIP_RUN * fip)
{
    int rtc = 0;

    if (fip->argc == 1)
    {
        int slot = get_argument_int (fip, 0);

        if (slot < alarm_slots_used)
        {
            if (alarm_functions[slot] == 0)                             // execute only check_alarms(), if we have NOT an alarm function in NIC script!
            {
                rtc = check_alarms (slot);
            }
        }
    }
    fip->reti = rtc;
    return FUNCTION_TYPE_INT;
}

#endif // 000

#define INPUT_MODE      0
#define OUTPUT_MODE     1

#define IN_NOPULL       0
#define IN_PULLUP       1
#define IN_PULLDOWN     2

#define OUT_PUSHPULL    0
#define OUT_OPENDRAIN   1

static int
nici_gpio_init (FIP_RUN * fip)
{
    if (fip->argc == 3 || fip->argc == 4)
    {
        int port;
        int pin;
        int mode;
        int pull;

        port    = get_argument_int (fip, 0);
        pin     = get_argument_int (fip, 1);
        mode    = get_argument_int (fip, 2);

        if (fip->argc == 4)
        {
            pull = get_argument_int (fip, 3);
        }
        else
        {
            pull = 0;
        }

#if defined (unix) || defined (WIN32)
        con_printf ("gpio_init: GPIO=%d PIN=%d MODE=%d PULL=%d\n", port, pin, mode, pull);
#else
        GPIO_InitTypeDef gpio;
        GPIO_StructInit (&gpio);
        gpio.GPIO_Pin   = 1 << pin;
        gpio.GPIO_Speed = GPIO_Speed_50MHz;

        if (mode == OUTPUT_MODE)
        {
            if (pull == OUT_OPENDRAIN)
            {
#if defined (STM32F10X)
                gpio.GPIO_Mode  = GPIO_Mode_Out_OD;                     // output opendrain
#elif defined (STM32F4XX)
                gpio.GPIO_Mode  = GPIO_Mode_OUT;
                gpio.GPIO_OType = GPIO_OType_OD;
                gpio.GPIO_PuPd  = GPIO_PuPd_NOPULL;
#endif
            }
            else // (pull == OUT_PUSHPULL)                              // output push-pull
            {
#if defined (STM32F10X)
                gpio.GPIO_Mode  = GPIO_Mode_Out_PP;
#elif defined (STM32F4XX)
                gpio.GPIO_Mode  = GPIO_Mode_OUT;
                gpio.GPIO_OType = GPIO_OType_PP;
                gpio.GPIO_PuPd  = GPIO_PuPd_NOPULL;
#endif
            }
        }
        else // mode == INPUT_MODE
        {
            if (pull == IN_PULLUP)                                      // input with internal pullup
            {
#if defined (STM32F10X)
                gpio.GPIO_Mode = GPIO_Mode_IPU;
#elif defined (STM32F4XX)
                gpio.GPIO_Mode = GPIO_Mode_IN;
                gpio.GPIO_PuPd = GPIO_PuPd_UP;
#endif
            }
            else if (pull == IN_PULLDOWN)                               // input with internal pulldown
            {
#if defined (STM32F10X)
                gpio.GPIO_Mode = GPIO_Mode_IPD;
#elif defined (STM32F4XX)
                gpio.GPIO_Mode = GPIO_Mode_IN;
                gpio.GPIO_PuPd = GPIO_PuPd_DOWN;
#endif
            }
            else // if (pull == IN_NOPULL)                              // input floating
            {
#if defined (STM32F10X)
                gpio.GPIO_Mode = GPIO_Mode_IN_FLOATING;
#elif defined (STM32F4XX)
                gpio.GPIO_Mode = GPIO_Mode_IN;
                gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;
#endif
            }
        }

#if defined (STM32F10X)
        RCC_APB2PeriphClockCmd (4 << port, ENABLE);             // RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE);
        GPIO_TypeDef * portp = (GPIO_TypeDef *) (APB2PERIPH_BASE + ((port + 2) << 10));
        GPIO_Init(portp, &gpio);
#elif defined (STM32F4XX)
        RCC_AHB1PeriphClockCmd (1 << port, ENABLE);             // RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOA, ENABLE);
        GPIO_TypeDef * portp = (GPIO_TypeDef *) (AHB1PERIPH_BASE + (port << 10));
        GPIO_Init(portp, &gpio);                                // GPIO_Init(GPIOA, &gpio);
#endif
#endif // unix
    }

    return FUNCTION_TYPE_VOID;
}

static int
nici_gpio_set (FIP_RUN * fip)
{
    if (fip->argc == 2)
    {
        int             port;
        int             pin;

        port    = get_argument_int (fip, 0);
        pin     = get_argument_int (fip, 1);

#if defined (unix) || defined (WIN32)
        con_printf ("gpio_set: PORT=%d PIN=%d\n", port, pin);
#else
        int mask = 1 << pin;

        GPIO_TypeDef *  portp;
#if defined (STM32F10X)
        portp = (GPIO_TypeDef *) (APB2PERIPH_BASE + ((port + 2) << 10));
        portp->BSRR = mask;                                             // GPIOA->BSRR = mask;
#elif defined (STM32F4XX)
        portp = (GPIO_TypeDef *) (AHB1PERIPH_BASE + (port << 10));
        portp->BSRRL = mask;                                            // GPIOA->BSRRL = mask;
#endif
#endif // unix
    }

    return FUNCTION_TYPE_VOID;
}

static int
nici_gpio_reset (FIP_RUN * fip)
{
    if (fip->argc == 2)
    {
        int             port;
        int             pin;

        port    = get_argument_int (fip, 0);
        pin     = get_argument_int (fip, 1);

#if defined (unix) || defined (WIN32)
        con_printf ("gpio_reset: PORT=%d PIN=%d\n", port, pin);
#else
        int mask = 1 << pin;

        GPIO_TypeDef *  portp;
#if defined (STM32F10X)
        portp = (GPIO_TypeDef *) (APB2PERIPH_BASE + ((port + 2) << 10));
        portp->BRR = mask;                                              // GPIOA->SRR = mask;
#elif defined (STM32F4XX)
        portp = (GPIO_TypeDef *) (AHB1PERIPH_BASE + (port << 10));
        portp->BSRRH = mask;                                            // GPIOA->BSRRH = mask;
#endif
#endif
    }

    return FUNCTION_TYPE_VOID;
}

static int
nici_gpio_toggle (FIP_RUN * fip)
{
    if (fip->argc == 2)
    {
        int             port;
        int             pin;

        port    = get_argument_int (fip, 0);
        pin     = get_argument_int (fip, 1);

#if defined (unix) || defined (WIN32)
        con_printf ("gpio_toggle: PORT=%d PIN=%d\n", port, pin);
#else
        int mask = 1 << pin;

        GPIO_TypeDef *  portp;
#if defined (STM32F10X)
        portp = (GPIO_TypeDef *) (APB2PERIPH_BASE + ((port + 2) << 10));
        portp->ODR  ^= mask;                                              // GPIOA->ODR ^= mask;
#elif defined (STM32F4XX)
        portp = (GPIO_TypeDef *) (AHB1PERIPH_BASE + (port << 10));
        portp->ODR ^= mask;                                            // GPIOA->ODR ^= mask;
#endif
#endif // unix
    }

    return FUNCTION_TYPE_VOID;
}

static int
nici_gpio_get (FIP_RUN * fip)
{
    int rtc = 0;
#if defined (unix) || defined (WIN32)
    static int last_rtc;
#endif

    if (fip->argc == 2)
    {
        int             port;
        int             pin;

        port    = get_argument_int (fip, 0);
        pin     = get_argument_int (fip, 1);

#if defined (unix) || defined (WIN32)
        con_printf ("gpio_get: PORT=%d PIN=%d\n", port, pin);
#else
        int mask = 1 << pin;

        GPIO_TypeDef *  portp;
#if defined (STM32F10X)
        portp = (GPIO_TypeDef *) (APB2PERIPH_BASE + ((port + 2) << 10));
        rtc = GPIO_ReadInputDataBit(portp, mask);                           // rtc = GPIO_ReadInputDataBit(GPIOA, mask);
#elif defined (STM32F4XX)
        portp = (GPIO_TypeDef *) (AHB1PERIPH_BASE + (port << 10));
        rtc = GPIO_ReadInputDataBit(portp, mask);                           // rtc = GPIO_ReadInputDataBit(GPIOA, mask);
#endif
#endif // unix
    }

#if defined (unix) || defined (WIN32)
    if (last_rtc)
    {
        last_rtc = 0;
    }
    else
    {
        last_rtc = 1;
    }

    rtc = last_rtc;
    fip->reti = rtc;
#else
    if (rtc == Bit_SET)
    {
        fip->reti = 1;
    }
    else
    {
        fip->reti = 0;
    }
#endif

    return FUNCTION_TYPE_INT;
}

static int
nici_bit_set (FIP_RUN * fip)
{
    int     value = 0;

    if (fip->argc == 2)
    {
        int     bit;

        value   = get_argument_int (fip, 0);
        bit     = get_argument_int (fip, 1);

        value |= 1 << bit;
    }

    fip->reti = value;
    return FUNCTION_TYPE_INT;
}

static int
nici_bit_reset (FIP_RUN * fip)
{
    int     value = 0;

    if (fip->argc == 2)
    {
        int     bit;

        value   = get_argument_int (fip, 0);
        bit     = get_argument_int (fip, 1);

        value &= ~(1 << bit);
    }

    fip->reti = value;
    return FUNCTION_TYPE_INT;
}

static int
nici_bit_toggle (FIP_RUN * fip)
{
    int     value = 0;

    if (fip->argc == 2)
    {
        int     bit;

        value   = get_argument_int (fip, 0);
        bit     = get_argument_int (fip, 1);

        value ^= (1 << bit);
    }

    fip->reti = value;
    return FUNCTION_TYPE_INT;
}

static int
nici_bit_isset (FIP_RUN * fip)
{
    int     value = 0;

    if (fip->argc == 2)
    {
        int     bit;

        value   = get_argument_int (fip, 0);
        bit     = get_argument_int (fip, 1);

        if (value & (1 << bit))
        {
            value = 1;
        }
        else
        {
            value = 0;
        }
    }

    fip->reti = value;
    return FUNCTION_TYPE_INT;
}

static int
nici_bitmask_and (FIP_RUN * fip)
{
    int     value = 0;

    if (fip->argc == 2)
    {
        int     mask1;
        int     mask2;

        mask1 = get_argument_int (fip, 0);
        mask2 = get_argument_int (fip, 1);

        value   = mask1 & mask2;
    }

    fip->reti = value;
    return FUNCTION_TYPE_INT;
}

static int
nici_bitmask_nand (FIP_RUN * fip)
{
    int     value = 0;

    if (fip->argc == 2)
    {
        int     mask1;
        int     mask2;

        mask1 = get_argument_int (fip, 0);
        mask2 = get_argument_int (fip, 1);

        value   = ~(mask1 & mask2);
    }

    fip->reti = value;
    return FUNCTION_TYPE_INT;
}

static int
nici_bitmask_or (FIP_RUN * fip)
{
    int     value = 0;

    if (fip->argc == 2)
    {
        int     mask1;
        int     mask2;

        mask1 = get_argument_int (fip, 0);
        mask2 = get_argument_int (fip, 1);

        value   = mask1 | mask2;
    }

    fip->reti = value;
    return FUNCTION_TYPE_INT;
}

static int
nici_bitmask_nor (FIP_RUN * fip)
{
    int     value = 0;

    if (fip->argc == 2)
    {
        int     mask1;
        int     mask2;

        mask1 = get_argument_int (fip, 0);
        mask2 = get_argument_int (fip, 1);

        value   = ~(mask1 | mask2);
    }

    fip->reti = value;
    return FUNCTION_TYPE_INT;
}

static int
nici_bitmask_xor (FIP_RUN * fip)
{
    int     value = 0;

    if (fip->argc == 2)
    {
        int     mask1;
        int     mask2;

        mask1 = get_argument_int (fip, 0);
        mask2 = get_argument_int (fip, 1);

        value   = mask1 ^ mask2;
    }

    fip->reti = value;
    return FUNCTION_TYPE_INT;
}

static int
nici_bitmask_xnor (FIP_RUN * fip)
{
    int     value = 0;

    if (fip->argc == 2)
    {
        int     mask1;
        int     mask2;

        mask1 = get_argument_int (fip, 0);
        mask2 = get_argument_int (fip, 1);

        value   = ~(mask1 ^ mask2);
    }

    fip->reti = value;
    return FUNCTION_TYPE_INT;
}

#define DEFINE_FUNCTIONS    1
#include "funclist.h"                                           // should be at least line
#endif // 0
