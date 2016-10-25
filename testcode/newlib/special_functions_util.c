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


void computeSinFunction(FILE *of, double *inputValues, int k){

	int i;
	double sin_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		sin_result=sin(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(sin_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}


void computeCosFunction(FILE *of, double *inputValues, int k){

	int i;
	double cos_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		cos_result=cos(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(cos_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}



void computeTanFunction(FILE *of, double *inputValues, int k){

	int i;
	double tan_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		tan_result=tan(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(tan_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}


void computeAtanFunction(FILE *of, double *inputValues, int k){

	int i;
	double atan_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		atan_result=atan(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(atan_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}


void computeAcosFunction(FILE *of, double *inputValues, int k){

	int i;
	double acos_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		acos_result=acos(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(acos_result, outputHexValue);
		printHex(of, inputHexValue,outputHexValue,time);
		
	}

}


void computeAsinFunction(FILE *of, double *inputValues, int k){

	int i;
	double asin_result;
	char *inputHexValue=(char *)malloc(30*sizeof(char));
	char *outputHexValue=(char *)malloc(30*sizeof(char));
	clock_t start,end;
	double time;

	for(i=0;i<=k;i++){
		start=clock();
		asin_result=asin(inputValues[i]);
		end=clock();
		time = compute_time(start,end);
		double2hex(inputValues[i], inputHexValue);
		double2hex(asin_result, outputHexValue);
		printHex(of, inputHexValue, outputHexValue,time);
		
	}

}
