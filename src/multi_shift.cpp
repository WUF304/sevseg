#include "multi_shift.hpp"

#include <string.h>
#include <stdint.h>

#include "global.hpp"

short last_digit (const int number)
{
    return number % 10;
}

Digits number_to_digits(int number)
{
    Digits d;
    // initialize our digits with a sane default value
    memset(&d.digits, 0, 12);
    uint8_t arr_pos = 0;
    while (number > 0)
    {
        // get last digit
        short ld = last_digit(number);
        // store it in the array
        d.digits[arr_pos] = ld;
        // divide number so we drop the currently read digit
        number /= 10;
        d.len = arr_pos + 1;
        arr_pos++;
        // our array only stores 12 digits
        if (arr_pos > 12)
        {
            break;
        }
    }
    return d;
}

void multi_shift(int number, uint8_t left_pad, int dot_pos)
{
    // get the digits from number
    Digits d = number_to_digits(number);
    d.dot_pos = dot_pos;
    digitalWrite(LATCH_PIN, LOW);
    //transmit the data. number is transmitted from right to left
    for (uint8_t pos = 0; pos < d.len; pos++)
    {   
        uint8_t transmit_byte = sev_seg_reg[d.digits[pos]];
        // if dot_pos is equal to current pos activate the dot led
        if (d.dot_pos != -1 && static_cast<uint8_t>(d.dot_pos) == pos)
        {
           transmit_byte |= 0x01;
        }
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, transmit_byte);
    }
    // left pad numbers smaller than left_pad
    if (d.len < left_pad)
    {
        for (int pad_digits = left_pad - d.len; pad_digits > 0; pad_digits--)
        {
            Serial.println("left padding " + String(pad_digits));
            Serial.println("d.len " + String(d.len));
            shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, 0x00);
        }
    }
    digitalWrite(LATCH_PIN, HIGH);
}