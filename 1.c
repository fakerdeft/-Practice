#include <stdio.h>
//������
int main() {

	int a = 0;
	printf("&a=%d\n", &a);
	
	int* pa; // �������������� // int���� �����ϰ� �ִ� ������ �ּҰ��� �����ϴ� ����
	pa = &a;

	int** ppa;
	ppa = &pa;

	**ppa = 1000; // ������ ������
	**&pa;
	*pa;
	*&a;
	a;

	printf("&**ppa=%p, &**&pa=%p, &*pa=%p, &*&a=%p, &a=%p\n", &**ppa, &**&pa, &*pa, &*&a, &a);
	printf("**ppa=%d, **&pa=%d, *pa=%d, *&a=%d, a=%d\n", *ppa, **&pa, *pa, *&a, a);

	return 0;
}