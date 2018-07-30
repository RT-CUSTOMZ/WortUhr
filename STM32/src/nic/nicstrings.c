#if 0 // fm: later
/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * nicstrings.c - string handling routines of nic interpreter
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
#include <stdlib.h>
#include <string.h>
#include "nicstrings.h"
#include "base.h"
#include "alloc.h"

#define STRINGSLOTS_ALLOC_GRANULARITY   20
STRING **       stringslots;
static int      stringslots_used;
static int      stringslots_allocated;

STRING **       tmp_stringslots;
static int      tmp_stringslots_used;
static int      tmp_stringslots_allocated;

#define ALLOC_GRANULARITY               64

static int
new_stringslots (void)
{
    if (stringslots_used == stringslots_allocated)
    {
        if (stringslots_allocated == 0)
        {
            stringslots = alloc_calloc (__FILE__, __LINE__, STRINGSLOTS_ALLOC_GRANULARITY, sizeof (STRING *));

            if (! stringslots)
            {
                return -1;
            }
        }
        else
        {
            stringslots = alloc_realloc (__FILE__, __LINE__, stringslots, (stringslots_allocated + STRINGSLOTS_ALLOC_GRANULARITY) * sizeof (STRING *));

            if (! stringslots)
            {
                return -1;
            }

            memset (stringslots + stringslots_allocated, 0, STRINGSLOTS_ALLOC_GRANULARITY * sizeof (STRING *));
        }

        stringslots_allocated += STRINGSLOTS_ALLOC_GRANULARITY;
    }
    return OK;
}


int
new_stringslot (const unsigned char * str)
{
    STRING *    s;
    int         len;
    int         siz;
    int         slot = stringslots_used;

    new_stringslots ();

    if (! stringslots[slot])
    {
        s = alloc_malloc (__FILE__, __LINE__, sizeof (STRING));

        if (s)
        {
            s->flags = 0;

            if (str)
            {
                len = ustrlen (str);
                siz = len + ALLOC_GRANULARITY;

                s->str = alloc_malloc (__FILE__, __LINE__, siz);

                if (s->str)
                {
                    s->siz = siz;
                    s->len = len;
                    ustrcpy (s->str, str);
                }
                else
                {
                    log_message ("alloc failed in new_stringslot()\n");
                    alloc_free (__FILE__, __LINE__, s);
                    s = (STRING *) NULL;
                }
            }
            else
            {
                s->len = 0;
                s->siz = 0;
                s->str = (unsigned char *) NULL;
            }
        }

        stringslots[slot] = s;
    }
    else
    {
        s = stringslots[slot];

        if (str && *str)
        {
            copy_str2string (s, str);
        }
        else
        {
            s->len = 0;

            if (s->siz > 0)
            {
                s->str[0] = '\0';
            }
        }
    }

    stringslots_used++;
    return slot;
}

void
del_stringslots (int slots)
{
    if (stringslots_used > slots)
    {
        stringslots_used -= slots;
    }
    else if (slots > 0)
    {
        log_message ("internal error in del_stringslot(): %d %d\n", slots, stringslots_used);
    }
}

static int
new_tmp_stringslots (void)
{
    if (tmp_stringslots_used == tmp_stringslots_allocated)
    {
        if (tmp_stringslots_allocated == 0)
        {
            tmp_stringslots = alloc_calloc (__FILE__, __LINE__, STRINGSLOTS_ALLOC_GRANULARITY, sizeof (STRING *));

            if (! tmp_stringslots)
            {
                return -1;
            }
        }
        else
        {
            tmp_stringslots = alloc_realloc (__FILE__, __LINE__, tmp_stringslots, (tmp_stringslots_allocated + STRINGSLOTS_ALLOC_GRANULARITY) * sizeof (STRING *));

            if (! tmp_stringslots)
            {
                return -1;
            }

            memset (tmp_stringslots + tmp_stringslots_allocated, 0, STRINGSLOTS_ALLOC_GRANULARITY * sizeof (STRING *));
        }

        tmp_stringslots_allocated += STRINGSLOTS_ALLOC_GRANULARITY;
    }
    return OK;
}


