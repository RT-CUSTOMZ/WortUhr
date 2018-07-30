/*---------------------------------------------------------------------------------------------------------------------------------------------------
 * funclist.h - declarations of all intern functions of nic interpreter
 *
 * Copyright (c) 2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *---------------------------------------------------------------------------------------------------------------------------------------------------
 */

#if DEFINE_FUNCTIONS == 0
typedef struct
{
    const char *            name;
    const int               min_args;
    const int               max_args;
    const int               return_type;
} FUNCTION_LIST;

#define ITEM(function,name,min,max,type)    { name,min,max,type }
FUNCTION_LIST function_list[] =

#else

#define ITEM(function,name,min,max,type)    function
int (*nici_functions[])(FIP_RUN *) =

#endif

{
    // function                         name                        min     max     return
    ITEM(nici_console_print,            "console.print",            1,      3,      FUNCTION_TYPE_INT),
    ITEM(nici_console_println,          "console.println",          1,      3,      FUNCTION_TYPE_INT),

    ITEM(nici_string_length,            "string.length",            1,      1,      FUNCTION_TYPE_INT),
    ITEM(nici_string_substring,         "string.substring",         2,      3,      FUNCTION_TYPE_STRING),

#if 000
    ITEM(nici_time_millis,              "time.millis",              0,      0,      FUNCTION_TYPE_INT),
    ITEM(nici_time_reset,               "time.reset",               0,      0,      FUNCTION_TYPE_VOID),
    ITEM(nici_time_set,                 "time.set",                 1,      1,      FUNCTION_TYPE_VOID),
    ITEM(nici_time_delay,               "time.delay",               1,      1,      FUNCTION_TYPE_VOID),

    ITEM(nici_alarm_init,               "alarm.init",               1,      2,      FUNCTION_TYPE_INT),
    ITEM(nici_alarm,                    "alarm",                    1,      1,      FUNCTION_TYPE_INT),
#endif // 000

    ITEM(nici_gpio_init,                "gpio.init",                3,      4,      FUNCTION_TYPE_VOID),
    ITEM(nici_gpio_set,                 "gpio.set",                 2,      2,      FUNCTION_TYPE_VOID),
    ITEM(nici_gpio_reset,               "gpio.reset",               2,      2,      FUNCTION_TYPE_VOID),
    ITEM(nici_gpio_toggle,              "gpio.toggle",              2,      2,      FUNCTION_TYPE_VOID),
    ITEM(nici_gpio_get,                 "gpio.get",                 2,      2,      FUNCTION_TYPE_INT),

    ITEM(nici_bit_set,                  "bit.set",                  2,      2,      FUNCTION_TYPE_INT),
    ITEM(nici_bit_reset,                "bit.reset",                2,      2,      FUNCTION_TYPE_INT),
    ITEM(nici_bit_toggle,               "bit.toggle",               2,      2,      FUNCTION_TYPE_INT),
    ITEM(nici_bit_isset,                "bit.isset",                2,      2,      FUNCTION_TYPE_INT),

    ITEM(nici_bitmask_and,              "bitmask.and",              2,      2,      FUNCTION_TYPE_INT),
    ITEM(nici_bitmask_nand,             "bitmask.nand",             2,      2,      FUNCTION_TYPE_INT),
    ITEM(nici_bitmask_or,               "bitmask.or",               2,      2,      FUNCTION_TYPE_INT),
    ITEM(nici_bitmask_nor,              "bitmask.nor",              2,      2,      FUNCTION_TYPE_INT),
    ITEM(nici_bitmask_xor,              "bitmask.xor",              2,      2,      FUNCTION_TYPE_INT),
    ITEM(nici_bitmask_xnor,             "bitmask.xnor",             2,      2,      FUNCTION_TYPE_INT),
};
