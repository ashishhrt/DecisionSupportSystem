/*
 * Function to retreive the educational criteria membership degree
 * Format -> [ Good, Moderate, Poor ]
*/

#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<math.h>

static void getAverageGrade(double a[]);
static void getCourseUnitsProportionAndUnitsPassed(double a[], double unitsPassed[]);
static void getConditionalAdmission(double a[]);
static void getRemainingSemesters(double a[]);

void getEducationalCriteria(double educationalCriteria[]){

	/*
	 * Educational criteria weights:
	 * Format: [ 
	 *           Average_grade, 
	 *           Passed_units_proportion,
	 *			 Remaining_semesters,
	 *           Units_passed, 
	 *           Conditional_admission 
	 *         ]
	*/
	double educationalCriteriaWeights[5] = { 0.25, 0.20, 0.08, 0.17, 0.30};
	
	/*****Educational criteria variables*****/
	double averageGrade[3];
	double courseUnitsProportion[3];
	double remainingSemesters[3];
	double unitsPassed[3]; 
	double conditionalAdmission[3]; 
	/***************************************/

	int i = 0, j = 0, _unitsPassed = 0;

	system("cls");
	//printf("%.3lf\n",exp(2.0));
	printf("\nEducational criteria:\n\n");

	/******Calculate the membership degree of various educational criterias*************/

	getAverageGrade(averageGrade);                     //get average grade membership degree
	getCourseUnitsProportionAndUnitsPassed(courseUnitsProportion, unitsPassed); 
	//get course units passed and course unit's proportion membership degree
	getRemainingSemesters(remainingSemesters);         //get remaining semesters membership degree
	getConditionalAdmission(conditionalAdmission);     //get average grade membership degree

	/************************************************************************************/

	/*******calculate whole educational criteria membership degree***********/

	for(i = 0; i < 3; i++){
		
		educationalCriteria[i] = (
			averageGrade[i] * educationalCriteriaWeights[0] +
			courseUnitsProportion[i] * educationalCriteriaWeights[1] + 
			remainingSemesters[i] * educationalCriteriaWeights[2] + 
			unitsPassed[i] * educationalCriteriaWeights[3] + 
			conditionalAdmission[i] * educationalCriteriaWeights[4]
		);

	}

	/************************************************************************/

	getch();

	return;
}

void getAverageGrade(double averageGrade[]){

	double grade = -1;  // range [0, 20]

	printf("\nEnter average grade[0-20]: ");
	scanf("%lf", &grade);

	if(grade < 0)
		grade = 0;
	else if(grade > 20)
		grade = 20;

	printf("Average grade: \n");
	averageGrade[0] = 1 / ( 1 + exp(-4 * (grade - 14)) );  //Good
	printf("Good: %.3lf \n", averageGrade[0]);
	averageGrade[1] = ( 1 / ( 1 + exp(-4 * (grade - 10)) ) ) - ( 1 / ( 1 + exp(-4 * (grade - 14)) ) );  //Moderate
	printf("Moderate: %.3lf \n", averageGrade[1]);
	averageGrade[2] = 1 / ( 1 + exp(4 * (grade - 10)) ); //Poor
	printf("Poor: %.3lf \n", averageGrade[2]);

	return;
}


