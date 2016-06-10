/*
 * COA function also known as Center of Area function.
 * It is used to defuzzify a fuzzified value and gives
 * a crisp value as output.
 * Approximation COA
 * COA = SUM(fuzzified_terms_value * membership_degree) / SUM( membership_degree * no._of times_used_in_numerator );
 *
 * Here it will defuzzify the final score(s) generated inside FIS system.
 * Based on that crisp value, final decision will be made.
 * returned vlaue [0-100]
*/

#include<stdio.h>

/*
* Distribution of fuzzy terms:
* Low: [0 35)
* Medium: [35 65]
* High: (65 100]
*/
#define MEDIUM_LIMIT_LEFT 35
#define MEDIUM_LIMIT_RIGHT 65

int COA(double outputVariables[]){

	double low = outputVariables[0];
	double medium = outputVariables[1];
	double high = outputVariables[2];

	int crispFinalScore = 0;
	/*
	 * Approximation COA, taking fuzzified_term_values with
	 * interval of 5.
	*/
	crispFinalScore = (
			low * (0 + 5 + 10 + 15 + 20 + 25 + 30) 
			+ medium *(35 + 40 + 45 + 50 + 55 + 60 + 65)
			+ high * (70 + 75 + 80 + 85 + 90 + 95 + 100)
		)
		/ 
		(
			low * 7 + medium * 7 + high * 7
		);

	return crispFinalScore;

}