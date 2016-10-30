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
	double val;
	clock_t startlh,endlh,startrh,endrh;
	char *xHexValue=(char *)malloc(30*sizeof(char));
	char *lhHexValue=(char *)malloc(30*sizeof(char));
	char *rhHexValue=(char *)malloc(30*sizeof(char));
	
	mpfr_t x,a,b;
	mpfr_init2(x,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);


	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		startlh=clock();
		mpfr_sin(a,x,MPFR_RNDD);
		mpfr_mul(a,a,a,MPFR_RNDD);
		mpfr_cos(b,x,MPFR_RNDD);
		mpfr_mul(b,b,b,MPFR_RNDD);
		mpfr_add(a,a,b,MPFR_RNDD);
		lh=mpfr_get_d(a,MPFR_RNDD);
		endlh=clock();
		startrh=clock();
		rh=1.0;
		endrh=clock();
		lht=compute_time(startlh,endlh);
		rht=compute_time(startrh,endrh);
		strcpy(identity,"sin^2(x)+cos^2(x)=1");
		double2hex(inputValues[i], xHexValue);
		double2hex(lh, lhHexValue);
		double2hex(rh, rhHexValue);
		printIdentityHex(ofp, identity,xHexValue, y, lhHexValue, lht, rhHexValue, rht);
		 			
	
	}
	mpfr_clears (x, a,b, (mpfr_ptr) 0);
}


void computeTrigIdentity2(FILE *ofp, double *inputValues_x, double *inputValues_y, int k){

        int i;
	double lh,rh;
        double lht, rht;
        char identity[100];
        double val;
        clock_t startlh,endlh,startrh,endrh;
        char *xHexValue=(char *)malloc(30*sizeof(char));
	char *yHexValue=(char *)malloc(30*sizeof(char));
        char *lhHexValue=(char *)malloc(30*sizeof(char));
        char *rhHexValue=(char *)malloc(30*sizeof(char));

	mpfr_t x,y,a,b,c;
	mpfr_init2(x,128);
	mpfr_init2(y,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);
	mpfr_init2(c,128);


        for(i=0;i<=k;i++){
                startlh=clock();
			mpfr_set_d(x,inputValues_x[i],MPFR_RNDD);
			mpfr_set_d(y,inputValues_y[i],MPFR_RNDD);
			mpfr_sub(a,x,y,MPFR_RNDD);
			mpfr_cos(a,a,MPFR_RNDD);
                lh=mpfr_get_d(a,MPFR_RNDD);
                endlh=clock();
                
			startrh=clock();
			mpfr_cos(a,x,MPFR_RNDD);
			mpfr_cos(b,y,MPFR_RNDD);
			mpfr_mul(a,a,b,MPFR_RNDD);
			mpfr_sin(b,x,MPFR_RNDD);
			mpfr_sin(c,y,MPFR_RNDD);
			mpfr_mul(b,b,c,MPFR_RNDD);
			mpfr_add(a,a,b,MPFR_RNDD);
               	rh=mpfr_get_d(a,MPFR_RNDD);
               	endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"cos(x-y)=sin(x)*sin(y)+cos(x)*cos(y)");
                double2hex(inputValues_x[i], xHexValue);
		double2hex(inputValues_y[i], yHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
                printIdentityHex(ofp, identity,xHexValue, yHexValue, lhHexValue, lht, rhHexValue, rht);


        }
	
	
	mpfr_clears (x, y,a,b,c, (mpfr_ptr) 0);

}

