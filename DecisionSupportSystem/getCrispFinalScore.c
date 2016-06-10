/*
 * Function to manage all the operations of FIS and finally return crisp final score
 * Format -> [ poor, moderate, good ]
*/

#include<stdio.h>
#include<conio.h>
#include<Windows.h>

extern void fuzzifyInputParameters(double p, double m, double g, double a[], double b[], double c[]);
extern void getOutputVariablesMbershipDegree(double a[], double b[], double c[], double x[]);
extern int COA(double a[]);

int getCrispFinalScore(double poor, double moderate, double good){

	/*
	 * Fuzzified input parameters
	 * Format -> [ low, medium, high] (acceptance degree)
	*/
	double fuzzifiedPoor[3];
	double fuzzifiedModerate[3];
	double fuzzifiedGood[3];
	/********************************/

	double outputVariables[3];  //hold the membership degree of output variables 
	int i = 0;

	system("cls");

	fuzzifyInputParameters(poor, moderate, good, fuzzifiedPoor, fuzzifiedModerate, fuzzifiedGood); //fuzzify input parameters

	printf("\nPoor: %.3f\n", poor);
	for(i = 0; i < 3; i++){
	
		printf("%.3f ", fuzzifiedPoor[i]);
	
	}
	
	printf("\nModerate: %.3f\n", moderate);
	for(i = 0; i < 3; i++){
	
		printf("%.3f ", fuzzifiedModerate[i]);
	
	}

	printf("\nGood: %.3f\n", good);
	for(i = 0; i < 3; i++){
	
		printf("%.3f ", fuzzifiedGood[i]);
	
	}
	
	getOutputVariablesMbershipDegree(fuzzifiedPoor, fuzzifiedModerate, fuzzifiedGood, outputVariables);

	//system("cls");

	/*printf("\nModerate: %.3f\n", moderate);
	for(i = 0; i < 3; i++){
	
		printf("%.3f ", fuzzifiedModerate[i]);
	
	}

	printf("\nGood: %.3f\n", good);
	for(i = 0; i < 3; i++){
	
		printf("%.3f ", fuzzifiedGood[i]);
	
	}*/

	printf("\nFinal score: \n");
	for(i = 0; i < 3; i++){
	
		printf("%.3f ", outputVariables[i]);
	
	}

	

	i = COA(outputVariables);  //calculate crisp value using Center of Area
	
	printf("\nCrisp Final Score: %d\n",i);

	getch();
	return i;
}