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
Call the compiled program and pass the number as parameter. 

### Example
From terminal:
```sh
./print_endian 12003400
```

Will produce the following output:
```sh
Input: 12003400
Little Endian:  48 28 B7 00 
Big Endian:     00 B7 28 48 
```

## Testing
To test the application simply run the following command from terminal:
```sh
python3 test.py
```

The testing utility takes optional arguments, which can be explored by running:
```sh
python3 test.py -h
```

The file `test_pairs.json` contains the default testing values. A different .json file from the default one can be provided as parameter or alternative new testing pairs can be added to this file.

### Example
From terminal
```sh
python3 test.py -v
```

Will produce the following output:
```sh
Testing: ' ', Expected: INVALID
Got: INVALID
1/11: passed
Testing: ' 23', Expected: 17 00 00 00, 00 00 00 17
Got: 17 00 00 00, 00 00 00 17
2/11: passed
Testing: '23 ', Expected: INVALID
Got: INVALID
3/11: passed
Testing: '4294967295', Expected: FF FF FF FF, FF FF FF FF
Got: FF FF FF FF, FF FF FF FF
4/11: passed
Testing: '4294967296', Expected: OUT OF RANGE
Got: OUT OF RANGE
5/11: passed
Testing: '-1', Expected: OUT OF RANGE
Got: OUT OF RANGE
6/11: passed
Testing: '32000000', Expected: 00 48 E8 01, 01 E8 48 00
Got: 00 48 E8 01, 01 E8 48 00
7/11: passed
Testing: '0', Expected: 00 00 00 00, 00 00 00 00
Got: 00 00 00 00, 00 00 00 00
8/11: passed
Testing: '123a456', Expected: INVALID
Got: INVALID
9/11: passed
Testing: '+1234567', Expected: 87 D6 12 00, 00 12 D6 87
Got: 87 D6 12 00, 00 12 D6 87
10/11: passed
Testing: '+123 456', Expected: INVALID
Got: INVALID
11/11: passed
```