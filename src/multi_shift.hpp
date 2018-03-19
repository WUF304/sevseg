#include <stdint.h>
/**
 * @brief Simple structure to hold our parsed number
 *
 * @details
 * 
 * Supports numbers up to 12 digits 
 */
struct Digits {
    Digits() : dot_pos(-1) {};
    short digits[12];
    uint8_t len;
    int dot_pos;
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
 * @param number Number to shift out
 * @param left_pad Left pad any number with less digits than this value. This
 *        value is effectively the number of displays you are using
 * @param dot_pos Position of the dot. Use -1 to deactivate the feature
 * 
 * @details
 * 
 * Number is parsed from right to left. So if you have multiple shift registers 
 * / 7seg displays the last display will show the first number in the 
 * Digits::digits array.
 * 
 * This is also important for the dot position. Choose the position with keeping
 * in mind that the digits of the number are stored in reverse order.
 */
void multi_shift(int number, uint8_t left_pad = 0, int dot_pos = -1);