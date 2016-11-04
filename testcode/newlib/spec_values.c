#include<stdio.h>
#include<math.h>
#include<time.h>
#include "functions_utils.c"
#include "special_functions_util.c"

int main(){



	FILE *if_exp;
	FILE *if_sin_cos_tan;
	FILE *if_asin_acos;
	FILE *if_atan;      

	FILE *of_exp;
	FILE *of_sin, *of_cos, *of_tan;
	FILE *of_asin, *of_acos, *of_atan;
	
	
	double inputValues_exp[150];
	double inputValues_sin_cos_tan[150];
	double inputValues_asin_acos[150];
	double inputValues_atan[150];

	int k_exp, k_sin_cos_tan, k_asin_acos,k_atan;
	
	
	char inputFileName_exp[]="input_special_values/newlib_special_exp.csv";
	char inputFileName_sin_cos_tan[]="input_special_values/newlib_special_sin_cos_tan.csv";
	char inputFileName_asin_acos[]="input_special_values/newlib_special_asin_acos.csv";
	char inputFileName_atan[]="input_special_values/newlib_special_atan.csv";
	


	char outputFileName_exp[]="output_special_values/newlib_spec_exp.csv";
	char outputFileName_sin[]="output_special_values/newlib_spec_sin.csv";
	char outputFileName_cos[]="output_special_values/newlib_spec_cos.csv";
	char outputFileName_tan[]="output_special_values/newlib_spec_tan.csv";
	char outputFileName_asin[]="output_special_values/newlib_spec_asin.csv";
	char outputFileName_acos[]="output_special_values/newlib_spec_acos.csv";
	char outputFileName_atan[]="output_special_values/newlib_spec_atan.csv";
	
	if_exp=openFile(inputFileName_exp, "r");
	of_exp=openFile(outputFileName_exp, "w");
	readValuesIntoArray(if_exp, inputValues_exp, &k_exp);	
	
	if_sin_cos_tan=openFile(inputFileName_sin_cos_tan, "r");
     	of_sin=openFile(outputFileName_sin, "w");
	of_cos=openFile(outputFileName_cos, "w");
	of_tan=openFile(outputFileName_tan, "w");
	readValuesIntoArray(if_sin_cos_tan, inputValues_sin_cos_tan, &k_sin_cos_tan);
	
	if_asin_acos=openFile(inputFileName_asin_acos, "r");
     	of_asin=openFile(outputFileName_asin, "w");
	of_acos=openFile(outputFileName_acos, "w");
	readValuesIntoArray(if_asin_acos, inputValues_asin_acos, &k_asin_acos);

	if_atan=openFile(inputFileName_atan, "r");
	of_atan=openFile(outputFileName_atan, "w");
	readValuesIntoArray(if_atan, inputValues_atan, &k_atan);

	

	computeExpFunction(of_exp, inputValues_exp, k_exp);

	computeSinFunction(of_sin, inputValues_sin_cos_tan, k_sin_cos_tan);
	computeCosFunction(of_cos, inputValues_sin_cos_tan, k_sin_cos_tan);
	computeTanFunction(of_tan, inputValues_sin_cos_tan, k_sin_cos_tan);

	computeAsinFunction(of_asin, inputValues_asin_acos, k_asin_acos);
	computeAcosFunction(of_acos, inputValues_asin_acos, k_asin_acos);
	
	computeAtanFunction(of_atan, inputValues_atan, k_atan);
	
	return 0;

}

