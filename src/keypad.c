#include "DISPLAY_WH1602B_4Bit.h"
#include "keypad.h"
#include <string.h>



void delay(void)
{
	for(uint32_t i=0 ; i < 300000 ; i++);
}



void setup_GPIO_for_keypad() {

	   //1.Enable the peripheral clock of GPIOD peripheral
		*pClockCtrlReg |= ( 1 << 3);

	  // 2.configure PD0,PD1,PD2,PD3 as output (rows)
		*pGPIODModeReg &= ~(0xFF); //clear
		*pGPIODModeReg |= 0x55;   //set

		// 3. configure PD8 , PD9, PD10, PD11 as input (columns)
	  *pGPIODModeReg &= ~(0xFF << 16);

		// 4.Enable internal pull-up resistors for PD8 PD9 PD10 PD11
	  *pPullupDownReg &= ~(0xFF << 16);
	  *pPullupDownReg |=  (0x55 << 16);
}


void copy(char* dest, char* src, int len) {
	for (int i=0; i<len; ++i) {
		*dest++ = *src++;
	}
}


void convert_hex_to_bin() {
		long int count=0;
		while(data[count])
		{
			switch(data[count])
			{
				case '0' : print_display_array("0000");
					break;
				case '1' : print_display_array("0001");
					break;
				case '2' : print_display_array("0010");
					break;
				case '3' : print_display_array("0011");
					break;
				case '4' : print_display_array("0100");
					break;
				case '5' : print_display_array("0101");
					break;
				case '6' : print_display_array("0110");
					break;
				case '7' : print_display_array("0111");
					break;
				case '8' : print_display_array("1000");
					break;
				case '9' : print_display_array("1001");
					break;
				case 'A' : print_display_array("1010");
					break;
				case 'B' : print_display_array("1011");
					break;
				case 'C' : print_display_array("1100");
					break;
				case 'D' : print_display_array("1101");
					break;
			}
			++count;
		}
}

char keypad_symbols[16] = {'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D'};

void Keypad_loop() {

//		  	 if (n_chars == 15) {
//		  		 setup_second_line();
//		  	 }


			for (uint8_t i=0; i<4; ++i) {

				//make all rows HIGH
				*pOutPutDataReg |= 0x0f;

				//make Ri LOW(PD0)
				*pOutPutDataReg &= ~( 1 << i);

				 //scan the columns

				//check C1 of Ri is low or high
				if(!(*pInPutDataReg & ( 1 << 8))) {
					//key is pressed
					if (i != 3) {
						delay();
						print_display(keypad_symbols[i*4]);
						data[n_chars] = keypad_symbols[i*4];
						++n_chars;
					}
					else {
						Display_Write_Ins(GO_TO_START_SECOND_LINE);
						convert_hex_to_bin();
					}
				}

				//check C2 of Ri is low or high
				if(!(*pInPutDataReg & ( 1 << 9))) {
					//key is pressed
					delay();
					print_display(keypad_symbols[i*4+1]);
					data[n_chars] = keypad_symbols[i*4+1];
					++n_chars;
				}

				//check C3 of Ri is low or high
				if(!(*pInPutDataReg & ( 1 << 10))) {
					//key is pressed
					if (i != 3) {
						delay();
						print_display(keypad_symbols[i*4+2]);
						data[n_chars] = keypad_symbols[i*4+2];
						++n_chars;
					}
					else {
						Display_clear();
						Display_Write_Ins(GO_TO_START_FIRST_LINE);
						n_chars = 0;
					}
				}

				//check C4 of Ri is low or high
				if(!(*pInPutDataReg & ( 1 << 11))) {
					//key is pressed
					if (i != 3) {
						delay();
						print_display(keypad_symbols[i*4+3]);
						data[n_chars] = keypad_symbols[i*4+3];
						++n_chars;
					}
					else {
						Display_Write_Ins(GO_TO_START_SECOND_LINE);
						convert_hex_to_bin();
					}
				}
				delay();
			}
}