int
new_tmp_stringslot (const unsigned char * str)
{
    STRING *    s;
    int         len;
    int         siz;
    int         slot;

    new_tmp_stringslots ();

    for (slot = 0; slot < tmp_stringslots_used; slot++)
    {
        if (! (tmp_stringslots[slot]->flags & STRING_FLAG_TEMP_ACTIVE))
        {
            break;
        }
    }

    if (slot == tmp_stringslots_used)
    {
        s = alloc_malloc (__FILE__, __LINE__, sizeof (STRING));

        if (s)
        {
            if (str)
            {
                len = ustrlen (str);
                siz = len + ALLOC_GRANULARITY;

                s->str = alloc_malloc (__FILE__, __LINE__, siz);

                if (s->str)
                {
                    s->siz = siz;
                    s->len = len;
                    ustrcpy (s->str, str);
                }
                else
                {
                    log_message ("alloc failed in new_stringslot()\n");
                    alloc_free (__FILE__, __LINE__, s);
                    s = (STRING *) NULL;
                }
            }
            else
            {
                s->len = 0;
                s->siz = 0;
                s->str = (unsigned char *) NULL;
            }
            s->flags = STRING_FLAG_TEMP_ACTIVE;
        }

        tmp_stringslots[slot] = s;
        tmp_stringslots_used++;
    }
    else
    {
        s = tmp_stringslots[slot];

        if (str && *str)
        {
            copy_str2string (s, str);
        }
        else
        {
            s->len = 0;

            if (s->siz > 0)
            {
                s->str[0] = '\0';
            }
        }
        s->flags = STRING_FLAG_TEMP_ACTIVE;
    }

    return slot;
}

void
deactivate_tmp_strings (void)
{
    int     i;

    for (i = 0; i < tmp_stringslots_used; i++)
    {
        tmp_stringslots[i]->flags &= ~STRING_FLAG_TEMP_ACTIVE;
    }
}

int
length_of_string (STRING * s)
{
    return s->len;
}

const unsigned char *
str_of_string (STRING * s)
{
    if (s->str)
    {
        return s->str;
    }
    return (const unsigned char *) "";
}

STRING *
copy_string2string (STRING * t, STRING * s)
{
    if (s)
    {
        if (t->siz < s->len + 1)
        {
            int siz = s->len + ALLOC_GRANULARITY;

            if (! t->str)
            {
                t->str = alloc_malloc (__FILE__, __LINE__, siz);
            }
            else
            {
                t->str = alloc_realloc (__FILE__, __LINE__, t->str, siz);
            }

            if (t->str)
            {
                t->siz = siz;

                if (s->siz)
                {
                    ustrcpy (t->str, s->str);
                }
                else
                {
                    t->str[0] = '\0';
                }

                t->len = s->len;
            }
            else
            {
                log_message ("alloc failed in copy_string2string()\n");
                alloc_free (__FILE__, __LINE__, t);
                t = (STRING *) NULL;
            }
        }
        else
        {
            if (t->str)
            {
                if (s->siz)
                {
                    ustrcpy (t->str, s->str);
                }
                else
                {
                    t->str[0] = '\0';
                }
            }
            else
            {
                log_message ("internal error in copy_string2string()\n");
            }
            t->len = s->len;
        }
    }
    else
    {
        t->str[0] = '\0';
        t->len = 0;
    }

    return t;
}

STRING *
copy_str2string (STRING * t, const unsigned char * str)
{
    if (str)
    {
        int len = ustrlen (str);

        if (t->siz < len + 1)
        {
            int siz = len + ALLOC_GRANULARITY;

            if (! t->str)
            {
                t->str = alloc_malloc (__FILE__, __LINE__, siz);
            }
            else
            {
                t->str = alloc_realloc (__FILE__, __LINE__, t->str, siz);
            }

            if (t->str)
            {
                t->siz = siz;
                ustrcpy (t->str, str);
                t->len = len;
            }
            else
            {
                log_message ("alloc failed in copy_str2string()\n");
                alloc_free (__FILE__, __LINE__, t);
                t = (STRING *) NULL;
            }
        }
        else
        {
            ustrcpy (t->str, str);
            t->len = len;
        }
    }
    else
    {
        t->str[0] = '\0';
        t->len = 0;
    }

    return t;
}

