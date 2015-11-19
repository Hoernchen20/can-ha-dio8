CC = /usr/local/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-gcc
AS = /usr/local/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-as
LD = /usr/local/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-ld
OC = /usr/local/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-objcopy
OD = /usr/local/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-objdump
SZ = /usr/local/gcc-arm-none-eabi-4_9-2015q3/bin/arm-none-eabi-size

# Compiler Flags
CFLAGS = -Wall -Os -std=c11 -DSTM32F1xx -DUSE_HAL_DRIVER
CFLAGS += -mcpu=cortex-m3 -mfloat-abi=soft -mthumb -ffunction-sections -fdata-sections -flto
CFLAGS += -I"Inc"
CFLAGS += -I"Drivers/STM32F1xx_HAL_Driver/Inc"
CFLAGS += -I"Drivers/STM32F1xx_HAL_Driver/Inc/Legacy"
CFLAGS += -I"Drivers/CMSIS/Device/ST/STM32F1xx/Include"
CFLAGS += -I"Drivers/CMSIS/Include"

# Assembler Flags
ASFLAGS = -mcpu=cortex-m3 -mfloat-abi=soft -mthumb

# Linker Flags
LDFLAGS = -mcpu=cortex-m3 -mfloat-abi=soft -mthumb -ffunction-sections -fdata-sections -Os -flto -Wl,--gc-sections -static -Tldscript/STM32F105XC_FLASH.ld

#Objdump Flags
ODFLAGS = -d -t -C

OBJ = main.o stm32f1xx_hal_msp.o stm32f1xx_it.o
OBJ += startup_stm32f105xc.o system_stm32f1xx.o
OBJ += stm32f1xx_hal.o stm32f1xx_hal_cortex.o
OBJ += stm32f1xx_hal_gpio.o
OBJ += stm32f1xx_hal_can.o stm32f1xx_hal_rcc.o stm32f1xx_hal_rcc_ex.o

DIO8: $(OBJ)
	$(CC) $(CFLAGS) -o DIO8.elf $(OBJ) $(LDFLAGS)
	$(OC) -O binary DIO8.elf DIO8.bin
	$(SZ) --format=berkeley "DIO8.elf"
	$(OD) $(ODFLAGS) DIO8.elf > DIO8.lss

%.o: Src/%.c
	$(CC) -c $(CFLAGS) $<

%.o: Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/%.c
	$(CC) -c $(CFLAGS) $<

%.o: Drivers/STM32F1xx_HAL_Driver/Src/%.c
	$(CC) -c $(CFLAGS) $<

#Startup file
startup_stm32f105xc.o: Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/gcc/startup_stm32f105xc.s
	$(CC) -c $(CFLAGS) $<

clean:
	rm *.o
