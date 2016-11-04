FILE* openFile(char *fileName, char *mode){


        FILE *fp;


       	fp = fopen(fileName,mode);

        if (fp == NULL) {
                fprintf(stderr, "Can't open input file %s!\n",fileName);
                exit(1);
        }
	return fp;

        }


double hex2double1(const char* s){

	double d=0.0;
	sscanf(s,"%lx",&d);
	return d;
}
double hex2double2(const char* s){

	double d=0.0;
	sscanf(s, "%lA", &d);
	return d;
}

void double2hex(double d, char* buffer){


	snprintf(buffer, 25, "%A", d);

}

void printValuesToDec(FILE * of, double *inputValues, int k){

	int i;
	for(i=0;i<=k;i++){
		fprintf(of, "%.32lf\n", inputValues[i]);
	}
}


void readValuesIntoArray(FILE *ifp, double *inputValues, int  *k){

         double valueDouble;
        char *inputHexValue=(char*)malloc(30*sizeof(char));
        *k=-1;
       	while(fscanf(ifp,"%s",inputHexValue)!=EOF){

                valueDouble=hex2double1(inputHexValue);
                (*k)++;
                inputValues[(*k)]=valueDouble;   




        }

}


double compute_time(clock_t start, clock_t end){

	double result;
	result=(double)(end-start)/(CLOCKS_PER_SEC/1000000);

	return result;
	}



void printHex(FILE *ofp, char *input, char * output,double t){


	char *outputHexValue_time=(char *)malloc(30*sizeof(char));
	
	double2hex(t, outputHexValue_time);

        fprintf(ofp,"%s,%s,%s\n", input, output,outputHexValue_time);
}

void printHex2(FILE *ofp, char *input, char* input1, char * output, double t){


	char *outputHexValue_time=(char *)malloc(30*sizeof(char));
	
	double2hex(t, outputHexValue_time);

        fprintf(ofp,"%s,%s,%s,%s\n", input, input1, output,outputHexValue_time);
}

