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


// list index
//A=0
//B=1
//C=2
//D=3
//E=4
//F=5

//calcul: index * 16 + pin number

// Example: PA2 = P(index*16+2) = P2

//S255 = actvate
//S0 = disactivate

#define LED_1 PE2 // M42 P66 (S255 or S0)
#define LED_2 PE3 // M42 P67 (S255 or S0)
#define LED_3 PE4 // M42 P68 (S255 or S0)
#define LED_4 PE5 // M42 P69 (S255 or S0)
#define LED_5 PE6 // M42 P70 (S255 or S0)

#define FAN PD3            // M42 P51 (S255 or S0)
#define PUMP_1 PD4         // M42 P52 (S255 or S0)
#define PUMP_2 PD5         // M42 P53 (S255 or S0)
#define ELECTROVALVE_1 PD6 // M42 P54 (S255 or S0)
#define ELECTROVALVE_2 PD7 // M42 P55 (S255 or S0)
#define LIGHT_TOP PB3      // M42 P19 (S255 or S0)
#define LIGHT_BOT PB4      // M42 P20 (S255 or S0)

#define PS_TANK PA0     // Pressure sensor tank
#define PS_VACUUM_1 PA2 // Pressure sensor head 1
#define PS_VACUUM_2 PA1 // Pressure sensor head 2

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


//#define RS485_RX                             PC11
//#define RS485_TX                             PC10
#define RS485_DE_RE                          PC12

#define UART4_TX_PIN PC10
#define UART4_RX_PIN PC11