#include<stdio.h>
#include <gmp.h>
#include <mpfr.h>
#include<time.h>
#include "functions_utils.c"
#include "identities_util.c"


int main(){

	FILE *if_identities_x, *if_identities_y, *if_identities_a, *if_identities_b, *if_identities_xy_x, *if_identities_xy_y;
	
	FILE *of_trig_identity1,*of_trig_identity2,*of_trig_identity3,*of_trig_identity4, *of_trig_identity5, *of_trig_identity6;
	 
	FILE  *of_non_trig_ident1_x_dec, *of_non_trig_ident1_y_dec, *of_non_trig_ident2_x_dec, *of_non_trig_ident2_y_dec,*of_non_trig_ident3_dec,*of_non_trig_ident4_x_dec, *of_non_trig_ident4_y_dec,*of_non_trig_ident4_a_dec, *of_non_trig_ident5_x_dec,*of_non_trig_ident5_a_dec, *of_non_trig_ident5_b_dec;

	FILE  *if_non_trig_ident1_x, *if_non_trig_ident1_y, *if_non_trig_ident2_x, *if_non_trig_ident2_y,*if_non_trig_ident3, *if_non_trig_ident4_x, *if_non_trig_ident4_y, *if_non_trig_ident4_a, *if_non_trig_ident5_x,*if_non_trig_ident5_a, *if_non_trig_ident5_b;

	FILE *of_non_trig_identity1,*of_non_trig_identity2, *of_non_trig_identity3, *of_non_trig_identity4,*of_non_trig_identity5;

	double inputValues_x[150];
	double inputValues_xy_x[150];
	double inputValues_xy_y[150];
	

	double inputValues_nontrig_1_x[150], inputValues_nontrig_1_y[150],inputValues_nontrig_2_x[150], inputValues_nontrig_2_y[150], inputValues_nontrig_3[150],inputValues_nontrig_4_x[150], inputValues_nontrig_4_y[150],inputValues_nontrig_4_a[150], inputValues_nontrig_5_x[150],inputValues_nontrig_5_a[150], inputValues_nontrig_5_b[150];
	
	int k_x, k_xy;
	int k_nontrig_1_xy, k_nontrig_3, k_nontrig_2_xy;

	
	char inputFileName_identities_x[]="input_identities/trigon_ident_batchX.csv";
	char inputFileName_identities_xy_x[]="input_identities/trigon_ident_batchXY_X.csv";
	char inputFileName_identities_xy_y[]="input_identities/trigon_ident_batchXY_Y.csv";

	char inputFileName_identities_nontrig_1_x[]="input_identities/nontrigon_ident_batch1_X.csv";
	char inputFileName_identities_nontrig_1_y[]="input_identities/nontrigon_ident_batch1_Y.csv";

	 char inputFileName_identities_nontrig_2_x[]="input_identities/nontrigon_ident_batch2_X.csv";
        char inputFileName_identities_nontrig_2_y[]="input_identities/nontrigon_ident_batch2_Y.csv";

	char inputFileName_identities_nontrig_3[]="input_identities/nontrigon_ident_batch3.csv";
	
	char inputFileName_identities_nontrig_4_x[]="input_identities/nontrigon_ident_batch4_X.csv";
        char inputFileName_identities_nontrig_4_y[]="input_identities/nontrigon_ident_batch4_Y.csv";
	char inputFileName_identities_nontrig_4_a[]="input_identities/nontrigon_ident_batch4_A.csv";

	char inputFileName_identities_nontrig_5_x[]="input_identities/nontrigon_ident_batch5_X.csv";
        char inputFileName_identities_nontrig_5_a[]="input_identities/nontrigon_ident_batch5_A.csv";
        char inputFileName_identities_nontrig_5_b[]="input_identities/nontrigon_ident_batch5_B.csv";




	

	
	char outputFileName_identity1[]="output_identities/trig_ident1.csv";
	char outputFileName_identity2[]="output_identities/trig_ident2.csv";
	char outputFileName_identity3[]="output_identities/trig_ident3.csv";
	char outputFileName_identity4[]="output_identities/trig_ident4.csv";
	char outputFileName_identity5[]="output_identities/trig_ident5.csv";
	char outputFileName_identity6[]="output_identities/trig_ident6.csv";
	
	char outputFileName_nontrig_identity1[]="output_identities/nontrig_ident1.csv";
	char outputFileName_nontrig_identity2[]="output_identities/nontrig_ident2.csv";
	char outputFileName_nontrig_identity3[]="output_identities/nontrig_ident3.csv";
	char outputFileName_nontrig_identity4[]="output_identities/nontrig_ident4.csv";
	char outputFileName_nontrig_identity5[]="output_identities/nontrig_ident5.csv";


	if_identities_x=openFile(inputFileName_identities_x, "r");
	readValuesIntoArray(if_identities_x,inputValues_x, &k_x);

	if_identities_xy_x=openFile(inputFileName_identities_xy_x, "r");
	readValuesIntoArray(if_identities_xy_x,inputValues_xy_x,&k_xy);
	
	if_identities_xy_y=openFile(inputFileName_identities_xy_y,"r");
	readValuesIntoArray(if_identities_xy_y, inputValues_xy_y, &k_xy); 
       


	if_non_trig_ident1_x=openFile(inputFileName_identities_nontrig_1_x,"r");
	readValuesIntoArray(if_non_trig_ident1_x, inputValues_nontrig_1_x, &k_nontrig_1_xy);
      
	if_non_trig_ident1_y=openFile(inputFileName_identities_nontrig_1_y,"r");
        readValuesIntoArray(if_non_trig_ident1_y, inputValues_nontrig_1_y, &k_nontrig_1_xy);
      
	if_non_trig_ident2_x=openFile(inputFileName_identities_nontrig_2_x,"r");
        readValuesIntoArray(if_non_trig_ident2_x, inputValues_nontrig_2_x, &k_nontrig_2_xy);
      
       if_non_trig_ident2_y=openFile(inputFileName_identities_nontrig_2_y,"r");
        readValuesIntoArray(if_non_trig_ident2_y, inputValues_nontrig_2_y, &k_nontrig_2_xy);
       
	if_non_trig_ident3=openFile(inputFileName_identities_nontrig_3,"r");
        readValuesIntoArray(if_non_trig_ident3, inputValues_nontrig_3, &k_nontrig_3);
	
	if_non_trig_ident4_x=openFile(inputFileName_identities_nontrig_4_x,"r");
        readValuesIntoArray(if_non_trig_ident4_x, inputValues_nontrig_4_x, &k_nontrig_2_xy);
      
       	if_non_trig_ident4_y=openFile(inputFileName_identities_nontrig_4_y,"r");
        readValuesIntoArray(if_non_trig_ident4_y, inputValues_nontrig_4_y, &k_nontrig_2_xy);
       	
	if_non_trig_ident4_a=openFile(inputFileName_identities_nontrig_4_a,"r");
        readValuesIntoArray(if_non_trig_ident4_a, inputValues_nontrig_4_a, &k_nontrig_2_xy);
       
	if_non_trig_ident5_x=openFile(inputFileName_identities_nontrig_5_x,"r");
        readValuesIntoArray(if_non_trig_ident5_x, inputValues_nontrig_5_x, &k_nontrig_2_xy);
       
       	if_non_trig_ident5_a=openFile(inputFileName_identities_nontrig_5_a,"r");
        readValuesIntoArray(if_non_trig_ident5_a, inputValues_nontrig_5_a, &k_nontrig_2_xy);
       
       	if_non_trig_ident5_b=openFile(inputFileName_identities_nontrig_5_b,"r");
        readValuesIntoArray(if_non_trig_ident5_b, inputValues_nontrig_5_b, &k_nontrig_2_xy);
       
	

	of_trig_identity1=openFile(outputFileName_identity1, "w");
	of_trig_identity2=openFile(outputFileName_identity2, "w");
	of_trig_identity3=openFile(outputFileName_identity3,"w");
	of_trig_identity4=openFile(outputFileName_identity4, "w");
	of_trig_identity5=openFile(outputFileName_identity5, "w");
	of_trig_identity6=openFile(outputFileName_identity6, "w");

	of_non_trig_identity1=openFile(outputFileName_nontrig_identity1,"w");
	of_non_trig_identity2=openFile(outputFileName_nontrig_identity2,"w");
	of_non_trig_identity3=openFile(outputFileName_nontrig_identity3, "w");
	of_non_trig_identity4=openFile(outputFileName_nontrig_identity4, "w");
	of_non_trig_identity5=openFile(outputFileName_nontrig_identity5, "w");
	


	computeTrigIdentity1(of_trig_identity1, inputValues_x, k_x);
	computeTrigIdentity4(of_trig_identity4, inputValues_x, k_x);
	computeTrigIdentity6(of_trig_identity6, inputValues_x, k_x);

	computeTrigIdentity2(of_trig_identity2, inputValues_xy_x, inputValues_xy_y, k_xy);
    	computeTrigIdentity3(of_trig_identity3, inputValues_xy_x, inputValues_xy_y, k_xy);
     	computeTrigIdentity5(of_trig_identity5, inputValues_xy_x, inputValues_xy_y, k_xy);

	
	computeNonTrigIdentity1(of_non_trig_identity1, inputValues_nontrig_1_x, inputValues_nontrig_1_y, k_nontrig_1_xy);
	computeNonTrigIdentity2(of_non_trig_identity2, inputValues_nontrig_2_x, inputValues_nontrig_2_y, k_nontrig_1_xy);
	computeNonTrigIdentity3(of_non_trig_identity3, inputValues_nontrig_3, k_nontrig_3);
	computeNonTrigIdentity4(of_non_trig_identity4, inputValues_nontrig_4_x,inputValues_nontrig_4_a, inputValues_nontrig_4_y, k_nontrig_1_xy);
	computeNonTrigIdentity5(of_non_trig_identity5, inputValues_nontrig_5_x, inputValues_nontrig_5_a, inputValues_nontrig_5_b, k_nontrig_1_xy);

	return 0;
}


