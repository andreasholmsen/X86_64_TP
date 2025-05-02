VERBOSE  = 1
PREFIX   = 
OPT     ?= 0
CFLAGS  ?= -O0

FCFLAGS  = $(CFLAGS) -Wall -g

ARM_CFLAGS ?=
x86_CFLAGS ?=
x64_CFLAGS ?=

ARM_CPU  := cortex-m3
ARM_ARCH := armv7-m

ARM_TARGET     := arm.bin
ARM_TARGET_ELF := arm.elf
ARM_GNU     := ../gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi
ARM_GCC     := $(PREFIX)$(ARM_GNU)-gcc -DARM
ARM_AS      := $(PREFIX)$(ARM_GNU)-as
ARM_LD      := $(PREFIX)$(ARM_GNU)-ld
ARM_OBJDUMP := $(PREFIX)$(ARM_GNU)-objdump
ARM_OBJCOPY := $(PREFIX)$(ARM_GNU)-objcopy
ARM_GDB     := $(PREFIX)$(ARM_GNU)-gdb
ARM_GNU_LIB := ../gcc-arm-none-eabi-10.3-2021.10/lib/gcc/arm-none-eabi/10.3.1/thumb/v7-m/nofp/

ARM_AFLAGS  := -mcpu=$(ARM_CPU) -mthumb
ARM_CFLAGS  += -nostdlib -nostartfiles -nodefaultlibs -ffreestanding  -mcpu=$(ARM_CPU) -mthumb
ARM_LDFLAGS := -T lm3s811evb.ld -g

x64_TARGET  := x64.bin
x64_GNU     := 
x64_GCC     := $(PREFIX)gcc -m64 -Dx64
x64_OBJDUMP := $(PREFIX)objdump
x64_OBJCOPY := $(PREFIX)objcopy
x64_GDB     := $(PREFIX)gdb

x86_TARGET  := x86.bin
x86_GNU     := 
x86_GCC     := $(PREFIX)gcc -m32 -Dx86
x86_OBJDUMP := $(PREFIX)objdump
x86_OBJCOPY := $(PREFIX)objcopy
x86_GDB     := $(PREFIX)gdb

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

ARM_OBJECTS = $(patsubst %.c, %_arm.o, $(wildcard *.c))
x64_OBJECTS = $(patsubst %.c, %_x64.o, $(wildcard *.c))
x86_OBJECTS = $(patsubst %.c, %_x86.o, $(wildcard *.c))

.PHONY: arm x64 x86
.PRECIOUS: 

all: clean arm x64 x86
dump: arm-dump x64-dump x86-dump	




#ARM COMPILATION

%_arm.o: %.c $(HEADERS)
	$(ARM_GCC) $(FCFLAGS) $(ARM_CFLAGS) -c $< -o $@

vectors.o : vectors.s
	$(ARM_AS) $(ARM_AFLAGS) vectors.s -o vectors.o
	
arm: lm3s811evb.ld vectors.o $(ARM_OBJECTS)
	$(ARM_LD) -L$(ARM_GNU_LIB) -o $(ARM_TARGET_ELF) $(ARM_LDFLAGS) vectors.o $(ARM_OBJECTS) -lgcc
	$(ARM_OBJCOPY) -O binary $(ARM_TARGET_ELF) $(ARM_TARGET)

arm-dump:
	$(ARM_OBJDUMP) -d $(ARM_TARGET_ELF) > $(ARM_TARGET).lst




#x86 COMPILATION

%_x86.o: %.c $(HEADERS)
	$(x86_GCC) $(FCFLAGS) $(x86_CFLAGS) -c $< -o $@
	
x86: $(x86_OBJECTS)
	$(x86_GCC) $(x86_OBJECTS) -o $(x86_TARGET)
	
x86-dump:
	$(x86_OBJDUMP) -d $(x86_TARGET) > $(x86_TARGET).lst




#x64 COMPILATION

%_x64.o: %.c $(HEADERS)
	$(x64_GCC) $(FCFLAGS) $(x64_CFLAGS) -c $< -o $@
	
x64: $(x64_OBJECTS)
	$(x64_GCC) $(x64_OBJECTS) -o $(x64_TARGET)
	
x64-dump:
	$(x64_OBJDUMP) -d $(x64_TARGET) > $(x64_TARGET).lst
	
	
test-arm:
	@echo "Testing ARM target:"
	@qemu-system-arm -M lm3s811evb -m 8K -nographic -no-reboot -kernel arm.bin
	
test-x86:
	@echo "Testing x86 target:"
	@./x86.bin
	
test-x64:
	@echo "Testing x64 target:"
	@./x64.bin
	

test: test-arm test-x86 test-x64
	
.PHONY: install

clean:
	@-rm -f *.o
	@-rm -f *.elf
	@-rm -f *.lst
	@-rm -f *.bin
