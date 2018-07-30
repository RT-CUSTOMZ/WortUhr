/*-------------------------------------------------------------------------------------------------------------------------------------------
 * tables12h.c - tables for WordClock12h
 *
 * Copyright (c) 2016-2017 Frank Meyer - frank(at)fli4l.de
 *
 * Supported Layouts:
 *
 * German:
 *   ESKISTLFÜNF
 *   ZEHNZWANZIG
 *   DREIVIERTEL
 *   TGNACHVORJM
 *   HALBQZWÖLFP
 *   ZWEINSIEBEN
 *   KDREIRHFÜNF
 *   ELFNEUNVIER
 *   WACHTZEHNRS
 *   BSECHSFMUHR
 *
 * Swiss German Variant 1:
 *   ESKISCHAFÜF
 *   VIERTUBFZÄÄ
 *   ZWÄNZGSIVOR
 *   ABOHAUBIEPM
 *   EISZWÖISDRÜ
 *   VIERIFÜFIQT
 *   SÄCHSISIBNI
 *   ACHTINÜNIEL
 *   ZÄNIERBEUFI
 *   ZWÖUFIAMUHR
 *
 * Swiss German Variant 2:
 *   ESKESCHAZÄÄ
 *   FÖIFCVIERTU
 *   ZWÄNZGSIVOR
 *   ABOHAUBIEGE
 *   EISZWÖISDRÜ
 *   VIERITFÖIFI
 *   SÄCHSISEBNI
 *   ACHTIENÜNIL
 *   ZÄNIERBRLFI
 *   ZWÖLFINAUHR
 *
 * English Variant 1:
 *   ITLISASAMPM
 *   ACQUARTERDC
 *   TWENTYFIVEX
 *   HALFSTENFTO
 *   PASTERUNINE
 *   ONESIXTHREE
 *   FOURFIVETWO
 *   EIGHTELEVEN
 *   SEVENTWELVE
 *   TENSEOCLOCK
 *
 * English Variant 2:
 *   ITKISGHALFE
 *   TENYQUARTER
 *   DTWENTYFIVE
 *   TOPASTEFOUR
 *   FIVETWONINE
 *   THREETWELVE
 *   BELEVENONES
 *   SEVENWEIGHT
 *   ITENSIXTIES
 *   TINEOICLOCK
 *
 * Swedish:
 *   KLOCKANTÄRK
 *   FEMYISTIONI
 *   KVARTQIENZO
 *   TJUGOLIVIPM
 *   ÖVERKAMHALV
 *   ETTUSVLXTVA
 *   TREMYKYFYRA
 *   FEMSFLORSEX
 *   SJUÄTTAINIO
 *   TIOELVATOLV
 *
 * French:
 *   ILNESTODEUX
 *   QUATRETROIS
 *   NEUFUNESEPT
 *   HUITSIXCINQ
 *   MIDIXMINUIT
 *   ONZERHEURES
 *   MOINSOLEDIX
 *   ETRQUARTPMD
 *   VINGT-CINQU
 *   ETSDEMIEPAM
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *-------------------------------------------------------------------------------------------------------------------------------------------
 */
#include "wclock24h-config.h"

#if WCLOCK24H == 0
#include "tables12h.h"

const char * tbl_modes[MODES_COUNT] =
{
    "WESSI",
    "OSSI",
    "RHEIN-RUHR",
    "SCHWABEN",
    "SCHWEIZERDEUTSCH 1",
    "SCHWEIZERDEUTSCH 2",
    "ENGLISH 1",
    "ENGLISH 2",
    "SWEDISH",
    "FRANCAIS",
};

const uint8_t tbl_it_is[IT_IS_MODES_COUNT][2] =
{
    { WP_ES, WP_IST },
    { WP_ES_CH, WP_ISCH_CH },
    { WP_IT_EN, WP_IS_EN },
    { WP_KLOCKAN, WP_AER },
    { WP_IL, WP_EST },
};

