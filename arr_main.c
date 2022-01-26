#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define MAX 10


int menu();
void reg(char name[][10], int kor[], int eng[], int mat[], int sci[], int sum[], int index);
void mod(char name[][10], int kor[], int eng[], int mat[], int sci[], int sum[], int index);
void prt(char name[][10], int kor[], int eng[], int mat[], int sci[], int sum[], int index);
void src(char name[][10], int kor[], int eng[], int mat[], int sci[], int sum[], int index);

int sample(char name[][10], int kor[], int eng[], int mat[], int sci[], int sum[]);

void main() {
	char name[10][10];				//이름 데이터 저장 배열
	int kor[10];					//국어점수 데이터 저장 배열
	int eng[10];					//영어점수 데이터 저장 배열
	int mat[10];					//수학점수 데이터 저장 배열
	int sci[10];					//과학점수 데이터 저장 배열
	int sum[10];					//총점수 데이터 저장 배열

	int index = 0;					//저장되어있는 데이터의(사람) 개수

	index = sample(name,kor,eng,mat,sci,sum);			//sample 입력
	
	while (1) {

		system("cls");		// 콘솔화면 지우는 함수 없어도 무방

		switch (menu()) {			//switch 대상으로 menu()함수의 반환값 지정

		case 1:							//menu_selc이 1일때 (등록)

			reg(name, kor, eng, mat, sci, sum, index);

			index++;		//사람 한명을 등록했으므로 index+1
			break;

		case 2:							//menu_selc이 2일때 (수정)
			
			mod(name, kor, eng, mat, sci, sum, index);

			break;

		case 3:							//menu_selc이 3일때 (출력)
			
			prt(name, kor, eng, mat, sci, sum, index);

			break;

		case 4:							//menu_selc이 4일때 (조회)
			
			src(name, kor, eng, mat, sci, sum, index);

			break;
		}

	}
}

int menu() {
	int input;

	printf("1.등록\n");			// 메
	printf("2.수정\n");			// 뉴
	printf("3.출력\n");			// 출
	printf("4.조회\n");			// 력
	printf(">>");
	scanf("%d", &input);		//input에 숫자 입력 1~4

	return input;				//input값 반환
}
void reg(char name[][10], int kor[], int eng[], int mat[], int sci[], int sum[], int index) {
	char i_name[10];

	system("cls");

	printf("이름 = ");
	scanf("%s", i_name);			//이름 i_name에 입력받아서
	strcpy(name[index], i_name);	//strcpy로 name 배열 빈공간에 i_name 복사해줌 index가 데이터(사람)수를 나타내므로 name[index]를 사용
	printf("국어성적 = ");
	scanf("%d", &(kor[index]));		//scanf로 국어 영어 수학 과학 성적 각각 
	printf("영어성적 = ");			//배열에 삽입, index가 데이터(사람)수를
	scanf("%d", &(eng[index]));		//나타내므로 kor[index]를 사용
	printf("수학성적 = ");
	scanf("%d", &(mat[index]));
	printf("과학성적 = ");
	scanf("%d", &(sci[index]));
	sum[index] = (kor[index] + eng[index] + mat[index] + sci[index]);		// 4과목 합하여 총 점수 배열에 삽입

}

void mod(char name[][10], int kor[], int eng[], int mat[], int sci[], int sum[], int index) {
	int mod_selc;
	char i_name[10];
	
	system("cls");

	for (int i = 0; i < index; i++)
		printf("%d. %s\n", i + 1, name[i]);		//수정할 번호 선택할수 있도록 순서와 이름 출력
	printf("수정할 학생의 번호>>");
	scanf("%d", &mod_selc);						//수정할 번호 선택 mod_selc에 저장


	printf("이름 = ");
	scanf("%s", i_name);						//데이터 등록과 같은 방법으로
	strcpy(name[mod_selc - 1], i_name);			//데이터 저장함
	printf("국어성적 = ");						//배열번호로 index 대신 mod_selc을 사용하여
	scanf("%d", &(kor[mod_selc - 1]));			//선택한 번호의 데이터를 수정함
	printf("영어성적 = ");
	scanf("%d", &(eng[mod_selc - 1]));
	printf("수학성적 = ");
	scanf("%d", &(mat[mod_selc - 1]));
	printf("과학성적 = ");
	scanf("%d", &(sci[mod_selc - 1]));
	sum[mod_selc - 1] = (kor[mod_selc - 1] + eng[mod_selc - 1] + mat[mod_selc - 1] + sci[mod_selc - 1]);

}

void prt(char name[][10], int kor[], int eng[], int mat[], int sci[], int sum[], int index) {
	int grade[10];									//석차 데이터 저장 배열

	system("cls");

	for (int i = 0; i < index; i++)					// 석차는 출력에서만 나타나므로 여기서 전부 1로 초기화
		grade[i] = 1;
	for (int i = 0; i < index; i++) {
		for (int j = 0; j < index; j++) {			// 자기보다 점수가 높은사람 수 만큼 
			if (sum[i] < sum[j])					// 더하면 올바른 석차가 된다는 점을 
				grade[i]++;							// 이용하여 석차계산
		}
	}
	printf("  이름   국어   영어    수학   과학   총점   평균   석차\n");
	printf("===================================================================\n");
	for (int i = 0; i < index + 1; i++) {
		for (int j = 0; j < index; j++) {
			if (i + 1 == grade[j])					// i를 1,2,3 순으로 증가시키면서 석차와 같으면 해당 순번(j)의 데이터 전부 출력
				printf("%s    %d    %d     %d    %d    %d    %d     %d\n", name[j], kor[j], eng[j], mat[j], sci[j], sum[j], sum[j] / 4, grade[j]);
		}
	}

	getch();			//출력한 화면을 보기위해 "아무키나 누르세요" 와 같은 기능
}
void src(char name[][10], int kor[], int eng[], int mat[], int sci[], int sum[], int index) {
	char i_name[10];

	system("cls");

	printf("조회할 이름>>");
	scanf("%s", i_name);						//조회할 이름 i_name에 입력

	for (int i = 0; i < index; i++) {			//i를 데이터(사람)의 수만큼 반복하여 
		if (!(strcmp(i_name, name[i]))) {		//name배열의 문자열과 입력받은 i_name의 문자열과 동일한지 확인
			printf("이름=%s\n", name[i]);		//만일 동일하다면
			printf("국어=%d\n", kor[i]);		//이름 국어 영어 수학 과학 출력
			printf("영어=%d\n", eng[i]);
			printf("수학=%d\n", mat[i]);
			printf("과학=%d\n", sci[i]);
		}
	}

	getch();
}

int sample(char name[][10], int kor[], int eng[], int mat[], int sci[], int sum[]) {

	strcpy(name[0], "홍길동");     // 여기서부터
	eng[0] = 60;
	kor[0] = 70;
	mat[0] = 80;
	sci[0] = 90;
	sum[0] = 300;
	strcpy(name[1], "임꺽정");
	eng[1] = 70;
	kor[1] = 75;
	mat[1] = 87;
	sci[1] = 60;
	sum[1] = 292;
	strcpy(name[2], "아무개");
	eng[2] = 54;
	kor[2] = 90;
	mat[2] = 100;
	sci[2] = 70;
	sum[2] = 314;

	return 3;
}
