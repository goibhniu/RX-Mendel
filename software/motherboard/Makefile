all : freertos.elf

SUB = RX600_RX62N-RDK_GNURX
SUB = osboard

CFLAGS = \
	-I ../include \
	-I Demo/$(SUB)/RTOSDemo/webserver \
	-I Demo/$(SUB)/RTOSDemo \
	-I Demo/$(SUB)/RTOSDemo/include \
	-I Demo/Common/ethernet/FreeTCPIP \
	-I ../rtos/include \
	-I ../rtos/portable/ \
	-DINCLUDE_HIGH_FREQUENCY_TIMER_TEST=1 \
	$(END)

CFILES_ENET = \
	Demo/$(SUB)/RTOSDemo/GNU-Files/start.asm \
	Demo/Common/Minimal/BlockQ.c \
	Demo/Common/Minimal/GenQTest.c \
	Demo/Common/Minimal/IntQueue.c \
	Demo/Common/Minimal/PollQ.c \
	Demo/Common/Minimal/QPeek.c \
	Demo/Common/Minimal/blocktim.c \
	Demo/Common/Minimal/death.c \
	Demo/Common/Minimal/flash.c \
	Demo/Common/Minimal/flop.c \
	Demo/Common/Minimal/integer.c \
	Demo/Common/Minimal/recmutex.c \
	Demo/Common/Minimal/semtest.c \
	Demo/Common/ethernet/FreeTCPIP/apps/httpd/http-strings.c \
	Demo/Common/ethernet/FreeTCPIP/apps/httpd/httpd-fs.c \
	Demo/Common/ethernet/FreeTCPIP/apps/httpd/httpd.c \
	Demo/Common/ethernet/FreeTCPIP/psock.c \
	Demo/Common/ethernet/FreeTCPIP/timer.c \
	Demo/Common/ethernet/FreeTCPIP/uip.c \
	Demo/Common/ethernet/FreeTCPIP/uip_arp.c \
	Demo/$(SUB)/RTOSDemo/GNU-Files/hwinit.c \
	Demo/$(SUB)/RTOSDemo/GNU-Files/inthandler.c \
	Demo/$(SUB)/RTOSDemo/HighFrequencyTimerTest.c \
	Demo/$(SUB)/RTOSDemo/IntQueueTimer.c \
	Demo/$(SUB)/RTOSDemo/ParTest.c \
	Demo/$(SUB)/RTOSDemo/Renesas-Files/hwsetup.c \
	Demo/$(SUB)/RTOSDemo/Renesas-Files/osboard.c \
	Demo/$(SUB)/RTOSDemo/main-full.c \
	Demo/$(SUB)/RTOSDemo/uIP_Task.c \
	Demo/$(SUB)/RTOSDemo/tty.c \
	Demo/$(SUB)/RTOSDemo/cprintf.c \
	Demo/$(SUB)/RTOSDemo/vects.c \
	Demo/$(SUB)/RTOSDemo/webserver/EMAC.c \
	Demo/$(SUB)/RTOSDemo/webserver/httpd-cgi.c \
	Demo/$(SUB)/RTOSDemo/webserver/phy.c \
	Source/list.c \
	Source/portable/GCC/RX600/port.c \
	Source/portable/MemMang/heap_2.c \
	Source/queue.c \
	Source/tasks.c

CFILES = \
	../startup/start.asm \
	main.c \
	gcode.c \
	vects.c \
	machine.c \
	serial.c \
	../rtos/list.c \
	../rtos/queue.c \
	../rtos/tasks.c \
	../rtos/portable/heap_2.c \
	../rtos/portable/port.c \
	../startup/hwinit.c \
	../startup/inthandler.c \
	../startup/hwsetup.c \
	$(END)

OFILES := $(addsuffix .o,$(basename $(CFILES)))

freertos.elf : $(OFILES)
	rx-elf-gcc -nostartfiles $(OFILES) -o freertos.elf -T RTOSDemo_Blinky_auto.gsi

%.o : %.c
	rx-elf-gcc -c $(CFLAGS) -O2 $< -o $@

%.o : %.S
	rx-elf-gcc -x assembler-with-cpp -c $(CFLAGS) -O2 $< -o $@

%.o : %.asm
	rx-elf-gcc -x assembler-with-cpp -c $(CFLAGS) -O2 $< -o $@

flash : freertos.elf
	sudo $(HOME)/workspace/flashtools/rxusb -v -b 115200 -c freertos.elf

clean :
	rm -f $(OFILES) freertos.elf

distclean: clean