void computeTrigIdentity3(FILE *ofp, double *inputValues_x, double *inputValues_y, int k){

        int i;
        double lh,rh;
            
        double lht, rht;
        char identity[100];
        double val;
        clock_t startlh,endlh,startrh,endrh;
       	char *xHexValue=(char *)malloc(30*sizeof(char));
         char *yHexValue=(char *)malloc(30*sizeof(char));
        char *lhHexValue=(char *)malloc(30*sizeof(char));
        char *rhHexValue=(char *)malloc(30*sizeof(char));

	mpfr_t x,y,a,b,c;
	mpfr_init2(x,128);
	mpfr_init2(y,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);
	mpfr_init2(c,128);


        for(i=0;i<=k;i++){
			mpfr_set_d(x,inputValues_x[i],MPFR_RNDD);
			mpfr_set_d(y,inputValues_y[i],MPFR_RNDD);

                startlh=clock();
			mpfr_add(a,x,y,MPFR_RNDD);
			mpfr_cos(a,a,MPFR_RNDD);
                lh=mpfr_get_d(a,MPFR_RNDD);

                endlh=clock();
                startrh=clock();
                mpfr_cos(a,x,MPFR_RNDD);
			mpfr_cos(b,y,MPFR_RNDD);
			mpfr_mul(a,a,b,MPFR_RNDD);
			mpfr_sin(b,x,MPFR_RNDD);
			mpfr_sin(c,y,MPFR_RNDD);
			mpfr_mul(b,b,c,MPFR_RNDD);
			mpfr_sub(a,a,b,MPFR_RNDD);
               	rh=mpfr_get_d(a,MPFR_RNDD);
               	endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"cos(x+y)=-sin(x)*sin(y)+cos(x)*cos(y)");
                double2hex(inputValues_x[i], xHexValue);
                double2hex(inputValues_y[i], yHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
                printIdentityHex(ofp, identity,xHexValue, yHexValue, lhHexValue, lht, rhHexValue, rht);


        }
	mpfr_clears (x, y,a,b,c, (mpfr_ptr) 0);

}

void computeTrigIdentity4(FILE *ofp, double *inputValues, int k){

        int i;
	double lh,rh;
            
        double lht, rht;
        char identity[100];
        char y[]="none";
        clock_t startlh,endlh,startrh,endrh;
        char *xHexValue=(char *)malloc(30*sizeof(char));
        char *lhHexValue=(char *)malloc(30*sizeof(char));
        char *rhHexValue=(char *)malloc(30*sizeof(char));

	mpfr_t x,a,b;
	mpfr_init2(x,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);


       	for(i=0;i<=k;i++){
			mpfr_set_d(x,inputValues[i],MPFR_RNDD);
                startlh=clock();
			mpfr_add(a,x,x,MPFR_RNDD);
			mpfr_sin(a,a,MPFR_RNDD);
                lh=mpfr_get_d(a,MPFR_RNDD);
                endlh=clock();
                startrh=clock();
			mpfr_sin(a,x,MPFR_RNDD);
			mpfr_cos(b,x,MPFR_RNDD);
			mpfr_mul(a,a,b,MPFR_RNDD);
			mpfr_add(a,a,a,MPFR_RNDD);
                rh=mpfr_get_d(a,MPFR_RNDD);
                endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"sin(2*x)=2*sin(x)*cos(x)");
                double2hex(inputValues[i], xHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
                printIdentityHex(ofp, identity,xHexValue, y, lhHexValue, lht, rhHexValue, rht);


       	}
	mpfr_clears (x,a,b, (mpfr_ptr) 0);

}