const uint8_t tbl_hours[HOUR_MODES_COUNT][HOUR_COUNT][MAX_HOUR_WORDS] =
{
    // GERMAN
    {                                                               // tbl_hours[0][] = hh:00
        {WP_ZWOELF,   WP_UHR},                                      // 00:00
        {WP_EIN,      WP_UHR},                                      // 01:00
        {WP_ZWEI,     WP_UHR},                                      // 02:00
        {WP_DREI_2,   WP_UHR},                                      // 03:00
        {WP_VIER_2,   WP_UHR},                                      // 04:00
        {WP_FUENF_2,  WP_UHR},                                      // 05:00
        {WP_SECHS,    WP_UHR},                                      // 06:00
        {WP_SIEBEN,   WP_UHR},                                      // 07:00
        {WP_ACHT,     WP_UHR},                                      // 08:00
        {WP_NEUN,     WP_UHR},                                      // 09:00
        {WP_ZEHN_2,   WP_UHR},                                      // 10:00
        {WP_ELF,      WP_UHR}                                       // 11:00
    },
    {                                                               // tbl_hours[1][] = hh:mm (not hh:00)
        {WP_ZWOELF},                                                // 00:mm
        {WP_EINS},                                                  // 01:mm
        {WP_ZWEI},                                                  // 02:mm
        {WP_DREI_2},                                                // 03:mm
        {WP_VIER_2},                                                // 04:mm
        {WP_FUENF_2},                                               // 05:mm
        {WP_SECHS},                                                 // 06:mm
        {WP_SIEBEN},                                                // 07:mm
        {WP_ACHT},                                                  // 08:mm
        {WP_NEUN},                                                  // 09:mm
        {WP_ZEHN_2},                                                // 10:mm
        {WP_ELF}                                                    // 11:mm
    },

    // SWISS1
    {                                                               // tbl_hours[2][] = hh:mm (not hh:00)
        {WP_ZWOEUFI_CH},                                            // 00:mm
        {WP_EIS_CH},                                                // 01:mm
        {WP_ZWOEI_CH},                                              // 02:mm
        {WP_DRUE_CH},                                               // 03:mm
        {WP_VIERI_CH},                                              // 04:mm
        {WP_FUEFI_CH},                                              // 05:mm
        {WP_SAECHSI_CH},                                            // 06:mm
        {WP_SIBNI_CH},                                              // 07:mm
        {WP_ACHTI_CH},                                              // 08:mm
        {WP_NUENI_CH},                                              // 09:mm
        {WP_ZAENI_CH},                                              // 10:mm
        {WP_EUFI_CH}                                                // 11:mm
    },

    // SWISS2
    {                                                               // tbl_hours[3][] = hh:mm (not hh:00)
        {WP_ZWOELFI_CH2},                                           // 00:mm
        {WP_EIS_CH2},                                               // 01:mm
        {WP_ZWOEI_CH2},                                             // 02:mm
        {WP_DRUE_CH2},                                              // 03:mm
        {WP_VIERI_CH2},                                             // 04:mm
        {WP_FOEIFI_CH2},                                            // 05:mm
        {WP_SAECHSI_CH2},                                           // 06:mm
        {WP_SEBNI_CH2},                                             // 07:mm
        {WP_ACHTI_CH2},                                             // 08:mm
        {WP_NUENI_CH2},                                             // 09:mm
        {WP_ZAENI_CH2},                                             // 10:mm
        {WP_ELFI_CH2}                                               // 11:mm
    },

    // ENGLISH1
    {                                                               // tbl_hours[4][] = hh:00
        {WP_TWELVE_EN, WP_OCLOCK_EN},                               // 00:00
        {WP_ONE_EN,    WP_OCLOCK_EN},                               // 01:00
        {WP_TWO_EN,    WP_OCLOCK_EN},                               // 02:00
        {WP_THREE_EN,  WP_OCLOCK_EN},                               // 03:00
        {WP_FOUR_EN,   WP_OCLOCK_EN},                               // 04:00
        {WP_FIVE_2_EN, WP_OCLOCK_EN},                               // 05:00
        {WP_SIX_EN,    WP_OCLOCK_EN},                               // 06:00
        {WP_SEVEN_EN,  WP_OCLOCK_EN},                               // 07:00
        {WP_EIGHT_EN,  WP_OCLOCK_EN},                               // 08:00
        {WP_NINE_EN,   WP_OCLOCK_EN},                               // 09:00
        {WP_TEN_2_EN,  WP_OCLOCK_EN},                               // 10:00
        {WP_ELEVEN_EN, WP_OCLOCK_EN}                                // 11:00
    },
    {                                                               // tbl_hours[5][] = hh:mm (not hh:00)
        {WP_TWELVE_EN},                                             // 00:mm
        {WP_ONE_EN},                                                // 01:mm
        {WP_TWO_EN},                                                // 02:mm
        {WP_THREE_EN},                                              // 03:mm
        {WP_FOUR_EN},                                               // 04:mm
        {WP_FIVE_2_EN},                                             // 05:mm
        {WP_SIX_EN},                                                // 06:mm
        {WP_SEVEN_EN},                                              // 07:mm
        {WP_EIGHT_EN},                                              // 08:mm
        {WP_NINE_EN},                                               // 09:mm
        {WP_TEN_2_EN},                                              // 10:mm
        {WP_ELEVEN_EN}                                              // 11:mm
    },

    // ENGLISH2
    {                                                               // tbl_hours[6][] = hh:00
        {WP_TWELVE_EN2, WP_O_EN2, WP_CLOCK_EN2},                    // 00:00
        {WP_ONE_EN2,    WP_O_EN2, WP_CLOCK_EN2},                    // 01:00
        {WP_TWO_EN2,    WP_O_EN2, WP_CLOCK_EN2},                    // 02:00
        {WP_THREE_EN2,  WP_O_EN2, WP_CLOCK_EN2},                    // 03:00
        {WP_FOUR_EN2,   WP_O_EN2, WP_CLOCK_EN2},                    // 04:00
        {WP_FIVE_2_EN2, WP_O_EN2, WP_CLOCK_EN2},                    // 05:00
        {WP_SIX_EN2,    WP_O_EN2, WP_CLOCK_EN2},                    // 06:00
        {WP_SEVEN_EN2,  WP_O_EN2, WP_CLOCK_EN2},                    // 07:00
        {WP_EIGHT_EN2,  WP_O_EN2, WP_CLOCK_EN2},                    // 08:00
        {WP_NINE_EN2,   WP_O_EN2, WP_CLOCK_EN2},                    // 09:00
        {WP_TEN_2_EN2,  WP_O_EN2, WP_CLOCK_EN2},                    // 10:00
        {WP_ELEVEN_EN2, WP_O_EN2, WP_CLOCK_EN2}                     // 11:00
    },
    {                                                               // tbl_hours[7][] = hh:mm (not hh:00)
        {WP_TWELVE_EN2},                                            // 00:mm
        {WP_ONE_EN2},                                               // 01:mm
        {WP_TWO_EN2},                                               // 02:mm
        {WP_THREE_EN2},                                             // 03:mm
        {WP_FOUR_EN2},                                              // 04:mm
        {WP_FIVE_2_EN2},                                            // 05:mm
        {WP_SIX_EN2},                                               // 06:mm
        {WP_SEVEN_EN2},                                             // 07:mm
        {WP_EIGHT_EN2},                                             // 08:mm
        {WP_NINE_EN2},                                              // 09:mm
        {WP_TEN_2_EN2},                                             // 10:mm
        {WP_ELEVEN_EN2}                                             // 11:mm
    },

    // SWEDISH
    {                                                               // tbl_hours[8][] = hh:mm
        {WP_TOLV},                                                  // 00:00
        {WP_ETT},                                                   // 01:00
        {WP_TVA},                                                   // 02:00
        {WP_TRE},                                                   // 03:00
        {WP_FYRA},                                                  // 04:00
        {WP_FEM_2},                                                 // 05:00
        {WP_SEX},                                                   // 06:00
        {WP_SJU},                                                   // 07:00
        {WP_ATTA},                                                  // 08:00
        {WP_NIO},                                                   // 09:00
        {WP_TIO_2},                                                 // 10:00
        {WP_ELVA}                                                   // 11:00
    },

    // FRENCH AM
    {                                                               // tbl_hours[9][] = hh:mm (AM)
        {WP_MINUIT},                                                // 00:00
        {WP_UNE, WP_HEURES},                                        // 01:00
        {WP_DEUX, WP_HEURES},                                       // 02:00
        {WP_TROIS, WP_HEURES},                                      // 03:00
        {WP_QUADRE, WP_HEURES},                                     // 04:00
        {WP_CINQ_1, WP_HEURES},                                     // 05:00
        {WP_SIX, WP_HEURES},                                        // 06:00
        {WP_SEPT, WP_HEURES},                                       // 07:00
        {WP_HUIT, WP_HEURES},                                       // 08:00
        {WP_NEUF, WP_HEURES},                                       // 09:00
        {WP_DIX_1, WP_HEURES},                                      // 10:00
        {WP_ONZE, WP_HEURES},                                       // 11:00
    },

    // FRENCH PM
    {                                                               // tbl_hours[10][] = hh:00 (PM)
        {WP_MIDI},                                                  // 00:00
        {WP_UNE, WP_HEURES},                                        // 01:00
        {WP_DEUX, WP_HEURES},                                       // 02:00
        {WP_TROIS, WP_HEURES},                                      // 03:00
        {WP_QUADRE, WP_HEURES},                                     // 04:00
        {WP_CINQ_1, WP_HEURES},                                     // 05:00
        {WP_SIX, WP_HEURES},                                        // 06:00
        {WP_SEPT, WP_HEURES},                                       // 07:00
        {WP_HUIT, WP_HEURES},                                       // 08:00
        {WP_NEUF, WP_HEURES},                                       // 09:00
        {WP_DIX_1, WP_HEURES},                                      // 10:00
        {WP_ONZE, WP_HEURES},                                       // 11:00
    }
};

