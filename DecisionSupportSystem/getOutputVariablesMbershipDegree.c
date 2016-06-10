/*
* Function to calculate the output variable membership degree
* based on rule base of FIS and rules strength.
* Format -> [ low, medium, high ]
*/

#include<stdio.h>
#include<malloc.h>
//#include<math.h>
#include<string.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define RULE_BASE_SIZE 25
#define LOW "low"
#define MEDIUM "medium"
#define HIGH "high"


static struct Rule{

	char *poor;  
	char *moderate;
	char * good;

	char *finalScore;
};

struct Rule *ruleBase[RULE_BASE_SIZE];

void generateruleBase();

void getOutputVariablesMbershipDegree(double fuzzifiedPoor[], double fuzzifiedModerate[], double fuzzifiedGood[], double outputVariables[])
{
	int i = 0, j= 0;

	/*
	* Membership set variables
	* help to determine the rules being fired.
	* Format -> [low, medium, high]
	*/

	char *poor[3];
	char *moderate[3];
	char *good[3];

	/*
	* output variables which we will place in the outputVariables[] array
	* in the end.
	*/
	double outputLow = 0;
	double outputMedium = 0;
	double outputHigh = 0;

	generateruleBase();  //generate rule base

	/*******Initialize membership set variables*****/
	poor[i] = fuzzifiedPoor[i] > 0 ? LOW : NULL;
	i++;
	poor[i] = fuzzifiedPoor[i] > 0 ? MEDIUM : NULL;
	i++;
	poor[i] = fuzzifiedPoor[i] > 0 ? HIGH : NULL;
	i = 0;

	moderate[i] = fuzzifiedPoor[i] > 0 ? LOW : NULL;
	i++;
	moderate[i] = fuzzifiedPoor[i] > 0 ? MEDIUM : NULL;
	i++;
	moderate[i] = fuzzifiedPoor[i] > 0 ? HIGH : NULL;
	i = 0;

	good[i] = fuzzifiedPoor[i] > 0 ? LOW : NULL;
	i++;
	good[i] = fuzzifiedPoor[i] > 0 ? MEDIUM : NULL;
	i++;
	good[i] = fuzzifiedPoor[i] > 0 ? HIGH : NULL;
	i = 0;
	/***********************************************/


	/*
	 * Fire rules based on membership set variables
	 * and set output variables using Zadeh's AND rule 
	 * i.e min of degree set for a rule and then OR rule
	 * i.e max of degree possible for each output variable
	*/

	for(i = 0; i < RULE_BASE_SIZE; i++){

		if(strcmpi(ruleBase[i]->poor, poor[0]) == 0){ //poor -> low

			if(strcmpi(ruleBase[i]->moderate, moderate[0]) == 0){ // moderate -> low


				if(strcmpi(ruleBase[i]->good, good[0]) == 0){ // good -> low

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[0], min(fuzzifiedModerate[0], fuzzifiedGood[0]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 : ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[1]) == 0){ //good -> medium

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[0], min(fuzzifiedModerate[0], fuzzifiedGood[1]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 : 
						( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //\finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[2]) == 0){ //good -> high

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[0], min(fuzzifiedModerate[0], fuzzifiedGood[2]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}


			}
			else if(strcmpi(ruleBase[i]->moderate, moderate[1]) == 0){ //moderate -> medium



				if(strcmpi(ruleBase[i]->good, good[0]) == 0){ // good -> low

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[0], min(fuzzifiedModerate[1], fuzzifiedGood[0]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[1]) == 0){ //good -> medium

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[0], min(fuzzifiedModerate[1], fuzzifiedGood[1]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[2]) == 0){ //good -> high

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[0], min(fuzzifiedModerate[1], fuzzifiedGood[2]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}

			}
			else if(strcmpi(ruleBase[i]->moderate, moderate[2]) == 0){ //moderate -> high

				if(strcmpi(ruleBase[i]->good, good[0]) == 0){ // good -> low

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[0], min(fuzzifiedModerate[2], fuzzifiedGood[0]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[1]) == 0){ //good -> medium

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[0], min(fuzzifiedModerate[2], fuzzifiedGood[1]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[2]) == 0){ //good -> high

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[0], min(fuzzifiedModerate[2], fuzzifiedGood[2]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}

			}

		}

		else if(strcmpi(ruleBase[i]->poor, poor[1]) == 0){ //poor -> medium

			if(strcmpi(ruleBase[i]->moderate, moderate[0]) == 0){ // moderate -> low


				if(strcmpi(ruleBase[i]->good, good[0]) == 0){ // good -> low

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[1], min(fuzzifiedModerate[0], fuzzifiedGood[0]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[1]) == 0){ //good -> medium

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[1], min(fuzzifiedModerate[0], fuzzifiedGood[1]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[2]) == 0){ //good -> high

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[1], min(fuzzifiedModerate[0], fuzzifiedGood[2]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}


			}
			else if(strcmpi(ruleBase[i]->moderate, moderate[1]) == 0){ //moderate -> medium



				if(strcmpi(ruleBase[i]->good, good[0]) == 0){ // good -> low

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[1], min(fuzzifiedModerate[1], fuzzifiedGood[0]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[1]) == 0){ //good -> medium

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[1], min(fuzzifiedModerate[1], fuzzifiedGood[1]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[2]) == 0){ //good -> high

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[1], min(fuzzifiedModerate[1], fuzzifiedGood[2]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}

			}
			else if(strcmpi(ruleBase[i]->moderate, moderate[2]) == 0){ //moderate -> high

				if(strcmpi(ruleBase[i]->good, good[0]) == 0){ // good -> low

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[1], min(fuzzifiedModerate[2], fuzzifiedGood[0]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[1]) == 0){ //good -> medium

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[1], min(fuzzifiedModerate[2], fuzzifiedGood[1]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[2]) == 0){ //good -> high

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[1], min(fuzzifiedModerate[2], fuzzifiedGood[2]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}

			}

		}

		else if(strcmpi(ruleBase[i]->poor, poor[2]) == 0){ //poor -> high

			if(strcmpi(ruleBase[i]->moderate, moderate[0]) == 0){ // moderate -> low


				if(strcmpi(ruleBase[i]->good, good[0]) == 0){ // good -> low

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[2], min(fuzzifiedModerate[0], fuzzifiedGood[0]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[1]) == 0){ //good -> medium

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[2], min(fuzzifiedModerate[0], fuzzifiedGood[1]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[2]) == 0){ //good -> high

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[2], min(fuzzifiedModerate[0], fuzzifiedGood[2]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}


			}
			else if(strcmpi(ruleBase[i]->moderate, moderate[1]) == 0){ //moderate -> medium



				if(strcmpi(ruleBase[i]->good, good[0]) == 0){ // good -> low

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[2], min(fuzzifiedModerate[1], fuzzifiedGood[0]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[1]) == 0){ //good -> medium

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[2], min(fuzzifiedModerate[1], fuzzifiedGood[1]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[2]) == 0){ //good -> high

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[2], min(fuzzifiedModerate[1], fuzzifiedGood[2]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}

			}
			else if(strcmpi(ruleBase[i]->moderate, moderate[2]) == 0){ //moderate -> high

				if(strcmpi(ruleBase[i]->good, good[0]) == 0){ // good -> low

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[2], min(fuzzifiedModerate[2], fuzzifiedGood[0]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[1]) == 0){ //good -> medium

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[2], min(fuzzifiedModerate[2], fuzzifiedGood[1]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}
				else if(strcmpi(ruleBase[i]->good, good[2]) == 0){ //good -> high

					int check_case = 0;
					double minimumDegree = min(fuzzifiedPoor[2], min(fuzzifiedModerate[2], fuzzifiedGood[2]) );
					check_case = (strcmpi(ruleBase[i]->finalScore, LOW) == 0) ? 1 
						: ( ( strcmpi(ruleBase[i]->finalScore, MEDIUM) == 0 ) ? 2 : 3 );

					switch(check_case){

					case 1: //finalScore of rule -> low
						outputLow = max(outputLow,minimumDegree);
						break;

					case 2: //finalScore of rule -> medium
						outputMedium = max(outputMedium, minimumDegree);
						break;

					case 3: //finalScore of rule -> high
						outputHigh = max(outputHigh, minimumDegree);
						break;

					}

				}

			}

		}

	}

	//Low
	outputVariables[0] = outputLow;
	//Medium
	outputVariables[1] = outputMedium;
	//High
	outputVariables[2] = outputHigh;

	return;

}

void generateruleBase(){

	int i = 0;

	//1
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = LOW;
	ruleBase[i]->moderate = LOW;
	ruleBase[i]->good = MEDIUM;
	ruleBase[i]->finalScore = MEDIUM;
	i++;

	//2
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = LOW;
	ruleBase[i]->moderate = LOW;
	ruleBase[i]->good = HIGH;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//3
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = LOW;
	ruleBase[i]->moderate = MEDIUM;
	ruleBase[i]->good = LOW;
	ruleBase[i]->finalScore = MEDIUM;
	i++;

	//4
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = LOW;
	ruleBase[i]->moderate = MEDIUM;
	ruleBase[i]->good = MEDIUM;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//5
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = LOW;
	ruleBase[i]->moderate = MEDIUM;
	ruleBase[i]->good = HIGH;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//6
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = LOW;
	ruleBase[i]->moderate = HIGH;
	ruleBase[i]->good = LOW;
	ruleBase[i]->finalScore = MEDIUM;
	i++;

	//7
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = LOW;
	ruleBase[i]->moderate = HIGH;
	ruleBase[i]->good = MEDIUM;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//8
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = LOW;
	ruleBase[i]->moderate = HIGH;
	ruleBase[i]->good = HIGH;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//9
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = MEDIUM;
	ruleBase[i]->moderate = LOW;
	ruleBase[i]->good = LOW;
	ruleBase[i]->finalScore = LOW;
	i++;

	//10
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = MEDIUM;
	ruleBase[i]->moderate = LOW;
	ruleBase[i]->good = MEDIUM;
	ruleBase[i]->finalScore = MEDIUM;
	i++;

	//11
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = MEDIUM;
	ruleBase[i]->moderate = LOW;
	ruleBase[i]->good = HIGH;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//12
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = MEDIUM;
	ruleBase[i]->moderate = MEDIUM;
	ruleBase[i]->good = LOW;
	ruleBase[i]->finalScore = MEDIUM;
	i++;

	//13
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = MEDIUM;
	ruleBase[i]->moderate = MEDIUM;
	ruleBase[i]->good = MEDIUM;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//14
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = MEDIUM;
	ruleBase[i]->moderate = MEDIUM;
	ruleBase[i]->good = HIGH;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//15
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = MEDIUM;
	ruleBase[i]->moderate = HIGH;
	ruleBase[i]->good = LOW;
	ruleBase[i]->finalScore = MEDIUM;
	i++;

	//16
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = MEDIUM;
	ruleBase[i]->moderate = HIGH;
	ruleBase[i]->good = MEDIUM;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//17
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = MEDIUM;
	ruleBase[i]->moderate = HIGH;
	ruleBase[i]->good = HIGH;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//18
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = HIGH;
	ruleBase[i]->moderate = LOW;
	ruleBase[i]->good = LOW;
	ruleBase[i]->finalScore = LOW;
	i++;

	//19
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = HIGH;
	ruleBase[i]->moderate = LOW;
	ruleBase[i]->good = MEDIUM;
	ruleBase[i]->finalScore = MEDIUM;
	i++;

	//20
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = HIGH;
	ruleBase[i]->moderate = LOW;
	ruleBase[i]->good = HIGH;
	ruleBase[i]->finalScore = MEDIUM;
	i++;

	//21
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = HIGH;
	ruleBase[i]->moderate = MEDIUM;
	ruleBase[i]->good = LOW;
	ruleBase[i]->finalScore = LOW;
	i++;

	//22
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = HIGH;
	ruleBase[i]->moderate = MEDIUM;
	ruleBase[i]->good = MEDIUM;
	ruleBase[i]->finalScore = MEDIUM;
	i++;

	//23
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = HIGH;
	ruleBase[i]->moderate = MEDIUM;
	ruleBase[i]->good = HIGH;
	ruleBase[i]->finalScore = HIGH;
	i++;

	//24
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = HIGH;
	ruleBase[i]->moderate = HIGH;
	ruleBase[i]->good = LOW;
	ruleBase[i]->finalScore = LOW;
	i++;

	//25
	ruleBase[i] = (struct Rule *)malloc(sizeof(struct Rule));
	ruleBase[i]->poor = HIGH;
	ruleBase[i]->moderate = HIGH;
	ruleBase[i]->good = MEDIUM;
	ruleBase[i]->finalScore = MEDIUM;
	i++;

	return;
}