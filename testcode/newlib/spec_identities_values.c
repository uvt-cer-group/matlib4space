#include<stdio.h>
#include <math.h>
#include<time.h>
#include "functions_utils.c"
#include "spec_identities_util.c"


int main(){

	FILE *if_identities_x;

	FILE *of_trig_identity1,*of_trig_identity2,*of_trig_identity3;

	double inputValues_x[150];
	
	int k_x;
	
	
	char inputFileName_identities_x[]="input_special_identities/newlib_special_identities_trig.csv";
	
	
	char outputFileName_identity1[]="output_special_identities/spec_trig_ident1.csv";
	char outputFileName_identity2[]="output_special_identities/spec_trig_ident2.csv";
	char outputFileName_identity3[]="output_special_identities/spec_trig_ident3.csv";
	

	if_identities_x=openFile(inputFileName_identities_x, "r");
	readValuesIntoArray(if_identities_x,inputValues_x, &k_x);

	of_trig_identity1=openFile(outputFileName_identity1, "w");
	of_trig_identity2=openFile(outputFileName_identity2, "w");
	of_trig_identity3=openFile(outputFileName_identity3, "w");

	computeTrigIdentity1(of_trig_identity1, inputValues_x, k_x);
	computeTrigIdentity2(of_trig_identity2, inputValues_x, k_x);
	computeTrigIdentity3(of_trig_identity3, inputValues_x, k_x);

	return 0;
}


