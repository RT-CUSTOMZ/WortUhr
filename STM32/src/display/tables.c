/*-------------------------------------------------------------------------------------------------------------------------------------------
 * tables.c - WC24H tables
 *
 * Copyright (c) 2014-2017 Frank Meyer - frank(at)fli4l.de
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *-------------------------------------------------------------------------------------------------------------------------------------------
 */
#include "wclock24h-config.h"

#if WCLOCK24H == 1

#include "tables.h"

const struct Modes tbl_modes[MODES_COUNT] =
{
    { MM_8, HM_5,  "hh mm (12)"         },
    { MM_8, HM_6,  "hh mm (24)"         },
    { MM_9, HM_5,  "hh und mm (12)"     },
    { MM_9, HM_6,  "hh und mm (24)"     },
    { MM_2, HM_3,  "mm nach hh (12+)"   },
    { MM_2, HM_4,  "mm nach hh (24)"    },
    { MM_3, HM_1,  "Ossi/Berlin (12)"   },
    { MM_3, HM_3,  "Ossi/Berlin (12+)"  },
    { MM_4, HM_1,  "Oesi (12)"          },
    { MM_4, HM_3,  "Oesi (12+)"         },
    { MM_5, HM_1,  "Rhein/Ruhr (12)"    },
    { MM_5, HM_3,  "Rhein/Ruhr (12+)"   },
    { MM_6, HM_2,  "Schwaben (12)"      },
    { MM_6, HM_3,  "Schwaben (12+)"     },
    { MM_7, HM_1,  "Wessi (12)"         },
    { MM_7, HM_3,  "Wessi (12+)"        },
    { MM_10, HM_7, "Countdown"          },
    { MM_11, HM_0, "Temperatur"         }
};

const uint8_t tbl_it_is[IT_IS_MODES_COUNT][2] =
{
    { WP_ES, WP_IST },
    { WP_IT, WP_IS }
};

