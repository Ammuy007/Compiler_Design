#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void E();
void EPRIME();
void T();
void F();
void TPRIME();
int i=0,error=0;
char input[20];
int main(){
	printf("Enter the arithmetic expression without whitespace\n");
	scanf("%[^\n]",input);
	E();
	if(strlen(input)==i && error==0){
		printf("Accepted\n");
	}
	else{
		printf("Rejected\n");
	}
	return 0;
}
void E(){
	T();
	EPRIME();
}
void EPRIME(){
	if(input[i]=='+'||input[i]=='-'){
		i++;	T();
		EPRIME();
	}

}
void T(){
	F();
	TPRIME();
}
void TPRIME(){
	if(input[i]=='*'||input[i]=='/'){
	i++;	F();
		TPRIME();
	}
}
void F(){
	if(isalnum(input[i])){
		i++;
	}
	else if(input[i]=='('){
		i++;
		E();
		if(input[i]==')'){
			i++;
		}
		else{
			error=1;
		}
		
	}
	else{
		error=1;
	}
}