void computeTrigIdentity5(FILE *ofp, double *inputValues_x, double *inputValues_y, int k){

        int i;
        double lh,rh;
             
        double lht, rht;
        char identity[100];
        double val;
        clock_t startlh,endlh,startrh,endrh;
       	char *xHexValue=(char *)malloc(30*sizeof(char));
         char *yHexValue=(char *)malloc(30*sizeof(char));
        char *lhHexValue=(char *)malloc(30*sizeof(char));
        char *rhHexValue=(char *)malloc(30*sizeof(char));

	mpfr_t x,y,a,b,c;
	mpfr_init2(x,128);
	mpfr_init2(y,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);
	mpfr_init2(c,128);


        for(i=0;i<=k;i++){
			mpfr_set_d(x,inputValues_x[i],MPFR_RNDD);
			mpfr_set_d(y,inputValues_y[i],MPFR_RNDD);

                startlh=clock();
			mpfr_add(b,x,y,MPFR_RNDD);
			mpfr_tan(a,b,MPFR_RNDD);
                lh=mpfr_get_d(a,MPFR_RNDD);
                endlh=clock();
			mpfr_set_d(b,1.0,MPFR_RNDD);
                startrh=clock();
                mpfr_tan(a,x,MPFR_RNDD);
   			mpfr_tan(c,y,MPFR_RNDD);
			mpfr_mul(c,a,c,MPFR_RNDD);
			mpfr_sub(b,b,c,MPFR_RNDD);
			mpfr_tan(c,y,MPFR_RNDD);
			mpfr_add(a,a,c,MPFR_RNDD);
			mpfr_div(a,a,b,MPFR_RNDD);
			rh=mpfr_get_d(a,MPFR_RNDD);
               	endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"tan(x+y)=(tan(x)+tan(y)/(1-tan(x)tan(y))");
                double2hex(inputValues_x[i], xHexValue);
                double2hex(inputValues_y[i], yHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
               printIdentityHex(ofp, identity,xHexValue, yHexValue, lhHexValue, lht, rhHexValue, rht);


        }
	mpfr_clears (x, y,a,b,c, (mpfr_ptr) 0);

}




void computeTrigIdentity6(FILE *ofp, double *inputValues, int k){

        int i;
	double lh,rh;
             
        double lht, rht;
        char identity[100];
        char y[]="none";
	double val;
        clock_t startlh,endlh,startrh,endrh;
        char *xHexValue=(char *)malloc(30*sizeof(char));
        char *lhHexValue=(char *)malloc(30*sizeof(char));
        char *rhHexValue=(char *)malloc(30*sizeof(char));
		
	mpfr_t x,a,b,c;
	mpfr_init2(x,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);
	mpfr_init2(c,128);


       	for(i=0;i<=k;i++){
			mpfr_set_d(c,2.0,MPFR_RNDD);
			mpfr_set_d(x,inputValues[i],MPFR_RNDD);
                startlh=clock();
			mpfr_div(b,x,c,MPFR_RNDD);
    			mpfr_cos(a,b,MPFR_RNDD);
                lh=mpfr_get_d(a,MPFR_RNDD);
                endlh=clock();
			mpfr_set_d(b,1.0,MPFR_RNDD);
                startrh=clock();
			mpfr_cos(a,x,MPFR_RNDD);
    			mpfr_add(a,a,b,MPFR_RNDD);
    			mpfr_div(a,a,c,MPFR_RNDD);
			mpfr_sqrt(a,a,MPFR_RNDD);
                rh=mpfr_get_d(a,MPFR_RNDD);
                endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"cos(x/2)=Sqrt[(1+cos(x))/2]");
                double2hex(inputValues[i], xHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
                printIdentityHex(ofp, identity,xHexValue, y, lhHexValue, lht, rhHexValue, rht);


       	}
		mpfr_clears (x,a,b,c, (mpfr_ptr) 0);

}

void computeNonTrigIdentity1(FILE *ofp, double *inputValues_x, double *inputValues_y, int k){

        int i;
	double lh,rh;
        double lht, rht;
        char identity[100];
        double val;
        clock_t startlh,endlh,startrh,endrh;
        char *xHexValue=(char *)malloc(30*sizeof(char));
	 char *yHexValue=(char *)malloc(30*sizeof(char));
        char *lhHexValue=(char *)malloc(30*sizeof(char));
        char *rhHexValue=(char *)malloc(30*sizeof(char));
	
	mpfr_t x,y,a,b;
	mpfr_init2(x,128);
	mpfr_init2(y,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);


        for(i=0;i<=k;i++){
			mpfr_set_d(x,inputValues_x[i],MPFR_RNDD);
			mpfr_set_d(y,inputValues_y[i],MPFR_RNDD);
                startlh=clock();
			mpfr_exp(a,x,MPFR_RNDD);
			mpfr_exp(b,y,MPFR_RNDD);
			mpfr_div(a,a,b,MPFR_RNDD);
                lh=mpfr_get_d(a,MPFR_RNDD);
                endlh=clock();
                startrh=clock();
			mpfr_sub(b,x,y,MPFR_RNDD);
			mpfr_exp(a,b,MPFR_RNDD);
			rh=mpfr_get_d(a,MPFR_RNDD);
             
               	endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"exp(a)/exp(b)=exp(a-b)");
                double2hex(inputValues_x[i], xHexValue);
		double2hex(inputValues_y[i], yHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
                printIdentityHex(ofp, identity,xHexValue, yHexValue, lhHexValue, lht, rhHexValue, rht);


        }
	mpfr_clears (x, y,a,b, (mpfr_ptr) 0);

}


