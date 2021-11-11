################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/drivers/Buttons.c \
../src/drivers/CAN_BUS.c \
../src/drivers/DISPLAY_WH1602B_4Bit.c \
../src/drivers/LEDs.c \
../src/drivers/MEMS.c \
../src/drivers/PWM_controller_PCA9685PW.c \
../src/drivers/USART.c \
../src/drivers/balancer.c \
../src/drivers/clock_config.c \
../src/drivers/i2c.c \
../src/drivers/interrupts.c \
../src/drivers/peripheral_pinout.c \
../src/drivers/timers.c 

OBJS += \
./src/drivers/Buttons.o \
./src/drivers/CAN_BUS.o \
./src/drivers/DISPLAY_WH1602B_4Bit.o \
./src/drivers/LEDs.o \
./src/drivers/MEMS.o \
./src/drivers/PWM_controller_PCA9685PW.o \
./src/drivers/USART.o \
./src/drivers/balancer.o \
./src/drivers/clock_config.o \
./src/drivers/i2c.o \
./src/drivers/interrupts.o \
./src/drivers/peripheral_pinout.o \
./src/drivers/timers.o 

C_DEPS += \
./src/drivers/Buttons.d \
./src/drivers/CAN_BUS.d \
./src/drivers/DISPLAY_WH1602B_4Bit.d \
./src/drivers/LEDs.d \
./src/drivers/MEMS.d \
./src/drivers/PWM_controller_PCA9685PW.d \
./src/drivers/USART.d \
./src/drivers/balancer.d \
./src/drivers/clock_config.d \
./src/drivers/i2c.d \
./src/drivers/interrupts.d \
./src/drivers/peripheral_pinout.d \
./src/drivers/timers.d 


# Each subdirectory must supply rules for building sources it contributes
src/drivers/%.o: ../src/drivers/%.c src/drivers/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F4XX -DHSE_VALUE=8000000 -DSTM32F40XX -DUSE_STDPERIPH_DRIVER -c -I../src -I../Libraries/CMSIS/Include -I../Libraries/Device/STM32F4xx/Include -I../Libraries/STM32F4xx_StdPeriph_Driver/inc -I"D:/university/7sem/diploma/keypad_display/src/drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

