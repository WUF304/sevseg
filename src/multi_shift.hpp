#include <stdint.h>
/**
 * @brief Simple structure to hold our parsed number
 *
 * @details
 * 
 * Supports numbers up to 12 digits 
 */
struct Digits {
    short digits[12];
    uint8_t len;
};

/**
 * @brief Getthe last digit of a number
 * 
 * @param number To get the last digit from
 * @return short  Digit as short
 */
short last_digit (const int number);
/**
 * @brief Create a digits object from a number
 * 
 * @param number To get the digits from
 * @return Digits 
 */
Digits number_to_digits(int number);
/**
 * @brief Shift every digit from number
 * 
 * @param number 
 * 
 * @details
 * 
 * Number is parsed from right to left. So if you have multiple shift registers 
 * / 7seg displays the last display will show the first number in the 
 * Digits::digits array.
 */
void multi_shift(int number);