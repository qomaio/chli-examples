#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <hli.h>

#define fm(a) {a;/*printf("%s returns %d\n",#a,status);*/}

#define NOBS 70000
#define NSERIES 20

int main(int argc, char **argv) {
	int i;
	int status,dbkey;
	char *dbname = "c_benchmark00.db";
	char objnam[80];
	double *valary;
	float ver;
	int range[3] = {HCASEX,1,NOBS};

	valary = malloc( sizeof(valary[0])*NOBS);

	printf("%s\n",__FILE__);
	struct timeval start;
	gettimeofday(&start,NULL);

	fm(cfmini(&status));
	fm(cfmver(&status, &ver));
	printf("FAME CHLI %.5f\n",ver);
	fm(cfmopdb(&status, &dbkey, dbname, HOMODE));
	for (i = 0; i < NSERIES; i++) {
		sprintf(objnam,"s%06d",i);
		fm(cfmnwob(&status, dbkey, objnam, HSERIE, HCASEX, HPRECN, HBSUND, HOBUND));
		fm(cfmwrng(&status, dbkey, objnam, range, valary, HNTMIS, NULL));
	}
	fm(cfmfin(&status));

	struct timeval end;
	gettimeofday(&end,NULL);
	long ds = (end.tv_sec - start.tv_sec);
	double seconds =  ( ((ds * 1000000) + end.tv_usec) - (start.tv_usec) ) / 1000000.0;
	printf("Time elpased is %.3lf seconds\n", seconds);
	return 0;
}
