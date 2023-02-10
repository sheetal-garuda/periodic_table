#include "grep.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{
 FILE *f[argc];
 
 int i=0;
 do{ 
 f[i]=fopen(argv[argc-i-1],"r");
 }while(f[i++]!=NULL);
 if(i==1)
 printf("File not found\n");
 else
 {
 char *pattern=argv[argc-i];
 char result[100000];
 int flag=0;
 for(int j=2;j<argc-i;j++){
 if(strcmp("-i",argv[j])==0) 
 
 {
 flag=1;
 break;
 }
 }
 for(int j=0;j<i-1;j++)
 {
 if(i>=2)
 {
 strcat(result,argv[argc-j-1]);
 strcat(result,":\n");
 }
 if(flag==1)
 findPatternIgnoreCase(f[j],pattern,result);
 else
 findPattern(f[j],pattern,result);
 }
 printf("%s",result);
 }
 return 0;
}