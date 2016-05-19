#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

int main(void){
	Fraction * fractOne;
	Fraction * fractTwo;
	Fraction * result;
	
	fractOne = createFract(1,2);
	fractTwo = createFract(3,4);
	printFract(fractOne);
	printFract(fractTwo);
	result = addFract(fractOne,fractTwo);
	printFract(result);
	result = subFract(fractOne,fractTwo);
	printFract(result);
	result = multFract(fractOne,fractTwo);
	printFract(result);
	result = divFract(fractOne,fractTwo);
	printFract(result);
	printf("\nThis is the numerator of the result: %d, this is the Denominator of the result: %d",getNumerator(result),getDenominator(result));
	result = modifyFract(result,1,1);
	printFract(result);
	result = removeFract(result);
	printFract(result);
	fractOne = removeFract(fractOne);
	printFract(fractOne);
	fractTwo = removeFract(fractTwo);
	printFract(fractTwo);
	return(0);
}