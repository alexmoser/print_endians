#include "print_endian_utils.h"
#include <string>

constexpr std::string test[] {
    " ",
    " 23",
    "23 ",
    "1234a",
    "aa",
    "123 345",
    "-111",
    "+344",
    "4294967295",
    "4294967296",
    "0",
    "32000000",
  };

int main(int argc, char **argv) {
  // if (argc != 2) {
  //   // Number of parameters incorrect
  //   std::cout << "Invalid number of parameters!";
  //   return 1;
  // }

  // Parse input
  // uint32_t number {};
  // eParserResult ret = parse_input(number, argv[1], 10);
  // std::cout << "return value: " << (int)ret << ", input: " << number << "\n";

  // TODO delete, current test
  for (auto &t : test) {
    // Parse input
    uint32_t number {};
    eParserResult ret = parse_input(number, t.c_str(), 10);
    std::cout << "Input: '" << t << "' | return value: " << (int)ret << ", input: " << number << "\n";
    
    // Print endian representations
    if (ret == eParserResult::SUCCESS) {
      print_LE(number);
      print_BE(number);
    }
  }

  return 0;
}