void computeNonTrigIdentity2(FILE *ofp, double *inputValues_x, double *inputValues_y, int k){

        int i;
	double lh,rh;
        double lht, rht;
        char identity[100];
        double val;
        clock_t startlh,endlh,startrh,endrh;
        char *xHexValue=(char *)malloc(30*sizeof(char));
	 char *yHexValue=(char *)malloc(30*sizeof(char));
        char *lhHexValue=(char *)malloc(30*sizeof(char));
        char *rhHexValue=(char *)malloc(30*sizeof(char));

	mpfr_t x,y,a,b;
	mpfr_init2(x,128);
	mpfr_init2(y,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);


        for(i=0;i<=k;i++){
			mpfr_set_d(x,inputValues_x[i],MPFR_RNDD);
			mpfr_set_d(y,inputValues_y[i],MPFR_RNDD);
                startlh=clock();
			mpfr_sqrt(a,x,MPFR_RNDD);
			mpfr_sqrt(b,y,MPFR_RNDD);
			mpfr_div(a,a,b,MPFR_RNDD);
                lh=mpfr_get_d(a,MPFR_RNDD);
                endlh=clock();
                startrh=clock();
			mpfr_div(b,x,y,MPFR_RNDD);
			mpfr_sqrt(a,b,MPFR_RNDD);
               	rh=mpfr_get_d(a,MPFR_RNDD);
               	endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"sqrt(a)/sqrt(b)=sqrt(a/b)");
                double2hex(inputValues_x[i], xHexValue);
		double2hex(inputValues_y[i], yHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
                printIdentityHex(ofp, identity,xHexValue, yHexValue, lhHexValue, lht, rhHexValue, rht);


        }
	mpfr_clears (x, y,a,b, (mpfr_ptr) 0);

}



void computeNonTrigIdentity3(FILE *ofp, double *inputValues, int k){

	int i;
	double lh,rh;
	double lht, rht;
	char identity[100];
	char y[]="none";
	double val;
	clock_t startlh,endlh,startrh,endrh;
	char *xHexValue=(char *)malloc(30*sizeof(char));
	char *lhHexValue=(char *)malloc(30*sizeof(char));
	char *rhHexValue=(char *)malloc(30*sizeof(char));

	mpfr_t x,a,b;
	mpfr_init2(x,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);

	
	for(i=0;i<=k;i++){
		mpfr_set_d(x,inputValues[i],MPFR_RNDD);
		startlh=clock();
		mpfr_exp(b,x,MPFR_RNDD);
		mpfr_log(a,b,MPFR_RNDD);
		lh=mpfr_get_d(a,MPFR_RNDD);
		endlh=clock();
		startrh=clock();
		rh=inputValues[i];
		endrh=clock();
		lht=compute_time(startlh,endlh);
		rht=compute_time(startrh,endrh);
		strcpy(identity,"log(exp(x))=x");
		double2hex(inputValues[i], xHexValue);
		double2hex(lh, lhHexValue);
		double2hex(rh, rhHexValue);
		printIdentityHex(ofp, identity,xHexValue, y, lhHexValue, lht, rhHexValue, rht);
		 			
	
	}
	mpfr_clears (x,a,b, (mpfr_ptr) 0);

}


