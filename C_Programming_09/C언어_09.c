// 파일로 입출력하기

// 파일 열기 fopen()
// FILE *fopen(const char *name, const char *mode)

// 파일 모드
// r : 읽기 모드로 파일 열고 없으면 NULL 반환
// w : 쓰기 모드로 파일 열고 파일 없으면 생성, 파일 존재하면 기존 내용 지워짐
// a : 파일 끝에 쓰고 파일 없으면 생성됨

// 파일 입출력 함수
// int fgetc(FILE *fp) : 파일로부터 하나의 문자 읽어서 반환, 파일 끝에 도달하거나 오류 발생하면 EOF 반환
// int fputc(int c, FILE *fp) : 파일에 하나의 문자를 쓰는 함수, 문자는 파일의 위치표시자가 가리키는 위치에 작성되며 파일 위치 표시자가 증가함
// char fgets(char *s, int n, FILE *fp) : 파일로부터 문자열 읽어서 s가 가리키는 위치에 저장, 하나의 줄이 완전히 읽히거, n-1개의 문자들이 읽히면 종료
// int fputs(const char *s, FILE *fp) : 파일에 s가 가리키는 문자열 저장
// int fscanf(FILE *fp, "%d %s", &int_value, str_name), int fprintf(FILE *fp, "%d %s", &int_value, str_name)

// 파일 복사하기
/*
#include <stdio.h>

int main()
{
	char line[100];
	FILE* fp1;
	FILE* fp2;
	fp1 = fopen("sample.txt", "r");
	fp2 = fopen("sample_cpy.txt", "w");

	if (fp1 == NULL//fp2 == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	while ((fgets(line, 100, fp)) != NULL)
		puts(line, fp2);

	fclose(fp);
	return 0;
}
*/

// 간단한 메모 프로그램 만들기
/*
#include <stdio.h>

int main()
{
	int c;
	FILE* fp;
	fp = fopen("memo.txt", "a");

	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	while ((c = getchar()) != EOF)
		fputc(c, fp);

	return 0;
}
*/

// fprintf() 예제
/*
#include <stdio.h>

int main()
{
	FILE* fp;

	int number = 20;
	double grade = 4.3;
	char name[] = "홍길동";
	char fname[100]; // 파일 이름을 내가 원하는 대로 하려면 필요한 변수

	printf("파일 이름 입력 : ");
	scanf("%s",fname);

	// fp = fopen("sample.txt", "w");
	fp = fopen(fname, "w");

	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	fprintf(fp, "%s\n", name);
	fprintf(fp, "%d\n", number);
	fprintf(fp, "%f\n", grade);

	// fopen으로 생성한 파일스트림을 fprintf으 인수로 사용
	// fprintf(stdout, "%s\n", name);
	// fprintf(stdout, "%d\n", number);
	// fprintf(stdout, "%f\n", grade);

	fclose(fp);
}
*/

// fscanf() 예제
/*
#include <stdio.h>

int main()
{
	FILE* fp;

	int number = 20;
	double grade = 4.3;
	char name[100]; 

	fp = fopen("sample.txt", "r");

	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	fscanf(fp, "%s", name);
	fscanf(fp, "%d", &number);
	fscanf(fp, "%lf", &grade);

	// fopen으로 생성한 파일스트림을 fprintf으 인수로 사용
	fprintf(stdout, "%s\n", name);
	fprintf(stdout, "%d\n", number);
	fprintf(stdout, "%f\n", grade);

	fclose(fp);
}
*/

// 리포트 표절 적발 코드
/*
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000
int main(void)
{
	FILE* file1, * file2;
	char filename1[100], filename2[100];
	char buffer1[MAX_SIZE],
		buffer2[MAX_SIZE];
	char* p1, * p2;
	int copy = 1;
	printf("리포트 #1 파일 이름: ");
	scanf("%s", filename1);
	printf("리포트 #2 파일 이름: ");
	scanf("%s", filename2);
	file1 = fopen(filename1, "r");
	file2 = fopen(filename2, "r");
	if (file1 == NULL || file2 == NULL) {
		printf("파일 열기 오류 \n");
		return 1;
	}
	while (1) {
		p1 = fgets(buffer1, MAX_SIZE, file1);
		p2 = fgets(buffer2, MAX_SIZE, file2);
		if (p1 == NULL && p2 == NULL)
			break;
		if (p1 == NULL || p2 == NULL) {
			copy = 0;
			break;
		}
		if (strcmp(buffer1, buffer2) != 0) {
			copy = 0;
			break;
		}
	}
	if (copy == 1)
		printf("2개의 리포트는 동일합니다. \n");
	else
		printf("2개의 리포트는 다릅니다. \n");

	fclose(file1);
	fclose(file2);
	return 0;
}
*/