const struct MinuteDisplay12 tbl_minutes[MODES_COUNT][MINUTE_COUNT] =
{
    {                                                               // tbl_minutes[0][] = WESSI
        {0, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {0}},                                                     // 00
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_FUENF_1, WP_NACH                          }},         // 05
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,  WP_NACH                          }},         // 10
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_VIERTEL, WP_NACH                          }},         // 15
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,  WP_VOR,  WP_HALB                 }},         // 20
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1, WP_VOR,  WP_HALB                 }},         // 25
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_HALB                                      }},         // 30
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1, WP_NACH, WP_HALB                 }},         // 35
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,  WP_NACH, WP_HALB                 }},         // 40
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_VIERTEL, WP_VOR                           }},         // 45
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,  WP_VOR                           }},         // 50
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1, WP_VOR                           }},         // 55
    },

    {                                                               // tbl_minutes[1][] = OSSI
        {0, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {0}},                                                     // 00
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_NACH                      }},         // 05
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,      WP_NACH                      }},         // 10
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_VIERTEL,                                  }},         // 45
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,      WP_VOR,  WP_HALB             }},         // 20
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_VOR,  WP_HALB             }},         // 25
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_HALB                                      }},         // 30
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_NACH, WP_HALB             }},         // 35
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,      WP_NACH, WP_HALB             }},         // 40
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_DREIVIERTEL                               }},         // 15
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,      WP_VOR                       }},         // 50
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_VOR                       }},         // 55
    },

    {                                                               // tbl_minutes[2][] = RHEIN-RUHR
        {0, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {0}},                                                     // 00
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_NACH                      }},         // 05
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,      WP_NACH                      }},         // 10
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_VIERTEL,     WP_NACH                      }},         // 15
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_ZWANZIG,     WP_NACH                      }},         // 20
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_VOR,  WP_HALB             }},         // 25
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_HALB                                      }},         // 30
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_NACH, WP_HALB             }},         // 35
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZWANZIG,     WP_VOR                       }},         // 40
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_VIERTEL,     WP_VOR                       }},         // 45
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,      WP_VOR                       }},         // 50
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_VOR                       }},         // 55
    },

    {                                                               // tbl_minutes[3][] = SCHWABEN
        {0, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {0}},                                                     // 00
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_NACH                      }},         // 05
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,      WP_NACH                      }},         // 10
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_VIERTEL,                                  }},         // 45
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_ZWANZIG,     WP_NACH                      }},         // 20
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_VOR,  WP_HALB             }},         // 25
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_HALB                                      }},         // 30
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_NACH, WP_HALB             }},         // 35
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZWANZIG,     WP_VOR                       }},         // 40
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_DREIVIERTEL,                              }},         // 15
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZEHN_1,      WP_VOR                       }},         // 50
        {1, MDF_IT_IS_GERMAN | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUENF_1,     WP_VOR                       }},         // 55
    },
    {                                                               // tbl_minutes[4][] = SCHWEIZERDEUTSCH1
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {0}},                                                     // 00
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_FUEF_CH,    WP_AB_CH                      }},         // 05
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_ZAEAE_CH,   WP_AB_CH                      }},         // 10
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_VIERTU_CH,  WP_AB_CH                      }},         // 15
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_ZWAENZG_CH, WP_AB_CH                      }},         // 20
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUEF_CH,    WP_VOR_CH, WP_HAUBI_CH        }},         // 25
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_HAUBI_CH                                  }},         // 30
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUEF_CH,    WP_AB_CH,  WP_HAUBI_CH        }},         // 35
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZWAENZG_CH, WP_VOR_CH                     }},         // 40
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_VIERTU_CH,  WP_VOR_CH                     }},         // 45
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZAEAE_CH,   WP_VOR_CH                     }},         // 50
        {2, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FUEF_CH,    WP_VOR_CH                     }},         // 55
    },
    {                                                               // tbl_minutes[5][] = SCHWEIZERDEUTSCH2
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {0}},                                                     // 00
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_FOIF_CH2,    WP_AB_CH2                    }},         // 05
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_ZAEAE_CH2,   WP_AB_CH2                    }},         // 10
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_VIERTU_CH2,  WP_AB_CH2                    }},         // 15
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_ZWAENZ_CH2,  WP_AB_CH2                    }},         // 20
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FOIF_CH2,    WP_VOR_CH2, WP_HAUBI_CH2     }},         // 25
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_HAUBI_CH2                                 }},         // 30
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FOIF_CH2,    WP_AB_CH2,  WP_HAUBI_CH2     }},         // 35
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZWAENZ_CH2,  WP_VOR_CH2                   }},         // 40
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_VIERTU_CH2,  WP_VOR_CH2                   }},         // 45
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_ZAEAE_CH2,   WP_VOR_CH2                   }},         // 50
        {3, MDF_IT_IS_SWISS  | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FOIF_CH2,    WP_VOR_CH2                   }},         // 55
    },
    {                                                               // tbl_minutes[6][] = ENGLISH var. 1
        {4, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {0}},                                                    // 00
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_FIVE_1_EN,  WP_PAST_EN                   }},         // 05
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_TEN_1_EN,   WP_PAST_EN                   }},         // 10
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_QUARTER_EN, WP_PAST_EN                   }},         // 15
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_TWENTY_EN,  WP_PAST_EN                   }},         // 20
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_TWENTY_EN,  WP_FIVE_1_EN, WP_PAST_EN     }},         // 25
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_HALF_EN,    WP_PAST_EN                   }},         // 30
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_TWENTY_EN,  WP_FIVE_1_EN, WP_TO_EN       }},         // 35
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_TWENTY_EN,  WP_TO_EN                     }},         // 40
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_QUARTER_EN, WP_TO_EN                     }},         // 45
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_TEN_1_EN,   WP_TO_EN                     }},         // 50
        {5, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FIVE_1_EN,  WP_TO_EN                     }},         // 55
    },
    {                                                               // tbl_minutes[7][] = ENGLISH var. 2
        {6, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {0}},                                                    // 00
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_FIVE_1_EN2,  WP_PAST_EN2                 }},         // 05
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_TEN_1_EN2,   WP_PAST_EN2                 }},         // 10
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_QUARTER_EN2, WP_PAST_EN2                 }},         // 15
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_TWENTY_EN2,  WP_PAST_EN2                 }},         // 20
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_TWENTY_EN2,  WP_FIVE_1_EN2, WP_PAST_EN2  }},         // 25
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_HALF_EN2,    WP_PAST_EN2                 }},         // 30
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_TWENTY_EN2,  WP_FIVE_1_EN2, WP_TO_EN2    }},         // 35
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_TWENTY_EN2,  WP_TO_EN2                   }},         // 40
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_QUARTER_EN2, WP_TO_EN2                   }},         // 45
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_TEN_1_EN2,   WP_TO_EN2                   }},         // 50
        {7, MDF_IT_IS_ENGLISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FIVE_1_EN2,  WP_TO_EN2                   }},         // 55
    },
    {                                                               // tbl_minutes[8][] = SWEDISH
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {0}},                                                    // 00
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_FEM_1, WP_OEVER                          }},         // 05
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_TIO_1, WP_OEVER                          }},         // 10
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_KVART, WP_OEVER                          }},         // 15
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_0, {WP_TJUGO, WP_OEVER                          }},         // 20
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FEM_1, WP_FEM_I, WP_HALV                 }},         // 25
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_HALV                                     }},         // 30
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FEM_1, WP_FEM_I, WP_HALV                 }},         // 35
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_TJUGO, WP_TJUGO_I                        }},         // 40
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_KVART, WP_KVART_I                        }},         // 45
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_TIO_1, WP_TIO_I                          }},         // 50
        {8, MDF_IT_IS_SWEDISH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_0, {WP_FEM_1, WP_FEM_I                          }},         // 55
    },
    {                                                               // tbl_minutes[9][] = FRENCH
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_1, {0}},                                                     // 00
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_1, {WP_CINQ_2                                    }},         // 05
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_1, {WP_DIX_2                                     }},         // 10
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_1, {WP_ET_1, WP_QUART                            }},         // 15
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_1, {WP_VINGT                                     }},         // 20
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_1, {WP_VINGTCINQ                                 }},         // 25
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_0 | MDF_AM_PM_MODE_1, {WP_ET_2, WP_DEMI                             }},         // 30
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_1, {WP_MOINS, WP_VINGTCINQ                       }},         // 35
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_1, {WP_MOINS, WP_VINGT                           }},         // 40
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_1, {WP_MOINS, WP_LE, WP_QUART                    }},         // 45
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_1, {WP_MOINS, WP_DIX_2                           }},         // 50
        {9, MDF_IT_IS_FRENCH | MDF_HOUR_OFFSET_1 | MDF_AM_PM_MODE_1, {WP_MOINS, WP_CINQ_2                          }},         // 55
    }
};

