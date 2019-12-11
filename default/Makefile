###############################################################################
# Makefile for the project 74LS259_uC
###############################################################################

## General Flags
PROJECT = 74LS259_uC
MCU = atmega2560
TARGET = 74LS259_uC.elf
CC = avr-gcc.exe

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -Os -std=gnu99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=74LS259_uC.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = 74LS259_uC.o 74LS259.o UART.o Utility.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) 74LS259_uC.hex 74LS259_uC.eep 74LS259_uC.lss size

## Compile
74LS259_uC.o: ../74LS259_uC.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

74LS259.o: ../74LS259.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

UART.o: ../UART.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

Utility.o: ../Utility.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) 74LS259_uC.elf dep/* 74LS259_uC.hex 74LS259_uC.eep 74LS259_uC.lss 74LS259_uC.map


## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)

