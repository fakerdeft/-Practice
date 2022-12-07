#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Score.h"

//���ϰ���
// < 0 �̸� _elem1�� _elem2���� �۴�
//	 0 �̸� _elem1�� _elem2�� ����
// > 0 �̸� _elem1�� _elem2���� ũ��
int CompareScore(const void* _elem1, const void* _elem2) {
	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	if (elem1->score > elem2->score)
		return 1;
	else if (elem1->score < elem2->score)
		return -1;
	else
		return 0;
}

int main() {
	//int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	qsort((void*)DataSet, Length, sizeof(Score), CompareScore);

	for (i = 0; i < 100; i++) {
		printf("number: %d, score: %lf\n", DataSet[i].number, DataSet[i].score);
	}

	printf("------------------------------------------------------------\n");

	for (i = 29900; i < Length; i++) {
		printf("number: %d, score: %lf\n", DataSet[i].number, DataSet[i].score);
	}

	printf("\n");

	return 0;
}