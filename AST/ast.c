#include "ast.h"
ASTNODE* makenode(char op,ASTNODE* left,ASTNODE* right){
	ASTNODE* node=(ASTNODE*)malloc(sizeof(ASTNODE));
	node->op=op;
	node->left=left;
	node->right=right;
	node->value=0;
}
ASTNODE* makeleaf(int value){
	ASTNODE* node=(ASTNODE*)malloc(sizeof(ASTNODE));
	node->op=0;
	node->left=NULL;
        node->right=NULL;
        node->value=value;

}
void print_ast(ASTNODE* node){
	if(node->left){
		print_ast(node->left);
	}
	if(node->right){
                print_ast(node->right);
        }
	if(node->op){
		printf("%c ",node->op);
	}
	else{
		printf("%d ",node->value);
	}
}
