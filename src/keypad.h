
uint8_t data[33];

char str[4];
char str_tx[6];
char new_line[2] = "\r\n";

uint8_t cycle = 1;
uint8_t n_chars = 0;


//peripheral register addresses

uint32_t volatile *const pGPIODModeReg  =  (uint32_t*)(0x40020C00);
uint32_t volatile *const pInPutDataReg  =  (uint32_t*)(0x40020C00+0x10);
uint32_t volatile *const pOutPutDataReg =  (uint32_t*)(0x40020C00+0x14);
uint32_t volatile *const pClockCtrlReg  =  (uint32_t*)(0x40023800+0x30);
uint32_t volatile *const pPullupDownReg =  (uint32_t*)(0x40020C00 + 0x0C);


void delay(void);

void setup_GPIO_for_keypad(void);

void convert_hex_to_bin(void);

void Keypad_loop(void);
