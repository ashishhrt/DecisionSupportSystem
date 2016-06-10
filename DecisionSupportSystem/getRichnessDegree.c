/*
 * Function to retreive the economic circumstances membership degree of student
 * Format -> [ Good, Moderate, Poor ]
*/

#include<stdio.h>
#include<math.h>
#include<Windows.h>

#define SLOPE 0.6
#define INFLECTION_POINT_LEFT 35
#define INFLECTION_POINT_RIGHT 65

static double getMembershipDegree(int avg, int category);

void getRichnessDegree(double economicCircumstatnces[]){

	int familyWealthSituation = 0;   //store family wealth condition [0-100]
	int residenceRegion = 0;         //store residence region point [0-100]
	int avgOfBothCriteria = 0;

	system("cls");
	printf("\nRichness Degree\n");

	printf("\nFamily wealth situation [0-100]: ");
	scanf("%d",&familyWealthSituation);

	printf("\nResidence region [0-100]: ");
	scanf("%d",&residenceRegion);

	avgOfBothCriteria = (familyWealthSituation + residenceRegion) / 2;  //get average of both sub-criteria

	economicCircumstatnces[0] = getMembershipDegree(avgOfBothCriteria, 1);  // good
	economicCircumstatnces[1] = getMembershipDegree(avgOfBothCriteria, 2);  // moderate
	economicCircumstatnces[2] = getMembershipDegree(avgOfBothCriteria, 3);  // poor

	return;
}

double getMembershipDegree(int avg, int category){

	double membershipDegree = 0;

	switch(category){
	
	case 1:
		membershipDegree = 1/(1 + exp(-SLOPE * (avg - INFLECTION_POINT_RIGHT)));  //good
		break;

	case 2:
		membershipDegree = 1/(1 + exp(-SLOPE * (avg - INFLECTION_POINT_LEFT)))   
			- 1/(1 + exp(-SLOPE * (avg - INFLECTION_POINT_RIGHT)));              //moderate
		break;

	case 3:
		membershipDegree = 1/(1 + exp(SLOPE * (avg - INFLECTION_POINT_LEFT)));   //poor
		break;

	}

	return membershipDegree;

}