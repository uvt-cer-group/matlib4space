#include<stdio.h>
#include<openlibm.h>
#include<time.h>
#include "functions_utils.c"
#include "non_trigon_functions_util.c"

int main(){



	FILE *if1_exp, *if2_exp, *if3_exp;
	FILE *if1_sqrt, *if2_sqrt, *if3_sqrt;
	FILE *if1_log, *if2_log, *if3_log;
	FILE *if_fabs,*if_fmin_fmax_x ,*if_fmin_fmax_y,*if_fmod_x ,*if_fmod_y ,*if_hypot_x ,*if_hypot_y, *if_modf,*if_pow_x, *if_pow_y, *if_rounding;      

	FILE *of1_exp, *of2_exp, *of3_exp;
	FILE *of1_log, *of2_log, *of3_log;
	FILE *of1_sqrt, *of2_sqrt, *of3_sqrt;
	FILE *of1_log10, *of2_log10, *of3_log10;
	FILE *of_fabs, *of_fmin, *of_fmax, *of_fmod, *of_hypot,*of_pow, *of_modf,*of_trunc, *of_ceil, *of_floor, *of_round;

	
	double inputValues1_exp[150], inputValues2_exp[150], inputValues3_exp[150];
	double inputValues1_sqrt[150], inputValues2_sqrt[150], inputValues3_sqrt[150];
	double inputValues1_log[150], inputValues2_log[150], inputValues3_log[150];
	double inputValues_fabs[150], inputValues_fmin_fmax_x[150], inputValues_fmin_fmax_y[150], inputValues_fmod_x[150],inputValues_fmod_y[150],inputValues_hypot_x[150], inputValues_hypot_y[150],inputValues_pow_x[150], inputValues_pow_y[150],inputValues_modf[150], inputValues_rounding[150];


	int k1_exp, k2_exp, k3_exp;
	int k1_log, k2_log, k3_log;
	int k1_sqrt, k2_sqrt, k3_sqrt;
	int k_fmin_fmax, k_fabs, k_fmod, k_hypot, k_pow,k_modf,k_rounding;
	
	char inputFileName1_exp[]="input_non_trig/exp_batch1.csv";
	char inputFileName2_exp[]="input_non_trig/exp_batch2.csv";
	char inputFileName3_exp[]="input_non_trig/exp_batch3.csv";
	char inputFileName1_log[]="input_non_trig/log_batch1.csv";
	char inputFileName2_log[]="input_non_trig/log_batch2.csv";
	char inputFileName3_log[]="input_non_trig/log_batch2.csv";
	char inputFileName1_sqrt[]="input_non_trig/sqrt_batch1.csv";
	char inputFileName2_sqrt[]="input_non_trig/sqrt_batch2.csv";
	char inputFileName3_sqrt[]="input_non_trig/sqrt_batch3.csv";
	char inputFileName_fabs[]="input_non_trig/fabs_batch.csv";
	char inputFileName_fmod_x[]="input_non_trig/fmod_batch_X.csv";
	char inputFileName_fmod_y[]="input_non_trig/fmod_batch_Y.csv";
	char inputFileName_fmin_fmax_x[]="input_non_trig/fmin_fmax_batch_X.csv";
	char inputFileName_fmin_fmax_y[]="input_non_trig/fmin_fmax_batch_Y.csv";
	char inputFileName_hypot_x[]="input_non_trig/hypot_batch_X.csv";
	char inputFileName_hypot_y[]="input_non_trig/hypot_batch_Y.csv";
	char inputFileName_pow_x[]="input_non_trig/pow_batch_X.csv";
	char inputFileName_pow_y[]="input_non_trig/pow_batch_Y.csv";
	char inputFileName_modf[]="input_non_trig/modf_batch.csv";
	char inputFileName_rounding[]="input_non_trig/rounding_batch.csv";




	char outputFileName1_exp[]="output_non_trig/batch_1_exp.csv";
	char outputFileName2_exp[]="output_non_trig/batch_2_exp.csv";
	char outputFileName3_exp[]="output_non_trig/batch_3_exp.csv";
	char outputFileName1_log[]="output_non_trig/batch_1_log.csv";
	char outputFileName2_log[]="output_non_trig/batch_2_log.csv";
	char outputFileName3_log[]="output_non_trig/batch_3_log.csv";
	char outputFileName1_log10[]="output_non_trig/batch_1_log10.csv";
	char outputFileName2_log10[]="output_non_trig/batch_2_log10.csv";
	char outputFileName3_log10[]="output_non_trig/batch_3_log10.csv";
	char outputFileName1_sqrt[]="output_non_trig/batch_1_sqrt.csv";
	char outputFileName2_sqrt[]="output_non_trig/batch_2_sqrt.csv";
	char outputFileName3_sqrt[]="output_non_trig/batch_3_sqrt.csv";
	char outputFileName_fabs[]="output_non_trig/batch_fabs.csv";
	char outputFileName_fmin[]="output_non_trig/batch_fmin.csv";
	char outputFileName_fmax[]="output_non_trig/batch_fmax.csv";
	char outputFileName_fmod[]="output_non_trig/batch_fmod.csv";
	char outputFileName_hypot[]="output_non_trig/batch_hypot.csv";
	char outputFileName_modf[]="output_non_trig/batch_modf.csv";
	char outputFileName_pow[]="output_non_trig/batch_pow.csv";
	char outputFileName_round[]="output_non_trig/batch_round.csv";
	char outputFileName_floor[]="output_non_trig/batch_floor.csv";
	char outputFileName_trunc[]="output_non_trig/batch_trunc.csv";
	char outputFileName_ceil[]="output_non_trig/batch_ceil.csv";



	

	if1_exp=openFile(inputFileName1_exp, "r");
	of1_exp=openFile(outputFileName1_exp, "w");
	readValuesIntoArray(if1_exp, inputValues1_exp, &k1_exp);	
	
	if2_exp=openFile(inputFileName2_exp, "r");
      of2_exp=openFile(outputFileName2_exp, "w");
	readValuesIntoArray(if2_exp, inputValues2_exp, &k2_exp);
	
	if3_exp=openFile(inputFileName3_exp, "r");
      	of3_exp=openFile(outputFileName3_exp, "w");
	readValuesIntoArray(if3_exp, inputValues3_exp, &k3_exp);

	if1_sqrt=openFile(inputFileName1_sqrt, "r");
	of1_sqrt=openFile(outputFileName1_sqrt, "w");
	readValuesIntoArray(if1_sqrt, inputValues1_sqrt, &k1_sqrt);

	if2_sqrt=openFile(inputFileName2_sqrt, "r");
	of2_sqrt=openFile(outputFileName2_sqrt, "w");
	readValuesIntoArray(if2_sqrt, inputValues2_sqrt, &k2_sqrt);

	if3_sqrt=openFile(inputFileName3_sqrt, "r");
	of3_sqrt=openFile(outputFileName3_sqrt, "w");
	readValuesIntoArray(if3_sqrt, inputValues3_sqrt, &k3_sqrt);
	
	if1_log=openFile(inputFileName1_log, "r");
	of1_log=openFile(outputFileName1_log, "w");
	of1_log10=openFile(outputFileName1_log10, "w");
	readValuesIntoArray(if1_log, inputValues1_log, &k1_log);

	if2_log=openFile(inputFileName2_log, "r");
	of2_log=openFile(outputFileName2_log, "w");
	of2_log10=openFile(outputFileName2_log10, "w");
	readValuesIntoArray(if2_log, inputValues2_log, &k2_log);

	if3_log=openFile(inputFileName3_log, "r");
	of3_log=openFile(outputFileName3_log, "w");
	of3_log10=openFile(outputFileName3_log10, "w");
	readValuesIntoArray(if3_log, inputValues3_log, &k3_log);

	if_fabs=openFile(inputFileName_fabs, "r");
	of_fabs=openFile(outputFileName_fabs, "w");
	readValuesIntoArray(if_fabs, inputValues_fabs, &k_fabs);

	if_fmin_fmax_x=openFile(inputFileName_fmin_fmax_x, "r");
	if_fmin_fmax_y=openFile(inputFileName_fmin_fmax_y, "r");
	of_fmin=openFile(outputFileName_fmin, "w");
	of_fmax=openFile(outputFileName_fmax, "w");
	readValuesIntoArray(if_fmin_fmax_x, inputValues_fmin_fmax_x, &k_fmin_fmax);
	readValuesIntoArray(if_fmin_fmax_y, inputValues_fmin_fmax_y, &k_fmin_fmax);

	if_fmod_x=openFile(inputFileName_fmod_x, "r");
	if_fmod_y=openFile(inputFileName_fmod_y, "r");
	of_fmod=openFile(outputFileName_fmod, "w");
	readValuesIntoArray(if_fmod_x, inputValues_fmod_x, &k_fmod);
	readValuesIntoArray(if_fmod_y, inputValues_fmod_y, &k_fmod);

	if_hypot_x=openFile(inputFileName_hypot_x, "r");
	if_hypot_y=openFile(inputFileName_hypot_y, "r");
	of_hypot=openFile(outputFileName_hypot, "w");
	readValuesIntoArray(if_hypot_x, inputValues_hypot_x, &k_hypot);
	readValuesIntoArray(if_hypot_y, inputValues_hypot_y, &k_hypot);

	if_pow_x=openFile(inputFileName_pow_x, "r");
	if_pow_y=openFile(inputFileName_pow_y, "r");
	of_pow=openFile(outputFileName_pow, "w");
	readValuesIntoArray(if_pow_x, inputValues_pow_x, &k_pow);
	readValuesIntoArray(if_pow_y, inputValues_pow_y, &k_pow);

	if_modf=openFile(inputFileName_modf, "r");
	of_modf=openFile(outputFileName_modf, "w");
	readValuesIntoArray(if_modf, inputValues_modf, &k_modf);

	if_rounding=openFile(inputFileName_rounding, "r");
	of_round=openFile(outputFileName_round, "w");
	of_floor=openFile(outputFileName_floor, "w");
	of_trunc=openFile(outputFileName_trunc, "w");
	of_ceil=openFile(outputFileName_ceil, "w");
	readValuesIntoArray(if_rounding, inputValues_rounding, &k_rounding);




	computeExpFunction(of1_exp, inputValues1_exp, k1_exp);
	computeExpFunction(of2_exp, inputValues2_exp, k2_exp);
	computeExpFunction(of3_exp, inputValues3_exp, k3_exp);

	computeSqrtFunction(of1_sqrt, inputValues1_sqrt, k1_sqrt);
	computeSqrtFunction(of2_sqrt, inputValues2_sqrt, k2_sqrt);
	computeSqrtFunction(of3_sqrt, inputValues3_sqrt, k3_sqrt);

	computeLogFunction(of1_log, inputValues1_log, k1_log);
	computeLogFunction(of2_log, inputValues2_log, k2_log);
	computeLogFunction(of3_log, inputValues3_log, k3_log);

	computeLog10Function(of1_log10, inputValues1_log, k1_log);
	computeLog10Function(of2_log10, inputValues2_log, k2_log);
	computeLog10Function(of3_log10, inputValues3_log, k3_log);

	computeFabsFunction(of_fabs, inputValues_fabs, k_fabs);
	computeFminFunction(of_fmin, inputValues_fmin_fmax_x, inputValues_fmin_fmax_y, k_fmin_fmax);
	computeFmaxFunction(of_fmax, inputValues_fmin_fmax_x, inputValues_fmin_fmax_y, k_fmin_fmax);
	computeFmodFunction(of_fmod, inputValues_fmod_x, inputValues_fmod_y, k_fmod);
	computeHypotFunction(of_hypot, inputValues_hypot_x, inputValues_hypot_y, k_hypot);
	computePowFunction(of_pow, inputValues_pow_x, inputValues_pow_y, k_pow);	
	computeModfFunction(of_modf, inputValues_modf, k_modf);
	computeRoundFunction(of_round, inputValues_rounding, k_rounding);
	computeTruncFunction(of_trunc, inputValues_rounding, k_rounding);
	computeFloorFunction(of_floor, inputValues_rounding, k_rounding);
	computeCeilFunction(of_ceil, inputValues_rounding, k_rounding);
	
	return 0;

}

