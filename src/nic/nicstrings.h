/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * nicstrings.h - declarations for string handling routines
 *
 * Copyright (c) 2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *---------------------------------------------------------------------------------------------------------------------------------------------------
 */

#define STRING_FLAG_NONE            0x00
#define STRING_FLAG_TEMP_ACTIVE     0x01

typedef struct
{
    int             siz;            // allocated size
    int             len;            // len
    unsigned char * str;            // C string
    int             flags;          // flags
} STRING;

extern STRING **                stringslots;
extern STRING **                tmp_stringslots;

extern int                      new_stringslot (const unsigned char *);
void                            del_stringslots (int);
extern int                      new_tmp_stringslot (const unsigned char *);
extern void                     deactivate_tmp_strings (void);
extern int                      length_of_string (STRING *);

extern const unsigned char *    str_of_string (STRING *);
extern STRING *                 copy_string2string (STRING *, STRING *);
extern STRING *                 copy_str2string (STRING *, const unsigned char *);
extern STRING *                 concat_string2string (STRING *, STRING *);
extern STRING *                 concat_str2string (STRING *, const unsigned char *);
extern void                     deallocate_strings (void);
extern void                     string_statistics (void);
