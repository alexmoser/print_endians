# Print Endians
Small program that accepts an unsigned 32-bit number from the user and then displays that number in big-endian and little-endian byte formats.

Example input: 
```
32000000
```

Example output: 
```
Big Endian: 01 E8 48 00
Little Endian: 00 48 E8 10
```
## Information
The program accepts any inputs but it returns error if:
- More than one input parameter is provided
- The input provided is not a positive integer number
- The input provided is not representable on 32bits (is ≥ 2^32)
- The input contains characters other than digits

Notes:
- Leading whitespaces are ignored
- A leading `+` symbol is accepted

## Usage
