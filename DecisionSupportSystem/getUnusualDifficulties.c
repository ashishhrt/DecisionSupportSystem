/*
 * Function to retreive the unusual difficulties membership degree faced by student
 * Format -> [ Good, Moderate, Poor ]
*/

#include<stdio.h>
#include<math.h>
#include<Windows.h>

#define SLOPE 0.6
#define INFLECTION_POINT_LEFT 35
#define INFLECTION_POINT_RIGHT 65

static double getMembershipDegree(int difficulty, int category);

void getUnusualDifficulties(double unusualDifficulties[]){

	int difficulty = 0;   //store unusual difficulty faced by student [0-100]

	system("cls");
	printf("\nUnusual Difficulties\n");

	printf("\nUnusual difficulties [0-100]: ");
	scanf("%d",&difficulty);

	unusualDifficulties[0] = getMembershipDegree(difficulty, 1);  // good
	unusualDifficulties[1] = getMembershipDegree(difficulty, 2);  // moderate
	unusualDifficulties[2] = getMembershipDegree(difficulty, 3);  // poor

	return;
}

double getMembershipDegree(int difficulty, int category){

	double membershipDegree = 0;

	switch(category){
	
	case 1:
		membershipDegree = 1/(1 + exp(-SLOPE * (difficulty - INFLECTION_POINT_RIGHT)));  //good
		break;

	case 2:
		membershipDegree = 1/(1 + exp(-SLOPE * (difficulty - INFLECTION_POINT_LEFT)))   
			- 1/(1 + exp(-SLOPE * (difficulty - INFLECTION_POINT_RIGHT)));              //moderate
		break;

	case 3:
		membershipDegree = 1/(1 + exp(SLOPE * (difficulty - INFLECTION_POINT_LEFT)));   //poor
		break;

	}

	return membershipDegree;

}