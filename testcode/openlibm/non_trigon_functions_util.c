
void computeExpFunction(FILE *of, double *inputValues, int k){

	int i;
	double exp_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		exp_result=exp(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(exp_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}


void computeSqrtFunction(FILE *of, double *inputValues, int k){

	int i;
	double sqrt_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		sqrt_result=sqrt(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(sqrt_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}


void computeLogFunction(FILE *of, double *inputValues, int k){

	int i;
	double log_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		log_result=log(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(log_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}



void computeLog10Function(FILE *of, double *inputValues, int k){

	int i;
	double log10_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		log10_result=log10(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(log10_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}


void computeFabsFunction(FILE *of, double *inputValues, int k){

	int i;
	double fabs_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		fabs_result=fabs(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(fabs_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}


void computeModfFunction(FILE *of, double *inputValues, int k){

	int i;
	double modf_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue2=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		double  *int_modf_result;
		start=clock();
		modf_result=modf(inputValues[i], int_modf_result);
		end=clock();
		double rez2= *int_modf_result;
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(modf_result, outputHexValue);
		double2hex(rez2, outputHexValue2);
		printHex2(of, inputHexValue, outputHexValue2,outputHexValue,time);
		
	}

}


void computeRoundFunction(FILE *of, double *inputValues, int k){

	int i;
	double round_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		round_result=round(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(round_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}


void computeFloorFunction(FILE *of, double *inputValues, int k){

	int i;
	double floor_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		floor_result=floor(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(floor_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}


void computeTruncFunction(FILE *of, double *inputValues, int k){

	int i;
	double trunc_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		trunc_result=trunc(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(trunc_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}

void computeCeilFunction(FILE *of, double *inputValues, int k){

	int i;
	double ceil_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		ceil_result=ceil(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(ceil_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}


void computePowFunction(FILE *of, double *inputValues, double *inputValues2, int k){

	int i;
	double pow_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *inputHexValue2=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		pow_result=pow(inputValues[i],inputValues2[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(inputValues2[i], inputHexValue);
		double2hex(pow_result, outputHexValue);
		printHex2(of, inputHexValue,inputHexValue2, outputHexValue,time);
		
	}

}

void computeHypotFunction(FILE *of, double *inputValues, double *inputValues2, int k){

	int i;
	double hypot_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *inputHexValue2=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		hypot_result=hypot(inputValues[i],inputValues2[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(inputValues2[i], inputHexValue);
		double2hex(hypot_result, outputHexValue);
		printHex2(of, inputHexValue,inputHexValue2, outputHexValue,time);
		
	}

}


void computeFmodFunction(FILE *of, double *inputValues, double *inputValues2, int k){

	int i;
	double fmod_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *inputHexValue2=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		fmod_result=fmod(inputValues[i],inputValues2[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(inputValues2[i], inputHexValue);
		double2hex(fmod_result, outputHexValue);
		printHex2(of, inputHexValue,inputHexValue2, outputHexValue,time);
		
	}

}


void computeFminFunction(FILE *of, double *inputValues, double *inputValues2, int k){

	int i;
	double fmin_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *inputHexValue2=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		fmin_result=fmin(inputValues[i],inputValues2[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(inputValues2[i], inputHexValue);
		double2hex(fmin_result, outputHexValue);
		printHex2(of, inputHexValue,inputHexValue2, outputHexValue,time);
		
	}

}


void computeFmaxFunction(FILE *of, double *inputValues, double *inputValues2, int k){

	int i;
	double fmax_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *inputHexValue2=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		fmax_result=fmax(inputValues[i],inputValues2[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(inputValues2[i], inputHexValue);
		double2hex(fmax_result, outputHexValue);
		printHex2(of, inputHexValue,inputHexValue2, outputHexValue,time);
		
	}

}

