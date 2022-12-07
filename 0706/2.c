#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//구조체
struct Student {  //사용자 정의 데이터 타입
	char name[30]; //구조체 멤버
	int age;
	int grade;

	struct Student* Next;
};

/*int main() {
	struct Student a;
	a.name[0] = 'M';
	a.name[1] = 'O';
	a.name[2] = 'N';
	a.name[3] = '\0';

	a.age = 10;
	a.grade = 3;

	printf("이름: %s, 나이: %d, 학년: %d\n", a.name, a.age, a.grade);
	
	(&a)->name[0] = 'K';
	(&a)->name[1] = 'O';
	(&a)->name[2] = 'N';
	(&a)->name[3] = '\0';

	(&a)->age = 12;
	(&a)->grade = 1;

	printf("이름: %s, 나이: %d, 학년: %d\n", (&a)->name, (&a)->age, (&a)->grade);
	

	return 0;
}*/

int main() {
	struct Student a;
	struct Student b;
	struct Student c;

	strcpy(a.name, "MONS");
	a.age = 10;
	a.grade = 3;

	strcpy(b.name, "MONS1");
	b.age = 11;
	b.grade = 2;

	strcpy(c.name, "MONS2");
	c.age = 12;
	c.grade = 3;

	a.Next = &b;
	b.Next = &c;

	printf("이름: %s, 나이: %d, 학년: %d\n", a.name, a.age, a.grade);
	printf("이름: %s, 나이: %d, 학년: %d\n", a.Next->name, a.Next->age, a.Next->grade);
	printf("이름: %s, 나이: %d, 학년: %d\n", a.Next->Next->name, a.Next->Next->age, a.Next->Next->grade);


	return 0;
}