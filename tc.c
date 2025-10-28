#include <stdio.h>
#include <string.h>
#define LEN 5
#define SIZE 50
struct{
    char res[SIZE];
    char op1[SIZE];
    char op;
    char op2[SIZE];
}tac[SIZE];
int num_instr=0;
char instr[SIZE];
void read_tac(){
    printf("Enter the number of instructions\n");
    scanf("%d",&num_instr);
    printf("Enter the instructions\n");
    int i;
    for(i=0;i<num_instr;i++){
        scanf("%s = %s %c %s",tac[i].res,tac[i].op1,&tac[i].op,tac[i].op2);
    }
}

char* get_instr(char op){
    char mnemonic[][LEN]={"MUL","ADD","","SUB","","DIV"};
    strcpy(instr,mnemonic[op-'*']);
    return instr;
}
void generate_tc(){
    int i;
    for(i=0;i<num_instr;i++){
        printf("MOV AX,%s\n%s AX,%s\nMOV %s,AX\n",tac[i].op1,get_instr(tac[i].op),tac[i].op2,tac[i].res);
    }
}
int main(){
    read_tac();
    printf("Equivalent Assembly code:\n");
    generate_tc();
}
