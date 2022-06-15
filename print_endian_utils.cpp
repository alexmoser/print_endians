#include "print_endian_utils.h"
#include <stdio.h>
#include <cstdint>
#include <string>


/**
 * @brief parse a text input into a 32-bit unsigned integer. Returns an error code,
 * 0 for SUCCESS.
 * 
 * @param number is the uint32 variable that will hold the parsed input value
 * @param input is the string (char *) that holds the input text
 * @param base is the base of the input
 * @return eParserResult is the success or error code result
 */
eParserResult parse_input(uint32_t &number, char const *input, int base = 0) {
  std::size_t pos {};
  long l_number;
  try {
    l_number = std::stol(input, &pos);
  }
  catch(std::invalid_argument const &ex) {
    // Invalid input
    return eParserResult::INVALID;
  }
  catch(std::out_of_range const &ex) {
    return eParserResult::OUT_OF_RANGE;
  }
  if (l_number > UINT32_MAX || l_number < 0) {
    return eParserResult::OUT_OF_RANGE;
  }
  if (input[pos] != '\0') {
    // There are non-digit characters in the input
    return eParserResult::INVALID;
  }

  number = l_number;
  return eParserResult::SUCCESS;
}

void print_BE(uint32_t number) {
  printf("Big Endian: ");
  for (int i=3; i>=0; i--) {
    printf("%02X ", (uint8_t) (number >> 8*i));
  }
  printf("\n");
}

void print_LE(uint32_t number) {
  printf("Little Endian: ");
  for (int i=0; i<4; i++) {
    printf("%02X ", (uint8_t) (number >> 8*i));
  }
  printf("\n");
}
