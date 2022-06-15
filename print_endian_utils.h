#ifndef PRINT_ENDIAN_UTILS_H
#define PRINT_ENDIAN_UTILS_H

#include <cstdint>


/* Return values for the parser function */
enum class eParserResult { SUCCESS, INVALID, OUT_OF_RANGE };


/**
 * Assumptions
 * There must be one (and only one) input
 * The input must be an integer number
 * The number must be positive (or 0)
 * The number must be representable on 32bits (< 2^32)
 * The input is invalid if anything other than digits are present (leading whitespaces are ignored)
 */

eParserResult parse_input(uint32_t &number, char const *input, int base = 0);

void print_BE(uint32_t number);
void print_LE(uint32_t number);

void print_result(eParserResult result);

#endif // PRINT_ENDIAN_UTILS_H