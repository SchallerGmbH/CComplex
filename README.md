# Complex

Arduino library for Complex math

## Description

This library defines the complex datatype and all the common math functions for it.

These functions include basic = - \* / but also power and gonio functions.

See Complex.h for all functions implemented.


## Note
The library has a big footprint so it fills up the memory of an UNO quite fast.

Issue found in version 0.1.9 - https://github.com/RobTillaart/Arduino/issues/90
Class does not compile for DUE and TEENSY

Apparently the name "Complex" is already in use (reserved) by some non-AVR compilers 
so it won't include the Complex.h file. Problem seen on Due and Teensy3.5

Solution:
- Make a copy of the Complex Library and rename the folder to CComplex 
- Rename Complex.h to CComplex.h
- Rename Complex.cpp to CComplec.cpp
- change one line in CComplex.cpp to include CComplex.h

