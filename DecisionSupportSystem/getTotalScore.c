/*
 * Function to retreive the total score for a certain student request
 * in fuzzy terms.
 * Format -> [ Good, Moderate, Poor ]
*/

#include<stdio.h>

void getTotalScore(double educationalCriteria[], double economicCircumstances[], double personalStatus[],
				   double unusualDifficulties[], double criteriaWeights[], double totalScoreForCriteria[])
{

	double good = 0;
	double moderate = 0;
	double poor = 0;

	int i = 0, j = 0;

	for(i = 0; i < 3; i++){
	
		totalScoreForCriteria[i] = (educationalCriteria[i] * criteriaWeights[0]) + (economicCircumstances[i] * criteriaWeights[1])
			+(personalStatus[i] * criteriaWeights[2]) + (unusualDifficulties[i] * criteriaWeights[3]);
	
	}

	return;

}