const uint8_t tbl_hours[HOUR_MODES_COUNT][HOUR_COUNT][MAX_HOUR_WORDS]=
{
    {   // tbl_hours[0][] = Mode 0 leer, fuer Temperaturanzeige!
        { 0 },                                                                              //  0. Stunde in Mode HM_0
        { 0 },                                                                              //  1. Stunde in Mode HM_0
        { 0 },                                                                              //  2. Stunde in Mode HM_0
        { 0 },                                                                              //  3. Stunde in Mode HM_0
        { 0 },                                                                              //  4. Stunde in Mode HM_0
        { 0 },                                                                              //  5. Stunde in Mode HM_0
        { 0 },                                                                              //  6. Stunde in Mode HM_0
        { 0 },                                                                              //  7. Stunde in Mode HM_0
        { 0 },                                                                              //  8. Stunde in Mode HM_0
        { 0 },                                                                              //  9. Stunde in Mode HM_0
        { 0 },                                                                              // 10. Stunde in Mode HM_0
        { 0 },                                                                              // 11. Stunde in Mode HM_0
        { 0 },                                                                              // 12. Stunde in Mode HM_0
        { 0 },                                                                              // 13. Stunde in Mode HM_0
        { 0 },                                                                              // 14. Stunde in Mode HM_0
        { 0 },                                                                              // 15. Stunde in Mode HM_0
        { 0 },                                                                              // 16. Stunde in Mode HM_0
        { 0 },                                                                              // 17. Stunde in Mode HM_0
        { 0 },                                                                              // 18. Stunde in Mode HM_0
        { 0 },                                                                              // 19. Stunde in Mode HM_0
        { 0 },                                                                              // 20. Stunde in Mode HM_0
        { 0 },                                                                              // 21. Stunde in Mode HM_0
        { 0 },                                                                              // 22. Stunde in Mode HM_0
        { 0 },                                                                              // 23. Stunde in Mode HM_0
        { 0 }                                                                               // 24. Stunde in Mode HM_0
    },
    {   // tbl_hours[1][] = Mode 1 MM - HH (12)
        {WP_ZWOELF_2},                                                                      //  0. Stunde in Mode HM_1
        {WP_IF_MINUTE_IS_0, WP_EIN_4, WP_EINS_2},                                           //  1. Stunde in Mode HM_1 (WP_EIN_4 if 01:00)
        {WP_ZWEI_2},                                                                        //  2. Stunde in Mode HM_1
        {WP_DREI_2},                                                                        //  3. Stunde in Mode HM_1
        {WP_VIER_2},                                                                        //  4. Stunde in Mode HM_1
        {WP_FUENF_2},                                                                       //  5. Stunde in Mode HM_1
        {WP_SECHS_2},                                                                       //  6. Stunde in Mode HM_1
        {WP_SIEBEN_2},                                                                      //  7. Stunde in Mode HM_1
        {WP_ACHT_2},                                                                        //  8. Stunde in Mode HM_1
        {WP_NEUN_2},                                                                        //  9. Stunde in Mode HM_1
        {WP_ZEHN_2},                                                                        // 10. Stunde in Mode HM_1
        {WP_ELF_2},                                                                         // 11. Stunde in Mode HM_1
        {WP_ZWOELF_2},                                                                      // 12. Stunde in Mode HM_1
        {WP_IF_MINUTE_IS_0, WP_EIN_4, WP_EINS_2},                                           // 13. Stunde in Mode HM_1 (WP_EIN_4 if 13:00)
        {WP_ZWEI_2},                                                                        // 14. Stunde in Mode HM_1
        {WP_DREI_2},                                                                        // 15. Stunde in Mode HM_1
        {WP_VIER_2},                                                                        // 16. Stunde in Mode HM_1
        {WP_FUENF_2},                                                                       // 17. Stunde in Mode HM_1
        {WP_SECHS_2},                                                                       // 18. Stunde in Mode HM_1
        {WP_SIEBEN_2},                                                                      // 19. Stunde in Mode HM_1
        {WP_ACHT_2},                                                                        // 20. Stunde in Mode HM_1
        {WP_NEUN_2},                                                                        // 21. Stunde in Mode HM_1
        {WP_ZEHN_2},                                                                        // 22. Stunde in Mode HM_1
        {WP_ELF_2},                                                                         // 23. Stunde in Mode HM_1
        {WP_ZWOELF_2}                                                                       // 24. Stunde in Mode HM_1
    },
    {   // tbl_hours[2][] = Mode 2 MM - HH UHR (12)
        {WP_ZWOELF_2, WP_UHR_2},                                                            //  0. Stunde in Mode HM_2
        {WP_EIN_4, WP_UHR_2},                                                               //  1. Stunde in Mode HM_2
        {WP_ZWEI_2, WP_UHR_2},                                                              //  2. Stunde in Mode HM_2
        {WP_DREI_2, WP_UHR_2},                                                              //  3. Stunde in Mode HM_2
        {WP_VIER_2, WP_UHR_2},                                                              //  4. Stunde in Mode HM_2
        {WP_FUENF_2, WP_UHR_2},                                                             //  5. Stunde in Mode HM_2
        {WP_SECHS_2, WP_UHR_2},                                                             //  6. Stunde in Mode HM_2
        {WP_SIEBEN_2, WP_UHR_2},                                                            //  7. Stunde in Mode HM_2
        {WP_ACHT_2, WP_UHR_2},                                                              //  8. Stunde in Mode HM_2
        {WP_NEUN_2, WP_UHR_2},                                                              //  9. Stunde in Mode HM_2
        {WP_ZEHN_2, WP_UHR_2},                                                              // 10. Stunde in Mode HM_2
        {WP_ELF_2, WP_UHR_2},                                                               // 11. Stunde in Mode HM_2
        {WP_ZWOELF_2, WP_UHR_2},                                                            // 12. Stunde in Mode HM_2
        {WP_EIN_4, WP_UHR_2},                                                               // 13. Stunde in Mode HM_2
        {WP_ZWEI_2, WP_UHR_2},                                                              // 14. Stunde in Mode HM_2
        {WP_DREI_2, WP_UHR_2},                                                              // 15. Stunde in Mode HM_2
        {WP_VIER_2, WP_UHR_2},                                                              // 16. Stunde in Mode HM_2
        {WP_FUENF_2, WP_UHR_2},                                                             // 17. Stunde in Mode HM_2
        {WP_SECHS_2, WP_UHR_2},                                                             // 18. Stunde in Mode HM_2
        {WP_SIEBEN_2, WP_UHR_2},                                                            // 19. Stunde in Mode HM_2
        {WP_ACHT_2, WP_UHR_2},                                                              // 20. Stunde in Mode HM_2
        {WP_NEUN_2, WP_UHR_2},                                                              // 21. Stunde in Mode HM_2
        {WP_ZEHN_2, WP_UHR_2},                                                              // 22. Stunde in Mode HM_2
        {WP_ELF_2, WP_UHR_2},                                                               // 23. Stunde in Mode HM_2
        {WP_ZWOELF_2, WP_UHR_2}                                                             // 24. Stunde in Mode HM_2
    },
    {   // tbl_hours[3][] = Mode 3 MM - HH UHR (12) NACHTS
        {WP_ZWOELF_2, WP_UHR_2, WP_NACHTS},                                                 //  0. Stunde in Mode HM_3
        {WP_EIN_4, WP_UHR_2, WP_NACHTS},                                                    //  1. Stunde in Mode HM_3
        {WP_ZWEI_2, WP_UHR_2, WP_NACHTS},                                                   //  2. Stunde in Mode HM_3
        {WP_DREI_2, WP_UHR_2, WP_NACHTS},                                                   //  3. Stunde in Mode HM_3
        {WP_VIER_2, WP_UHR_2, WP_FRUEH, WP_MORGENS},                                        //  4. Stunde in Mode HM_3
        {WP_FUENF_2, WP_UHR_2, WP_FRUEH, WP_MORGENS},                                       //  5. Stunde in Mode HM_3
        {WP_SECHS_2, WP_UHR_2, WP_MORGENS},                                                 //  6. Stunde in Mode HM_3
        {WP_SIEBEN_2, WP_UHR_2, WP_MORGENS},                                                //  7. Stunde in Mode HM_3
        {WP_ACHT_2, WP_UHR_2, WP_MORGENS},                                                  //  8. Stunde in Mode HM_3
        {WP_NEUN_2, WP_UHR_2, WP_MORGENS},                                                  //  9. Stunde in Mode HM_3
        {WP_ZEHN_2, WP_UHR_2, WP_VOR_2, WP_MITTAGS},                                        // 10. Stunde in Mode HM_3
        {WP_ELF_2, WP_UHR_2, WP_VOR_2, WP_MITTAGS},                                         // 11. Stunde in Mode HM_3
        {WP_ZWOELF_2, WP_UHR_2, WP_MITTAGS},                                                // 12. Stunde in Mode HM_3
        {WP_EIN_4, WP_UHR_2, WP_MITTAGS},                                                   // 13. Stunde in Mode HM_3
        {WP_ZWEI_2, WP_UHR_2, WP_NACH_2, WP_MITTAGS},                                       // 14. Stunde in Mode HM_3
        {WP_DREI_2, WP_UHR_2, WP_NACH_2, WP_MITTAGS},                                       // 15. Stunde in Mode HM_3
        {WP_VIER_2, WP_UHR_2, WP_NACH_2, WP_MITTAGS},                                       // 16. Stunde in Mode HM_3
        {WP_FUENF_2, WP_UHR_2, WP_NACH_2, WP_MITTAGS},                                      // 17. Stunde in Mode HM_3
        {WP_SECHS_2, WP_UHR_2, WP_ABENDS},                                                  // 18. Stunde in Mode HM_3
        {WP_SIEBEN_2, WP_UHR_2, WP_ABENDS},                                                 // 19. Stunde in Mode HM_3
        {WP_ACHT_2, WP_UHR_2, WP_ABENDS},                                                   // 20. Stunde in Mode HM_3
        {WP_NEUN_2, WP_UHR_2, WP_ABENDS},                                                   // 21. Stunde in Mode HM_3
        {WP_ZEHN_2, WP_UHR_2, WP_ABENDS},                                                   // 22. Stunde in Mode HM_3
        {WP_ELF_2, WP_UHR_2, WP_NACHTS},                                                    // 23. Stunde in Mode HM_3
        {WP_ZWOELF_2, WP_UHR_2, WP_NACHTS}                                                  // 24. Stunde in Mode HM_3
    },
    {   // tbl_hours[4][] = Mode 4 MM - HH UHR (24)
        {WP_NULL_2, WP_UHR_2},                                                              //  0. Stunde in Mode HM_4
        {WP_EIN_4, WP_UHR_2},                                                               //  1. Stunde in Mode HM_4
        {WP_ZWEI_2, WP_UHR_2},                                                              //  2. Stunde in Mode HM_4
        {WP_DREI_2, WP_UHR_2},                                                              //  3. Stunde in Mode HM_4
        {WP_VIER_2, WP_UHR_2},                                                              //  4. Stunde in Mode HM_4
        {WP_FUENF_2, WP_UHR_2},                                                             //  5. Stunde in Mode HM_4
        {WP_SECHS_2, WP_UHR_2},                                                             //  6. Stunde in Mode HM_4
        {WP_SIEBEN_2, WP_UHR_2},                                                            //  7. Stunde in Mode HM_4
        {WP_ACHT_2, WP_UHR_2},                                                              //  8. Stunde in Mode HM_4
        {WP_NEUN_2, WP_UHR_2},                                                              //  9. Stunde in Mode HM_4
        {WP_ZEHN_2, WP_UHR_2},                                                              // 10. Stunde in Mode HM_4
        {WP_ELF_2, WP_UHR_2},                                                               // 11. Stunde in Mode HM_4
        {WP_ZWOELF_2, WP_UHR_2},                                                            // 12. Stunde in Mode HM_4
        {WP_DREI_2, WP_ZEHN_2, WP_UHR_2},                                                   // 13. Stunde in Mode HM_4
        {WP_VIER_2, WP_ZEHN_2, WP_UHR_2},                                                   // 14. Stunde in Mode HM_4
        {WP_FUENF_2, WP_ZEHN_2, WP_UHR_2},                                                  // 15. Stunde in Mode HM_4
        {WP_SECH_2, WP_ZEHN_2, WP_UHR_2},                                                   // 16. Stunde in Mode HM_4
        {WP_SIEB_2, WP_ZEHN_2, WP_UHR_2},                                                   // 17. Stunde in Mode HM_4
        {WP_ACHT_2, WP_ZEHN_2, WP_UHR_2},                                                   // 18. Stunde in Mode HM_4
        {WP_NEUN_2, WP_ZEHN_2, WP_UHR_2},                                                   // 19. Stunde in Mode HM_4
        {WP_ZWANZIG_2, WP_UHR_2},                                                           // 20. Stunde in Mode HM_4
        {WP_EIN_4, WP_UND_3, WP_ZWANZIG_2, WP_UHR_2},                                       // 21. Stunde in Mode HM_4
        {WP_ZWEI_2, WP_UND_3, WP_ZWANZIG_2, WP_UHR_2},                                      // 22. Stunde in Mode HM_4
        {WP_DREI_2, WP_UND_3, WP_ZWANZIG_2, WP_UHR_2},                                      // 23. Stunde in Mode HM_4
        {WP_VIER_2, WP_UND_3, WP_ZWANZIG_2, WP_UHR_2}                                       // 24. Stunde in Mode HM_4
    },
    {   // tbl_hours[5][] = Mode 5 HH UHR (12) - MM
        {WP_NULL_1, WP_UHR_1},                                                              //  0. Stunde in Mode HM_5
        {WP_EIN_1, WP_UHR_1},                                                               //  1. Stunde in Mode HM_5
        {WP_ZWEI_1, WP_UHR_1},                                                              //  2. Stunde in Mode HM_5
        {WP_DREI_1, WP_UHR_1},                                                              //  3. Stunde in Mode HM_5
        {WP_VIER_1, WP_UHR_1},                                                              //  4. Stunde in Mode HM_5
        {WP_FUENF_1, WP_UHR_1},                                                             //  5. Stunde in Mode HM_5
        {WP_SECHS_1, WP_UHR_1},                                                             //  6. Stunde in Mode HM_5
        {WP_SIEBEN_1, WP_UHR_1},                                                            //  7. Stunde in Mode HM_5
        {WP_ACHT_1, WP_UHR_1},                                                              //  8. Stunde in Mode HM_5
        {WP_NEUN_1, WP_UHR_1},                                                              //  9. Stunde in Mode HM_5
        {WP_ZEHN_1, WP_UHR_1},                                                              // 10. Stunde in Mode HM_5
        {WP_ELF_1, WP_UHR_1},                                                               // 11. Stunde in Mode HM_5
        {WP_ZWOELF_1, WP_UHR_1},                                                            // 12. Stunde in Mode HM_5
        {WP_EIN_1, WP_UHR_1},                                                               // 13. Stunde in Mode HM_5
        {WP_ZWEI_1, WP_UHR_1},                                                              // 14. Stunde in Mode HM_5
        {WP_DREI_1, WP_UHR_1},                                                              // 15. Stunde in Mode HM_5
        {WP_VIER_1, WP_UHR_1},                                                              // 16. Stunde in Mode HM_5
        {WP_FUENF_1, WP_UHR_1},                                                             // 17. Stunde in Mode HM_5
        {WP_SECHS_1, WP_UHR_1},                                                             // 18. Stunde in Mode HM_5
        {WP_SIEBEN_1, WP_UHR_1},                                                            // 19. Stunde in Mode HM_5
        {WP_ACHT_1, WP_UHR_1},                                                              // 20. Stunde in Mode HM_5
        {WP_NEUN_1, WP_UHR_1},                                                              // 21. Stunde in Mode HM_5
        {WP_ZEHN_1, WP_UHR_1},                                                              // 22. Stunde in Mode HM_5
        {WP_ELF_1, WP_UHR_1},                                                               // 23. Stunde in Mode HM_5
        {WP_ZWOELF_1, WP_UHR_1}                                                             // 24. Stunde in Mode HM_5
    },
    {   // tbl_hours[6][] = Mode 6 HH UHR 24) - MM
        {WP_NULL_1, WP_UHR_1},                                                              //  0. Stunde in Mode HM_6
        {WP_EIN_1, WP_UHR_1},                                                               //  1. Stunde in Mode HM_6
        {WP_ZWEI_1, WP_UHR_1},                                                              //  2. Stunde in Mode HM_6
        {WP_DREI_1, WP_UHR_1},                                                              //  3. Stunde in Mode HM_6
        {WP_VIER_1, WP_UHR_1},                                                              //  4. Stunde in Mode HM_6
        {WP_FUENF_1, WP_UHR_1},                                                             //  5. Stunde in Mode HM_6
        {WP_SECHS_1, WP_UHR_1},                                                             //  6. Stunde in Mode HM_6
        {WP_SIEBEN_1, WP_UHR_1},                                                            //  7. Stunde in Mode HM_6
        {WP_ACHT_1, WP_UHR_1},                                                              //  8. Stunde in Mode HM_6
        {WP_NEUN_1, WP_UHR_1},                                                              //  9. Stunde in Mode HM_6
        {WP_ZEHN_1, WP_UHR_1},                                                              // 10. Stunde in Mode HM_6
        {WP_ELF_1, WP_UHR_1},                                                               // 11. Stunde in Mode HM_6
        {WP_ZWOELF_1, WP_UHR_1},                                                            // 12. Stunde in Mode HM_6
        {WP_DREI_1, WP_ZEHN_1, WP_UHR_1},                                                   // 13. Stunde in Mode HM_6
        {WP_VIER_1, WP_ZEHN_1, WP_UHR_1},                                                   // 14. Stunde in Mode HM_6
        {WP_FUENF_1, WP_ZEHN_1, WP_UHR_1},                                                  // 15. Stunde in Mode HM_6
        {WP_SECH_1, WP_ZEHN_1, WP_UHR_1},                                                   // 16. Stunde in Mode HM_6
        {WP_SIEB_1, WP_ZEHN_1, WP_UHR_1},                                                   // 17. Stunde in Mode HM_6
        {WP_ACHT_1, WP_ZEHN_1, WP_UHR_1},                                                   // 18. Stunde in Mode HM_6
        {WP_NEUN_1, WP_ZEHN_1, WP_UHR_1},                                                   // 19. Stunde in Mode HM_6
        {WP_ZWANZIG_1, WP_UHR_1},                                                           // 20. Stunde in Mode HM_6
        {WP_EIN_1, WP_UND_1, WP_ZWANZIG_1, WP_UHR_1},                                       // 21. Stunde in Mode HM_6
        {WP_ZWEI_1, WP_UND_1, WP_ZWANZIG_1, WP_UHR_1},                                      // 22. Stunde in Mode HM_6
        {WP_DREI_1, WP_UND_1, WP_ZWANZIG_1, WP_UHR_1},                                      // 23. Stunde in Mode HM_6
        {WP_VIER_1, WP_UND_1, WP_ZWANZIG_1, WP_UHR_1}                                       // 24. Stunde in Mode HM_6
    },
    {   // tbl_hours[7][] = Mode 7 MITTERNACHT (0 UHR)
        {WP_MITTERNACHT},                                                                   //  0. Stunde in Mode HM_7
        {WP_EIN_4, WP_UHR_2, WP_FRUEH},                                                     //  1. Stunde in Mode HM_7
        {WP_ZWEI_2, WP_UHR_2, WP_FRUEH},                                                    //  2. Stunde in Mode HM_7
        {WP_DREI_2, WP_UHR_2, WP_FRUEH},                                                    //  3. Stunde in Mode HM_7
        {WP_VIER_2, WP_UHR_2, WP_FRUEH},                                                    //  4. Stunde in Mode HM_7
        {WP_FUENF_2, WP_UHR_2, WP_FRUEH},                                                   //  5. Stunde in Mode HM_7
        {WP_SECHS_2, WP_UHR_2, WP_FRUEH},                                                   //  6. Stunde in Mode HM_7
        {WP_SIEBEN_2, WP_UHR_2, WP_MORGENS},                                                //  7. Stunde in Mode HM_7
        {WP_ACHT_2, WP_UHR_2, WP_MORGENS},                                                  //  8. Stunde in Mode HM_7
        {WP_NEUN_2, WP_UHR_2, WP_MORGENS},                                                  //  9. Stunde in Mode HM_7
        {WP_ZEHN_2, WP_UHR_2, WP_MORGENS},                                                  // 10. Stunde in Mode HM_7
        {WP_ELF_2, WP_UHR_2, WP_MORGENS},                                                   // 11. Stunde in Mode HM_7
        {WP_ZWOELF_2, WP_UHR_2, WP_MITTAGS},                                                // 12. Stunde in Mode HM_7
        {WP_EIN_4, WP_UHR_2, WP_NACH_2, WP_MITTAGS},                                        // 13. Stunde in Mode HM_7
        {WP_ZWEI_2, WP_UHR_2, WP_NACH_2, WP_MITTAGS},                                       // 14. Stunde in Mode HM_7
        {WP_DREI_2, WP_UHR_2, WP_NACH_2, WP_MITTAGS},                                       // 15. Stunde in Mode HM_7
        {WP_VIER_2, WP_UHR_2, WP_NACH_2, WP_MITTAGS},                                       // 16. Stunde in Mode HM_7
        {WP_FUENF_2, WP_UHR_2, WP_NACH_2, WP_MITTAGS},                                      // 17. Stunde in Mode HM_7
        {WP_SECHS_2, WP_UHR_2, WP_ABENDS},                                                  // 18. Stunde in Mode HM_7
        {WP_SIEBEN_2, WP_UHR_2, WP_ABENDS},                                                 // 19. Stunde in Mode HM_7
        {WP_ACHT_2, WP_UHR_2, WP_ABENDS},                                                   // 20. Stunde in Mode HM_7
        {WP_NEUN_2, WP_UHR_2, WP_ABENDS},                                                   // 21. Stunde in Mode HM_7
        {WP_ZEHN_2, WP_UHR_2, WP_NACHTS},                                                   // 22. Stunde in Mode HM_7
        {WP_ELF_2, WP_UHR_2, WP_NACHTS},                                                    // 23. Stunde in Mode HM_7
        {WP_MITTERNACHT}                                                                    // 24. Stunde in Mode HM_7
    }
};

