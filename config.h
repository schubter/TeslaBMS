#pragma once

#include <Arduino.h>

// Simple BMS wiring

// inputs
#define INACUR1 A0 
#define INACUR2 A1
#define INKEY 16
#define INACPRESENT 17

// outputs - high active
#define OUTCONTACTOR 20
#define OUTPRECHARGE 21
#define OUTCHARGERELEAY 23
#define OUTCONTACTOR 24
#define OUTPWMDRIVER 3
#define OUTPWMDRIVER2 4
#define INBMBFAULT 11

// bms status values
#define Boot 0
#define Ready 1
#define Drive 2
#define Charge 3
#define Precharge 4
#define Err 5

// current sensor values
#define Undefined 0
#define Analogue 1
#define Canbus 2
#define cursens Canbus

// Set to the proper port for your USB connection - SerialUSB on Due (Native) or Serial for Due (Programming) or Teensy
#define SERIALCONSOLE Serial

// Define this to be the serial port the Tesla BMS modules are connected to.
#define SERIALBMS Serial3

#define REG_DEV_STATUS      1
#define REG_GPAI            1
#define REG_VCELL1          3
#define REG_VCELL2          5
#define REG_VCELL3          7
#define REG_VCELL4          9
#define REG_VCELL5          0xB
#define REG_VCELL6          0xD
#define REG_TEMPERATURE1    0xF
#define REG_TEMPERATURE2    0x11
#define REG_ALERT_STATUS    0x20
#define REG_FAULT_STATUS    0x21
#define REG_COV_FAULT       0x22
#define REG_CUV_FAULT       0x23
#define REG_ADC_CTRL        0x30
#define REG_IO_CTRL         0x31
#define REG_BAL_CTRL        0x32
#define REG_BAL_TIME        0x33
#define REG_ADC_CONV        0x34
#define REG_ADDR_CTRL       0x3B

#define MAX_MODULE_ADDR     0x3E

#define EEPROM_VERSION      0x10    //update any time EEPROM struct below is changed.
#define EEPROM_PAGE         0

typedef struct {
    uint8_t version;
    uint8_t checksum;
    uint32_t canSpeed;
    uint8_t batteryID;  //which battery ID should this board associate as on the CAN bus
    uint8_t logLevel;
    float OverVSetpoint;
    float UnderVSetpoint;
    float OverTSetpoint;
    float UnderTSetpoint;
    float balanceVoltage;
    float balanceHyst;
} EEPROMSettings;
