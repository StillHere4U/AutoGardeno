
#include "sleeper.h"

/**
 * Fonction sleep arduino
 */
void arduinoSleepSec(int temps_sec) {
  int sec;
  for(sec = 0; sec < temps_sec; sec++) {
    LowPower.idle(SLEEP_1S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF,
               SPI_OFF, USART0_OFF, TWI_OFF);
  }
}