const struct WordIllu illumination[WP_COUNT] =
{
    {0,0,0},                                                        //  0 = WP_END_OF_WORDS = ""
    {0,0,2},                                                        //  1 = WP_ES           = "ES"
    {0,3,3},                                                        //  2 = WP_IST          = "IST"
    {0,7,4},                                                        //  3 = WP_FUENF_1      = "FÜNF"
    {1,0,4},                                                        //  4 = WP_ZEHN_1       = "ZEHN"
    {1,4,7},                                                        //  5 = WP_ZWANZIG      = "ZWANZIG"
    {2,0,4},                                                        //  6 = WP_DREI_1       = "DREI"
    {2,4,4},                                                        //  7 = WP_VIER         = "VIER"
    {2,4,7},                                                        //  8 = WP_VIERTEL      = "VIERTEL"
    {2,0,11},                                                       //  9 = WP_DREIVIERTEL  = "DREIVIERTEL"
    {3,2,4},                                                        // 10 = WP_NACH         = "NACH"
    {3,6,3},                                                        // 11 = WP_VOR          = "VOR"
    {4,0,4},                                                        // 12 = WP_HALB         = "HALB"
    {4,5,5},                                                        // 13 = WP_ZWOELF       = "ZWÖLF"
    {5,0,4},                                                        // 14 = WP_ZWEI         = "ZWEI"
    {5,2,3},                                                        // 15 = WP_EIN          = "EIN"
    {5,2,4},                                                        // 16 = WP_EINS         = "EINS"
    {5,5,6},                                                        // 17 = WP_SIEBEN       = "SIEBEN"
    {6,1,4},                                                        // 18 = WP_DREI_2       = "DREI"
    {6,7,4},                                                        // 19 = WP_FUENF_2      = "FÜNF"
    {7,0,3},                                                        // 20 = WP_ELF          = "ELF"
    {7,3,4},                                                        // 21 = WP_NEUN         = "NEUN"
    {7,7,4},                                                        // 22 = WP_VIER_2       = "VIER"
    {8,1,4},                                                        // 23 = WP_ACHT         = "ACHT"
    {8,5,4},                                                        // 24 = WP_ZEHN_2       = "ZEHN"
    {9,1,5},                                                        // 25 = WP_SECHS        = "SECHS"
    {9,8,3},                                                        // 26 = WP_UHR          = "UHR"

    {0,0,2},                                                        // 27 = WP_ES_CH        = "ES"
    {0,3,4},                                                        // 28 = WP_ISCH_CH      = "ISCH"
    {0,8,3},                                                        // 29 = WP_FUEF_CH      = "FÜF"
    {1,0,6},                                                        // 30 = WP_VIERTU_CH    = "VIERTU"
    {1,8,3},                                                        // 31 = WP_ZAEAE_CH     = "ZÄÄ"
    {2,0,6},                                                        // 32 = WP_ZWAENZG_CH   = "ZWÄNZG"
    {2,8,3},                                                        // 33 = WP_VOR_CH       = "VOR"
    {3,0,2},                                                        // 34 = WP_AB_CH        = "AB"
    {3,3,5},                                                        // 35 = WP_HAUBI_CH     = "HAUBI"
    {4,0,3},                                                        // 36 = WP_EIS_CH       = "EIS"
    {4,3,4},                                                        // 37 = WP_ZWOEI_CH     = "ZWÖI"
    {4,8,3},                                                        // 38 = WP_DRUE_CH      = "DRÜ"
    {5,0,5},                                                        // 39 = WP_VIERI_CH     = "VIERI"
    {5,5,4},                                                        // 40 = WP_FUEFI_CH     = "FÜFI"
    {6,0,6},                                                        // 41 = WP_SAECHSI_CH   = "SÄCHSI"
    {6,6,5},                                                        // 42 = WP_SIBNI_CH     = "SIBNI"
    {7,0,5},                                                        // 43 = WP_ACHTI_CH     = "ACHTI"
    {7,5,4},                                                        // 44 = WP_NUENI_CH     = "NÜNI"
    {8,0,4},                                                        // 45 = WP_ZAENI_CH     = "ZÄNI"
    {8,7,4},                                                        // 46 = WP_EUFI_CH      = "EUFI"
    {9,0,6},                                                        // 47 = WP_ZWOEFI_CH    = "ZWÖUFI"
    {9,8,3},                                                        // 48 = WP_UHR_CH       = "UHR"

    {0,0,2},                                                        // 49 = WP_ES_CH2       = "ES"
    {0,3,4},                                                        // 50 = WP_ESCH_CH2     = "ESCH"
    {1,0,4},                                                        // 51 = WP_FOIF_CH2     = "FOIF"
    {1,5,6},                                                        // 52 = WP_VIERTU_CH2   = "VIERTU"
    {0,8,3},                                                        // 53 = WP_ZAEAE_CH2    = "ZÄÄ"
    {2,0,6},                                                        // 54 = WP_ZWAENZ_CH2   = "ZWÄNZ"
    {2,8,3},                                                        // 55 = WP_VOR_CH2      = "VOR"
    {3,0,2},                                                        // 56 = WP_AB_CH2       = "AB"
    {3,3,5},                                                        // 57 = WP_HAUBI_CH2    = "HAUBI"
    {4,0,3},                                                        // 58 = WP_EIS_CH2      = "EIS"
    {4,3,4},                                                        // 59 = WP_ZWOEI_CH2    = "ZWÖI"
    {4,8,3},                                                        // 60 = WP_DRUE_CH2     = "DRÜ"
    {5,0,5},                                                        // 61 = WP_VIERI_CH2    = "VIERI"
    {5,6,5},                                                        // 62 = WP_FOEIFI_CH2   = "FÖIFI"
    {6,0,6},                                                        // 63 = WP_SAECHSI_CH2  = "SÄCHSI"
    {6,6,5},                                                        // 64 = WP_SEBNI_CH2    = "SEBNI"
    {7,0,5},                                                        // 65 = WP_ACHTI_CH2    = "ACHTI"
    {7,6,4},                                                        // 66 = WP_NUENI_CH2    = "NÜNI"
    {8,0,4},                                                        // 67 = WP_ZAENI_CH2    = "ZÄNI"
    {8,7,4},                                                        // 68 = WP_ELFI_CH2     = "ELFI"
    {9,0,6},                                                        // 69 = WP_ZWOELFI_CH2  = "ZWÖLFI"
    {9,8,3},                                                        // 70 = WP_UHR_CH2      = "UHR"

    {0,0,2},                                                        // 71 = WP_IT_EN        = "IT"
    {0,3,2},                                                        // 72 = WP_IS_EN        = "IS"
    {0,7,2},                                                        // 73 = WP_AM_EN        = "AM"
    {0,9,2},                                                        // 74 = WP_PM_EN        = "PM"
    {1,2,7},                                                        // 75 = WP_QUARTER_EN   = "QUARTER"
    {2,0,6},                                                        // 76 = WP_TWENTY_EN    = "TWENTY"
    {2,6,4},                                                        // 77 = WP_FIVE_1_EN    = "FIVE"
    {3,0,4},                                                        // 78 = WP_HALF_EN      = "HALF"
    {3,5,3},                                                        // 79 = WP_TEN_EN       = "TEN"
    {3,9,2},                                                        // 80 = WP_TO_EN        = "TO"
    {4,0,4},                                                        // 81 = WP_PAST_EN      = "PAST"
    {4,7,4},                                                        // 82 = WP_NINE_EN      = "NINE"
    {5,0,3},                                                        // 83 = WP_ONE_EN       = "ONE"
    {5,3,3},                                                        // 84 = WP_SIX_EN       = "SIX"
    {5,6,5},                                                        // 85 = WP_THREE_EN     = "THREE"
    {6,0,4},                                                        // 86 = WP_FOUR_EN      = "FOUR"
    {6,4,4},                                                        // 87 = WP_FIVE_2_EN    = "FIVE"
    {6,8,3},                                                        // 88 = WP_TWO_EN       = "TWO"
    {7,0,5},                                                        // 89 = WP_EIGHT_EN     = "EIGHT"
    {7,5,6},                                                        // 90 = WP_ELEVEN_EN    = "ELEVEN"
    {8,0,5},                                                        // 91 = WP_SEVEN_EN     = "SEVEN"
    {8,5,6},                                                        // 92 = WP_TWELVE_EN    = "TWELVE"
    {9,0,3},                                                        // 93 = WP_TEN_2_EN     = "TEN"
    {9,5,6},                                                        // 94 = WP_CLOCK_EN     = "OCLOCK"

    {0,0,2},                                                        //  95 = WP_IT_EN2       = "IT"
    {0,3,2},                                                        //  96 = WP_IS_EN2       = "IS"
    {1,4,7},                                                        //  97 = WP_QUARTER_EN2  = "QUARTER"
    {2,1,6},                                                        //  98 = WP_TWENTY_EN2   = "TWENTY"
    {2,7,4},                                                        //  99 = WP_FIVE_1_EN2   = "FIVE"
    {0,6,4},                                                        // 100 = WP_HALF_EN2     = "HALF"
    {1,0,3},                                                        // 101 = WP_TEN_EN2      = "TEN"
    {3,0,2},                                                        // 102 = WP_TO_EN2       = "TO"
    {3,2,4},                                                        // 103 = WP_PAST_EN2     = "PAST"
    {4,7,4},                                                        // 104 = WP_NINE_EN2     = "NINE"
    {6,7,3},                                                        // 105 = WP_ONE_EN2      = "ONE"
    {8,4,3},                                                        // 106 = WP_SIX_EN2      = "SIX"
    {5,0,5},                                                        // 107 = WP_THREE_EN2    = "THREE"
    {3,7,4},                                                        // 108 = WP_FOUR_EN2     = "FOUR"
    {4,0,4},                                                        // 109 = WP_FIVE_2_EN2   = "FIVE"
    {4,4,3},                                                        // 110 = WP_TWO_EN2      = "TWO"
    {7,6,5},                                                        // 111 = WP_EIGHT_EN2    = "EIGHT"
    {6,1,6},                                                        // 112 = WP_ELEVEN_EN2   = "ELEVEN"
    {7,0,5},                                                        // 113 = WP_SEVEN_EN2    = "SEVEN"
    {5,5,6},                                                        // 114 = WP_TWELVE_EN2   = "TWELVE"
    {8,1,3},                                                        // 115 = WP_TEN_2_EN2    = "TEN"
    {9,4,1},                                                        // 116 = WP_O_EN2        = "O"
    {9,6,5},                                                        // 117 = WP_CLOCK_EN2    = "CLOCK"

    {0,0,7},                                                        // 118 = WP_KLOCKAN      = "KLOCKAN"
    {0,8,2},                                                        // 119 = WP_AER          = "ÄR"
    {1,0,3},                                                        // 120 = WP_FEM_1        = "FEM"
    {1,4,1},                                                        // 121 = WP_FEM_I        = "I"
    {1,6,3},                                                        // 122 = WP_TIO_1        = "TIO"
    {1,10,1},                                                       // 123 = WP_TIO_I        = "I"
    {2,0,5},                                                        // 124 = WP_KVART        = "KVART"
    {2,6,1},                                                        // 125 = WP_KVART_I      = "I"
    {3,0,5},                                                        // 126 = WP_TJUGO        = "TJUGO"
    {3,6,1},                                                        // 127 = WP_TJUGO_I      = "I"
    {4,0,4},                                                        // 128 = WP_OEVER        = "ÖVER"
    {4,7,4},                                                        // 129 = WP_HALV         = "HALV"
    {5,0,3},                                                        // 130 = WP_ETT          = "ETT"
    {5,8,3},                                                        // 131 = WP_TVA          = "TVA"
    {6,0,3},                                                        // 132 = WP_TRE          = "TRE"
    {6,7,4},                                                        // 133 = WP_FYRA         = "FYRA"
    {7,0,3},                                                        // 134 = WP_FEM_2        = "FEM"
    {7,8,3},                                                        // 135 = WP_SEX          = "SEX"
    {8,0,3},                                                        // 136 = WP_SJU          = "SJU"
    {8,3,4},                                                        // 137 = WP_ATTA         = "ATTA"
    {8,8,3},                                                        // 138 = WP_NIO          = "NIO"
    {9,0,3},                                                        // 139 = WP_TIO_2        = "TIO"
    {9,3,4},                                                        // 140 = WP_ELVA         = "ELVA"
    {9,7,4},                                                        // 141 = WP_TOLV         = "TOLV"

    {0,0,2},                                                        // 142 = WP_IL           = "IL"
    {0,3,3},                                                        // 143 = WP_EST          = "EST"
    {0,7,4},                                                        // 144 = WP_DEUX         = "DEUX"
    {1,0,6},                                                        // 145 = WP_QUADRE       = "QUADRE"
    {1,6,5},                                                        // 146 = WP_TROIS        = "TROIS"
    {2,0,4},                                                        // 147 = WP_NEUF         = "NEUF"
    {2,4,3},                                                        // 148 = WP_UNE          = "UNE"
    {2,7,4},                                                        // 149 = WP_SEPT         = "SEPT"
    {3,0,4},                                                        // 150 = WP_HUIT         = "HUIT"
    {3,4,3},                                                        // 151 = WP_SIX          = "SIX"
    {3,7,4},                                                        // 152 = WP_CINQ_1       = "CINQ"
    {4,0,4},                                                        // 153 = WP_MIDI         = "MIDI"
    {4,2,3},                                                        // 154 = WP_DIX_1        = "DIX"
    {4,5,6},                                                        // 155 = WP_MINUIT       = "MINUIT"
    {5,0,4},                                                        // 156 = WP_ONZE         = "ONZE"
    {5,5,6},                                                        // 157 = WP_HEURES       = "HEURES"
    {6,0,5},                                                        // 158 = WP_MOINS        = "MOINS"
    {6,6,2},                                                        // 159 = WP_LE           = "LE"
    {6,8,3},                                                        // 160 = WP_DIX_2        = "DIX"
    {7,0,2},                                                        // 161 = WP_ET_1         = "ET"
    {7,3,5},                                                        // 162 = WP_QUART        = "QUART"
    {8,0,5},                                                        // 163 = WP_VINGT        = "VINGT"
    {8,0,10},                                                       // 164 = WP_VINGTCINQ   = "VINGT-CINQ"
    {8,6,4},                                                        // 165 = WP_CINQ_2       = "CINQ"
    {9,0,2},                                                        // 166 = WP_ET_2         = "ET"
    {9,3,4}                                                         // 167 = WP_DEMI         = "DEMI"
};

