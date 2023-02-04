// ���Ϸ� ������ϱ�

// ���� ���� fopen()
// FILE *fopen(const char *name, const char *mode)

// ���� ���
// r : �б� ���� ���� ���� ������ NULL ��ȯ
// w : ���� ���� ���� ���� ���� ������ ����, ���� �����ϸ� ���� ���� ������
// a : ���� ���� ���� ���� ������ ������

// ���� ����� �Լ�
// int fgetc(FILE *fp) : ���Ϸκ��� �ϳ��� ���� �о ��ȯ, ���� ���� �����ϰų� ���� �߻��ϸ� EOF ��ȯ
// int fputc(int c, FILE *fp) : ���Ͽ� �ϳ��� ���ڸ� ���� �Լ�, ���ڴ� ������ ��ġǥ���ڰ� ����Ű�� ��ġ�� �ۼ��Ǹ� ���� ��ġ ǥ���ڰ� ������
// char fgets(char *s, int n, FILE *fp) : ���Ϸκ��� ���ڿ� �о s�� ����Ű�� ��ġ�� ����, �ϳ��� ���� ������ ������, n-1���� ���ڵ��� ������ ����
// int fputs(const char *s, FILE *fp) : ���Ͽ� s�� ����Ű�� ���ڿ� ����
// int fscanf(FILE *fp, "%d %s", &int_value, str_name), int fprintf(FILE *fp, "%d %s", &int_value, str_name)

// ���� �����ϱ�
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
		printf("���� ���� ����\n");
		return 1;
	}

	while ((fgets(line, 100, fp)) != NULL)
		puts(line, fp2);

	fclose(fp);
	return 0;
}
*/

// ������ �޸� ���α׷� �����
/*
#include <stdio.h>

int main()
{
	int c;
	FILE* fp;
	fp = fopen("memo.txt", "a");

	if (fp == NULL)
	{
		printf("���� ���� ����\n");
		return 1;
	}

	while ((c = getchar()) != EOF)
		fputc(c, fp);

	return 0;
}
*/

// fprintf() ����
/*
#include <stdio.h>

int main()
{
	FILE* fp;

	int number = 20;
	double grade = 4.3;
	char name[] = "ȫ�浿";
	char fname[100]; // ���� �̸��� ���� ���ϴ� ��� �Ϸ��� �ʿ��� ����

	printf("���� �̸� �Է� : ");
	scanf("%s",fname);

	// fp = fopen("sample.txt", "w");
	fp = fopen(fname, "w");

	if (fp == NULL)
	{
		printf("���� ���� ����\n");
		return 1;
	}

	fprintf(fp, "%s\n", name);
	fprintf(fp, "%d\n", number);
	fprintf(fp, "%f\n", grade);

	// fopen���� ������ ���Ͻ�Ʈ���� fprintf�� �μ��� ���
	// fprintf(stdout, "%s\n", name);
	// fprintf(stdout, "%d\n", number);
	// fprintf(stdout, "%f\n", grade);

	fclose(fp);
}
*/

// fscanf() ����
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
		printf("���� ���� ����\n");
		return 1;
	}

	fscanf(fp, "%s", name);
	fscanf(fp, "%d", &number);
	fscanf(fp, "%lf", &grade);

	// fopen���� ������ ���Ͻ�Ʈ���� fprintf�� �μ��� ���
	fprintf(stdout, "%s\n", name);
	fprintf(stdout, "%d\n", number);
	fprintf(stdout, "%f\n", grade);

	fclose(fp);
}
*/

// ����Ʈ ǥ�� ���� �ڵ�
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
	printf("����Ʈ #1 ���� �̸�: ");
	scanf("%s", filename1);
	printf("����Ʈ #2 ���� �̸�: ");
	scanf("%s", filename2);
	file1 = fopen(filename1, "r");
	file2 = fopen(filename2, "r");
	if (file1 == NULL || file2 == NULL) {
		printf("���� ���� ���� \n");
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
		printf("2���� ����Ʈ�� �����մϴ�. \n");
	else
		printf("2���� ����Ʈ�� �ٸ��ϴ�. \n");

	fclose(file1);
	fclose(file2);
	return 0;
}
*/