void getCourseUnitsProportionAndUnitsPassed(double courseUnitsProportion[], double unitsPassed[]){

	double _courseUnitsProportion = -1;  // range [0, 1]
	int _unitsAttempted = -1; // range [0, 140]
	int _unitsPassed = -1; 

	printf("\nCourse units taken out of 140 units: ");
	scanf("%d", &_unitsAttempted);

	if(_unitsAttempted < 0){
		_unitsAttempted = 0;
	}
	else if(_unitsAttempted > 140){
		_unitsAttempted = 140;
	}

	printf("\nUnits passed out of %d units:  ", _unitsAttempted);
	scanf("%d", &_unitsPassed);

	if(_unitsPassed < 0)
		_unitsPassed = 0;
	else if(_unitsPassed > _unitsAttempted)
		_unitsPassed = _unitsAttempted;

	printf("Units Passed: \n");
	unitsPassed[0] = 1 / ( 1 + exp(-0.6 * (_unitsPassed - 120)) );  //Good
	printf("Good: %.3lf\n", unitsPassed[0]);
	unitsPassed[1] = ( 1 / ( 1 + exp(-0.6 * (_unitsPassed - 90)) ) ) - ( 1 / ( 1 + exp(-(0.6 * _unitsPassed - 120)) ) );  //Moderate
	printf("M: %.3lf\n", unitsPassed[1]);
	unitsPassed[2] = 1 / ( 1 + exp(0.6 * (_unitsPassed - 90)) ); //Poor
	printf("P: %.3lf\n", unitsPassed[2]);

	if(_unitsAttempted == 0)
		_courseUnitsProportion = 0;
	else
		_courseUnitsProportion = _unitsPassed / (double)_unitsAttempted;
	
	printf("Prportion\n");
	courseUnitsProportion[0] = 1 / ( 1 + exp(-80 * (_courseUnitsProportion - 0.8)) );  //Good
	printf("G: %.3lf\n", courseUnitsProportion[0]);
	courseUnitsProportion[1] = ( 1 / ( 1 + exp(-80 * (_courseUnitsProportion - 0.6)) ) ) - 
		( 1 / ( 1 + exp(-80 * (_courseUnitsProportion - 0.8)) ) );  //Moderate
	printf("M: %.3lf\n", courseUnitsProportion[1]);
	courseUnitsProportion[2] = 1 / ( 1 + exp(80 * (_courseUnitsProportion - 0.6)) ); //Poor
	printf("P: %.3lf\n", courseUnitsProportion[2]);
	
	return;

}

void getConditionalAdmission(double conditionalAdmission[]){

	int _conditionalAdmission = -1;  // range [0, 10]

	printf("\nNumber of Conditional admission's granted[0-10]:  ");
	scanf("%d", &_conditionalAdmission);

	if(_conditionalAdmission < 4)
		_conditionalAdmission = 3;
	else if(_conditionalAdmission > 6)
		_conditionalAdmission = 7;

	switch(_conditionalAdmission){
	
	case 3: 
		conditionalAdmission[0] = 1; //good
		conditionalAdmission[1] = 0; //moderate
		conditionalAdmission[2] = 0; //poor
		break;
	case 4: 
		conditionalAdmission[0] = 0.1; //good
		conditionalAdmission[1] = 0.8; //moderate
		conditionalAdmission[2] = 0.1; //poor
		break;
	case 5: 
		conditionalAdmission[0] = 0; //good
		conditionalAdmission[1] = 0.4; //moderate
		conditionalAdmission[2] = 0.6; //poor
		break;
	case 6: 
		conditionalAdmission[0] = 0; //good
		conditionalAdmission[1] = 0.2; //moderate
		conditionalAdmission[2] = 0.8; //poor
		break;
	case 7: 
		conditionalAdmission[0] = 0; //good
		conditionalAdmission[1] = 0; //moderate
		conditionalAdmission[2] = 1; //poor
		break;
	}

	printf("Conditional admission\n");
	printf("G: %.3lf\n", conditionalAdmission[0]);
	printf("M: %.3lf\n", conditionalAdmission[1]);
	printf("P: %.3lf\n", conditionalAdmission[2]);

	return;

}

void getRemainingSemesters(double remainingSemesters[]){

	int _remainingSemesters = -1;  // range [0, 8]

	printf("\nRemaining semesters[0-8]:  ");
	scanf("%d", &_remainingSemesters);

	if(_remainingSemesters < 3)
		_remainingSemesters = 2;
	else if(_remainingSemesters > 5)
		_remainingSemesters = 6;

	switch(_remainingSemesters){
	
	case 2: 
		remainingSemesters[0] = 0; //good
		remainingSemesters[1] = 0.1; //moderate
		remainingSemesters[2] = 0.9; //poor
		break;
	case 3: 
		remainingSemesters[0] = 0.1; //good
		remainingSemesters[1] = 0.8; //moderate
		remainingSemesters[2] = 0.1; //poor
		break;
	case 4: 
		remainingSemesters[0] = 0.6; //good
		remainingSemesters[1] = 0.4; //moderate
		remainingSemesters[2] = 0; //poor
		break;
	case 5: 
		remainingSemesters[0] = 0.8; //good
		remainingSemesters[1] = 0.2; //moderate
		remainingSemesters[2] = 0; //poor
		break;
	case 6: 
		remainingSemesters[0] = 1; //good
		remainingSemesters[1] = 0; //moderate
		remainingSemesters[2] = 0; //poor
		break;
	}

	printf("Remaining sem\n");
	printf("G: %.3lf\n", remainingSemesters[0]);
	printf("M: %.3lf\n", remainingSemesters[1]);
	printf("P: %.3lf\n", remainingSemesters[2]);

	return;

}