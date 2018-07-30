/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * functions.h - declarations for nic interpreter runtime system
 *
 * Copyright (c) 2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *---------------------------------------------------------------------------------------------------------------------------------------------------
 */

#define MAX_BUTTONS                 8
#define MAX_BUTTON_CNT              5                                   // if 5 times same state, button state is valid

typedef struct
{
    int port;
    int pin;
    int active_low;
    int pressed_cnt;
    int released_cnt;
    int pressed;
} BUTTON;

extern volatile                 BUTTON buttons[MAX_BUTTONS];
extern volatile int             buttons_used;

extern int      alarm_slots_used;
extern void     update_alarm_timers (void);

extern int      (*nici_functions[])(FIP_RUN *);
