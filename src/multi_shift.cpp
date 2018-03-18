#include "multi_shift.hpp"

#include <string.h>
#include <stdint.h>

#include "global.hpp"

/**
 * @brief Getthe last digit of a number
 * 
 * @param number To get the last digit from
 * @return short  Digit as short
 */
short last_digit (const int number)
{
    return number % 10;
}

/**
 * @brief Create a digits object from a number
 * 
 * @param number To get the digits from
 * @return Digits 
 */
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
        d.len = arr_pos;
        arr_pos++;
        // our array only stores 12 digits
        if (arr_pos > 12)
        {
            break;
        }
    }
    return d;
}

void multi_shift(int number)
{
    digitalWrite(LATCH_PIN, LOW);
    Digits d = number_to_digits(number);
    for (uint8_t pos = 0; pos <= d.len; pos++)
    {
        shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, sev_seg_reg[d.digits[pos]]);
    }
    digitalWrite(LATCH_PIN, HIGH);
}