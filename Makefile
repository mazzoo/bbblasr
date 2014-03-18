
# toolchain

CROSS?=arm-linux-gnueabihf-

CC=$(CROSS)gcc
LD=$(CROSS)ld
#LD=$(CROSS)ld.bfd
#LD=$(CROSS)ld.gold
OBJCOPY=$(CROSS)objcopy
AS=$(CROSS)as

LINKERFILE=bbblasr.ld

# other host tools
# apt-get install uboot-mkimage

MKIMAGE?=mkimage
PASM?=pasm


# compilation settings

#LADDR=0x80010040
#TADDR=0x80010040
LADDR=0x80000000
TADDR=0x80000000
#LADDR=0x40200800
#TADDR=0x40200800

CFLAGS=-nostdinc
CFLAGS+=-nostdlib
CFLAGS+=-O2
CFLAGS+=-Wall
CFLAGS+=-Werror
CFLAGS+=-msoft-float
CFLAGS+=-marm
CFLAGS+=-mno-thumb-interwork
CFLAGS+=-mabi=aapcs-linux
CFLAGS+=-march=armv7-a
CFLAGS+=-fPIC
CFLAGS+=

#LDFLAGS=-pie
#LDFLAGS+=--gc-sections
#LDFLAGS+=-Bstatic
LDFLAGS+=-Ttext $(TADDR)
LDFLAGS+=-T $(LINKERFILE)
LDFLAGS+=


# compilation steps of our target

TARGET=bbblasr
IMAGE=$(TARGET).img
BINARY=$(TARGET).bin
ELF=$(TARGET).elf
MAP=$(TARGET).map

ASOBJECTS=startup.o
ASOBJECTS+=

OBJECTS=bbblasr.o
OBJECTS+=bbblasr_libc.o
OBJECTS+=pru.o
OBJECTS+=$(ASOBJECTS)
OBJECTS+=


all:$(IMAGE)

%.o:%.s
	$(AS) $< -o $@

pru.c:bbblasr_pru0_bin.h bbblasr_pru1_bin.h

bbblasr_pru%_bin.h:bbblasr_pru.p
	$(eval PRU_NR=$(subst _bin.h,,$(subst bbblasr_pru,,$@)))
	$(PASM) -V3 bbblasr_pru.p -CPRU$(PRU_NR)_code -DPRU_NR=$(PRU_NR) bbblasr_pru$(PRU_NR)

$(ELF):$(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

$(BINARY):$(ELF)
	$(OBJCOPY) --gap-fill=0xff -O binary $< $@

# FIXME hmm -T kernel or firmware or multi or standalone
# FIXME doesn't like my -O u-boot
$(IMAGE):$(BINARY)
	$(MKIMAGE) \
	 -A arm \
	 -T standalone \
	 -C none \
	 -a $(LADDR) \
	 -e $(TADDR) \
	 -n  "bbb logic analyzer for sigrok" \
	 -d $< $@

clean:
	$(RM) $(IMAGE)
	$(RM) $(OBJECTS)
	$(RM) $(BINARY)
	$(RM) $(ELF)
	$(RM) $(MAP)
	$(RM) bbblasr_pru0_bin.h
	$(RM) bbblasr_pru1_bin.h
