#include <stdio.h>
#include <hli.h>

#define fm(a) {a;printf("%s returns %d\n",#a,status);}
int main(int argc,char **argv){
int status;
float ver;
printf("Hello FAME\n");
fm( cfmini(&status));
fm(cfmver(&status,&ver));
fm(cfmfin(&status));

return 0;
  }