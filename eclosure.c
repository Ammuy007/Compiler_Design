#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 50
int numstates=0,numtrans=0;
bool epstable[MAX][MAX]={false};
void get_nfa(){
        char transition[MAX]={'\0'};
        char* p;
        printf("Enter the number of states\n");
        scanf("%d",&numstates);
        printf("Enter the number of transitions\n");
        scanf("%d",&numtrans);
        printf("Enter the transitions\n");
        for(int i=0;i<numtrans;i++){
                scanf("%s",transition);
                if((p=strchr(transition,'#'))!=NULL){
                        int i,j;
                        sscanf(transition,"q%d",&i);
                        j=atoi(p+2);
                        epstable[i][j]=true;
                }

        }
}
void findeclose(int state,bool visited[]){
        visited[state]=true;
        for(int i=0;i<numstates;i++){
                if(!visited[i] && epstable[state][i]){
                        findeclose(i,visited);
                }
        }
}
void printeclose(){
        for(int i=0;i<numstates;i++){
                bool visited[MAX]={false};
                char outstr[MAX]={'\0'};
                char tempstr[MAX]={'\0'};
                findeclose(i,visited);
                printf("E-closure of q%d={",i);
                for(int j=0;j<numstates;j++){
                        if(visited[j]){
                                sprintf(tempstr,"q%d,",j);
                                strcat(outstr,tempstr);
                        }
                }
                outstr[strlen(outstr)-1]='\0';
                printf("%s}\n",outstr);
        }
}
int main(){
        get_nfa();
        printeclose();
        return 0;
}
