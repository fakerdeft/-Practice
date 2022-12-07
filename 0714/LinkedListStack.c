#define _CRT_SECURE_NO_WARNINGS
#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	//������ ��������ҿ� ����
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
	(*Stack)->Count = 0;
}

void LLS_DestroyStack(LinkedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		Node* Popped = LLS_Pop(Stack);
		LLS_DestroyNode(Popped);
	}

	//������ ��������ҿ��� ����
	free(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData); //������ ����

	NewNode->NextNode = NULL; //���� ��忡 ���� ������ NULL�� �ʱ�ȭ

	return NewNode; //��� �ּ� ��ȯ
}

void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == NULL)
	{
		Stack->List = NewNode;
		Stack->Count++;
	}
	else
	{
		//�ֻ��� ��带 ã�� NewNode����(�״´�)
		/*Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL)
		{
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;*/

		Node* OldTop = Stack->Top; //�������
		OldTop->NextNode = NewNode;
		NewNode->PrevNode = OldTop;

		Stack->Count++;
	}
	//������ Top �ʵ忡 �� ��� �ּ� ���
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	//LLS_Pop() �Լ��� ��ȯ�� �ֻ��� ���
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
		Stack->Count--;
	}
	else
	{
		/*
		//���ο� �ֻ��� ��带 ������ Top�� ���
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}
		Stack->Top = CurrentTop;
		CurrentTop->NextNode = NULL;*/
		Stack->Top = TopNode->PrevNode;
		Stack->Top->NextNode = NULL;
		TopNode -> PrevNode = NULL;

		Stack->Count--;
	}

	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	int Count = 0;
	Node* Current = Stack->List;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == NULL);
}

int getsize(LinkedListStack* Stack)
{
	return Stack->Count;
}