#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Calculator.h"

// (117.32+83)*49
// 1+2*3
int main()
{
    char InfixExpression[100]; //������ ���� ����
    char PostfixExpression[100]; //������ ���� ����

    double Result = 0.0;

    memset(InfixExpression, 0, sizeof(InfixExpression));
    memset(PostfixExpression, 0, sizeof(PostfixExpression));

    printf("Enter Infix Expression:");
    scanf("%s", InfixExpression); //(117.32+83)*49

    GetPostfix(InfixExpression, PostfixExpression); // position:0 length:14 ���� ����

    printf("Infix:%s\nPostfix:%s\n",
        InfixExpression,
        PostfixExpression);

    Result = Calculate(PostfixExpression);

    printf("Calculation Result : %f\n", Result);

    return 0;
}