/*
 * power.h
 *
 *  Created on: May 8, 2016
 *      Author: peter
 */

#ifndef TXPOWERSETTINGS_H_
#define TXPOWERSETTINGS_H_

// Define if board uses the Skyworks 66100 front end module
#define USING_FEM


#ifdef USING_FEM
#define MAX_TX_LEVEL 27;
#define MIN_TX_LEVEL -27;
#else
#define MAX_TX_LEVEL 20;
#define MIN_TX_LEVEL -27;
#endif

#include <inttypes.h>

/*
 * Table settings derived from Silabs AN900. Enumeration is for convenience and type safety. PWR_PXX = +XXdBm, PWR_MXX = -XXdBm
 */

typedef enum {
#ifdef USING_FEM
    PWR_P27 = 0,
    PWR_P26,
    PWR_P25,
    PWR_P24,
    PWR_P23,
    PWR_P22,
    PWR_P21,
    PWR_P20,
#else
    PWR_P20 = 0,
#endif
    PWR_P19,
    PWR_P18,
    PWR_P17,
    PWR_P16,
    PWR_P15,
    PWR_P14,
    PWR_P13,
    PWR_P12,
    PWR_P11,
    PWR_P10,
    PWR_P09,
    PWR_P08,
    PWR_P07,
    PWR_P06,
    PWR_P05,
    PWR_P04,
    PWR_P03,
    PWR_P02,
    PWR_P01,
    PWR_P00,
    PWR_M01,
    PWR_M02,
    PWR_M03,
    PWR_M04,
    PWR_M05,
    PWR_M06,
    PWR_M07,
    PWR_M08,
    PWR_M09,
    PWR_M10,
    PWR_M11,
    PWR_M12,
    PWR_M13,
    PWR_M14,
    PWR_M15,
    PWR_M16,
    PWR_M17,
    PWR_M18,
    PWR_M19,
    PWR_M20,
    PWR_M21,
    PWR_M22,
    PWR_M23,
    PWR_M24,
    PWR_M25,
    PWR_M26,
    PWR_M27
}
tx_power_level;

typedef struct {
    tx_power_level level;       // For convenience
    uint8_t pa_mode;            // PA Mode
    uint8_t pa_level;           // PA power level (native parameter)
    uint8_t pa_bias_clkduty;    // PA bias clock duty
    uint8_t bypass;             // Desired state of BYP pin on Skyworks 66100 FEM
}
pa_params;



static const pa_params POWER_TABLE[] = {
#ifdef USING_FEM
        {PWR_P27, 0x09, 0x11, 0x11, 0x01},
        {PWR_P26, 0x09, 0x0d, 0x10, 0x01},
        {PWR_P25, 0x09, 0x0d, 0x0d, 0x01},
        {PWR_P24, 0x09, 0x0a, 0x0f, 0x01},
        {PWR_P23, 0x09, 0x07, 0x15, 0x01},
        {PWR_P22, 0x09, 0x09, 0x0e, 0x01},
        {PWR_P21, 0x09, 0x09, 0x0d, 0x01},
#endif
        {PWR_P20, 0x08, 0x5f, 0x00, 0x00},
        {PWR_P19, 0x08, 0x3d, 0x00, 0x00},
        {PWR_P18, 0x08, 0x32, 0x00, 0x00},
        {PWR_P17, 0x08, 0x2b, 0x00, 0x00},
        {PWR_P16, 0x08, 0x25, 0x00, 0x00},
        {PWR_P15, 0x08, 0x21, 0x00, 0x00},
        {PWR_P14, 0x08, 0x1d, 0x00, 0x00},
        {PWR_P13, 0x08, 0x19, 0x00, 0x00},
        {PWR_P12, 0x08, 0x16, 0x00, 0x00},
        {PWR_P11, 0x08, 0x14, 0x00, 0x00},
        {PWR_P10, 0x08, 0x12, 0x00, 0x00},
        {PWR_P09, 0x08, 0x10, 0x00, 0x00},
        {PWR_P08, 0x08, 0x0e, 0x00, 0x00},
        {PWR_P07, 0x08, 0x14, 0xc0, 0x00},
        {PWR_P06, 0x08, 0x11, 0xc0, 0x00},
        {PWR_P05, 0x09, 0x25, 0x25, 0x00},
        {PWR_P04, 0x09, 0x23, 0x23, 0x00},
        {PWR_P03, 0x09, 0x21, 0x21, 0x00},
        {PWR_P02, 0x09, 0x1f, 0x1f, 0x00},
        {PWR_P01, 0x09, 0x1d, 0x1d, 0x00},
        {PWR_P00, 0x09, 0x1c, 0x1b, 0x00},
        {PWR_M01, 0x09, 0x1a, 0x1a, 0x00},
        {PWR_M02, 0x09, 0x19, 0x18, 0x00},
        {PWR_M03, 0x09, 0x18, 0x16, 0x00},
        {PWR_M04, 0x09, 0x16, 0x16, 0x00},
        {PWR_M05, 0x09, 0x14, 0x15, 0x00},
        {PWR_M06, 0x09, 0x14, 0x13, 0x00},
        {PWR_M07, 0x09, 0x12, 0x13, 0x00},
        {PWR_M08, 0x09, 0x11, 0x12, 0x00},
        {PWR_M09, 0x09, 0x11, 0x10, 0x00},
        {PWR_M10, 0x09, 0x0f, 0x10, 0x00},
        {PWR_M11, 0x09, 0x0f, 0x0e, 0x00},
        {PWR_M12, 0x09, 0x0e, 0x0d, 0x00},
        {PWR_M13, 0x09, 0x0d, 0x0d, 0x00},
        {PWR_M14, 0x09, 0x0c, 0x0c, 0x00},
        {PWR_M15, 0x09, 0x0b, 0x0c, 0x00},
        {PWR_M16, 0x09, 0x0b, 0x0b, 0x00},
        {PWR_M17, 0x09, 0x09, 0x0c, 0x00},
        {PWR_M18, 0x09, 0x08, 0x0c, 0x00},
        {PWR_M19, 0x09, 0x08, 0x0b, 0x00},
        {PWR_M20, 0x09, 0x07, 0x0b, 0x00},
        {PWR_M21, 0x09, 0x07, 0x0a, 0x00},
        {PWR_M22, 0x09, 0x07, 0x09, 0x00},
        {PWR_M23, 0x09, 0x07, 0x08, 0x00},
        {PWR_M24, 0x09, 0x07, 0x07, 0x00},
        {PWR_M25, 0x09, 0x07, 0x06, 0x00},
        {PWR_M26, 0x09, 0x05, 0x08, 0x00},
        {PWR_M27, 0x09, 0x05, 0x07, 0x00}
};


#endif /* TXPOWERSETTINGS_H_ */
