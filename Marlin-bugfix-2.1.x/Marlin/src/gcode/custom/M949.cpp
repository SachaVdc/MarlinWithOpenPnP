#include "../../inc/MarlinConfig.h"
#include "../gcode.h"

#include <string.h>



void GcodeSuite::M949() {

  //char *p = parser.string_arg;

  MYSERIAL2.println("UART4 OK");
  //MYSERIAL2.print("\r\n");

  //MYSERIAL2.flush();
  //delayMicroseconds(200);
  //WRITE(RS485_TX_ENABLE_PIN, LOW);    // retour réception
}