#include <stdio.h>
#include <stdlib.h>
typedef struct ASTNODE{
	char op;
	struct ASTNODE* left;
	struct ASTNODE* right;
	int value;
}ASTNODE;
ASTNODE* makenode(char op,ASTNODE* left,ASTNODE* right);
ASTNODE* makeleaf(int value);
void print_ast(ASTNODE* node);
