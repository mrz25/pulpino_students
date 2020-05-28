# and don't touch the rest unless you know what you're doing.
CROSS_COMPILE ?= /opt/riscv_multilib/bin/riscv64-unknown-elf-
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))

CC      =   $(CROSS_COMPILE)gcc
LD      =   $(CROSS_COMPILE)ld
OBJDUMP =   $(CROSS_COMPILE)objdump
OBJCOPY =   $(CROSS_COMPILE)objcopy
SIZE    =   $(CROSS_COMPILE)size

DFLAGS  =

ARCH = -march=rv32imc -mabi=ilp32

# Board support
BSP           = \ #board_support

BSP_INCLUDE   = \ #$(BSP)/hwlib/include

BOARD_INCLUDE = ./includes/sys_lib/inc\
	./includes/string_lib/inc\

BOOT_INCLUDE  = \

OBJS = boot_code.o\
	./includes/sys_lib/src/spi.o\
	./includes/sys_lib/src/gpio.o\
	./includes/sys_lib/src/uart.o\
	./includes/sys_lib/src/utils.o\
	./includes/string_lib/src/qprintf.o\
	
EMB_OBJS =  ./includes/ref/crt0.boot.o 

LDS_EMB     = ./includes/ref/link.common.ld
LDS_BOOT    = ./includes/ref/link.boot.ld
OUTPUT      = boot_code
OUTPUT_EMB  = $(OUTPUT)_emb
OUTPUT_BOOT = $(OUTPUT)


.PHONY: all 
all: clean bootable dat_boot 

.PHONY: emb
emb: clean embedded dat_emb


.PHONY: bootable
bootable: $(OUTPUT_BOOT)
$(OUTPUT_BOOT): $(LDS_BOOT) $(EMB_OBJS) $(OBJS)
	${CC} ${ARCH} $(BOARD_INCLUDE:%=-I%) $(BOOT_INCLUDE:%=-I%) -flto -O3 -Wl,--gc-sections -o $(OUTPUT_BOOT).elf $(EMB_OBJS) -nostartfiles $(OBJS) -lm -T $(LDS_BOOT) -lc
	${OBJCOPY} -O binary $(OUTPUT_BOOT).elf $(OUTPUT_BOOT).bin
	${OBJDUMP} -D $(OUTPUT_BOOT).elf > disasm_boot.S
	$(SIZE) $(OUTPUT_BOOT).elf

.PHONY: embedded
embedded: $(OUTPUT_EMB)
$(OUTPUT_EMB): $(LDS_EMB) $(EMB_OBJS) $(OBJS)
	${CC} ${ARCH} $(BOARD_INCLUDE:%=-I%) $(BSP_INCLUDE:%=-I%) -flto -O2 -Wl,--gc-sections -o $(OUTPUT_EMB).elf $(EMB_OBJS) -nostartfiles $(OBJS) -lm -T $(LDS_EMB) -lc
	${OBJCOPY} -O binary $(OUTPUT_EMB).elf $(OUTPUT_EMB).bin
	${OBJDUMP} -D $(OUTPUT_EMB).elf > disasm_emb.S
	$(SIZE) $(OUTPUT_EMB).elf

.PHONY: dat_emb
dat_emb: embedded
	.././elf2dat.sh $(OUTPUT_EMB).elf

.PHONY: dat_boot
dat_boot: bootable
	python3 ../generate_dat.py $(OUTPUT_BOOT).bin ../$(OUTPUT_BOOT).dat

.PHONY: clean
clean:
	rm -f $(OBJS) $(DBG_OBJS) $(EMB_OBJS)
	rm -f $(OUTPUT_DBG)
	rm -f $(OUTPUT_EMB).elf $(OUTPUT_EMB).bin
	rm -f $(OUTPUT_BOOT).elf $(OUTPUT_BOOT).bin
	rm -f $(OUTPUT_EMB).dat
	rm -f ../$(OUTPUT_BOOT).dat
	rm -f disasm.S disasm_debug.S disasm_emb.S disasm_boot.S


%.o:	%.S
	${CC} ${ARCH} $(BOARD_INCLUDE:%=-I%) -c $^ -o $@

%.o:	%.c
	${CC} ${ARCH} $(DFLAGS) $(BOARD_INCLUDE:%=-I%) $(BOOT_INCLUDE:%=-I%) $(BSP_INCLUDE:%=-I%) $(GDBDEBUG) -c $^ -o $@
