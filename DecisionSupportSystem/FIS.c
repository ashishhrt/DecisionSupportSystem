/*
 * FIS -> Fuzzy Inference System
 * Specifications: 
 *		Type: Multi Input Single Output (MISO)
 *		Inference method: Mamdani
 *		Operators: Standard (Zadeh's method)
 *		Defuzzification method: Center of Area (COA)
 *
 * FIS is designed to generate the crisp value of the final score
 * based on which the final decision is made.
*/

#include<stdio.h>

/****Limits variable based on council members experience****/
#define REJECTION_LIMIT 40          //[0, 40)
#define ALTERNATIVE_LIMIT_LEFT 39
#define ALTERNATIVE_LIMIT_RIGHT 60  //[40, 60)
#define ACCEPTANCE_LIMIT_LEFT 59
#define ACCEPTANCE_LIMIT_RIGHT 101  //[60, 100]
/**********************************************************/

extern int getCrispFinalScore(double p1, double p2, double p3);


//p1 -> poor, p2 -> moderate, p3 -> good
char* FIS(double p1, double p2, double p3){

	/**The final decision base**/
	char *decision[] = {
	
		"Rejection",
		"Alternative decision",
		"Acceptance"

	};
	/***************************/

	char *proposedDecision = NULL;

	int finalScore = 0;  //hold crisp final score based on which decision is made [0-100]

	finalScore = getCrispFinalScore(p1, p2, p3);

	if(finalScore < REJECTION_LIMIT){
		
		proposedDecision = decision[0];

	}
	else if(finalScore > ALTERNATIVE_LIMIT_LEFT && finalScore < ALTERNATIVE_LIMIT_RIGHT){
	
		proposedDecision = decision[1];

	}
	else if(finalScore > ACCEPTANCE_LIMIT_LEFT && finalScore < ACCEPTANCE_LIMIT_RIGHT){
	
		proposedDecision = decision[2];
	
	}
	
	return proposedDecision;

}