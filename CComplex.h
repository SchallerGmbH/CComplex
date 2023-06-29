#pragma once
//
//    FILE: Complex.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.3.2
// PURPOSE: Arduino library for Complex math
//     URL: https://github.com/RobTillaart/Complex
//          http://arduino.cc/playground/Main/ComplexMath


#include "Arduino.h"
#include "Printable.h"

#ifdef USECCOMPLEX_DOUBLE
//#define ctype_t double
typedef double ctype_t;
#else
//#define ctype_t float
typedef float ctype_t;
#endif


#define COMPLEX_LIB_VERSION                 (F("0.3.2"))


class Complex: public Printable
{
public:
    Complex(const ctype_t r = 0, const ctype_t i = 0) : re(r), im(i) {};
    Complex(const Complex &c) : re(c.re), im(c.im) {};


    void set(const ctype_t r, const ctype_t i ) { re = r; im = i; };
    void setReal(const ctype_t r)  { re = r; };
    void setImag(const ctype_t i ) { im = i; };
    ctype_t real() const { return re; };
    ctype_t imag() const { return im; };


    size_t printTo(Print& p) const;
    size_t printToDig(Print& p, int digits) const;

    void polar(const ctype_t modulus, const ctype_t phase);
    ctype_t phase() const       { return atan2(im, re); };
    ctype_t modulus() const     { return hypot(re, im); };
    //  conjugate is the number mirrored in x-axis
    Complex conjugate() const { return Complex(re, -im); };
    Complex reciprocal() const;


    bool operator == (const Complex&) const;
    bool operator != (const Complex&) const;


    Complex operator - () const; // negation


    Complex operator + (const Complex&) const;
    Complex operator - (const Complex&) const;
    Complex operator * (const Complex&) const;
    Complex operator / (const Complex&) const;

    Complex& operator += (const Complex&);
    Complex& operator -= (const Complex&);
    Complex& operator *= (const Complex&);
    Complex& operator /= (const Complex&);


    Complex c_sqrt() const;
    Complex c_sqr() const;
    Complex c_exp() const;
    Complex c_log() const;
    Complex c_log10() const;
    Complex c_pow(const Complex &) const;
    Complex c_logn(const Complex &) const;


    Complex c_sin() const;
    Complex c_cos() const;
    Complex c_tan() const;
    Complex c_asin() const;
    Complex c_acos() const;
    Complex c_atan() const;


    Complex c_csc() const;
    Complex c_sec() const;
    Complex c_cot() const;
    Complex c_acsc() const;
    Complex c_asec() const;
    Complex c_acot() const;


    Complex c_sinh() const;
    Complex c_cosh() const;
    Complex c_tanh() const;
    Complex c_asinh() const;
    Complex c_acosh() const;
    Complex c_atanh() const;


    Complex c_csch() const;
    Complex c_sech() const;
    Complex c_coth() const;
    Complex c_acsch() const;
    Complex c_asech() const;
    Complex c_acoth() const;


protected:
    ctype_t re;
    ctype_t im;

    Complex gonioHelper1(const byte) const;
    Complex gonioHelper2(const byte) const;
};


static const Complex one(1, 0);


// -- END OF FILE --

