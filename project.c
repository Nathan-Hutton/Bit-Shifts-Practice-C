/*
 * project.c
 *
 * Project 1: split up the fields of a double value to
 * manipulate its value.
 *
 * Nathan Hutton
 */

#include <stdio.h>

// These functions will be implemented in a separate file
// (hence "extern") for Steps 1 and 4
extern long double_to_long_bits(double x);
extern double long_bits_to_double(long l);

// Functions to fill in for Step 2
long sign_of(long l);
long exponent_of(long l);
long fraction_of(long l);

// Function to fill in for Step 3
long assemble_long_bits(long sign, long exponent, long fraction);

// Functions to fill in for Step 5
double log_base_2(double x);
double negative_zero();
double infinity();
double halve(double x);

int main()
{
    // Write your code to test your functions here
    // (for Step 5, replace with your final program)
    // double x = 1234567890;
    // long y = double_to_long_bits(x);

    // printf("%ld\n", y);
    // printf("%ld\n", fraction_of(y));
    // printf("%ld\n", exponent_of(y));
    // printf("%ld\n", sign_of(y));
    // printf("%ld\n", assemble_long_bits(sign_of(y), exponent_of(y), fraction_of(y)));
    // printf("%.3f\n", long_bits_to_double(y));
    // printf("%f\n", log_base_2(x));
    // printf("%f\n", negative_zero());
    // printf("%f\n", infinity());
    printf("%f\n", halve(0.0));

    return 0;
}

// -- Functions for Step 2 --
long sign_of(long l)
{
    return (l >> 63) & 0x1;
}

long exponent_of(long l)
{
    return (l >> 52) & 0x7ff;
}

long fraction_of(long l)
{
    return l & 0xfffffffffffff;
}

// -- Function for Step 3 --
long assemble_long_bits(long sign, long exponent, long fraction)
{
    return sign << 63 | exponent << 52 | fraction;
}

// -- Functions for Step 5 --
double log_base_2(double x)
{
    long bits = double_to_long_bits(x);
    long exponent_bits = exponent_of(bits);
    return exponent_bits - 1023;
}

double negative_zero()
{
    long bits = assemble_long_bits(0, 0, 0);
    return long_bits_to_double(bits);
}

double infinity()
{
    long bits = assemble_long_bits(1, 0x7ff, 0);
    return long_bits_to_double(bits);
}

double halve(double x)
{
    long bits = double_to_long_bits(x);
    long sign = sign_of(bits);
    long exponent = exponent_of(bits);
    long fraction = fraction_of(bits);
    exponent = exponent - 1;
    long final_bits = assemble_long_bits(sign, exponent, fraction);
    return long_bits_to_double(final_bits);;
}
