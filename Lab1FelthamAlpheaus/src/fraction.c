#include "fraction.h"

/*Alpheaus Feltham, 0903594*/

/*Creates a new Fraction
precondition: Denominator value must not be 0
postcondition: Fraction must not be NULL or empty, denominator must not be 0
*/
Fraction * createFract (int num,int denom){
	Fraction * fract;
	
	fract = malloc(sizeof(Fraction));
	
	fract->numerator = num;
	fract->denominator = denom;
	
	return(fract);
}

/*Removes an existing Fraction
precondition: Fraction must not be NULL or empty
postcondition: Fraction must be NULL
*/
Fraction * removeFract (Fraction * fract){
	free(fract);
	return(NULL);
}

/*Finds the largest divisor of both the numerator and denominator, used for simplifying fractions
precondition: Inputs must not be NULL, denominator must not be 0
postcondition: Result must be correct
*/
int findLargestDivisor (int num, int denom){
	
	int i;
	int result;
	if(num > denom){
		for (i=1;i<=denom;i++){
			if((num % i == 0) && (denom % i == 0)){
				result = i;
			}
		}
	}else if (denom > num){
		for (i=1;i<=num;i++){
			if((num % i == 0) && (denom % i == 0)){
				result = i;
			}
		}
	}else if (denom == num){
		return (1);
	}
	
	return(result);
}

/*Simplifies the Fraction
precondition: Fraction must not be NULL, denominator must not be 0
postcondition: Result must be correct
*/
Fraction * simplify (Fraction * fract){

	int divisor;
	int neg;
	
	neg = 1;
	
	if (fract->numerator < 0){
		neg = -1;
		fract->numerator = fract->numerator * neg;
	}
	
	divisor = findLargestDivisor (fract->numerator,fract->denominator);
	fract->denominator = (fract->denominator / divisor);
	fract->numerator = ((fract->numerator / divisor) * neg);

	return(fract);
}

/*Modifies the Fraction's values
precondition: Fraction must exist, and not be NULL
postcondition: Fraction must not be NULL or empty
*/
Fraction * modifyFract (Fraction * fract, int newNum, int newDenom){
	
	fract->numerator = newNum;
	fract->denominator = newDenom;
	
	fract = simplify (fract);
	
	return(fract);
}

/*Adds two Fractions together
precondition: Neither Fraction can be NULL or empty
postcondition: Resulting Fraction must not be NULL or empty, and must have the correct values
*/
Fraction * addFract (Fraction * fractOne, Fraction * fractTwo){
	
	Fraction * result;
	
	result = createFract(1,1);
	result->numerator = ((fractOne->numerator * fractTwo->denominator) + (fractTwo->numerator * fractOne->denominator));
	result->denominator = (fractOne->denominator * fractTwo->denominator);
	
	result = simplify (result);
	
	return(result);
}

/*Subtracts two Fractions from each other
precondition: Neither Fraction can be NULL or empty
postcondition: Resulting Fraction must not be NULL or empty, and must have the correct values
*/
Fraction * subFract (Fraction * fractOne, Fraction * fractTwo){
	
	Fraction * result;
	
	result = createFract(1,1);
	
	result->numerator = ((fractOne->numerator * fractTwo->denominator) - (fractTwo->numerator * fractOne->denominator));
	result->denominator = (fractOne->denominator * fractTwo->denominator);
	
	result = simplify (result);
	
	return(result);
}

/*Multiplies two Fractions together
precondition: Neither Fraction can be NULL or empty
postcondition: Resulting Fraction must not be NULL or empty, and must have the correct values
*/
Fraction * multFract (Fraction * fractOne, Fraction * fractTwo){
	
	Fraction * result;
	
	result = createFract(1,1);
	
	result->numerator = (fractOne->numerator * fractTwo->numerator);
	result->denominator = (fractOne->denominator * fractTwo->denominator);
	
	result = simplify (result);
	
	return(result);
}

/*Divides two Fractions
precondition: Neither Fraction can be NULL or empty
postcondition: Resulting Fraction must not be NULL or empty, and must have the correct values
*/
Fraction * divFract (Fraction * fractOne, Fraction * fractTwo){
	
	Fraction * result;
	
	result = createFract(1,1);
	
	result->numerator = (fractOne->numerator * fractTwo->denominator);
	result->denominator = (fractOne->denominator * fractTwo->numerator);
	
	result = simplify (result);
	
	return(result);
}

/*Prints the fraction to the screen
precondition: Fraction must not be NULL or empty
postcondition: Values must be printed to screen
*/
void printFract (Fraction * fract){
	if(fract != NULL){
		printf("\n%d/%d",fract->numerator,fract->denominator);
	}else{
		printf("\nERROR, EMPTY FRACTION");
	}
}

/*Gets the Numerator of the Fraction
precondition: Fraction must not be NULL
postcondition: none
*/
int getNumerator (Fraction * fract){
	
	return(fract->numerator);
}

/*Gets the Denominator of the Fraction
precondition: Fraction must not be NULL
postcondition: none
*/
int getDenominator (Fraction * fract){
	
	return(fract->denominator);
}