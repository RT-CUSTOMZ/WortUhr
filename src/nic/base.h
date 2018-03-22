/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * base.h - some basic declarations
 *
 * Copyright (c) 2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *---------------------------------------------------------------------------------------------------------------------------------------------------
 */

#define TRUE                                1
#define FALSE                               0
#define OK                                  0
#define ERR                                 (-1)

#define ustrcpy(t,s)                        (void) strcpy  ((char *) (t), (const char *) (s))
#define ustrncpy(t,s,n)                     (void) strncpy ((char *) (t), (char *) (s), (size_t) (n))
#define ustrcat(t,s)                        (void) strcat  ((char *) (t), (char *) (s))
#define ustrncat(t,s,n)                     (void) strncat ((char *) (t), (char *) (s), (size_t) (n))
#define ustrlen(s)                          (int) strlen  ((const char *) (s))
#define ustrcmp(t,s)                        strcmp  ((char *) (t), (char *) (s))
#define ustrncmp(t,s,n)                     strncmp ((char *) (t), (char *) (s), (size_t) (n))
#define ustricmp(t,s)                       ustricmp_func ((unsigned char *) (t), (unsigned char *) (s))
#define ustrchr(s,c)                        (unsigned char *) strchr  ((char *) s, (int) c)
#define ustrrchr(s,c)                       (unsigned char *) strrchr ((char *) s, (int) c)
#define ustrpbrk(t,s)                       (unsigned char *) strpbrk ((char *) t, (char *) s)
#define ustrspn(t,s)                        (unsigned char *) strspn  ((char *) t, (char *) s)
#define ustrcspn(t,s)                       (unsigned char *) strcspn ((char *) t, (char *) s)
#define ustrtok(t,s)                        (unsigned char *) strtok  ((char *) t, (char *) s)
#if defined (WIN32)
#define ustrdup(s)                          (unsigned char *) _strdup ((char *) (s))
#else
#define ustrdup(s)                          (unsigned char *) strdup ((char *) (s))
#endif
#define uatoi(s)                            atoi ((char *) (s))

#if defined (unix) || defined (WIN32)
#define log_message(fmt, ...)               fprintf(stderr, fmt, ##__VA_ARGS__)
#define con_printf(fmt, ...)                fprintf(stdout, fmt, ##__VA_ARGS__)
#define con_puts(s)                         fputs (s, stdout)
#define con_putc(ch)                        fputc (ch, stdout)
#else
#ifdef STM32F4XX
#include <stm32f4xx.h>
#else
#include <stm32f10x.h>
#endif
#include "console.h"
#define log_message(fmt, ...)               log_printf(fmt, ##__VA_ARGS__)
#define con_printf(fmt, ...)                log_printf(fmt, ##__VA_ARGS__)
#define con_puts(s)                         log_uart_puts (s)
#define con_putc(ch)                        log_uart_putc (ch)
#endif
