/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * nici.h - declarations for nic interpreter
 *
 * Copyright (c) 2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *---------------------------------------------------------------------------------------------------------------------------------------------------
 */

#define                 RESULT_UNKNOWN          0x00
#define                 RESULT_INT              0x01
#define                 RESULT_CSTRING          0x02
#define                 RESULT_INT_ARRAY        0x04
#define                 RESULT_CSTRING_ARRAY    0x08
#define                 RESULT_BYTE_ARRAY       0x10

extern int              get_argument (FIP_RUN *, int argi, unsigned char **, int *);
extern int              get_argument_int (FIP_RUN *, int);
extern int              get_argument_byte (FIP_RUN *, int);
extern uint8_t *        get_argument_byte_ptr (FIP_RUN *, int);
extern unsigned char *  get_argument_string (FIP_RUN *, int);
extern int              nici (int, FIP_RUN *);

#if defined (unix) || defined (WIN32)
// yet nothing
#else
extern int nicimain (void);
#if 000
extern volatile int millis;
extern volatile int alarm_millis;
#endif // 000

#endif
