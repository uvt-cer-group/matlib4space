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
	
	for(i=0;i<=k;i++){
		startlh=clock();
		lh=sin(inputValues[i])*sin(inputValues[i])+cos(inputValues[i])*cos(inputValues[i]);
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

        for(i=0;i<=k;i++){
                startlh=clock();
                val=inputValues_x[i]-inputValues_y[i];
                lh=cos(val);
                endlh=clock();
                startrh=clock();
               	rh=sin(inputValues_x[i])*sin(inputValues_y[i])+cos(inputValues_x[i])*cos(inputValues_y[i]);
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

        for(i=0;i<=k;i++){
                startlh=clock();
                val=inputValues_x[i]+inputValues_y[i];
                lh=cos(val);
                endlh=clock();
                startrh=clock();
                rh=-sin(inputValues_x[i])*sin(inputValues_y[i])+cos(inputValues_x[i])*cos(inputValues_y[i]);
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

       	for(i=0;i<=k;i++){
                startlh=clock();
                lh=sin(inputValues[i]*2);
                endlh=clock();
                startrh=clock();
                rh=2*sin(inputValues[i])*cos(inputValues[i]);
                endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"sin(2*x)=2*sin(x)*cos(x)");
                double2hex(inputValues[i], xHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
                printIdentityHex(ofp, identity,xHexValue, y, lhHexValue, lht, rhHexValue, rht);


       	}
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

        for(i=0;i<=k;i++){
                startlh=clock();
                val=inputValues_x[i]+inputValues_y[i];
                lh=tan(val);
                endlh=clock();
                startrh=clock();
                rh=(tan(inputValues_x[i])+tan(inputValues_y[i]))/(1-tan(inputValues_x[i])*tan(inputValues_y[i]));
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

       	for(i=0;i<=k;i++){
                startlh=clock();
		val=inputValues[i]/2.0;
                lh=cos(val);
                endlh=clock();
                startrh=clock();
		val=(1+cos(inputValues[i]))/2.0;
                rh=sqrt(val);
                endrh=clock();
                lht=compute_time(startlh,endlh);
                rht=compute_time(startrh,endrh);
                strcpy(identity,"cos(x/2)=Sqrt[(1+cos(x))/2]");
                double2hex(inputValues[i], xHexValue);
                double2hex(lh, lhHexValue);
                double2hex(rh, rhHexValue);
                printIdentityHex(ofp, identity,xHexValue, y, lhHexValue, lht, rhHexValue, rht);


       	}
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

        for(i=0;i<=k;i++){
                startlh=clock();
                lh=exp(inputValues_x[i])/exp(inputValues_y[i]);
                endlh=clock();
                startrh=clock();
		val=inputValues_x[i]-inputValues_y[i];
               	rh=exp(val);
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

        for(i=0;i<=k;i++){
                startlh=clock();
                lh=sqrt(inputValues_x[i])/sqrt(inputValues_y[i]);
                endlh=clock();
                startrh=clock();
		val=inputValues_x[i]/inputValues_y[i];
               	rh=sqrt(val);
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
	
	for(i=0;i<=k;i++){
		startlh=clock();
		lh=log(exp(inputValues[i]));
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

        for(i=0;i<=k;i++){
                startlh=clock();
                lh=pow(inputValues_x[i]*inputValues_y[i], inputValues_a[i]);
                endlh=clock();
                startrh=clock();
               	rh=pow(inputValues_x[i],inputValues_a[i])* pow(inputValues_y[i],inputValues_a[i]);
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

        for(i=0;i<=k;i++){
                startlh=clock();
                lh=pow(inputValues_x[i],inputValues_a[i])/(inputValues_x[i], inputValues_b[i]);
                endlh=clock();
                startrh=clock();
               	rh=pow(inputValues_x[i],(inputValues_a[i]-inputValues_b[i]));
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
}

