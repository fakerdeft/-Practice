#include <stdio.h>
//포인터
int main() {

	int a = 0;
	printf("&a=%d\n", &a);
	
	int* pa; // 포인터형지정자 // int값을 저장하고 있는 공간의 주소값을 저장하는 변수
	pa = &a;

	int** ppa;
	ppa = &pa;

	**ppa = 1000; // 포인터 연산자
	**&pa;
	*pa;
	*&a;
	a;

	printf("&**ppa=%p, &**&pa=%p, &*pa=%p, &*&a=%p, &a=%p\n", &**ppa, &**&pa, &*pa, &*&a, &a);
	printf("**ppa=%d, **&pa=%d, *pa=%d, *&a=%d, a=%d\n", *ppa, **&pa, *pa, *&a, a);

	return 0;
}
