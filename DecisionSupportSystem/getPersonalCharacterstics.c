/*
 * Function to retreive the personal characterstics membership degree of student
 * Format -> [ Good, Moderate, Poor ]
*/

#include<stdio.h>
#include<math.h>
#include<Windows.h>

#define SLOPE 0.6
#define INFLECTION_POINT_LEFT 35
#define INFLECTION_POINT_RIGHT 65

static double getMembershipDegree(int finalScore, int category);

void getPersonalCharacterstics(double personalStatus[]){

	/*****Sub-Criteria range [0-100] **************/
	int veteran = 0;
	int sponsorship = 0;
	int gender = 0;
	int sickness = 0;
	int eduLevelOfFamily = 0;
	/*********************************************/

	int finalScore = 0;

	system("cls");
	printf("\nPersonal Characterstics:\n");

	printf("\nVeteran [0-100]: ");
	scanf("%d",&veteran);

	printf("\nSponsorship [0-100]: ");
	scanf("%d",&sponsorship);

	printf("\n(0 - Male\t[1-100] - Female)\nGender: ");
	scanf("%d",&gender);

	printf("\nSickness [0-100]: ");
	scanf("%d",&sickness);

	printf("\nEdu. level of family [0-100]: ");
	scanf("%d",&eduLevelOfFamily);

	finalScore = min(100, (veteran + sponsorship + gender + sickness + eduLevelOfFamily));

	personalStatus[0] = getMembershipDegree(finalScore, 1);  // good
	personalStatus[1] = getMembershipDegree(finalScore, 2);  // moderate
	personalStatus[2] = getMembershipDegree(finalScore, 3);  // poor

	return;
}

double getMembershipDegree(int finaScore, int category){

	double membershipDegree = 0;

	switch(category){
	
	case 1:
		membershipDegree = 1/(1 + exp(-SLOPE * (finaScore - INFLECTION_POINT_RIGHT)));  //good
		break;

	case 2:
		membershipDegree = 1/(1 + exp(-SLOPE * (finaScore - INFLECTION_POINT_LEFT)))   
			- 1/(1 + exp(-SLOPE * (finaScore - INFLECTION_POINT_RIGHT)));              //moderate
		break;

	case 3:
		membershipDegree = 1/(1 + exp(SLOPE * (finaScore - INFLECTION_POINT_LEFT)));   //poor
		break;

	}

	return membershipDegree;

}