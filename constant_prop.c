#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 10
#define OPNDSIZE 5
typedef struct{
	char op;
	char op1[OPNDSIZE];
	char op2[OPNDSIZE];
	char res[OPNDSIZE];
}quadruple;
int numquads=0;
quadruple quads[MAX];
typedef enum {false,true}bool;
bool isint(char* s){
	while(*s){
		if(!isdigit(*s)){
			return false;
		}
		s++;
	}
	return true;
}
int calculate(char optr,char* op1,char* op2){
	int x=atoi(op1);
	int y=atoi(op2);
	switch(optr){
		case '+':return x+y;
		case '-':return x-y;
		case '*':return x*y;
		case '/':if(y!=0){
			return x/y;
			}
		default:break;
	}
}
char* getconstvalue(char* opnd){
	for(int i=0;i<numquads;i++){
		if(quads[i].op=='='&&strcmp(quads[i].res,opnd)==0){
			return quads[i].op1;
		}
	}
	return opnd;
}
void fold(){
	for(int i=0;i<numquads;i++){
		if(isint(quads[i].op1)&&isint(quads[i].op2)){
			int result=calculate(quads[i].op,quads[i].op1,quads[i].op2);
			quads[i].op='=';
			strcpy(quads[i].op2,"-");
			snprintf(quads[i].op1,OPNDSIZE,"%d",result);
		}
	}
}
void propagate(){
	for(int i=0;i<numquads;i++){
		strcpy(quads[i].op1,getconstvalue(quads[i].op1));
		strcpy(quads[i].op2,getconstvalue(quads[i].op2));
		if(isint(quads[i].op1)&&isint(quads[i].op2)){
			fold();
		}
	}
}
int main(){
	memset(quads,0,sizeof(quads));
	printf("Enter the number of 3-adress instructions\n");
	scanf("%d",&numquads);
	printf("Enter the instructions\n");
	for(int i=0;i<numquads;i++){
		getchar();
		quads[i].op=getchar();
		scanf("%s %s %s",quads[i].op1,quads[i].op2,quads[i].res);
	}
	fold();
	propagate();
	printf("OPTR\tOPND1\tOPND2\tResult\n");
	for(int i=0;i<numquads;i++){
		printf("%c\t%s\t%s\t%s\n",quads[i].op,quads[i].op1,quads[i].op2,quads[i].res);
	}
	return 0;
}