//		     //make all rows HIGH
//		    *pOutPutDataReg |= 0x0f;
//
//		    //make R1 LOW(PD0)
//		    *pOutPutDataReg &= ~( 1 << 0);
//
//		    //scan the columns
//
//		    //check C1(PD8) low or high
//		    if(!(*pInPutDataReg & ( 1 << 8))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('1');
//		    	data[n_chars] = '1';
//		    	++n_chars;
//		    }
//
//		    //check C2(PD9) low or high
//		    if(!(*pInPutDataReg & ( 1 << 9))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('2');
//		    	data[n_chars] = '2';
//		    	++n_chars;
//		    }
//
//		    //check C3(PD10) low or high
//		    if(!(*pInPutDataReg & ( 1 << 10))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('3');
//		    	data[n_chars] = '3';
//		    	++n_chars;
//		    }
//
//		    //check C4(PD11) low or high
//		    if(!(*pInPutDataReg & ( 1 << 11))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('A');
//		    	data[n_chars] = 'A';
//		    	++n_chars;
//		    }
//
//
//		    //make all rows HIGH
//		     *pOutPutDataReg |= 0x0f;
//		    //make R2 LOW(PD1)
//		    *pOutPutDataReg &= ~( 1 << 1);
//
//		    //scan the columns
//		    //check C1(PD8) low or high
//		    if(!(*pInPutDataReg & ( 1 << 8))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('4');
//		    	data[n_chars] = '4';
//		    	++n_chars;
//		    }
//
//		    //check C2(PD9) low or high
//		    if(!(*pInPutDataReg & ( 1 << 9))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('5');
//		    	data[n_chars] = '5';
//		    	++n_chars;
//		    }
//
//		    //check C3(PD10) low or high
//		    if(!(*pInPutDataReg & ( 1 << 10))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('6');
//		    	data[n_chars] = '6';
//		    	++n_chars;
//		    }
//
//		    //check C4(PD11) low or high
//		    if(!(*pInPutDataReg & ( 1 << 11))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('B');
//		    	data[n_chars] = 'B';
//		    	++n_chars;
//		    }
//
//		    //make all rows HIGH
//		     *pOutPutDataReg |= 0x0f;
//		    //make R3 LOW(PD2)
//		    *pOutPutDataReg &= ~( 1 << 2);
//
//		    //scan the columns
//		    //check C1(PD8) low or high
//		    if(!(*pInPutDataReg & ( 1 << 8))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('7');
//		    	data[n_chars] = '7';
//		    	++n_chars;
//		    }
//
//		    //check C2(PD9) low or high
//		    if(!(*pInPutDataReg & ( 1 << 9))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('8');
//		    	data[n_chars] = '8';
//		    	++n_chars;
//		    }
//
//		    //check C3(PD10) low or high
//		    if(!(*pInPutDataReg & ( 1 << 10))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('9');
//		    	data[n_chars] = '9';
//		    	++n_chars;
//		    }
//
//		    //check C4(PD11) low or high
//		    if(!(*pInPutDataReg & ( 1 << 11))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('C');
//		    	data[n_chars] = 'C';
//		    	++n_chars;
//		    }
//
//		    //make all rows HIGH
//		     *pOutPutDataReg |= 0x0f;
//		    //make R4 LOW(PD2)
//		    *pOutPutDataReg &= ~( 1 << 3);
//
//		    //scan the columns
//		    //check C1(PD8) low or high
//		    if(!(*pInPutDataReg & ( 1 << 8))){
//		    	//key is pressed
//		    	delay();
//	//	    	print_display('*');
//		    	Display_Write_Ins(GO_TO_START_SECOND_LINE);
//		    	convert_hex_to_bin();
//		    }
//
//		    //check C2(PD9) low or high
//		    if(!(*pInPutDataReg & ( 1 << 9))){
//		    	//key is pressed
//		    	delay();
//		    	print_display('0');
//		    	data[n_chars] = '0';
//		    	++n_chars;
//		    }
//
//		    //check C3(PD10) low or high
//		    if(!(*pInPutDataReg & ( 1 << 10))){
//		    	//key is pressed
//		    	delay();
//	//	    	print_display('#');
//		    	Display_Write_Ins(GO_TO_START_SECOND_LINE);
//		    	convert_hex_to_bin();
//		    }
//
//		    //check C4(PD11) low or high
//		    if(!(*pInPutDataReg & ( 1 << 11))){
//		    	//key is pressed
//		    	delay();
////		    	print_display('D');
////		    	data[n_chars] = 'D';
////		    	++n_chars;
//		    	Display_clear();
//		    	Display_Write_Ins(GO_TO_START_FIRST_LINE);
//		    	n_chars = 0;
//		    }
//		    delay();
//}


//
//int main(void)
//{
//
////  setup_clock();
////  setup_LED(LED_PORT, LED_PINS);
//  setup_GPIO_for_keypad();
//
//  //Display_example();
//  //delay();
//
//  setup_Display();
//  setup_first_line();
//
//
//}

