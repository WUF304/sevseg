#include <Arduino.h>

#include "global.hpp"
#include "multi_shift.hpp"

#define MULTI

void setup() {
    Serial.begin(9600);
    // put your setup code here, to run once:
    pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
    Serial.println("Setup finished");
}

void loop() {
    // simple countdown counter
    for (uint8_t i = 9; i >= 0; i--)
    {
        Serial.println("Getting " + String(i) + " from sev_seg_reg");
        // mage the register writeable
        digitalWrite(LATCH_PIN, LOW);
        // shiftout the data to the 74hc595 LSBFIRST
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, sev_seg_reg[i]);
        // store the data in the internal register
        digitalWrite(LATCH_PIN, HIGH);
        delay(1000);
        if (i == 0)
        {
            break;
        }
    }
    #ifdef MULTI
    // write out the number 82 and show a dot. if you have only one 7 
    // segment display connected you will see the number 8 with a dot
    multi_shift(82, 0, 1);
    delay(2000);
    // shift out the number 3 left padded. in this case the first display will 
    // show nothing
    multi_shift(3, 2, -1);
    delay(2000);
    #endif
}