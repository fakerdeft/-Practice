#include <stdio.h>
#include <stdlib.h>
int global = 100; //�ܺκ���,��������

int main() {
	int a = 10; //���ú���,�ڵ�����
	global = 200;

	// malloc, calloc, realloc
	int* pa = (int*)malloc(100);

	for (int i = 0; i < 25; i++) { //�����޸� ���� �Ҵ�
		pa[i] = i;
	}
	for (int i = 0; i < 25; i++) {
		printf("pa[%d] = %d\n", i, pa[i]);
	}

	free(pa); // �����޸� �ݳ�

	return 0;
}