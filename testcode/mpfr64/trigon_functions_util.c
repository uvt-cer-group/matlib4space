void readValuesIntoArray2(FILE *ifp, double *inputValues, int  *k){

         double valueDouble;
        char *inputHexValue=(char*)malloc(30*sizeof(char));
        *k=-1;
	while(fscanf(ifp,"%s",inputHexValue)!=EOF){

                valueDouble=hex2double2(inputHexValue);
                (*k)++;
                inputValues[(*k)]=valueDouble;   




        }

}


void computeTrigFunctions(FILE *of_sin, FILE *of_cos, FILE *of_tan,double *inputValues, int k){

	int i;
	double sin_result, cos_result, tan_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue_sin=(char *)malloc(30*sizeof(char));
	char *outputHexValue_cos=(char *)malloc(30*sizeof(char));
	char *outputHexValue_tan=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time_sin, time_cos, time_tan;
	
	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_sin(a,x,MPFR_RNDD);
		sin_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time_sin = compute_time(start,end);

		start=clock();
		mpfr_cos(a,x,MPFR_RNDD);
		cos_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time_cos = compute_time(start,end);

		start=clock();
		mpfr_tan(a,x,MPFR_RNDD);
		tan_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time_tan = compute_time(start,end);

		double2hex(inputValues[i], inputHexValue);
		double2hex(sin_result, outputHexValue_sin);
		double2hex(cos_result, outputHexValue_cos);
		double2hex(tan_result, outputHexValue_tan);		
		printHex(of_sin, inputHexValue, outputHexValue_sin,time_sin);
		printHex(of_cos, inputHexValue, outputHexValue_cos,time_cos);
		printHex(of_tan, inputHexValue, outputHexValue_tan,time_tan);
		
	}
	mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();


}


void computeTrigFunctionsReverse(FILE *of_asin, FILE *of_acos, FILE *of_atan, FILE *of_atan2, double *inputValues_asin, double * inputValues_acos, double *inputValues_atan, double *inputValues_atan2_x, double *inputValues_atan2_y, int k, int k_atan2){

        int i;
        double asin_result, acos_result, atan_result, atan2_result;
        char *inputHexValue_asin=(char *)malloc(30*sizeof(char));
	char *inputHexValue_acos=(char *)malloc(30*sizeof(char));
	char *inputHexValue_atan=(char *)malloc(30*sizeof(char));
	char *inputHexValue_atan2_x=(char *)malloc(30*sizeof(char));
	char *inputHexValue_atan2_y=(char *)malloc(30*sizeof(char));
      char *outputHexValue_asin=(char *)malloc(30*sizeof(char));
      char *outputHexValue_acos=(char *)malloc(30*sizeof(char));
      char *outputHexValue_atan=(char *)malloc(30*sizeof(char));
	char *outputHexValue_atan2=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time_asin, time_acos, time_atan, time_atan2;

	mpfr_t x,y,a;
	mpfr_init2(x,64);
	mpfr_init2(y,64);
	mpfr_init2(a,64);

       	for(i=0;i<=k;i++){
			mpfr_set_d(x,inputValues_asin[i],MPFR_RNDD);
			start=clock();
			mpfr_asin(a,x,MPFR_RNDD);
                asin_result=mpfr_get_d(a,MPFR_RNDD);
			end=clock();
			time_asin = compute_time(start,end);

			mpfr_set_d(x,inputValues_acos[i],MPFR_RNDD);
			start=clock();
			mpfr_acos(a,x,MPFR_RNDD);
                acos_result=mpfr_get_d(a,MPFR_RNDD);
			end=clock();
			time_acos = compute_time(start,end);
			
			mpfr_set_d(x,inputValues_atan[i],MPFR_RNDD);
			start=clock();
			mpfr_atan(a,x,MPFR_RNDD);
                atan_result=mpfr_get_d(a,MPFR_RNDD);
			end=clock();
			time_atan = compute_time(start,end);

			

                double2hex(inputValues_asin[i], inputHexValue_asin);
		double2hex(inputValues_acos[i], inputHexValue_acos);
		double2hex(inputValues_atan[i], inputHexValue_atan);
                double2hex(asin_result, outputHexValue_asin);
                double2hex(acos_result, outputHexValue_acos);
                double2hex(atan_result, outputHexValue_atan);             
                printHex(of_asin, inputHexValue_asin, outputHexValue_asin,time_asin);
                printHex(of_acos, inputHexValue_acos, outputHexValue_acos,time_acos);
                printHex(of_atan, inputHexValue_atan, outputHexValue_atan,time_atan);
                
			
        }
	
	for(i=0;i<=k_atan2;i++){
		mpfr_set_d(y,inputValues_atan2_y[i],MPFR_RNDD);	
			mpfr_set_d(x,inputValues_atan2_x[i],MPFR_RNDD);	
			start=clock();
			mpfr_atan2(a,x,y,MPFR_RNDD);
                	atan2_result=mpfr_get_d(a,MPFR_RNDD);
			end=clock();
			time_atan2 = compute_time(start,end);
			double2hex(inputValues_atan2_x[i], inputHexValue_atan2_x);
			double2hex(inputValues_atan2_y[i], inputHexValue_atan2_y);
			double2hex(atan2_result, outputHexValue_atan2);             
                	printHex2(of_atan2, inputHexValue_atan2_x, inputHexValue_atan2_y, outputHexValue_atan2,time_atan2);
	}
	

	mpfr_clear(x);
	mpfr_clear(y);
  	mpfr_clear(a);
	mpfr_free_cache();


}

