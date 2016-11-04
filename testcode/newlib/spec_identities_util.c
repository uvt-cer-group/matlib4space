void printIdentityHex(FILE * ofp, char *identity, char *x, char *y, char *lh, double lht, char * rh, double rht){


	char *rt=(char *)malloc(30*sizeof(char ));
	char *lt=(char *) malloc(30*sizeof(char ));
	double2hex(lht, lt);
	double2hex(rht, rt);
	
	fprintf(ofp,"%s,%s,%s,%s,%s,%s,%s\n",identity, x, y, lh, lt, rh, rt); 

}

void printIdentityHex1(FILE * ofp, char *identity, char *x, char *y, char *z, char *lh, double lht, char * rh, double rht){


	char *rt=(char *)malloc(30*sizeof(char ));
	char *lt=(char *) malloc(30*sizeof(char ));
	double2hex(lht, lt);
	double2hex(rht, rt);
	
	fprintf(ofp,"%s,%s,%s,%s,%s,%s,%s,%s\n",identity, x, y, z, lh, lt, rh, rt); 

}




void computeTrigIdentity1(FILE *ofp, double *inputValues, int k){

	int i;
	double lh,rh;
	double lht, rht;
	char identity[100];
	char y[]="none";
	clock_t startlh,endlh,startrh,endrh;
	char *xHexValue=(char *)malloc(30*sizeof(char));
	char *lhHexValue=(char *)malloc(30*sizeof(char));
	char *rhHexValue=(char *)malloc(30*sizeof(char));
	
	for(i=0;i<=k;i++){
		startlh=clock();
		lh=sin(inputValues[i]);
		endlh=clock();
		startrh=clock();
		rh=-sin(inputValues[i]);
		endrh=clock();
		lht=compute_time(startlh,endlh);
		rht=compute_time(startrh,endrh);
		strcpy(identity,"sin(x)= -sin(x)");
		double2hex(inputValues[i], xHexValue);
		double2hex(lh, lhHexValue);
		double2hex(rh, rhHexValue);
		printIdentityHex(ofp, identity,xHexValue, y, lhHexValue, lht, rhHexValue, rht);
		 			
	
	}
}


void computeTrigIdentity2(FILE *ofp, double *inputValues, int k){

	int i;
	double lh,rh;
	double lht, rht;
	char identity[100];
	char y[]="none";
	clock_t startlh,endlh,startrh,endrh;
	char *xHexValue=(char *)malloc(30*sizeof(char));
	char *lhHexValue=(char *)malloc(30*sizeof(char));
	char *rhHexValue=(char *)malloc(30*sizeof(char));
	
	for(i=0;i<=k;i++){
		startlh=clock();
		lh=cos(inputValues[i]);
		endlh=clock();
		startrh=clock();
		rh=cos(-inputValues[i]);
		endrh=clock();
		lht=compute_time(startlh,endlh);
		rht=compute_time(startrh,endrh);
		strcpy(identity,"cos(x)= cos(-x)");
		double2hex(inputValues[i], xHexValue);
		double2hex(lh, lhHexValue);
		double2hex(rh, rhHexValue);
		printIdentityHex(ofp, identity,xHexValue, y, lhHexValue, lht, rhHexValue, rht);
		 			
	
	}
}

void computeTrigIdentity3(FILE *ofp, double *inputValues, int k){

	int i;
	double lh,rh;
	double lht, rht;
	char identity[100];
	char y[]="none";
	clock_t startlh,endlh,startrh,endrh;
	char *xHexValue=(char *)malloc(30*sizeof(char));
	char *lhHexValue=(char *)malloc(30*sizeof(char));
	char *rhHexValue=(char *)malloc(30*sizeof(char));
	
	for(i=0;i<=k;i++){
		startlh=clock();
		lh=tan(inputValues[i]);
		endlh=clock();
		startrh=clock();
		rh=-tan(-inputValues[i]);
		endrh=clock();
		lht=compute_time(startlh,endlh);
		rht=compute_time(startrh,endrh);
		strcpy(identity,"tan(x)= -tan(-x)");
		double2hex(inputValues[i], xHexValue);
		double2hex(lh, lhHexValue);
		double2hex(rh, rhHexValue);
		printIdentityHex(ofp, identity,xHexValue, y, lhHexValue, lht, rhHexValue, rht);
		 			
	
	}
}


