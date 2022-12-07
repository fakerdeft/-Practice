#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdlib.h>
#include "LinkedListStack.h"

typedef enum 
{
	LEFT_PARENTHESIS='(',RIGHT_PARENTHESIS=')',
	PLUS='+',MINUS = '-',MULTIPLY='*',DIVIDE='/',
	SPACE=' ',OPERAND
}SYMBOL;

int IsNumber(char Cipher); //숫자판단
unsigned int GetNextToken(char* Expression, char* Token, int* TYPE);
int IsPrior(char Operator1, char Operator2);
void GetPostfix(char* InfixExpression, char* PostfixExpression); //중위식->후위식
double Calculate(char* PostfixExpression);

#endif