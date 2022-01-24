#include "stm32f4xx.h"
#include "drivers/DISPLAY_WH1602B_4Bit.h"
#include "drivers/clock_config.h"


#include <stdint.h>
#include <stdio.h>


int main(void)
{

  setup_GPIO_for_keypad();

  Display_example();
  delay();

  setup_Display();
  setup_first_line();


  while(1)
  {

//	  	 if (n_chars == 15) {
//	  		 setup_second_line();
//	  	 }

	    Keypad_loop();
  }
}





