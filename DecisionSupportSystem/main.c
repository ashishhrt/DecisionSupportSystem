#include<stdio.h>
#include<stdlib.h>
#include<math.h>

extern void makeRequest(double a[]);
extern void getEducationalCriteria(double a[]);
extern void getRichnessDegree(double a[]);
extern void getPersonalCharacterstics(double a[]);
extern void getUnusualDifficulties(double a[]);
extern void getTotalScore(double w[], double x[], double y[], double z[], double a[], double b[]);
extern char* FIS(double poor, double moderate, double good);

int main(void){
	
	int testCase = 1;
	char choice = 'n';

	while(testCase){
		
		/* criteriaWeights format: (in percent %)
		* [
		*		0 -> Educational(w1)
		*		1 -> Richness degree(w2)
		*		2 -> Personal characterstics(w3)
		*		3 -> Unusual difficulties(w4)
		* ]
		*/
		double criteriaWeights[4];           //holds weights of criteria corresponding to request type

		/* criteria format containing their membership degrees
		* criteria
		* [
		*		0 -> good
		*		1 -> moderate
		*		2 -> poor
		* ]
		*/
		double educationalCriteria[3];    //holds membership degree of educational criteria of student
		double economicCircumstances[3];  //holds membership degree of economic circumstances of student
		double personalStatus[3];         //holds membership degree of personal status of student
		double unusualDifficulties[3];    //holds membership degree of unusual difficulties of student
		double totalScoreForCriteria[3];  //holds score for a certain student request in fuzzy terms
		char *finalDecision;              //Sotre the final decision proposed by system

		makeRequest(criteriaWeights); //receive criteria weights

		getEducationalCriteria(educationalCriteria); //get educational criteria weight

		getRichnessDegree(economicCircumstances);    //get economic status of student

		getPersonalCharacterstics(personalStatus);   //get personal status of student
		
		getUnusualDifficulties(unusualDifficulties); //get unusual difficulties faced by student

		getTotalScore(educationalCriteria, economicCircumstances, personalStatus, unusualDifficulties, criteriaWeights, totalScoreForCriteria);
		//get total score

		finalDecision = FIS(totalScoreForCriteria[2], totalScoreForCriteria[1], totalScoreForCriteria[0]);

		system("cls");

		printf("\n\nFinal decision proposed: ");
		printf("%s\n\n", finalDecision);
		
		printf("Try again? (y/n): ");
		fflush(stdin);
		scanf("%c",&choice);

		if(choice == 'y' || choice == 'Y')
		;
		else
			testCase = 0;
	}

	return 0;

}