void computeNonTrigIdentity4(FILE *ofp, double *inputValues_x,double *inputValues_a,double *inputValues_y, int k){

        int i;
	double lh,rh;
        double lht, rht;
        char identity[100];
        clock_t startlh,endlh,startrh,endrh;
        char *xHexValue=(char *)malloc(30*sizeof(char));
	   char *yHexValue=(char *)malloc(30*sizeof(char));
	   char *aHexValue=(char *)malloc(30*sizeof(char));
        char *lhHexValue=(char *)malloc(30*sizeof(char));
        char *rhHexValue=(char *)malloc(30*sizeof(char));

	mpfr_t x,y,a,b,c;
	mpfr_init2(x,128);
	mpfr_init2(y,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);
	mpfr_init2(c,128);

        for(i=0;i<=k;i++){
			mpfr_set_d(x,inputValues_x[i],MPFR_RNDD);
			mpfr_set_d(y,inputValues_y[i],MPFR_RNDD);
			mpfr_set_d(c,inputValues_a[i],MPFR_RNDD);
                startlh=clock();
			mpfr_mul(b,x,y,MPFR_RNDD);
			mpfr_pow(a,b,c,MPFR_RNDD);
                lh=mpfr_get_d(a,MPFR_RNDD);
                endlh=clock();
                startrh=clock();
			mpfr_pow(a,x,c,MPFR_RNDD);
			mpfr_pow(b,y,c,MPFR_RNDD);
			mpfr_mul(a,a,b,MPFR_RNDD);
               	rh=mpfr_get_d(a,MPFR_RNDD);
               	endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"pow(x*y,a)=pow(x,a)*pow(y,a)");
                double2hex(inputValues_x[i], xHexValue);
			double2hex(inputValues_y[i], yHexValue);
			double2hex(inputValues_a[i], aHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
                printIdentityHex1(ofp, identity,xHexValue, yHexValue,aHexValue, lhHexValue, lht, rhHexValue, rht);


        }
	mpfr_clears (x, y,a,b,c, (mpfr_ptr) 0);

}



void computeNonTrigIdentity5(FILE *ofp, double *inputValues_x,double *inputValues_a,double *inputValues_b, int k){

        int i;
	double lh,rh;
        double lht, rht;
        char identity[100];
        clock_t startlh,endlh,startrh,endrh;
        char *xHexValue=(char *)malloc(30*sizeof(char));
	   char *aHexValue=(char *)malloc(30*sizeof(char));
	   char *bHexValue=(char *)malloc(30*sizeof(char));
        char *lhHexValue=(char *)malloc(30*sizeof(char));
        char *rhHexValue=(char *)malloc(30*sizeof(char));

	mpfr_t x,y,a,b,c;
	mpfr_init2(x,128);
	mpfr_init2(y,128);
	mpfr_init2(a,128);
    	mpfr_init2(b,128);
	mpfr_init2(c,128);


        for(i=0;i<=k;i++){
			mpfr_set_d(x,inputValues_x[i],MPFR_RNDD);
			mpfr_set_d(y,inputValues_a[i],MPFR_RNDD);
			mpfr_set_d(c,inputValues_b[i],MPFR_RNDD);

                startlh=clock();
                mpfr_pow(a,x,y,MPFR_RNDD);
			mpfr_pow(b,x,c,MPFR_RNDD);
			mpfr_div(a,a,b,MPFR_RNDD);
			lh=mpfr_get_d(a,MPFR_RNDD);
                endlh=clock();
                startrh=clock();
			mpfr_sub(b,y,c,MPFR_RNDD);
			mpfr_pow(a,x,b,MPFR_RNDD);
               	rh=mpfr_get_d(a,MPFR_RNDD);
               	endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"pow(x,a)/pow(x,b)=pow(x,(a-b))*pow(b,n)");
                double2hex(inputValues_x[i], xHexValue);
			double2hex(inputValues_a[i], aHexValue);
			double2hex(inputValues_b[i], bHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
                printIdentityHex1(ofp, identity,xHexValue, aHexValue,bHexValue, lhHexValue, lht, rhHexValue, rht);


        }
	mpfr_clears (x, y,a,b,c, (mpfr_ptr) 0);

}

