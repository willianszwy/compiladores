#ifndef ASTGEN_H
#define ASTGEN_H

#include <stdio.h>

typedef struct AstElement {
    struct AstElement *left;
    struct AstElement *right;
    char nodetype;
    char *name;
    char *op;
    int val;
    char *type;
    struct AstElement* cond;
    struct AstElement** statements;
    int count;
} AstElement;


AstElement* makeAssignment(char*name,  AstElement* val);
AstElement* makeExpByNum(int val);
AstElement* makeExpByName(char*name);
AstElement* makeExp( AstElement* left,  AstElement* right, char* op);
AstElement* makeStatement( AstElement* dest,  AstElement* toAppend);
AstElement* makeNotExp(AstElement* exp);
AstElement* makeUnaryExp(char* op, AstElement* left);
AstElement* makePrint(char* name);
AstElement* makePrintString(char* name);
AstElement* makeRead(char* name);
AstElement* makeDeclaration(char* type, char* name);
AstElement* makeBlank();

AstElement* makeIf( AstElement* cond, AstElement* left,  AstElement* right);



AstElement* makeAssignment( char*name, AstElement* val)
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'A';
    result->name = name;
    result->right = val;
    return result;
}

AstElement* makeExpByNum(int val)
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'V';
    result->val = val;
    return result;
}

AstElement* makeExpByName(char*name)
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'N';
    result->name = name;
    return result;
}

AstElement* makeNotExp(AstElement* exp)
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'Z';
    result->right = exp;
    return result;
}

AstElement* makeBlank()
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'B';
    return result;
}

AstElement* makeExp(AstElement* left, AstElement* right, char* op)
{
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'E';
    result->left = left;
    result->right = right;
    result->op = op;
    return result;
}

AstElement* makeIf( AstElement* cond, AstElement* left,  AstElement* right){
    AstElement* result = malloc(sizeof(AstElement));
    result->nodetype = 'I';
    result->left = left;
    result->right = right;
    result->cond = cond;
    return result;
}

AstElement* makeStatement(AstElement* result, AstElement* toAppend)
{
    
    if(!result)
    {
        result = malloc(sizeof(AstElement));
        result->nodetype = 'S';
        result->count = 0;
        result->statements = 0;
    }
    result->nodetype = 'S';    
    result->count++;
    result->statements = realloc(result->statements, result->count*sizeof(AstElement));
    result->statements[result->count-1] = toAppend;
    return result;
}


AstElement* makePrint(char* name){
    AstElement* result = malloc(sizeof (AstElement));
    result->nodetype = 'P';
    result->name = name;
    return result; 
}

AstElement* makePrintString(char* name){
    AstElement* result = malloc(sizeof (AstElement));
    result->nodetype = 'W';
    result->name = name;
    return result; 
}

AstElement* makeRead(char* name){
    AstElement* result = malloc(sizeof (AstElement));
    result->nodetype = 'R';
    result->name = name;
    return result; 
}
AstElement* makeDeclaration(char* type, char* name){
    AstElement* result = malloc(sizeof (AstElement));
    result->nodetype = 'D';
    result->type = type;
    result->name = name;
    return result; 
}

struct AstElement* makeWhile(struct AstElement* cond, struct AstElement* exec)
{
    struct AstElement* result = malloc(sizeof(*result));
    result->nodetype = 'L';
    result->cond = cond;
    result->right = exec;
    return result;
}

struct AstElement* makeUnaryExp(char* op, AstElement* left)
{
    struct AstElement* result = malloc(sizeof(*result));
    result->nodetype = 'U';
    result->left = left;
    result->op = op;
    return result;
}

#endif