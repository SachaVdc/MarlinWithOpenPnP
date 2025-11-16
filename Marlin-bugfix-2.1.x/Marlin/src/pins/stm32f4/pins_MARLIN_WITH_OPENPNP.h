/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define BOARD_INFO_NAME "Marlin With OpenPnP"
/**
 * STM32F407VET6 Motherboard with OpenPnP
 */

#define ALLOW_STM32DUINO
#include "env_validate.h"

#define DEFAULT_MACHINE_NAME "Pick-and-Place Machine"

/**
 * By default, the extra stepper motor configuration is:
 * I = Left Head
 * J = Right Head
 */

#define SRAM_EEPROM_EMULATION
#define MARLIN_EEPROM_SIZE               0x2000U  // 8K

/******************** CONFIG PINS (STM32) ********************/

#define LED_1 PE2 // LED 1
#define LED_2 PE3 // LED 2
#define LED_3 PE4 // LED 3
#define LED_4 PE5 // LED 4
#define LED_5 PE6 // LED 5

#define FAN PD3 // Fan
#define PUMP_1 PD4 // Pump 1
#define PUMP_2 PD5 // Pump 2
#define ELECTROVALVE_1 PD6 // Electrovalve 1
#define ELECTROVALVE_2 PD7 // Electrovalve 2
#define LIGHT_TOP PB3 // Top Light
#define LIGHT_BOT PB4 // Bottom Light

#define PS_TANK PA0     // Pressure sensor tank
#define PS_VACUUM_1 PA1 // Pressure sensor vacuum 1
#define PS_VACUUM_2 PA2 // Pressure sensor vacuum 2

//
// Limit Switches
//
#define X_STOP_PIN                          PC13
#define Y_STOP_PIN                          PC14
#define Z_STOP_PIN                          PC15

// None of these require limit switches by default, so we leave these commented
// here for your reference.
//#define I_MIN_PIN                         PA8
//#define I_MAX_PIN                         PA8
//#define J_MIN_PIN                         PD13
//#define J_MAX_PIN                         PD13
//#define K_MIN_PIN                         PC9
//#define K_MAX_PIN                         PC9

//
// Steppers
//
#define X_STEP_PIN                          PD15
#define X_DIR_PIN                           PD14
#define X_ENABLE_PIN                        PD13
//define X_ALARM_PIN                        PD12

#define Y_STEP_PIN                          PD11
#define Y_DIR_PIN                           PD10
#define Y_ENABLE_PIN                        PD9
//define Y_ALARM_PIN                        PD8

#define Z_STEP_PIN                          PC5
#define Z_DIR_PIN                           PC4
#define Z_ENABLE_PIN                        PB1
//#define Z_ALARM_PIN                       PB0
//#define Z_UART                            PA7

#define I_STEP_PIN                          PE8
#define I_DIR_PIN                           PE7
#define I_ENABLE_PIN                        PE10
//#define I_ALARM_PIN                       PE9
//#define I_UART                            PB2


#define J_STEP_PIN                          PE13
#define J_DIR_PIN                           PE12
#define J_ENABLE_PIN                        PE15
//#define J_ALARM_PIN                       PE14
//#define J_UART                            PE11

//#define CAN_RX PD0
//#define CAN_TX PD1

//#define RS485_RX PC11
//#define RS485_TX PC10
//#define RS485_DE PC12