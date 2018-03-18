#include <Arduino.h>

const uint8_t DATA_PIN = 7;
const uint8_t CLOCK_PIN = 6;
const uint8_t LATCH_PIN = 5;

const byte sev_seg_reg[10] {
    B11111100, // 0
    B01100000, // 1
    B11011010, // 2
    B11110010, // 3
    B01100110, // 4
    B10110110, // 5
    B10111110, // 6
    B11100000, // 7
    B11111110, // 8
    B11110110  // 9
};

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
}