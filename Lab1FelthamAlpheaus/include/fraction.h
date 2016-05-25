#include <stdio.h>
#include <stdlib.h>

/*Alpheaus Feltham, 0903594*/

typedef struct FractionInfo{
	int numerator;
	int denominator;
}Fraction;

Fraction * createFract (int num, int denom);

Fraction * removeFract (Fraction * fract);

int findLargestDivisor (int num, int denom);

Fraction * simplify (Fraction * fract);

Fraction * modifyFract (Fraction * fract, int newNum, int newDenom);

Fraction * addFract (Fraction * fractOne, Fraction * fractTwo);

Fraction * subFract (Fraction * fractOne, Fraction * fractTwo);

Fraction * multFract (Fraction * fractOne, Fraction * fractTwo);

Fraction * divFract (Fraction * fractOne, Fraction * fractTwo);

void printFract (Fraction * fract);

int getNumerator (Fraction * fract);

int getDenominator (Fraction * fract);