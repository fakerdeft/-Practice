#define _CRT_SECURE_NO_WARNINGS
#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	//스택을 자유저장소에 생성
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

	//스택을 자유저장소에서 해제
	free(Stack);
}

Node* LLS_CreateNode(char* NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(strlen(NewData) + 1);

	strcpy(NewNode->Data, NewData); //데이터 저장

	NewNode->NextNode = NULL; //다음 노드에 대한 포인터 NULL로 초기화

	return NewNode; //노드 주소 반환
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
		//최상위 노드를 찾아 NewNode연결(쌓는다)
		/*Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL)
		{
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;*/

		Node* OldTop = Stack->Top; //꼬리노드
		OldTop->NextNode = NewNode;
		NewNode->PrevNode = OldTop;

		Stack->Count++;
	}
	//스택의 Top 필드에 새 노드 주소 등록
	Stack->Top = NewNode;
}

Node* LLS_Pop(LinkedListStack* Stack)
{
	//LLS_Pop() 함수가 반환할 최상위 노드
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
		//새로운 최상위 노드를 스택의 Top에 등록
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