#if 0 // GERMAN (just for test)
const char * display[WC_ROWS] =
{
    "ESKISTLFÜNF",
    "ZEHNZWANZIG",
    "DREIVIERTEL",
    "TGNACHVORJM",
    "HALBQZWÖLFP",
    "ZWEINSIEBEN",
    "KDREIRHFÜNF",
    "ELFNEUNVIER",
    "WACHTZEHNRS",
    "BSECHSFMUHR"
};
#endif // 0

#if 0 // SWISS1
const char * display[WC_ROWS] =
{
    "ESKISCHAFÜF",
    "VIERTUBFZÄÄ",
    "ZWÄNZGSIVOR",
    "ABOHAUBIEPM",
    "EISZWÖISDRÜ",
    "VIERIFÜFIQT",
    "SÄCHSISIBNI",
    "ACHTINÜNIEL",
    "ZÄNIERBEUFI",
    "ZWÖUFIAMUHR"
};
#endif // 0

#if 0 // SWISS2
const char * display[WC_ROWS] =
{
    "ESKESCHAZÄÄ",
    "FÖIFCVIERTU",
    "ZWÄNZGSIVOR",
    "ABOHAUBIEGE",
    "EISZWÖISDRÜ",
    "VIERITFÖIFI",
    "SÄCHSISEBNI",
    "ACHTIENÜNIL",
    "ZÄNIERBELFI",
    "ZWÖLFINAUHR"
};
#endif // 0

