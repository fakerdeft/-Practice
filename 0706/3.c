#include <stdio.h>
#include <stdlib.h>
int global = 100; //외부변수,전역변수

int main() {
	int a = 10; //로컬변수,자동변수
	global = 200;

	// malloc, calloc, realloc
	int* pa = (int*)malloc(100);

	for (int i = 0; i < 25; i++) { //동적메모리 공간 할당
		pa[i] = i;
	}
	for (int i = 0; i < 25; i++) {
		printf("pa[%d] = %d\n", i, pa[i]);
	}

	free(pa); // 동적메모리 반납
	return 0;
}
