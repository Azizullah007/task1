#include "conf.h"
#include "init.h"
#include "adc.h"

/* Global variables **********************************************************/
uint32_t systemBlink = 0;

/*
 * @brief	MCU peripherals initialization function
 *
 * @param	void
 * @retval	void
 */
void peripheralsInit(){
  PIT_Init();
  SIU_Init();
  SIU.PCR[45].R = 0x0200;
}

/*
 * @brief	System internal function calls and blink
 *
 * @param	void
 * @retval	void
 */
void systemFunction(void){
	ADC0_StartConversion();
	ADC1_StartConversion();

	if(systemBlink < 24){
		systemBlink++;
	}
	else{
		SIU.GPDO[45].R = ~SIU.GPDO[45].R;
		systemBlink = 0;
	}
}
