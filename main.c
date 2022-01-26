#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAX 10

typedef struct student {
	char name[10];
	int kor;
	int eng;
	int mat;
	int sci;
	int sum;
	int grade;
}s;

int menu();
void reg(s *s, int index);
void mod(s *s, int index);
void prt(s *s, int index);
void src(s* s, int index);

int example(s* s);

void main() {
	s s[MAX];
	int index = 0;
	index=example(s);

	while (1) {
		system("cls");
		switch (menu()) {
		case 1:
			system("cls");
			reg(s,index);
			index++;
			break;
		case 2:
			system("cls");
			mod(s, index);
			break;
		case 3:
			system("cls");
			prt(s, index);
			break;
		case 4:
			system("cls");
			src(s, index);
			break;
		}

	}
}

int menu() {
	int A;

	printf("1.등록\n");
	printf("2.수정\n");
	printf("3.출력\n");
	printf("4.조회\n");
	printf(">>");
	scanf("%d", &A);

	return A;
}

void reg(s *s, int index){
	char name[10];
	printf("이름 = ");
	scanf("%s", name);
	strcpy(s[index].name, name);
	printf("국어성적 = ");
	scanf("%d", &(s[index].kor));
	printf("영어성적 = ");
	scanf("%d", &(s[index].eng));
	printf("수학성적 = ");
	scanf("%d", &(s[index].mat));
	printf("과학성적 = ");
	scanf("%d", &(s[index].sci));
	s[index].sum = (s[index].kor + s[index].eng + s[index].mat + s[index].sci);

}
void mod(s *s, int index){
	int sel;
	char name[10];
	for (int i = 0; i < index; i++)
		printf("%d. %s\n", i + 1, s[i].name);
	printf("수정할 학생의 번호>>");
	scanf("%d", &sel);
	printf("이름 = ");
	scanf("%s", name);
	strcpy(s[sel-1].name, name);
	printf("국어성적 = ");
	scanf("%d", &(s[sel-1].kor));
	printf("영어성적 = ");
	scanf("%d", &(s[sel-1].eng));
	printf("수학성적 = ");
	scanf("%d", &(s[sel-1].mat));
	printf("과학성적 = ");
	scanf("%d", &(s[sel-1].sci));
	s[sel-1].sum = (s[sel-1].kor + s[sel-1].eng + s[sel-1].mat + s[sel-1].sci);

}
void prt(s *s, int index) {
	for (int i = 0; i < index; i++)
		s[i].grade = 1;
	for (int i = 0; i < index; i++) {
		for (int j = 0; j < index; j++) {
			if (s[i].sum < s[j].sum)
				s[i].grade++;
		}
	}
	printf("  이름   국어   영어    수학   과학   총점   평균   석차\n");
	printf("===================================================================\n");
	for (int i = 0; i < index+1; i++) {
		for (int j = 0; j < index; j++) {
			if (i + 1 == s[j].grade)
				printf("%s    %d    %d     %d    %d    %d    %d     %d\n",s[j].name,s[j].kor,s[j].eng,s[j].mat,s[j].sci,s[j].sum,s[j].sum/4,s[j].grade);
		}
	}
	getch();
}
void src(s *s, int index){
	char name[10];
	printf("조회할 이름>>");
	scanf("%s", name);

	for (int i = 0; i < index; i++) {
		if (!(strcmp(name, s[i].name))) {
			printf("이름=%s\n",s[i].name);
			printf("국어=%d\n",s[i].kor);
			printf("영어=%d\n",s[i].eng);
			printf("수학=%d\n",s[i].mat);
			printf("과학=%d\n",s[i].sci);
		}
	}
	getch();
}

int example(s *s){
	strcpy(s[0].name, "홍길동");
	s[0].eng = 60;
	s[0].kor = 70;
	s[0].mat = 80;
	s[0].sci = 90;
	s[0].sum = 300;
	strcpy(s[1].name, "임꺽정");
	s[1].eng = 70;
	s[1].kor = 75;
	s[1].mat = 87;
	s[1].sci = 60;
	s[1].sum = 292;
	strcpy(s[2].name, "아무개");
	s[2].eng = 54;
	s[2].kor = 90;
	s[2].mat = 100;
	s[2].sci = 70;
	s[2].sum = 314;
	
	return 3;
}
