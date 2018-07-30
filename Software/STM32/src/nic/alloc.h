/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * alloc.h - declarations for nic interpreter allocation routines
 *
 * Copyright (c) 2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *---------------------------------------------------------------------------------------------------------------------------------------------------
 */

#include <stdlib.h>

#if defined(unix) || defined(WIN32)

extern void *                   alloc_malloc (char *, int, size_t);
extern void *                   alloc_realloc (char *, int, void *, size_t);
extern void *                   alloc_calloc (char *, int, size_t, size_t);
extern void                     alloc_free (char *, int, void *);
extern void                     alloc_list (void);

#else

#define alloc_malloc(f,l,s)     malloc(s)
#define alloc_realloc(f,l,p,s)  realloc(p,s)
#define alloc_calloc(f,l,m,s)   calloc(m,s)
#define alloc_free(f,l,p)       free(p)

#endif
