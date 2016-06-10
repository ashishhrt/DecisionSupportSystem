/*
 * Function to covert input variables to FIS
 * into fuzzy set.
 * Format -> [ low, medium, high] (acceptance degree)
*/

#include<stdio.h>
#include<math.h>

#define SLOPE 80
#define INFLECTION_POINT_LEFT 0.35
#define INFLECTION_POINT_RIGHT 0.65

static void fuzzify(double inputParameter, double fuzzifiedValues[]);

void fuzzifyInputParameters(double poor, double moderate, double good,
							  double fuzzifiedPoor[], double fuzzifiedModerate[], double fuzzifiedGood[] )
{

	fuzzify(poor, fuzzifiedPoor);
	fuzzify(moderate, fuzzifiedModerate);
	fuzzify(good, fuzzifiedGood);

	return;

}

void fuzzify(double inputParameter, double fuzzifiedValues[]){

	fuzzifiedValues[0] = 1 / ( 1 + exp(SLOPE * (inputParameter - INFLECTION_POINT_LEFT) ));  //low
	fuzzifiedValues[1] = 1 / ( 1 + exp(-SLOPE * (inputParameter - INFLECTION_POINT_LEFT) ))  //medium
		- 1 / ( 1 + exp(-SLOPE * (inputParameter - INFLECTION_POINT_RIGHT) ));
	fuzzifiedValues[2] = 1 / ( 1 + exp(-SLOPE * (inputParameter - INFLECTION_POINT_RIGHT) )); //high

	return;

}