/* Code generated by Beremiz c_ext confnode */

#ifdef ARDUINO_PLATFORM

#include <stdio.h>
#include "iec_types_all.h"

/* User variables reference */
extern "C" __IEC_BOOL_t CONFIG0__ST0;
#define St0 CONFIG0__ST0.value
extern "C" __IEC_BOOL_t CONFIG0__ST1;
#define St1 CONFIG0__ST1.value
extern "C" __IEC_BOOL_t CONFIG0__ST2;
#define St2 CONFIG0__ST2.value
extern "C" __IEC_BOOL_t CONFIG0__ST3;
#define St3 CONFIG0__ST3.value
extern "C" __IEC_BOOL_t CONFIG0__ST4;
#define St4 CONFIG0__ST4.value
extern "C" __IEC_BOOL_t CONFIG0__ST5;
#define St5 CONFIG0__ST5.value

/* User sketch */
// This is the Arduino side of the project. The functions sketch_setup() and

// sketch_loop() provide the same functionality of the setup() and loop()

// functions of a regular Arduino sketch. On top of this code editor there is a

// variable table. You can add variables there that are shared between the 

// arduino code and the PLC code. Since they are shared, you can, for example,

// read a sensor on the arduino sketch and use the reading in a PLC program. 

// On the PLC side you must declare the same variable with the class "external"

// before being able to use it in your program.



// This Arduino sketch implementation is compatible with virtually every library

// or code you can possibly run on the regular Arduino IDE. You can create your

// own functions and also #include external libraries (as long as they are also

// installed on your Arduino IDE). The only catch is that your sketch_loop() 

// function cannot block (long while loop or delays), or else your PLC code will

// block as well.



// Notes about this particular demo: Since this demo uses the serial port, you

// cannot enable Modbus Serial on your project, otherwise it will conflict with

// the messages being printed from this sketch. Also, this sketch shares a

// STRING with the PLC side. This is not a regular c-string, it is an IEC 61131

// STRING. Variables shared between the PLC and Arduino sketch are always IEC

// 61131 variables. For normal datatypes like INT, REAL, DINT, etc, there are

// direct equivalents in C (int16_t, float and int32_t respectively), so you

// shouldn't have any problems with those. An IEC STRING however is a more 

// complex structure. You can typecast an IEC STRING into a c-string by using 

// (char *)STRING.body as shown in the example below.





/*

void sketch_setup()

{

    Serial.begin(115200);

    Serial.println("Hello World! I'm starting now...");

}



void sketch_loop()

{

    if (PrintMSG)

    {

        Serial.println((char *)SerialMSG.body);

    }

}

*/



/////////////////////////////////////////////////////////////////////



#include <Arduino_ConnectionHandler.h>

#include <LiquidCrystal_I2C.h>

int state_buffer = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void sketch_setup() {

  lcd.init();

  lcd.backlight();
}

void sketch_loop() {

lcd.setCursor(0, 0);

lcd.print("In State:");
lcd.setCursor(0,1);



state_buffer = St0 + St1*(1<<1) + St2*(1<<2) + St3*(1<<3) + St4*(1<<4) + St5*(1<<5);

switch(state_buffer){



case 0b1:

    lcd.print("0");

    break;

case 0b10:

    lcd.print("1");

    break;

case 0b100:

    lcd.print("2");

    break;

case 0b1000:

    lcd.print("3");

    break;

case 0b10000:

    lcd.print("4");

    break;

case 0b100000:

    lcd.print("5");

    break;

}


delay(500);

lcd.clear();

}
#endif