const struct MinuteDisplay tbl_minutes[MINUTE_MODES_COUNT][MINUTE_COUNT]=
{
    {   // tbl_minutes[0][] = Mode 1 MM NACH
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{0}},                                                                            //  0. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EINS_1, WP_NACH_1}},                                                         //  1. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_NACH_1}},                                                         //  2. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_NACH_1}},                                                         //  3. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_NACH_1}},                                                         //  4. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_NACH_1}},                                                        //  5. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_NACH_1}},                                                        //  6. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_NACH_1}},                                                       //  7. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_NACH_1}},                                                         //  8. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_NACH_1}},                                                         //  9. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZEHN_1, WP_NACH_1}},                                                         // 10. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ELF_1, WP_NACH_1}},                                                          // 11. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWOELF_1, WP_NACH_1}},                                                       // 12. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_ZEHN_1, WP_NACH_1}},                                              // 13. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_ZEHN_1, WP_NACH_1}},                                              // 14. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_ZEHN_1, WP_NACH_1}},                                             // 15. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECH_1, WP_ZEHN_1, WP_NACH_1}},                                              // 16. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEB_1, WP_ZEHN_1, WP_NACH_1}},                                              // 17. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_ZEHN_1, WP_NACH_1}},                                              // 18. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_ZEHN_1, WP_NACH_1}},                                              // 19. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWANZIG_1, WP_NACH_1}},                                                      // 20. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_ZWANZIG_1, WP_NACH_1}},                                  // 21. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_ZWANZIG_1, WP_NACH_1}},                                 // 22. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_ZWANZIG_1, WP_NACH_1}},                                 // 23. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_ZWANZIG_1, WP_NACH_1}},                                 // 24. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_ZWANZIG_1, WP_NACH_1}},                                // 25. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_ZWANZIG_1, WP_NACH_1}},                                // 26. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_ZWANZIG_1, WP_NACH_1}},                               // 27. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_ZWANZIG_1, WP_NACH_1}},                                 // 28. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_ZWANZIG_1, WP_NACH_1}},                                 // 29. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREISSIG_1, WP_NACH_1}},                                                     // 30. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_DREISSIG_1, WP_NACH_1}},                                 // 31. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_DREISSIG_1, WP_NACH_1}},                                // 32. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_DREISSIG_1, WP_NACH_1}},                                // 33. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_DREISSIG_1, WP_NACH_1}},                                // 34. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_DREISSIG_1, WP_NACH_1}},                               // 35. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_DREISSIG_1, WP_NACH_1}},                               // 36. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_DREISSIG_1, WP_NACH_1}},                              // 37. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_DREISSIG_1, WP_NACH_1}},                                // 38. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_DREISSIG_1, WP_NACH_1}},                                // 39. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIERZIG_1, WP_NACH_1}},                                                      // 40. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_VIERZIG_1, WP_NACH_1}},                                  // 41. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_VIERZIG_1, WP_NACH_1}},                                 // 42. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_VIERZIG_1, WP_NACH_1}},                                 // 43. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_VIERZIG_1, WP_NACH_1}},                                 // 44. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_VIERZIG_1, WP_NACH_1}},                                // 45. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_VIERZIG_1, WP_NACH_1}},                                // 46. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_VIERZIG_1, WP_NACH_1}},                               // 47. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_VIERZIG_1, WP_NACH_1}},                                 // 48. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_VIERZIG_1, WP_NACH_1}},                                 // 49. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENFZIG_1, WP_NACH_1}},                                                     // 50. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_FUENFZIG_1, WP_NACH_1}},                                 // 51. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_FUENFZIG_1, WP_NACH_1}},                                // 52. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_FUENFZIG_1, WP_NACH_1}},                                // 53. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_FUENFZIG_1, WP_NACH_1}},                                // 54. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_FUENFZIG_1, WP_NACH_1}},                               // 55. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_FUENFZIG_1, WP_NACH_1}},                               // 56. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_FUENFZIG_1, WP_NACH_1}},                              // 57. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_FUENFZIG_1, WP_NACH_1}},                                // 58. Minute in Mode MM_1
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_FUENFZIG_1, WP_NACH_1}}                                 // 59. Minute in Mode MM_1
    },
    {   // tbl_minutes[1][] = Mode 2 MM MINUTEN NACH
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{0}},                                                                            //  0. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1}},                                            //  1. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  2. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  3. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  4. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  5. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  6. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1}},                                         //  7. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  8. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  9. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                           // 10. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ELF_1, WP_MINUTEN_1, WP_NACH_1}},                                            // 11. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWOELF_1, WP_MINUTEN_1, WP_NACH_1}},                                         // 12. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 13. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 14. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                               // 15. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECH_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 16. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEB_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 17. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 18. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 19. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                                        // 20. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                    // 21. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 22. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 23. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 24. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 25. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 26. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                 // 27. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 28. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 29. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREISSIG_1, WP_MINUTEN_1, WP_NACH_1}},                                       // 30. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 31. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 32. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 33. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 34. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_NACH_1}},                 // 35. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_NACH_1}},                 // 36. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_NACH_1}},                // 37. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 38. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 39. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIERZIG_1, WP_MINUTEN_1, WP_NACH_1}},                                        // 40. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_NACH_1}},                    // 41. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 42. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 43. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 44. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 45. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 46. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_NACH_1}},                 // 47. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 48. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 49. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENFZIG_1, WP_MINUTEN_1, WP_NACH_1}},                                       // 50. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_NACH_1}},                   // 51. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 52. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 53. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 54. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_NACH_1}},                 // 55. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_NACH_1}},                 // 56. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_NACH_1}},                // 57. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_NACH_1}},                  // 58. Minute in Mode MM_2
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_NACH_1}}                   // 59. Minute in Mode MM_2
    },
    {   // tbl_minutes[2][] = Mode 3 OSSI - MM MINUTEN NACH (VIERTEL NACH, HALB, VIERTEL VOR)
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UHR_2}},                                                                     //  0. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1}},                                            //  1. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  2. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  3. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  4. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  5. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  6. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1}},                                         //  7. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  8. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  9. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                           // 10. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ELF_1, WP_MINUTEN_1, WP_NACH_1}},                                            // 11. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWOELF_1, WP_MINUTEN_1, WP_NACH_1}},                                         // 12. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 13. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 14. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIERTEL_1}},                                                                 // 15. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECH_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 16. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEB_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 17. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 18. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 19. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 20. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 21. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 22. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                 // 23. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                  // 24. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                  // 25. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 26. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 27. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 28. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1, WP_HALB}},                                    // 29. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_HALB}},                                                                      // 30. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1, WP_HALB}},                                   // 31. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 32. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 33. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 34. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                 // 35. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                 // 36. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                // 37. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 38. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 39. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 40. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ELF_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                   // 41. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWOELF_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                // 42. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                       // 43. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                       // 44. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREIVIERTEL}},                                                               // 45. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 46. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 47. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWOELF_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 48. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ELF_1, WP_MINUTEN_1, WP_VOR_1}},                                             // 49. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 50. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 51. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 52. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 53. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1}},                                           // 54. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1}},                                           // 55. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 56. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 57. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 58. Minute in Mode MM_3
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1}}                                              // 59. Minute in Mode MM_3
    },
    {   // tbl_minutes[3][] = Mode 4 OESI - MINUTEN NACH (VIERTEL NACH, HALB, DREIVIERTEL)
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UHR_2}},                                                                     //  0. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1}},                                            //  1. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  2. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  3. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  4. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  5. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  6. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1}},                                         //  7. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  8. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  9. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                           // 10. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ELF_1, WP_MINUTEN_1, WP_NACH_1}},                                            // 11. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWOELF_1, WP_MINUTEN_1, WP_NACH_1}},                                         // 12. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 13. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 14. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIERTEL_1, WP_NACH_1}},                                                      // 15. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECH_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 16. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEB_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 17. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 18. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 19. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                                        // 20. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 21. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 22. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                 // 23. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                  // 24. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                  // 25. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 26. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 27. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 28. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1, WP_HALB}},                                    // 29. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_HALB}},                                                                      // 30. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1, WP_HALB}},                                   // 31. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 32. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 33. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 34. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                 // 35. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                 // 36. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                // 37. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 38. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 39. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                                         // 40. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 41. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 42. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEB_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 43. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECH_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 44. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREIVIERTEL}},                                                               // 45. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 46. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 47. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWOELF_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 48. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ELF_1, WP_MINUTEN_1, WP_VOR_1}},                                             // 49. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 50. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 51. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 52. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 53. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1}},                                           // 54. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1}},                                           // 55. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 56. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 57. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 58. Minute in Mode MM_4
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1}}                                              // 59. Minute in Mode MM_4
    },
    {   // tbl_minutes[4][] = Mode 5 RHEIN/ RUHR - MINUTEN NACH (VIERTEL, HALB, DREIVIERTEL)
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UHR_2}},                                                                     //  0. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1}},                                            //  1. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  2. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  3. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  4. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  5. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  6. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1}},                                         //  7. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  8. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  9. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                           // 10. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ELF_1, WP_MINUTEN_1, WP_NACH_1}},                                            // 11. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWOELF_1, WP_MINUTEN_1, WP_NACH_1}},                                         // 12. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 13. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 14. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIERTEL_1, WP_NACH_1}},                                                      // 15. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECH_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 16. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEB_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 17. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 18. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 19. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                                        // 20. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 21. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 22. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                 // 23. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                  // 24. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                  // 25. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 26. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 27. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 28. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1, WP_HALB}},                                    // 29. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_HALB}},                                                                      // 30. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1, WP_HALB}},                                   // 31. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 32. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 33. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 34. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                 // 35. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                 // 36. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                // 37. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 38. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 39. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                                         // 40. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 41. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 42. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEB_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 43. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECH_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 44. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIERTEL_1, WP_VOR_1}},                                                       // 45. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 46. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 47. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWOELF_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 48. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ELF_1, WP_MINUTEN_1, WP_VOR_1}},                                             // 49. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 50. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 51. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 52. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 53. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1}},                                           // 54. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1}},                                           // 55. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 56. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 57. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 58. Minute in Mode MM_5
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1}}                                              // 59. Minute in Mode MM_5
    },
    {   // tbl_minutes[5][] = Mode 6 SCHWABEN - MM MINUTEN NACH (VIERTEL NACH, HALB, DREIVIERTEL)
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UHR_2}},                                                                     //  0. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1}},                                            //  1. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  2. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  3. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  4. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  5. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  6. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1}},                                         //  7. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  8. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  9. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                           // 10. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ELF_1, WP_MINUTEN_1, WP_NACH_1}},                                            // 11. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWOELF_1, WP_MINUTEN_1, WP_NACH_1}},                                         // 12. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 13. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 14. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIERTEL_1}},                                                                 // 15. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECH_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 16. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEB_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 17. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 18. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 19. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWANZIG_1, WP_MINUTEN_1, WP_NACH_1}},                                        // 20. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 21. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 22. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                 // 23. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                  // 24. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                  // 25. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 26. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 27. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 28. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1, WP_HALB}},                                    // 29. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_HALB}},                                                                      // 30. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1, WP_HALB}},                                   // 31. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 32. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 33. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 34. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                 // 35. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                 // 36. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                // 37. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 38. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 39. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                                         // 40. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 41. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 42. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEB_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 43. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECH_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 44. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREIVIERTEL}},                                                               // 45. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 46. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 47. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWOELF_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 48. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ELF_1, WP_MINUTEN_1, WP_VOR_1}},                                             // 49. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 50. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 51. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 52. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 53. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1}},                                           // 54. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1}},                                           // 55. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 56. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 57. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 58. Minute in Mode MM_6
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1}}                                              // 59. Minute in Mode MM_6
    },
    {   // tbl_minutes[6][] = Mode 7 WESSI - MM MINUTEN NACH (VIERTEL, HALB, DREIVIERTEL)
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UHR_2}},                                                                     //  0. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1}},                                            //  1. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  2. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  3. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  4. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  5. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1}},                                          //  6. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1}},                                         //  7. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  8. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1}},                                           //  9. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                           // 10. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ELF_1, WP_MINUTEN_1, WP_NACH_1}},                                            // 11. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWOELF_1, WP_MINUTEN_1, WP_NACH_1}},                                         // 12. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 13. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 14. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIERTEL_1, WP_NACH_1}},                                                      // 15. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECH_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 16. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEB_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 17. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 18. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1}},                                // 19. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 20. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 21. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 22. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                 // 23. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                  // 24. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                  // 25. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 26. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 27. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1, WP_HALB}},                                   // 28. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1, WP_HALB}},                                    // 29. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_HALB}},                                                                      // 30. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_NACH_1, WP_HALB}},                                   // 31. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 32. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 33. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 34. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                 // 35. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                 // 36. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                // 37. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 38. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 39. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                  // 40. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ELF_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                   // 41. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWOELF_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                                // 42. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                       // 43. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_NACH_1, WP_HALB}},                       // 44. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIERTEL_1, WP_VOR_1}},                                                       // 45. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 46. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                 // 47. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWOELF_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 48. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ELF_1, WP_MINUTEN_1, WP_VOR_1}},                                             // 49. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 50. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 51. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 52. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 53. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1}},                                           // 54. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1}},                                           // 55. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 56. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 57. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1}},                                            // 58. Minute in Mode MM_7
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1}}                                              // 59. Minute in Mode MM_7
    },
    {   // tbl_minutes[7][] = Mode 8 MM
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{0}},                                                                            //  0. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EINS_2}},                                                                    //  1. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_2}},                                                                    //  2. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_2}},                                                                    //  3. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_2}},                                                                    //  4. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_2}},                                                                   //  5. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_2}},                                                                   //  6. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_2}},                                                                  //  7. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_2}},                                                                    //  8. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_2}},                                                                    //  9. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZEHN_2}},                                                                    // 10. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ELF_2}},                                                                     // 11. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWOELF_2}},                                                                  // 12. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_2, WP_ZEHN_2}},                                                         // 13. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_2, WP_ZEHN_2}},                                                         // 14. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_2, WP_ZEHN_2}},                                                        // 15. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECH_2, WP_ZEHN_2}},                                                         // 16. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEB_2, WP_ZEHN_2}},                                                         // 17. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_2, WP_ZEHN_2}},                                                         // 18. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_2, WP_ZEHN_2}},                                                         // 19. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWANZIG_2}},                                                                 // 20. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_4, WP_UND_3, WP_ZWANZIG_2}},                                             // 21. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_2, WP_UND_3, WP_ZWANZIG_2}},                                            // 22. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_2, WP_UND_3, WP_ZWANZIG_2}},                                            // 23. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_2, WP_UND_3, WP_ZWANZIG_2}},                                            // 24. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_2, WP_UND_3, WP_ZWANZIG_2}},                                           // 25. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_2, WP_UND_3, WP_ZWANZIG_2}},                                           // 26. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_2, WP_UND_3, WP_ZWANZIG_2}},                                          // 27. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_2, WP_UND_3, WP_ZWANZIG_2}},                                            // 28. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_2, WP_UND_3, WP_ZWANZIG_2}},                                            // 29. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREISSIG_2}},                                                                // 30. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_4, WP_UND_3, WP_DREISSIG_2}},                                            // 31. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_2, WP_UND_3, WP_DREISSIG_2}},                                           // 32. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_2, WP_UND_3, WP_DREISSIG_2}},                                           // 33. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_2, WP_UND_3, WP_DREISSIG_2}},                                           // 34. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_2, WP_UND_3, WP_DREISSIG_2}},                                          // 35. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_2, WP_UND_3, WP_DREISSIG_2}},                                          // 36. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_2, WP_UND_3, WP_DREISSIG_2}},                                         // 37. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_2, WP_UND_3, WP_DREISSIG_2}},                                           // 38. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_2, WP_UND_3, WP_DREISSIG_2}},                                           // 39. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIERZIG_2}},                                                                 // 40. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_4, WP_UND_3, WP_VIERZIG_2}},                                             // 41. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_2, WP_UND_3, WP_VIERZIG_2}},                                            // 42. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_2, WP_UND_3, WP_VIERZIG_2}},                                            // 43. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_2, WP_UND_3, WP_VIERZIG_2}},                                            // 44. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_2, WP_UND_3, WP_VIERZIG_2}},                                           // 45. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_2, WP_UND_3, WP_VIERZIG_2}},                                           // 46. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_2, WP_UND_3, WP_VIERZIG_2}},                                          // 47. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_2, WP_UND_3, WP_VIERZIG_2}},                                            // 48. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_2, WP_UND_3, WP_VIERZIG_2}},                                            // 49. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENFZIG_2}},                                                                // 50. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_4, WP_UND_3, WP_FUENFZIG_2}},                                            // 51. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_2, WP_UND_3, WP_FUENFZIG_2}},                                           // 52. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_2, WP_UND_3, WP_FUENFZIG_2}},                                           // 53. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_2, WP_UND_3, WP_FUENFZIG_2}},                                           // 54. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_2, WP_UND_3, WP_FUENFZIG_2}},                                          // 55. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_2, WP_UND_3, WP_FUENFZIG_2}},                                          // 56. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_2, WP_UND_3, WP_FUENFZIG_2}},                                         // 57. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_2, WP_UND_3, WP_FUENFZIG_2}},                                           // 58. Minute in Mode MM_8
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_2, WP_UND_3, WP_FUENFZIG_2}}                                            // 59. Minute in Mode MM_8
    },
    {   // tbl_minutes[8][] = Mode 9 UND MM MINUTEN
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{0}},                                                                            //  0. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_EINE_2, WP_MINUTE_2}},                                             //  1. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ZWEI_2, WP_MINUTEN_2}},                                            //  2. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_DREI_2, WP_MINUTEN_2}},                                            //  3. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_VIER_2, WP_MINUTEN_2}},                                            //  4. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_FUENF_2, WP_MINUTEN_2}},                                           //  5. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SECHS_2, WP_MINUTEN_2}},                                           //  6. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SIEBEN_2, WP_MINUTEN_2}},                                          //  7. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ACHT_2, WP_MINUTEN_2}},                                            //  8. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_NEUN_2, WP_MINUTEN_2}},                                            //  9. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ZEHN_2, WP_MINUTEN_2}},                                            // 10. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ELF_2, WP_MINUTEN_2}},                                             // 11. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ZWOELF_2, WP_MINUTEN_2}},                                          // 12. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_DREI_2, WP_ZEHN_2, WP_MINUTEN_2}},                                 // 13. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_VIER_2, WP_ZEHN_2, WP_MINUTEN_2}},                                 // 14. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_FUENF_2, WP_ZEHN_2, WP_MINUTEN_2}},                                // 15. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SECH_2, WP_ZEHN_2, WP_MINUTEN_2}},                                 // 16. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SIEB_2, WP_ZEHN_2, WP_MINUTEN_2}},                                 // 17. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ACHT_2, WP_ZEHN_2, WP_MINUTEN_2}},                                 // 18. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_NEUN_2, WP_ZEHN_2, WP_MINUTEN_2}},                                 // 19. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ZWANZIG_2, WP_MINUTEN_2}},                                         // 20. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_EIN_4, WP_UND_3, WP_ZWANZIG_2, WP_MINUTEN_2}},                     // 21. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ZWEI_2, WP_UND_3, WP_ZWANZIG_2, WP_MINUTEN_2}},                    // 22. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_DREI_2, WP_UND_3, WP_ZWANZIG_2, WP_MINUTEN_2}},                    // 23. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_VIER_2, WP_UND_3, WP_ZWANZIG_2, WP_MINUTEN_2}},                    // 24. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_FUENF_2, WP_UND_3, WP_ZWANZIG_2, WP_MINUTEN_2}},                   // 25. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SECHS_2, WP_UND_3, WP_ZWANZIG_2, WP_MINUTEN_2}},                   // 26. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SIEBEN_2, WP_UND_3, WP_ZWANZIG_2, WP_MINUTEN_2}},                  // 27. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ACHT_2, WP_UND_3, WP_ZWANZIG_2, WP_MINUTEN_2}},                    // 28. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_NEUN_2, WP_UND_3, WP_ZWANZIG_2, WP_MINUTEN_2}},                    // 29. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_DREISSIG_2, WP_MINUTEN_2}},                                        // 30. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_EIN_4, WP_UND_3, WP_DREISSIG_2, WP_MINUTEN_2}},                    // 31. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ZWEI_2, WP_UND_3, WP_DREISSIG_2, WP_MINUTEN_2}},                   // 32. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_DREI_2, WP_UND_3, WP_DREISSIG_2, WP_MINUTEN_2}},                   // 33. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_VIER_2, WP_UND_3, WP_DREISSIG_2, WP_MINUTEN_2}},                   // 34. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_FUENF_2, WP_UND_3, WP_DREISSIG_2, WP_MINUTEN_2}},                  // 35. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SECHS_2, WP_UND_3, WP_DREISSIG_2, WP_MINUTEN_2}},                  // 36. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SIEBEN_2, WP_UND_3, WP_DREISSIG_2, WP_MINUTEN_2}},                 // 37. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ACHT_2, WP_UND_3, WP_DREISSIG_2, WP_MINUTEN_2}},                   // 38. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_NEUN_2, WP_UND_3, WP_DREISSIG_2, WP_MINUTEN_2}},                   // 39. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_VIERZIG_2, WP_MINUTEN_2}},                                         // 40. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_EIN_4, WP_UND_3, WP_VIERZIG_2, WP_MINUTEN_2}},                     // 41. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ZWEI_2, WP_UND_3, WP_VIERZIG_2, WP_MINUTEN_2}},                    // 42. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_DREI_2, WP_UND_3, WP_VIERZIG_2, WP_MINUTEN_2}},                    // 43. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_VIER_2, WP_UND_3, WP_VIERZIG_2, WP_MINUTEN_2}},                    // 44. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_FUENF_2, WP_UND_3, WP_VIERZIG_2, WP_MINUTEN_2}},                   // 45. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SECHS_2, WP_UND_3, WP_VIERZIG_2, WP_MINUTEN_2}},                   // 46. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SIEBEN_2, WP_UND_3, WP_VIERZIG_2, WP_MINUTEN_2}},                  // 47. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ACHT_2, WP_UND_3, WP_VIERZIG_2, WP_MINUTEN_2}},                    // 48. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_NEUN_2, WP_UND_3, WP_VIERZIG_2, WP_MINUTEN_2}},                    // 49. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_FUENFZIG_2, WP_MINUTEN_2}},                                        // 50. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_EIN_4, WP_UND_3, WP_FUENFZIG_2, WP_MINUTEN_2}},                    // 51. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ZWEI_2, WP_UND_3, WP_FUENFZIG_2, WP_MINUTEN_2}},                   // 52. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_DREI_2, WP_UND_3, WP_FUENFZIG_2, WP_MINUTEN_2}},                   // 53. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_VIER_2, WP_UND_3, WP_FUENFZIG_2, WP_MINUTEN_2}},                   // 54. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_FUENF_2, WP_UND_3, WP_FUENFZIG_2, WP_MINUTEN_2}},                  // 55. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SECHS_2, WP_UND_3, WP_FUENFZIG_2, WP_MINUTEN_2}},                  // 56. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_SIEBEN_2, WP_UND_3, WP_FUENFZIG_2, WP_MINUTEN_2}},                 // 57. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_ACHT_2, WP_UND_3, WP_FUENFZIG_2, WP_MINUTEN_2}},                   // 58. Minute in Mode MM_9
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_UND_2, WP_NEUN_2, WP_UND_3, WP_FUENFZIG_2, WP_MINUTEN_2}}                    // 59. Minute in Mode MM_9
    },
    {   // tbl_minutes[9][] = Mode 10 MM MINUTEN VOR
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{0}},                                                                         //  0. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_VOR_1}},                //  1. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_VOR_1}},                //  2. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_VOR_1}},              //  3. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_VOR_1}},               //  4. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_VOR_1}},               //  5. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_VOR_1}},                //  6. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_VOR_1}},                //  7. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_VOR_1}},                //  8. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EIN_1, WP_UND_1, WP_FUENFZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 //  9. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENFZIG_1, WP_MINUTEN_1, WP_VOR_1}},                                     // 10. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 11. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 12. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_VOR_1}},               // 13. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_VOR_1}},                // 14. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_VOR_1}},                // 15. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 16. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 17. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 18. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EIN_1, WP_UND_1, WP_VIERZIG_1, WP_MINUTEN_1, WP_VOR_1}},                  // 19. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                                      // 20. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_VOR_1}},                // 21. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_VOR_1}},                // 22. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_VOR_1}},              // 23. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_VOR_1}},               // 24. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_VOR_1}},               // 25. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_VOR_1}},                // 26. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_VOR_1}},                // 27. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_VOR_1}},                // 28. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EIN_1, WP_UND_1, WP_DREISSIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 29. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREISSIG_1, WP_MINUTEN_1, WP_VOR_1}},                                     // 30. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 31. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 32. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},               // 33. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                // 34. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                // 35. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 36. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 37. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                 // 38. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EIN_1, WP_UND_1, WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                  // 39. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWANZIG_1, WP_MINUTEN_1, WP_VOR_1}},                                      // 40. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                              // 41. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                              // 42. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEB_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                              // 43. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                             // 44. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                             // 45. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                              // 46. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                              // 47. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWOELF_1, WP_MINUTEN_1, WP_VOR_1}},                                       // 48. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ELF_1, WP_MINUTEN_1, WP_VOR_1}},                                          // 49. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZEHN_1, WP_MINUTEN_1, WP_VOR_1}},                                         // 50. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_NEUN_1, WP_MINUTEN_1, WP_VOR_1}},                                         // 51. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ACHT_1, WP_MINUTEN_1, WP_VOR_1}},                                         // 52. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SIEBEN_1, WP_MINUTEN_1, WP_VOR_1}},                                       // 53. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_SECHS_1, WP_MINUTEN_1, WP_VOR_1}},                                        // 54. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_FUENF_1, WP_MINUTEN_1, WP_VOR_1}},                                        // 55. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_VIER_1, WP_MINUTEN_1, WP_VOR_1}},                                         // 56. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_DREI_1, WP_MINUTEN_1, WP_VOR_1}},                                         // 57. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_ZWEI_1, WP_MINUTEN_1, WP_VOR_1}},                                         // 58. Minute in Mode MM_10
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1,{WP_EINE_1, WP_MINUTE_1, WP_VOR_1}}                                           // 59. Minute in Mode MM_10
    },
    {   // tbl_minutes[10][] = Mode 11 TEMPERATUR "CC GRAD"
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZEHN_1, WP_GRAD}},                                                        //  0. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZEHN_1, WP_EIN_3, WP_HALB, WP_GRAD}},                                     //  1. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ELF_1, WP_GRAD}},                                                         //  2. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ELF_1, WP_EIN_3, WP_HALB, WP_GRAD}},                                      //  3. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWOELF_1, WP_GRAD}},                                                      //  4. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWOELF_1, WP_EIN_3, WP_HALB, WP_GRAD}},                                   //  5. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_ZEHN_1, WP_GRAD}},                                             //  6. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_ZEHN_1, WP_EIN_3, WP_HALB, WP_GRAD}},                          //  7. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_ZEHN_1, WP_GRAD}},                                             //  8. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_ZEHN_1, WP_EIN_3, WP_HALB, WP_GRAD}},                          //  9. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_ZEHN_1, WP_GRAD}},                                            // 10. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_ZEHN_1, WP_EIN_3, WP_HALB, WP_GRAD}},                         // 11. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECH_1, WP_ZEHN_1, WP_GRAD}},                                             // 12. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECH_1, WP_ZEHN_1, WP_EIN_3, WP_HALB, WP_GRAD}},                          // 13. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEB_1, WP_ZEHN_1, WP_GRAD}},                                             // 14. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEB_1, WP_ZEHN_1, WP_EIN_3, WP_HALB, WP_GRAD}},                          // 15. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_ZEHN_1, WP_GRAD}},                                             // 16. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_ZEHN_1, WP_EIN_3, WP_HALB, WP_GRAD}},                          // 17. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_ZEHN_1, WP_GRAD}},                                             // 18. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_ZEHN_1, WP_EIN_3, WP_HALB, WP_GRAD}},                          // 19. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWANZIG_1, WP_GRAD}},                                                     // 20. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWANZIG_1, WP_EIN_3, WP_HALB, WP_GRAD}},                                  // 21. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_ZWANZIG_1, WP_GRAD}},                                 // 22. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_ZWANZIG_1, WP_EIN_3, WP_HALB, WP_GRAD}},              // 23. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_ZWANZIG_1, WP_GRAD, WP_WARM}},                       // 24. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_ZWANZIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},    // 25. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_ZWANZIG_1, WP_GRAD, WP_WARM}},                       // 26. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_ZWANZIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},    // 27. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_ZWANZIG_1, WP_GRAD, WP_WARM}},                       // 28. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_ZWANZIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},    // 29. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_ZWANZIG_1, WP_GRAD, WP_WARM}},                      // 30. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_ZWANZIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},   // 31. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_ZWANZIG_1, WP_GRAD, WP_WARM}},                      // 32. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_ZWANZIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},   // 33. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_ZWANZIG_1, WP_GRAD, WP_WARM}},                     // 34. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_ZWANZIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},  // 35. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_ZWANZIG_1, WP_GRAD, WP_WARM}},                       // 36. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_ZWANZIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},    // 37. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_ZWANZIG_1, WP_GRAD, WP_WARM}},                       // 38. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_ZWANZIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},    // 39. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREISSIG_1, WP_GRAD, WP_WARM}},                                           // 40. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREISSIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},                        // 41. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_DREISSIG_1, WP_GRAD, WP_WARM}},                       // 42. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_EIN_1, WP_UND_1, WP_DREISSIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},    // 43. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_DREISSIG_1, WP_GRAD, WP_WARM}},                      // 44. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ZWEI_1, WP_UND_1, WP_DREISSIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},   // 45. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_DREISSIG_1, WP_GRAD, WP_WARM}},                      // 46. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_DREI_1, WP_UND_1, WP_DREISSIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},   // 47. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_DREISSIG_1, WP_GRAD, WP_WARM}},                      // 48. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_VIER_1, WP_UND_1, WP_DREISSIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},   // 49. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_DREISSIG_1, WP_GRAD, WP_WARM}},                     // 50. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_FUENF_1, WP_UND_1, WP_DREISSIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},  // 51. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_DREISSIG_1, WP_GRAD, WP_WARM}},                     // 52. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SECHS_1, WP_UND_1, WP_DREISSIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},  // 53. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_DREISSIG_1, WP_GRAD, WP_WARM}},                    // 54. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_SIEBEN_1, WP_UND_1, WP_DREISSIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}}, // 55. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_DREISSIG_1, WP_GRAD, WP_WARM}},                      // 56. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_ACHT_1, WP_UND_1, WP_DREISSIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}},   // 57. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_DREISSIG_1, WP_GRAD, WP_WARM}},                      // 58. Minute in Mode MM_11
        {MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0,{WP_NEUN_1, WP_UND_1, WP_DREISSIG_1, WP_EIN_3, WP_HALB, WP_GRAD, WP_WARM}}    // 59. Minute in Mode MM_11
    },
};

