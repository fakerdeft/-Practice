#include <stdio.h>

int main() {

	int array[] = { 2,4,8,9,1,3,7,6,5,0 };
	int flag = 0;
	int length = sizeof(array) / sizeof(int);

	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				int t = 0;
				t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
				flag = 1;
			}
			for (int i = 0; i < length; i++) {
				printf("%d ", array[i]);
			}
			printf("\n");

		}
		if (flag == 0) {
			break;
		}
	}

	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}