STRING *
concat_string2string (STRING * t, STRING * s)
{
    if (s)
    {
        if (t->siz < t->len + s->len + 1)
        {
            int siz = t->len + s->len + ALLOC_GRANULARITY;

            if (! t->str)
            {
                t->str = alloc_malloc (__FILE__, __LINE__, siz);
            }
            else
            {
                t->str = alloc_realloc (__FILE__, __LINE__, t->str, siz);
            }

            if (t->str)
            {
                t->siz = siz;

                if (s->siz)
                {
                    ustrcpy (t->str + t->len, s->str);
                    t->len += s->len;
                }
                else
                {
                    t->str[t->len] = '\0';
                }
            }
            else
            {
                log_message ("alloc failed in concat_string2string()\n");
                alloc_free (__FILE__, __LINE__, t);
                t = (STRING *) NULL;
            }
        }
        else
        {
            if (s->siz)
            {
                ustrcpy (t->str + t->len, s->str);
                t->len += s->len;
            }
        }
    }

    return t;
}

STRING *
concat_str2string (STRING * t, const unsigned char * str)
{
    if (str)
    {
        int len = ustrlen (str);

        if (t->siz < t->len + len + 1)
        {
            int siz = t->len + len + ALLOC_GRANULARITY;

            if (! t->str)
            {
                t->str = alloc_malloc (__FILE__, __LINE__, siz);
            }
            else
            {
                t->str = alloc_realloc (__FILE__, __LINE__, t->str, siz);
            }

            if (t->str)
            {
                t->siz = siz;
                ustrcpy (t->str + t->len, str);
                t->len += len;
            }
            else
            {
                log_message ("alloc failed in concat_str2string()\n");
                alloc_free (__FILE__, __LINE__, t);
                t = (STRING *) NULL;
            }
        }
        else
        {
            ustrcpy (t->str + t->len, str);
            t->len += len;
        }
    }

    return t;
}

void
deallocate_strings (void)
{
    int i;

    if (tmp_stringslots)
    {
        for (i = 0; i < tmp_stringslots_allocated; i++)             // we use more than tmp_stringslots_used
        {
            if (tmp_stringslots[i])
            {
                if (tmp_stringslots[i]->str)
                {
                    alloc_free (__FILE__, __LINE__, tmp_stringslots[i]->str);
                }
                alloc_free (__FILE__, __LINE__, tmp_stringslots[i]);
            }
        }
        alloc_free (__FILE__, __LINE__, tmp_stringslots);
        tmp_stringslots_used = 0;
        tmp_stringslots_allocated = 0;
    }

    if (stringslots)
    {
        for (i = 0; i < stringslots_allocated; i++)                 // we use more than stringslots_used
        {
            if (stringslots[i])
            {
                if (stringslots[i]->str)
                {
                    alloc_free (__FILE__, __LINE__, stringslots[i]->str);
                }
                alloc_free (__FILE__, __LINE__, stringslots[i]);
            }
        }
        alloc_free (__FILE__, __LINE__, stringslots);
        stringslots_used = 0;
        stringslots_allocated = 0;
    }
}

void
string_statistics (void)
{
    int i;

    log_message ("constant stringslots used = %d\n", stringslots_used);
    log_message ("temp     stringslots used = %d\n", tmp_stringslots_used);

    for (i = 0; i < tmp_stringslots_used; i++)
    {
        if (tmp_stringslots[i]->flags)
        {
            log_message ("temp stringslot[%d] '%s' is active, flags=0x%02x!\n", i, tmp_stringslots[i]->str, tmp_stringslots[i]->flags);
        }
    }

    log_message ("stringslots_allocated = %d\n", stringslots_allocated);
}
#endif // 0
