#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"

int main(void){
	Fraction * fractOne;
	Fraction * fractTwo;
	Fraction * result;
	
	/*This Test program thoroughly tests each of the functions by running it and printing the results to the screen. The tester can then see if the results are accurate.*/
	
	/*In the case of the alternate definition, I do not beleive I would have to change my fraction ADT, as it would still meet the specifications.*/
	
	fractOne = createFract(1,2);
	fractTwo = createFract(3,4);
	result = createFract(1,1);
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
	getchar();
	return(0);
}