#if 0 // ENGLISH1
const char * display[WC_ROWS] =
{
    "ITLISASAMPM",
    "ACQUARTERDC",
    "TWENTYFIVEX",
    "HALFSTENFTO",
    "PASTERUNINE",
    "ONESIXTHREE",
    "FOURFIVETWO",
    "EIGHTELEVEN",
    "SEVENTWELVE",
    "TENSEOCLOCK"
};
#endif // 0

#if 0 // ENGLISH2
const char * display[WC_ROWS] =
{
    "ITKISGHALFE",
    "TENYQUARTER",
    "DTWENTYFIVE",
    "TOPASTEFOUR",
    "FIVETWONINE",
    "THREETWELVE",
    "BELEVENONES",
    "SEVENWEIGHT",
    "ITENSIXTIES",
    "TINEOICLOCK"
};
#endif // 0

#if 0 // SWEDISH
const char * display[WC_ROWS] =
{
    "KLOCKANTÄRK",
    "FEMYISTIONI",
    "KVARTQIENZO",
    "TJUGOLIVIPM",
    "ÖVERKAMHALV",
    "ETTUSVLXTVA",
    "TREMYKYFYRA",
    "FEMSFLORSEX",
    "SJUÄTTAINIO",
    "TIOELVATOLV"
};
#endif // 0

#if 0 // FRENCH:
const char * display[WC_ROWS] =
{
    "ILNESTODEUX",
    "QUATRETROIS",
    "NEUFUNESEPT",
    "HUITSIXCINQ",
    "MIDIXMINUIT",
    "ONZERHEURES",
    "MOINSOLEDIX",
    "ETRQUARTPMD",
    "VINGT-CINQU",
    "ETSDEMIEPAM"
};
#endif // 0

#endif
