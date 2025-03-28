/*
The code in this script gives a combined example of doing GPIO with an expansion module connected to the OPTA. 

To get a better understanding of these capabilities, check out the examples provided in the library. 
These can be accessed by going to: File > Examples > Arduino_Opta_Blueprint
The code in this script is simply an adaptation of these examples.

*/
// class ExpansionModule {
// public:
//   ExpansionModule();
//   void setDigitalOut();
// private:
// }

// // constructor
// ExpansionModule::ExpansionModule() {
// }

// ExpansionModule::setDigitalOut() {
// }

// Digital Write will alternate on/off on pin 1


#include "OptaBlue.h"  // opta library

using namespace Opta;

void printExpansionType(ExpansionType_t t);
void printUint16(uint16_t v);

void setup() {
  Serial.begin(115200);  // begin Serial communication with the OPTA
  delay(2000);

  OptaController.begin();  // MUST be included in the setup of every script controlling the OPTA
}

void loop() {

  OptaController.update();  // MUST be included in the loop of every script controlling the OPTA

  static long int start_m = millis();
  static bool st = true;
  // Go through every available expansion module number available, check for ones that are
  for (int i = 0; i < OPTA_CONTROLLER_MAX_EXPANSION_NUM; i++) {
    /* ask for a digital expansion 
     * just one of these will be a valid expansion */
    // There's two types of expansion modules
    DigitalMechExpansion mechExp = OptaController.getExpansion(i);
    DigitalStSolidExpansion stsolidExp = OptaController.getExpansion(i);
    /* always check for the validity of the expansion */
    if (mechExp) {

      // ---------------- digital write ----------------

      /* get and print information about expansion */
      printExpansionInfo(mechExp.getIndex(), mechExp.getType(),
                         mechExp.getI2CAddress());
      if (st) {
        mechExp.digitalWrite(0, LOW);  //turn off pin 0
      } else {
        mechExp.digitalWrite(0, HIGH);  //turn off pin 0
      }
      mechExp.updateDigitalOutputs();
      /* pin status can be sent to the expansion also setting the 
           * last parameter of digitalWrite to true (default is false) 
           * however this involves a lot of unnecessary I2C transaction */

      // ---------------- digital read ----------------

      mechExp.updateDigitalInputs();

      /* this will return the pin status of the pin */
      PinStatus v_digital = mechExp.digitalRead(1);

      if (v_digital == HIGH) {
        Serial.print("HH");
      } else {
        Serial.print("LL");
      }
      Serial.print(' ');


      // ---------------- analog read ----------------
      uint16_t v_analog = mechExp.analogRead(2);
      printUint16(v_analog);
      Serial.print(" ");
      /* this will return the voltage at the pin k in Volts
         * we pass false as the last argument since we have
         * just read the analog value with the previous analogRead */
      float V = mechExp.pinVoltage(2, false);
      Serial.print("(" + String(V) + "V) ");
    }

    /* always check for the validity of the expansion */
    if (stsolidExp) {

      // ---------------- digital write ----------------

      /* get and print information about expansion */
      printExpansionInfo(stsolidExp.getIndex(), stsolidExp.getType(), stsolidExp.getI2CAddress());

      if (st) {
        stsolidExp.digitalWrite(0, HIGH);

      } else {
        stsolidExp.digitalWrite(0, LOW);
      }
      stsolidExp.updateDigitalOutputs();

      /* pin status can be sent to the expansion also setting the 
           * last parameter of digitalWrite to true (default is false) 
           * however this involves a lot of unnecessary I2C transaction */

      // ---------------- digital read ----------------

      stsolidExp.updateDigitalInputs();

      /* this will return the pin status of the pin */
      PinStatus v_digital = stsolidExp.digitalRead(1);

      if (v_digital == HIGH) {
        Serial.print("HH");
      } else {
        Serial.print("LL");
      }
      Serial.print(' ');


      // ---------------- analog read ----------------
      uint16_t v_analog = stsolidExp.analogRead(2);
      printUint16(v_analog);
      Serial.print(" ");
      /* this will return the voltage at the pin k in Volts
         * we pass false as the last argument since we have
         * just read the analog value with the previous analogRead */
      float V = stsolidExp.pinVoltage(2, false);
      Serial.print("(" + String(V) + "V) ");
    }
  }

  /* non blocking delay, this will run every 1000 ms */
  if (millis() - start_m > 500) {
    start_m = millis();
    st = !st;
  }

}


/*
Function to determine and print the type of expansion module being used
*/
void printExpansionType(ExpansionType_t t) {
  if (t == EXPANSION_NOT_VALID) {
    Serial.print("Unknown!");
  } else if (t == EXPANSION_OPTA_DIGITAL_MEC) {
    Serial.print("DIGITAL [Mechanical]");
  } else if (t == EXPANSION_OPTA_DIGITAL_STS) {
    Serial.print("DIGITAL [Solid State]");
  } else if (t == EXPANSION_DIGITAL_INVALID) {
    Serial.print("DIGITAL [!!Invalid!!]");
  } else if (t == EXPANSION_OPTA_ANALOG) {
    Serial.print("ANALOG");
  } else {
    Serial.print("Unknown!");
  }
}

/*
Function to determine and print the info of the expansion module being used
*/

void printExpansionInfo(uint8_t index, ExpansionType_t type, uint8_t i2c_address) {
  /* -------------------------------------------------------------------------- */
  Serial.print("Expansion[" + String(index) + "]:");
  Serial.print(" type ");
  printExpansionType(type);
  Serial.print(", I2C address: ");
  Serial.println(i2c_address);
}

void printUint16(uint16_t v) {
  /* -------------------------------------------------------------------------- */
  if (v < 10) {
    Serial.print("    ");
  } else if (v < 100) {
    Serial.print("   ");

  } else if (v < 1000) {
    Serial.print("  ");

  } else if (v < 10000) {
    Serial.print(" ");
  }
  Serial.print(v);
}