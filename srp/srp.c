#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXPRODLEN 10
#define MAX 50
#define NUMPROD 6
short top=-1,ip_ptr=0;
char input[MAX]={0};
char stack[MAX]={0};
char productions[NUMPROD][MAXPRODLEN]={"E=E+E","E=E-E","E=E*E","E=E/E","E=i","E=(E)"};
char* ptr_prod=&productions[0][0];
void shift(char c);
void reduce(int prodno,char* stackpos);
int main(){
	printf("Enter the string to be parsed\n");
	scanf("%[^\n]",input);
	getchar();
	printf("STACK\t\tINPUT\t\tACTION\n");
	while(input[ip_ptr]!='\0'){
		shift(input[ip_ptr++]);
		for(int j=0;j<NUMPROD;j++){
			for(int i=0;i<NUMPROD;i++){
				char* pos=strstr(stack,ptr_prod+i*MAXPRODLEN+2);
				if(pos!=NULL){
					reduce(i,pos);
				}
			}
		}
	}
	if(top==0 && stack[top]=='E'){
		printf("Accepted\n");
	}
	else{
		printf("Rejected\n");
	}
	return 0;
}
void shift(char c){
	stack[++top]=c;
	printf("%s\t\t%s\t\tShifted %c to stack\n",stack,(input+ip_ptr),c);
}
void reduce(int prodno,char* stackpos){
	int len=strlen(stackpos);
	top-=len;
	bzero((stack+top+1),len);
	stack[++top]=productions[prodno][0];
	 printf("%s\t\t%s\t\tReduced by the production %s\n",stack,(input+ip_ptr),productions[prodno]);
}
