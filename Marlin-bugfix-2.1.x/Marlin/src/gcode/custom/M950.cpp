#include "../../inc/MarlinConfig.h"
#include "../gcode.h"

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_can.h"
#include "M950.h"

// Déclaration du handle CAN
CAN_HandleTypeDef hcan1;

void CAN1_Init() {
  __HAL_RCC_CAN1_CLK_ENABLE();

  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 6;               // 500 kbit/s
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_12TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE;
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = ENABLE;
  hcan1.Init.ReceiveFifoLocked = DISABLE;
  hcan1.Init.TransmitFifoPriority = DISABLE;

  if (HAL_CAN_Init(&hcan1) != HAL_OK) {
    SERIAL_ECHOLN("Error: CAN Init failed!");
    return;
  }

  HAL_CAN_Start(&hcan1);
  HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
}

void GcodeSuite::M950() {
  if (!parser.seen('I') || !parser.seen('L')) {
    SERIAL_ECHOLN("Error:M950 requires parameters (I, L, D1..D8)");
    return;
  }

  const uint16_t can_id = parser.intval('I');    // ID CAN
  const uint8_t length = parser.intval('L');     // DLC
  uint8_t data[8] = {0};

for (uint8_t i = 0; i < length; i++) {
    char param_char = (char)('D' + i);        // D, E, F, ... pas D1, D2
    data[i] = parser.intval(param_char, 0);
  }

  CAN_TxHeaderTypeDef txHeader;
  uint32_t mailbox;
  txHeader.StdId = can_id;
  txHeader.IDE = CAN_ID_STD;
  txHeader.RTR = CAN_RTR_DATA;
  txHeader.DLC = length;

  if (HAL_CAN_AddTxMessage(&hcan1, &txHeader, data, &mailbox) != HAL_OK) {
    SERIAL_ECHOLN("Error: CAN transmission failed.");
    return;
  }

  SERIAL_ECHOLN("echo:CAN message sent.");
}