Example code and some information about my research to control a 1.2Ghz 800mW Partom video transmitter (similar to FOX and others) with an Arduino.

I tested the code with an Arduino Pro Mini 3.3V 8Mhz and it's working fine.

You need to desolder the PIC and solder three cables (DATA, CLOCK and LATCH ENABLE) to the Arduino pines 7, 8 and 9. You have to connect also the ground between them.

There are some pictures in the pictures folder about the VTX modification and connection for you to get an idea.

Sorry for the messy code. It just works and was "as is" when I finaly made it work.

Many thanks to "Changosurf" for the information in this page: https://www.rcgroups.com/forums/showpost.php?p=31933755&postcount=3868 (take care, the data for the 18bit latch registry didn't worked with my VTX).
