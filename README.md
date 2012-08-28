Documentation, tools and software for the OneTouch VerioIQ blood glucose meter

Bjoern Heller <tec@hellercom.de> (c) 2012

This Software is licensed under GNU/GPL


This Project serves as documentation/demo for using the Wellion CALLA (Premium)
blood glucose meter as a compact general purpose portable developement platform.

### Hardware ###

Documentation regarding the PCB, schematics and needed datasheets can be found in /doc .

Pictures can be found here:
http://www.flickr.com/photos/hellercom/sets/72157631243223554/

The Wellion Calla features:

-full-color OLED display with SSD1353U4 (Displaycontroller) 160x132 pixel (active area 35mmx28mm)
-Texas Instruments TI MSP430 CPU (MSP430FG4619) 16-Bit RISC
-fully battery powered (two AAA-Cells)
-3V Supply-Voltage
-Ultra-low power consumption
-direct mini-USB Interface
-RTC (Real-time-clock)
-NTC temperature sensor
-integrated high precision reference, ADC/DAC and Instrumentation AMP
-external serial flash memory (Winbond 25x40avnig)

### Get one ###

So, where to get one?

-eBay (~ 1-10 EUR)
-Pharmacy (~ 19 EUR)

Look out, there are several similar looking models w/o color-OLED like the "light".
I don't even know if these are "compatible". Likely they have different CPU's.

### Debugger used ###

MSP-FET430UIF

### Programming ###

mspdebug uif -j -d /dev/ttyUSB0

### Device pinout ###

#Connector CN2#

from right 7 6 5 4 3 2 [1]

1 - GND
2 - RST 	(CPU pin 94)
3 - TDO/TDI 	(cpu pin 90)
4 - TDI/TCLK	(cpu pin 91)
5 - TMS		(cpu pin 92)
6 - TCK		(cpu pin 93)
7 - VCC


!!Disclaimer!!

This project is not affiliated in any way with Wellion (Med Trust) or other companies.
I'm not responsible for harm or damage that is done to anyone using this project.
If you are dependent on your Wellion blood glucose meter, you should never open the device or try
to flash firmware into the device.
This project is NO enhancement for your Wellion meter nor will it EVER be able to measure blood glucose!!
So far, you've been warned!
