#if 0 // fm: later
/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * alloc.c - allocation handling routines for nic interpreter
 *
 * Copyright (c) 2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *---------------------------------------------------------------------------------------------------------------------------------------------------
 */
#if defined(unix) || defined(WIN32)
#include <stdio.h>
#include <stdlib.h>

#define MAX_SLOTS   256

typedef struct
{
    char *          fname;
    int             line;
    unsigned long   addr;
    size_t          size;
} SLOT;

static SLOT slots[MAX_SLOTS];

static void
zero (char * str, char * fname, int line, void * addr, size_t size)
{
    fprintf (stderr, "%s line %d: zero %s addr: 0x%08lx size: %d\n", fname, line, str, (unsigned long) addr, size);
}

static void
malloc_slot (char * fname, int line, void * addr, size_t size)
{
    int     i;

    if (size == 0)
    {
        zero ("malloc", fname, line, addr, size);
    }

    for (i = 0; i < MAX_SLOTS; i++)
    {
        if (! slots[i].addr)
        {
            slots[i].fname  = fname;
            slots[i].line   = line;
            slots[i].addr   = (unsigned long) addr;
            slots[i].size   = size;
            break;
        }
    }
}

static void
realloc_slot (char * fname, int line, void * old_addr, void * new_addr, size_t size)
{
    int     i;

    if (size == 0)
    {
        zero ("realloc", fname, line, new_addr, size);
    }

    for (i = 0; i < MAX_SLOTS; i++)
    {
        if (slots[i].addr == (unsigned long) old_addr)
        {
            slots[i].fname  = fname;
            slots[i].line   = line;
            slots[i].addr   = (unsigned long) new_addr;
            slots[i].size   = size;
            break;
        }
    }
}

static void
free_slot (char * fname, int line, void * addr)
{
    int     i;

    for (i = 0; i < MAX_SLOTS; i++)
    {
        if (slots[i].addr == (unsigned long) addr)
        {
            // fprintf (stderr, "free_slot found: file: %s line: %d address 0x%08lx allocated: file: %s line: %d\n", fname, line, (unsigned long) addr, slots[i].fname, slots[i].line);
            slots[i].fname  = (char *) NULL;
            slots[i].line   = 0;
            slots[i].addr   = 0;
            slots[i].size   = 0;
            break;
        }
    }

    if (i == MAX_SLOTS)
    {
        fprintf (stderr, "free_slot: file: %s line: %d address 0x%08lx not allocated\n", fname, line, (unsigned long) addr);
    }
}

void *
alloc_malloc (char * fname, int line, size_t size)
{
    void *  rtc;

    rtc = malloc (size);
    malloc_slot (fname, line, rtc, size);
    return rtc;
}

void *
alloc_realloc (char * fname, int line, void * ptr, size_t size)
{
    void *  rtc;

    rtc = realloc (ptr, size);
    realloc_slot (fname, line, ptr, rtc, size);
    return rtc;
}

void *
alloc_calloc (char * fname, int line, size_t nmemb, size_t size)
{
    void *  rtc;

    rtc = calloc (nmemb, size);
    malloc_slot (fname, line, rtc, nmemb * size);
    return rtc;
}

void
alloc_free (char * fname, int line, void * ptr)
{
    free_slot (fname, line, ptr);
    free (ptr);
}

void
alloc_list (void)
{
    int     header_printed = 0;
    int     i;

    for (i = 0; i < MAX_SLOTS; i++)
    {
        if (slots[i].addr)
        {
            if (! header_printed)
            {
                fprintf (stderr, "alloc list:\n");
                header_printed = 1;
            }

            fprintf (stderr, "%2d: file: %s line: %d addr: 0x%08lx size: %d\n", i, slots[i].fname, slots[i].line, slots[i].addr, slots[i].size);
        }
    }
}
#endif
#endif // 0