const struct WordIllu illumination[WP_COUNT]=
{
    {  0,  0,  0 },                                                                         // 0 = WP_END_OF_WORDS      = ""
    {  0,  0,  2 },                                                                         // 1 = WP_ES                = "ES"
    {  0,  0,  2 },                                                                         // 2 = WP_IT                = "IT"
    {  0,  3,  3 },                                                                         // 3 = WP_IST               = "IST"
    {  0,  3,  2 },                                                                         // 4 = WP_IS                = "IS"
    {  0,  7,  7 },                                                                         // 5 = WP_VIERTEL_1         = "VIERTEL"
    {  0, 14,  4 },                                                                         // 6 = WP_NEIN              = "NEIN"
    {  0, 15,  3 },                                                                         // 7 = WP_EIN_1             = "EIN"
    {  0, 15,  4 },                                                                         // 8 = WP_EINS_1            = "EINS"
    {  0, 16,  2 },                                                                         // 9 = WP_IN                = "IN"
    {  1,  0,  4 },                                                                         // 10 = WP_DREI_1           = "DREI"
    {  1,  2,  3 },                                                                         // 11 = WP_EIN_2            = "EIN"
    {  1,  2,  4 },                                                                         // 12 = WP_EINE_1           = "EINE"
    {  1,  2,  5 },                                                                         // 13 = WP_EINER            = "EINER"
    {  1,  7,  4 },                                                                         // 14 = WP_SECH_1           = "SECH"
    {  1,  7,  5 },                                                                         // 15 = WP_SECHS_1          = "SECHS"
    {  1, 11,  4 },                                                                         // 16 = WP_SIEB_1           = "SIEB"
    {  1, 11,  6 },                                                                         // 17 = WP_SIEBEN_1         = "SIEBEN"
    {  2,  0,  3 },                                                                         // 18 = WP_ELF_1            = "ELF"
    {  2,  2,  4 },                                                                         // 19 = WP_FUENF_1          = "F�NF"
    {  2,  6,  4 },                                                                         // 20 = WP_NEUN_1           = "NEUN"
    {  2, 10,  4 },                                                                         // 21 = WP_VIER_1           = "VIER"
    {  2, 14,  4 },                                                                         // 22 = WP_ACHT_1           = "ACHT"
    {  3,  0,  4 },                                                                         // 23 = WP_NULL_1           = "NULL"
    {  3,  4,  4 },                                                                         // 24 = WP_ZWEI_1           = "ZWEI"
    {  3,  9,  5 },                                                                         // 25 = WP_ZWOELF_1         = "ZW�LF"
    {  3, 14,  4 },                                                                         // 26 = WP_ZEHN_1           = "ZEHN"
    {  4,  0,  3 },                                                                         // 27 = WP_UND_1            = "UND"
    {  4,  4,  7 },                                                                         // 28 = WP_ZWANZIG_1        = "ZWANZIG"
    {  4, 11,  7 },                                                                         // 29 = WP_VIERZIG_1        = "VIERZIG"
    {  5,  0,  8 },                                                                         // 30 = WP_DREISSIG_1       = "DREISSIG"
    {  5,  8,  7 },                                                                         // 31 = WP_FUENFZIG_1       = "F�NFZIG"
    {  5, 15,  3 },                                                                         // 32 = WP_UHR_1            = "UHR"
    {  6,  0,  6 },                                                                         // 33 = WP_MINUTE_1         = "MINUTE"
    {  6,  0,  7 },                                                                         // 34 = WP_MINUTEN_1        = "MINUTEN"
    {  6,  8,  3 },                                                                         // 35 = WP_VOR_1            = "VOR"
    {  6, 11,  3 },                                                                         // 36 = WP_UND_2            = "UND"
    {  6, 14,  4 },                                                                         // 37 = WP_NACH_1           = "NACH"
    {  6, 14,  5 },                                                                         // 38 = WP_NACHT_1          = "NACHT"
    {  7,  0,  5 },                                                                         // 39 = WP_WOCHE            = "WOCHE"
    {  7,  0,  6 },                                                                         // 40 = WP_WOCHEN           = "WOCHEN"
    {  7,  6,  3 },                                                                         // 41 = WP_IST              = "IST"
    {  7,  8,  3 },                                                                         // 42 = WP_TAG              = "TAG"
    {  7,  8,  4 },                                                                         // 43 = WP_TAGE             = "TAGE"
    {  7,  8,  5 },                                                                         // 44 = WP_TAGEN            = "TAGEN"
    {  7, 13,  6 },                                                                         // 45 = WP_KAFFEE           = "KAFFEE"
    {  7, 14,  4 },                                                                         // 46 = WP_AFFE             = "AFFE"
    {  8,  0,  5 },                                                                         // 47 = WP_FEIND            = "FEIND"
    {  8,  1,  3 },                                                                         // 48 = WP_EIN_3            = "EIN"
    {  8,  4, 11 },                                                                         // 49 = WP_DREIVIERTEL      = "DREIVIERTEL"
    {  8,  8,  7 },                                                                         // 50 = WP_VIERTEL_2        = "VIERTEL"
    {  8, 15,  4 },                                                                         // 51 = WP_HALB             = "HALB"
    {  9,  0,  4 },                                                                         // 52 = WP_SIEB_2           = "SIEB"
    {  9,  0,  6 },                                                                         // 53 = WP_SIEBEN_2         = "SIEBEN"
    {  9,  5,  4 },                                                                         // 54 = WP_NEUN_2           = "NEUN"
    {  9,  8,  4 },                                                                         // 55 = WP_NULL_2           = "NULL"
    {  9, 12,  4 },                                                                         // 56 = WP_ZWEI_2           = "ZWEI"
    {  9, 13,  4 },                                                                         // 57 = WP_WEIN             = "WEIN"
    {  9, 14,  3 },                                                                         // 58 = WP_EIN_4            = "EIN"
    {  9, 14,  4 },                                                                         // 59 = WP_EINE_2           = "EINE"
    { 10,  0,  4 },                                                                         // 60 = WP_FUENF_2          = "F�NF"
    { 10,  4,  4 },                                                                         // 61 = WP_SECH_2           = "SECH"
    { 10,  4,  5 },                                                                         // 62 = WP_SECHS_2          = "SECHS"
    { 10,  9,  5 },                                                                         // 63 = WP_NACHT_2          = "NACHT"
    { 10, 10,  4 },                                                                         // 64 = WP_ACHT_2           = "ACHT"
    { 10, 14,  4 },                                                                         // 65 = WP_VIER_2           = "VIER"
    { 11,  0,  4 },                                                                         // 66 = WP_DREI_2           = "DREI"
    { 11,  2,  3 },                                                                         // 67 = WP_EIN_5            = "EIN"
    { 11,  2,  4 },                                                                         // 68 = WP_EINS_2           = "EINS"
    { 11,  6,  3 },                                                                         // 69 = WP_UND_3            = "UND"
    { 11, 10,  3 },                                                                         // 70 = WP_ELF_2            = "ELF"
    { 11, 14,  4 },                                                                         // 71 = WP_ZEHN_2           = "ZEHN"
    { 12,  0,  7 },                                                                         // 72 = WP_ZWANZIG_2        = "ZWANZIG"
    { 12,  7,  4 },                                                                         // 73 = WP_GRAD             = "GRAD"
    { 12, 10,  8 },                                                                         // 74 = WP_DREISSIG_2       = "DREISSIG"
    { 13,  0,  7 },                                                                         // 75 = WP_VIERZIG_2        = "VIERZIG"
    { 13,  7,  5 },                                                                         // 76 = WP_ZWOELF_2         = "ZW�LF"
    { 13, 11,  7 },                                                                         // 77 = WP_FUENFZIG_2       = "F�NFZIG"
    { 14,  0,  6 },                                                                         // 78 = WP_MINUTE_2         = "MINUTE"
    { 14,  0,  7 },                                                                         // 79 = WP_MINUTEN_2        = "MINUTEN"
    { 14,  7,  3 },                                                                         // 80 = WP_IST_3            = "IST"
    { 14, 10,  3 },                                                                         // 81 = WP_UHR_2            = "UHR"
    { 14, 13,  4 },                                                                         // 82 = WP_KALT             = "KALT"
    { 14, 16,  3 },                                                                         // 83 = WP_TUER             = "T�R"
    { 15,  0,  4 },                                                                         // 84 = WP_FRUEH            = "FR�H"
    { 15, 4,  11 },                                                                         // 85 = WP_CAMPUSWOCHE      = "CAMPUSWOCHE"
    { 15, 15,  3 },                                                                         // 86 = WP_VOR_2            = "VOR"
    { 15, 16,  3 },                                                                         // 87 = WP_ORT              = "ORT"
    { 16,  0,  6 },                                                                         // 88 = WP_ABENDS           = "ABENDS"
    { 16,  6, 11 },                                                                         // 89 = WP_MITTERNACHT      = "MITTERNACHT"
    { 16, 12,  4 },                                                                         // 90 = WP_NACH_2           = "NACH"
    { 16, 12,  6 },                                                                         // 91 = WP_NACHTS           = "NACHTS"
    { 17,  0,  7 },                                                                         // 92 = WP_MORGENS          = "MORGENS"
    { 17,  7,  4 },                                                                         // 93 = WP_WARM             = "WARM"
    { 17, 11,  7 },                                                                         // 94 = WP_MITTAGS          = "MITTAGS"
    {  0, 18, -4 },                                                                         // 95 = WP_STOP             = "STOP"
    {  3, 18, -4 },                                                                         // 96 = WP_POST             = "POST"
    {  9, 18, -3 },                                                                         // 97 = WP_DER              = "DER"
    { 12, 18, -6 },                                                                         // 98 = WP_FERTIG           = "FERTIG"
    { 14, 16, -3 },                                                                         // 99 = WP_TOT              = "TOT"
    { 10, 13, -5 },                                                                         // 100 = WP_TRINK           = "TRINK"
    { 15, 13, -3 },                                                                         // 101 = WP_HAT             = "HAT"
    { 11,  9, -2 },                                                                         // 102 = WP_JA              = "JA"
    {  1,  7, -4 },                                                                         // 103 = WP_SEIN            = "SEIN"
    {  6,  6, -3 },                                                                         // 104 = WP_NIE             = "NIE"
 };

#endif // WCLOCK24H == 1
