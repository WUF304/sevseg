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