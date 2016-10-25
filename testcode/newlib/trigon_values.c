#include<stdio.h>
#include<math.h>
#include<time.h>
#include "functions_utils.c"
#include "trigon_functions_util.c"




int main(){

	FILE *if1, *if2;

	FILE *if1_asin,*if1_acos,*if1_atan,*if1_atan2_x,*if1_atan2_y;
      FILE *if2_asin,*if2_acos,*if2_atan,*if2_atan2_x,*if2_atan2_y;

	FILE *of1_sin,*of1_cos,*of1_tan;
	FILE *of2_sin,*of2_cos,*of2_tan;

	FILE *of1_asin,*of1_acos,*of1_atan,*of1_atan2;
     FILE *of2_asin,*of2_acos,*of2_atan,*of2_atan2;
       

	double valueDouble;
	char *inputHexValue=(char*)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	
	double inputValues1[150], inputValues2[150];
	double inputValues1_asin[150], inputValues1_acos[150], inputValues1_atan[150],inputValues1_atan2_x[150],inputValues1_atan2_y[150];
	double inputValues2_asin[150], inputValues2_acos[150], inputValues2_atan[150],inputValues2_atan2_x[150],inputValues2_atan2_y[150];
	
	int k1, k2;	
	int k1_asin, k1_acos, k1_atan, k1_atan2;
	int k2_asin, k2_acos, k2_atan, k2_atan2;
	int i;

	char inputFileName1[]="input_trig/trigon_batch1.csv";
	char inputFileName2[]="input_trig/trigon_batch2.csv";

	char inputFileName1_asin_acos[]="input_trig/asin_acos_batch1.csv";
	char inputFileName2_asin_acos[]="input_trig/asin_acos_batch2.csv";

	char inputFileName1_atan[]="input_trig/atan_batch1.csv";
	char inputFileName2_atan[]="input_trig/atan_batch2.csv";

	char inputFileName1_atan2_x[]="input_trig/atan2_batch1_x.csv";
	char inputFileName1_atan2_y[]="input_trig/atan2_batch1_y.csv";
	char inputFileName2_atan2_x[]="input_trig/atan2_batch2_x.csv";
	char inputFileName2_atan2_y[]="input_trig/atan2_batch2_y.csv";



	char outputFileName1_sin[]="output/batch_1_sin.csv";
	char outputFileName1_cos[]="output/batch_1_cos.csv";
	char outputFileName1_tan[]="output/batch_1_tan.csv";


	char outputFileName2_sin[]="output/batch_2_sin.csv";
	char outputFileName2_cos[]="output/batch_2_cos.csv";
	char outputFileName2_tan[]="output/batch_2_tan.csv";


	

	char outputFileName1_asin[]="output/batch_1_asin.csv";
     	char outputFileName1_acos[]="output/batch_1_acos.csv";
     	char outputFileName1_atan[]="output/batch_1_atan.csv";
	char outputFileName1_atan2[]="output/batch_1_atan2.csv";



     	char outputFileName2_asin[]="output/batch_2_asin.csv";
     	char outputFileName2_acos[]="output/batch_2_acos.csv";
     	char outputFileName2_atan[]="output/batch_2_atan.csv";
	char outputFileName2_atan2[]="output/batch_2_atan2.csv";


	if1 =openFile(inputFileName1,"r");
	of1_sin=openFile(outputFileName1_sin,"w");
	of1_cos=openFile(outputFileName1_cos,"w");
	of1_tan=openFile(outputFileName1_tan,"w");
	readValuesIntoArray(if1,inputValues1,&k1);


	if2 =openFile(inputFileName2,"r");
      	of2_sin=openFile(outputFileName2_sin,"w");
      	of2_cos=openFile(outputFileName2_cos,"w");
      	of2_tan=openFile(outputFileName2_tan,"w");
	readValuesIntoArray(if2,inputValues2,&k2);
	
	
	
	computeTrigFunctions(of1_sin,of1_cos, of1_tan, inputValues1, k1);
	computeTrigFunctions(of2_sin,of2_cos, of2_tan, inputValues2, k2);
	


	//open input files for reverse trigometric functions
	if1_asin=openFile(inputFileName1_asin_acos,"r");
     	if1_atan=openFile(inputFileName1_atan,"r");
	if1_atan2_x=openFile(inputFileName1_atan2_x,"r");
	if1_atan2_y=openFile(inputFileName1_atan2_y,"r");
	readValuesIntoArray2(if1_asin, inputValues1_asin, &k1_asin);
	readValuesIntoArray2(if1_asin, inputValues1_acos, &k1_acos);	
	readValuesIntoArray2(if1_atan, inputValues1_atan, &k1_atan);
	readValuesIntoArray2(if1_atan2_x, inputValues1_atan2_x, &k1_atan2);
	readValuesIntoArray2(if1_atan2_y, inputValues1_atan2_y, &k1_atan2);

	if2_asin=openFile(inputFileName2_asin_acos,"r");
     	if2_atan=openFile(inputFileName2_atan,"r");
	if2_atan2_x=openFile(inputFileName2_atan2_x,"r");
	if2_atan2_y=openFile(inputFileName2_atan2_y,"r");
	readValuesIntoArray2(if2_asin, inputValues2_asin, &k2_asin);
     	readValuesIntoArray2(if2_asin, inputValues2_acos, &k2_acos);
     	readValuesIntoArray2(if2_atan, inputValues2_atan, &k2_atan);
	readValuesIntoArray2(if2_atan2_x, inputValues2_atan2_x, &k2_atan2);
	readValuesIntoArray2(if2_atan2_y, inputValues2_atan2_y, &k2_atan2);		

	

	of1_asin=openFile(outputFileName1_asin,"w");
     	of1_acos=openFile(outputFileName1_acos,"w");
     	of1_atan=openFile(outputFileName1_atan,"w");
     	of1_atan2=openFile(outputFileName1_atan2,"w");

	of2_asin=openFile(outputFileName2_asin,"w");
     	of2_acos=openFile(outputFileName2_acos,"w");
     	of2_atan=openFile(outputFileName2_atan,"w");
     	of2_atan2=openFile(outputFileName2_atan2,"w");

	

	computeTrigFunctionsReverse(of1_asin,of1_acos, of1_atan, of1_atan2,inputValues1_asin, inputValues1_acos, inputValues1_atan, inputValues1_atan2_x, inputValues1_atan2_y, k1, k1_atan2);
	computeTrigFunctionsReverse(of2_asin,of2_acos, of2_atan, of2_atan2,inputValues2_asin, inputValues2_acos, inputValues2_atan, inputValues2_atan2_x, inputValues2_atan2_y, k2, k2_atan2);	
	
	return 0;
}
	

