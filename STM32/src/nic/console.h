/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * console.h - declarations of serial routines
 *
 * Copyright (c) 2016-2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *---------------------------------------------------------------------------------------------------------------------------------------------------
 */
#include <stdarg.h>

#undef UART_PREFIX
#define UART_PREFIX                 log
#include "uart.h"

#define console_getc                log_uart_getc
#define console_poll                log_uart_poll
#define console_putc(c)             do { log_uart_putc (c); } while (0)
#define console_puts(s)             do { log_uart_puts (s); } while (0)
#define console_flush()             do { log_uart_flush (); } while (0)

extern int                          log_vprintf (const char *, va_list);
extern int                          log_printf (const char *, ...);
extern void                         log_init (uint32_t);
