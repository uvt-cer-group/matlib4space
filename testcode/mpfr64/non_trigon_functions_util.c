void computeExpFunction(FILE *of, double *inputValues, int k){

	int i;
	double exp_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;
	
	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_exp(a,x,MPFR_RNDD);
		exp_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(exp_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}
	mpfr_clears (x, a,(mpfr_ptr) 0);
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();*/

}


void computeSqrtFunction(FILE *of, double *inputValues, int k){

	int i;
	double sqrt_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;
	
	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_sqrt(a,x,MPFR_RNDD);
		sqrt_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(sqrt_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}
	mpfr_clears (x, a, (mpfr_ptr) 0);
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();*/

}


void computeLogFunction(FILE *of, double *inputValues, int k){

	int i;
	double log_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_log(a,x,MPFR_RNDD);
		log_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(log_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();*/
	mpfr_clears (x, a, (mpfr_ptr) 0);
}



void computeLog10Function(FILE *of, double *inputValues, int k){

	int i;
	double log10_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_log10(a,x,MPFR_RNDD);
		log10_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(log10_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();*/
	mpfr_clears (x, a, (mpfr_ptr) 0);
}


void computeFabsFunction(FILE *of, double *inputValues, int k){

	int i;
	double fabs_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_abs(a,x,MPFR_RNDD);
		fabs_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(fabs_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();*/
	mpfr_clears (x, a, (mpfr_ptr) 0);
}


void computeModfFunction(FILE *of, double *inputValues, int k){

	int i;
	double modf_result,modf_result2;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue2=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a,b;
	mpfr_init2(x,64);
	mpfr_init2(a,64);
	mpfr_init2(b,64);

	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_modf(a,b,x,MPFR_RNDD);
		modf_result= mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		modf_result2= mpfr_get_d(b,MPFR_RNDD);
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(modf_result, outputHexValue);
		double2hex(modf_result2, outputHexValue2);
		printHex2(of, inputHexValue, outputHexValue,outputHexValue2,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_clear(b);
	mpfr_free_cache();*/
	mpfr_clears (x, a, b, (mpfr_ptr) 0);
}


void computeRoundFunction(FILE *of, double *inputValues, int k){

	int i;
	double round_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);
	
	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_round(a,x);
		round_result=(double)mpfr_get_si(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(round_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();*/
	mpfr_clears (x, a, (mpfr_ptr) 0);
}


void computeFloorFunction(FILE *of, double *inputValues, int k){

	int i;
	double floor_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;


	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);

	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_floor(a,x);
		floor_result=(double)mpfr_get_si(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(floor_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();*/
	mpfr_clears (x, a, (mpfr_ptr) 0);
}


void computeTruncFunction(FILE *of, double *inputValues, int k){

	int i;
	double trunc_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_trunc(a,x);
		trunc_result=(double)mpfr_get_si(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(trunc_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();*/
	mpfr_clears (x, a, (mpfr_ptr) 0);

}

void computeCeilFunction(FILE *of, double *inputValues, int k){

	int i;
	double ceil_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_ceil(a,x);
		ceil_result=(double) mpfr_get_si(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(ceil_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();*/
	mpfr_clears (x,a, (mpfr_ptr) 0);
}


void computePowFunction(FILE *of, double *inputValues, double *inputValues2, int k){

	int i;
	double pow_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *inputHexValue2=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a;
	mpfr_init2(x,64);
	mpfr_init2(a,64);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues2[i],MPFR_RNDD);
		mpfr_set_d(a,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_pow(a,a,x,MPFR_RNDD);
		pow_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(inputValues2[i], inputHexValue);
		double2hex(pow_result, outputHexValue);
		printHex2(of, inputHexValue,inputHexValue2, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_free_cache();*/
	mpfr_clears (x, a, (mpfr_ptr) 0);
}

void computeHypotFunction(FILE *of, double *inputValues, double *inputValues2, int k){

	int i;
	double hypot_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *inputHexValue2=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a,b;
	mpfr_init2(x,64);
	mpfr_init2(a,64);
	mpfr_init2(b,64);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues2[i],MPFR_RNDD);
		mpfr_set_d(b,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_hypot(a,b,x,MPFR_RNDD);
		hypot_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(inputValues2[i], inputHexValue);
		double2hex(hypot_result, outputHexValue);
		printHex2(of, inputHexValue,inputHexValue2, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_clear(b);
	mpfr_free_cache();*/
	mpfr_clears (x, a, b, (mpfr_ptr) 0);
}


void computeFmodFunction(FILE *of, double *inputValues, double *inputValues2, int k){

	int i;
	double fmod_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *inputHexValue2=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a,b;
	mpfr_init2(x,64);
	mpfr_init2(a,64);
	mpfr_init2(b,64);

	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues2[i],MPFR_RNDD);
		mpfr_set_d(b,inputValues[i],MPFR_RNDD);

		start=clock();
		mpfr_fmod(a,b,x,MPFR_RNDD);
		fmod_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(inputValues2[i], inputHexValue);
		double2hex(fmod_result, outputHexValue);
		printHex2(of, inputHexValue,inputHexValue2, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_clear(b);
	mpfr_free_cache();*/
	mpfr_clears (x, a, b, (mpfr_ptr) 0);
}


void computeFminFunction(FILE *of, double *inputValues, double *inputValues2, int k){

	int i;
	double fmin_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *inputHexValue2=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a,b;
	mpfr_init2(x,64);
	mpfr_init2(a,64);
	mpfr_init2(b,64);

	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues2[i],MPFR_RNDD);
		mpfr_set_d(b,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_min(a,b,x,MPFR_RNDD);
		fmin_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(inputValues2[i], inputHexValue);
		double2hex(fmin_result, outputHexValue);
		printHex2(of, inputHexValue,inputHexValue2, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_clear(b);
	mpfr_free_cache();*/
	mpfr_clears (x, a, b, (mpfr_ptr) 0);
}


void computeFmaxFunction(FILE *of, double *inputValues, double *inputValues2, int k){

	int i;
	double fmax_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *inputHexValue2=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	mpfr_t x,a,b;
	mpfr_init2(x,64);
	mpfr_init2(a,64);
	mpfr_init2(b,64);

	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues2[i],MPFR_RNDD);
		mpfr_set_d(b,inputValues[i],MPFR_RNDD);
		start=clock();
		mpfr_max(a,b,x,MPFR_RNDD);
		fmax_result=mpfr_get_d(a,MPFR_RNDD);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(inputValues2[i], inputHexValue);
		double2hex(fmax_result, outputHexValue);
		printHex2(of, inputHexValue,inputHexValue2, outputHexValue,time);
		
	}
	/*mpfr_clear(x);
  	mpfr_clear(a);
	mpfr_clear(b);
	mpfr_free_cache();*/
	mpfr_clears (x, a, b, (mpfr_ptr) 0);
}

