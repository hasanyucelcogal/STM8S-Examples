#makefile N76E003AT20
#Ngo Hung Cuong
#make download and make force added by Hasan Yucel COGAL
CC = sdcc
PRJ = main
FLASH_SIZE = 8192

#do not edit
OBJ_DIR = obj

SRC = main.c
SRC += stm8s_gpio.c
SRC += stm8s_tim4.c
SRC += stm8s_clk.c
#SRC += tm1628.c
#SRC += vfd.c

VPATH = lib/src

OBJS = $(patsubst %.c,obj/%.rel,$(SRC))

all: $(OBJS)
	$(CC) -mstm8 $(OBJS) -o $(PRJ).ihx
	packihx $(PRJ).ihx > $(PRJ).hex
#	makebin -s $(FLASH_SIZE) $(PRJ).ihx $(PRJ).bin

obj/%.rel: %.c
	$(CC) -c -mstm8 -DSTM8S003 -DUSE_STDPERIPH_DRIVER $< -I. -Ilib/inc -o $@

clean:
	rm -f obj/*.*
	rm -f $(PRJ).*

download:
	stm8flash -c stlink -p stm8s003k3 -w main.hex

force:$(OBJS)
	$(CC) -mstm8 $(OBJS) -o $(PRJ).ihx
	packihx $(PRJ).ihx > $(PRJ).hex
#	makebin -s $(FLASH_SIZE) $(PRJ).ihx $(PRJ).bin

	stm8flash -c stlink -p stm8s003k3 -w main.hex
	
	rm -f obj/*.*
#	rm -f $(PRJ).*

.PHONY: all clean download force


