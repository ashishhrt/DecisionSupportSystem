/*
 * Function to retreive the weights of various criteria
 * based on the type of request made by a student to
 * Especial case council.
*/

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void makeRequest(double criteriaWeight[]){

	/* Weights formt
	 * weights[][]
	 * [
	 *		0 -> continuation of study 
	 *		1 -> extension of semesters
	 *		2 -> leave of absence
	 *		3 -> major changing
	 *		4 -> university transfer
	 *		5 -> return back to the program
	 * ]
	 * [
	 *		0 -> Educational(w1)
	 *		1 -> Richness degree(w2)
	 *		2 -> Personal characterstics(w3)
	 *		3 -> Unusual difficulties(w4)
	 * ]
	*/

	double weights[6][4] = {  //hold the weights of different criteria based on different request type
		{0.35, 0.05, 0.25, 0.35},
		{0.60, 0.05, 0.15, 0.20},
		{0, 0, 0.20, 0.80},
		{0.70, 0.05, 0.05, 0.20},
		{0.10, 0.05, 0.40, 0.45},
		{0.25, 0.05, 0.25, 0.45}
	};

	int requestNo = 0;
	int loop = 1;
	int i = 0, j = 0;

	while(loop){ //take input request

		system("cls");
		printf("\nDecision Support System\n\nWelcome!\n");

		printf("\nSelect a request type:\n");
		printf("\n1.Continuation of study.");
		printf("\n2.Extension of semesters.");
		printf("\n3.Leave of absence.");
		printf("\n4.Major changing.");
		printf("\n5.University transfer.");
		printf("\n6.Return to the program.");
		printf("\nPress 0 to EXIT");

		printf("\n\nEnter request number: ");
		scanf("%d",&requestNo);  //accept request number

		switch(requestNo){ //assign weights of various criteria depending on request type
		
		case 1: for(i = 0; i < 4; i++){
					criteriaWeight[i] = weights[0][i];  
				}
				break;
		case 2: for(i = 0; i < 4; i++){
					criteriaWeight[i] = weights[1][i];  
				}
				break;
		case 3: for(i = 0; i < 4; i++){
					criteriaWeight[i] = weights[2][i];  
				}
				break;
		case 4: for(i = 0; i < 4; i++){
					criteriaWeight[i] = weights[3][i];  
				}
				break;
		case 5: for(i = 0; i < 4; i++){
					criteriaWeight[i] = weights[4][i];  
				}
				break;
		case 6: for(i = 0; i < 4; i++){
					criteriaWeight[i] = weights[5][i];  
				}
				break;
		default: exit(1);  //terminate the program

		}

		loop = 0;
	}

	return;

}