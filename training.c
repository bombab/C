#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
int main() {

	int A[3] = {1, 2, 3};
	int B[10];
	int i;
	for (i = 0; i < sizeof(B) / sizeof(B[0]); i++) {
		B[i] = A[i % 3];
	}

	for (i = 0; i < sizeof(B) / sizeof(B[0]); i++) {
		printf("%d ", B[i]);
	}

	return 0;
}
*/

/*
int main() {

	char str1[80], str2[80];
	char temp[80];
	printf("�� ���ڿ� �Է� : ");
	scanf("%s %s", str1, str2);
	printf("�ٲٱ� �� : %s, %s\n", str1, str2);
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	printf("�ٲ� �� : %s, %s\n", str1, str2);
	return 0;
}
*/


// ���� ���� ���� - ��ҹ��� ��ȯ ���α׷�


/*
int main() {
	char str[100];
	int ChangedNum = 0;
	printf("���� �Է� : ");
	gets(str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			str[i] = str[i] + 32;
			ChangedNum++;
		}
	}
	printf("�ٲ� ����: ");
	puts(str);
	printf("�ٲ� ���� �� : %d\n", ChangedNum);
	return 0;
}
*/


// ���� ���� ���� - �̴� ���� ���α׷�


/*
void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);
int main() {
	double max, mid, min;
	printf("�Ǽ��� 3�� �Է� : ");
	scanf("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("���ĵ� �� ��� : %.1lf, %.1lf, %.1lf\n", max, mid, min);
	return 0;
}
void swap(double* pa, double* pb)
{
	double temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}
void line_up(double *pta, double *ptb, double *ptc)
{
	if (*pta < *ptb) swap(pta, ptb);
	if (*pta < *ptc) swap(pta, ptc);
	if (*ptb < *ptc) swap(ptb, ptc);
}
*/


//--�ǽ�����2--

// 1. �Ƕ�̵� ���
/*
int main() {
	int n = 0;
	printf("�ﰢ���� ���̴�? ==> ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 -i; j++  ) {
			printf(" ");
		}
		for (int j = 0; j < i * 2 + 1;j ++) {
			printf("#");
		}
		printf("\n");
	}
	return 0;
}
*/


//���� ȭ�� ��ȯ �Լ�

/*
int TransDegree(int nDegree, int nType);
int main() {
	int degree = 0;
	int type;
	printf("�µ�(N>0) : ");
	scanf("%d", &degree);
	printf("����(0), ȭ��(1) : ");
	scanf("%d", &type);
	int answer = TransDegree(degree, type);
	if (type == 0) {
		printf("���� ==> ȭ�� : %d\n",answer);
	}
	else {
		printf("ȭ�� ==> ���� : %d\n",answer);
	}
	return 0;
}
int TransDegree(int nDegree, int nType) {
	if (nType == 0) {
		return nDegree * 9 / 5 + 32;3
	}
	else {
		return (nDegree - 32) * 5 / 9;
	}
}*/

/* ���ڸ� ���� �ݺ�Ƚ�� ��� ���α׷�
int main() {
	unsigned int num = 0;
	int arr[10] = { 0 };
	int remainder = 0;
	printf("���� �Է�: ");
	scanf("%d", &num);
	do {
		remainder = num % 10;
		num = num / 10;
		arr[remainder]++;
	} while (num != 0);
	printf("����: %13d", 0);
	for (int i = 1; i < 10; i++) {
		printf("%3d", i);
	}
	printf("\n�߻�Ƚ��: %9d", arr[0]);
	for (int i = 1; i < 10; i++) {
		printf("%3d",arr[i]);
	}
	return 0;
}*/

// ���� ���� ���� - �ζ� ��ȣ ���� ���α׷�
/*
void input_nums(int* lotto_nums);
void print_nums(int* lotto_nums);
int main() {
	int lotto_nums[6];
	input_nums(lotto_nums);
	print_nums(lotto_nums);

	return 0;
}
void input_nums(int* lotto_nums) {
	for (int i = 0; i < 6; i++) {
		while (1) {
			int ForBreak = 0;
			printf("��ȣ �Է� : ");
			scanf("%d", lotto_nums + i);
			for (int j = 0; j < i; j++) {
				if (lotto_nums[i] == lotto_nums[j]) ForBreak = 1;
			}
			if (ForBreak == 0) break;
			else {
				printf("���� ��ȣ�� �ֽ��ϴ�.\n");
			}

		}
	}
}
void print_nums(int* lotto_nums) {
	printf("�ζ� ��ȣ : ");
	for (int i = 0; i < 6; i++) {
		printf("%-3d",*(lotto_nums+i));
	}
}
*/

//�ǽ����� 3

// �ּڰ� ��� ���α׷�
/*
double ary_min(double* op, int size);
int main() {
	double ary[] = {1.5, 20.1, 16.4, 2.3, 3.5};

	double min = ary_min(ary, sizeof(ary) / sizeof(ary[0]));
	printf("�迭�� �ּڰ� : %.1lf", min);
	return 0;
}
double ary_min(double* op, int size) {
	double min = op[0];
	for (int i = 1; i < size; i++) {
		if (op[i] < min) min = op[i];
	}
	return min;
}
*/


// ���� ���� ���� - ���̰� ���� �� �ܾ� ã��

/*
int main() {
	int max = 0;

	while (1) {
		int num = 0;
		int res = 0;
		res = getchar();
		if (res == EOF) break;
		num++;
		while (getchar() != '\n') {
			num++;
		}
		if (max < num) max = num;
	}
	printf("���� �� �ܾ��� ���� : %d\n", max);
	return 0;
}
*/

// ���ڿ� �Է¹ް� �ҹ���,�빮��,���ڰ��� ���� ���α׷�


/*
void my_gets(char* str, int size);
int main() {
	char str[100];
	int s = 0;
	int b = 0;
	int num = 0;
	printf("���ڿ� : ");
	my_gets(str, 100);
	for (int i = 0; i < 100; i++) {
		if (str[i] >= 48 && str[i] <= 57) num++;
		if (str[i] >= 65 && str[i] <= 90) b++;
		if (str[i] >= 97 && str[i] <= 122) s++;
	}

	printf("\n�ҹ���: %d\n", s);
	printf("�빮��: %d\n", b);
	printf("����: %d\n", num);
	return 0;
}
void my_gets(char* str, int size) {
	int ch;

	int i = 0;
	ch = getchar();
	while ((ch != '\n') && (i < size - 1)) {
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\0';
} */

//strcpy �Լ� ����

/*
char* my_strcpy(char* pd, char* ps);
int main() {
	char str[80] = "strawberry";
	printf("�ٲٱ� �� ���ڿ� : %s\n", str);
	my_strcpy(str, "apple");
	printf("�ٲ� �� ���ڿ� : %s\n", str);
	printf("�ٸ� ���ڿ� ���� : %s\n", my_strcpy(str, "kiwi"));
	return 0;
}
char* my_strcpy(char* pd, char* ps) {
	char* po = pd;
	while (*ps != '\0') {
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = *ps;
	return po;
}
*/


//strcat �Լ� ����
/*
char* my_strcat(char* pd, char* ps) {
	char* po = pd;
	while (*pd != '\0') {
		pd++;
	}
	while (*ps != '\0') {
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
	return po;
}*/

// strlen �Լ� ����
/*
int my_strlen(char* ps) {
	int len = 0;
	while (*ps != '\0') {
		len++;
		ps++;
	}
	return len;
}
*/

//strcmp �Լ� ����
/*
int my_strcmp(char* pa, char* pb) {

	while (*pa == *pb && *pa != '\0') {
		pa++;
		pb++;
	}
	if (*pa > *pb) return -1;
	else if (*pa < *pb) return 1;
	else return 0;
}
*/

// Ű����� �Է��� ���̰� 5�ڸ� �Ѵ� ��� *��� ���α׷�
/*
int main() {
	char str[16] = {0};
	printf("�ܾ� �Է� : ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';
	printf("�Է��� �ܾ� : %s", str);

	if (strlen(str) > 5) {
		for (unsigned int i = 5; i < strlen(str); i++) {
			str[i] = '*';
		}
	}
	printf(", ������ �ܾ� : %s \n", str);
}
*/

// ���� ���� ���� -- �ܾ� ���� ���α׷�
/*
int main() {
	char str1[100] = {0};
	char str2[100] = {0};
	char str3[100] = {0};
	char temp[100] = {0};
	printf("�� �ܾ� �Է� : ");
	scanf("%s%s%s", str1, str2, str3);
	if (strcmp(str1, str2) == 1) {
		strcpy(temp, str1);
		strcpy(str1, str2);
		strcpy(str2, temp);
	}
	if (strcmp(str1, str3) == 1) {
		strcpy(temp, str1);
		strcpy(str1, str3);
		strcpy(str3, temp);
	}
	if (strcmp(str2, str3) == 1) {
		strcpy(temp, str2);
		strcpy(str2, str3);
		strcpy(str3, temp);
	}
	printf("%s, %s, %s\n",str1,str2,str3);
	return 0;
}
*/

//�ǽ����� 4

/*
int main() {
	char arr[100] = {0};
	char invert[100] = {0};
	while (1) {
		printf("���ڿ�: ");
		fgets(arr, sizeof(arr), stdin);
		if (arr[0] == 'x') break;
		arr[strlen(arr) - 1] = '\0';
		for (unsigned int i = 0; i < strlen(arr); i++) {
			invert[i] = arr[strlen(arr) - 1 - i];
		}
		printf("�Ųٷ�: %s\n", invert);
	}
	return 0;
}
*/

//���� ���� ���� - ���� ���� ��ȯ ���α׷�
/*
void input_data(int* pa, int* pb);
void swap_data(void);
void print_data(int a, int b);
int a, b;
int main() {
	input_data(&a, &b);
	swap_data();
	print_data(a, b);
	return 0;
}
void input_data(int* pa, int* pb) {
	printf("�� ���� �Է� : ");
	scanf("%d%d", pa, pb);
}
void swap_data(void) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}
void print_data(int a, int b) {
	printf("�� ���� ��� : %d, %d\n", a, b);
}
*/

// ���� ���� ���� - ���� ���� �� ���ϱ�
/*
int main() {
	int arr[5][6] = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20}
	};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][5] += arr[i][j];
			arr[4][j] += arr[i][j];
			arr[4][5] += arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
*/


//�ǽ����� 5 ���� 1

/*
int main() {
	char arr[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j || i + j == 4) {
				arr[i][j] = 'X';
			}
			else arr[i][j] = 'O';
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/

//���� ���� ���� - ������ ��ȯ ���α׷�


/*
void swap(char* str, void* pta, void* ptb);
int main() {
	int age1, age2;
	double height1, height2;
	printf("ù ��° ����� ���̿� Ű �Է� : ");
	scanf("%d %lf", &age1, &height1);
	printf("�� ��° ����� ���̿� Ű �Է� : ");
	scanf("%d %lf", &age2, &height2);
	swap("int", &age1, &age2);
	swap("double", &height1, &height2);
	printf("ù ��° ����� ���̿� Ű : %d, %.1lf\n", age1, height1);
	printf("�� ��° ����� ���̿� Ű : %d, %.1lf\n", age2, height2);
	return 0;
}
void swap(char* str, void* pta, void* ptb) {
	if (strcmp(str, "int") == 0) {
		int temp;
		temp = *(int*)pta;
		*(int*)pta = *(int*)ptb;
		*(int*)ptb = temp;
	}
	else if (strcmp(str, "double") == 0) {
		double temp;
		temp = *(double*)pta;
		*(double*)pta = *(double*)ptb;
		*(double*)ptb = temp;
	}
}
*/


/*
void search_planet(char** planet, int count);
int main() {
	char* planets[] = {
		"Mercury","Venus", "Earth",
		"Mars", "Jupiter", "Saturn",
		"Uranus", "Neptune", "Pluto"
	};
	int count = sizeof(planets) / sizeof(planets[0]);
	search_planet(planets, count);
	return 0;
}
void search_planet(char** planet, int count) {

	while (1) {
		char temp[20] = { 0 };
		int opt = 0;
		printf("�¾�� �༺�� �̸���? (�����Է�, exit�� ����) ==> ");
		gets(temp);
		if (strcmp(temp, "exit") == 0) break;
		for (int i = 0; i < count; i++) {
			if (strcmp(temp, planet[i]) == 0) {
				printf("%s��(��) %d��° �༺�Դϴ�!\n",planet[i], i + 1);
				opt = 1;
				break;
			}
		}
		if (opt == 0) {
			printf("%s��(��) �¾���� �༺�� �ƴմϴ�!\n",temp);
		}
	}
}
*/

/*
int main() {
	//����
	int** matrix;
	int size = 4;
	int row = 5;
	matrix = (int**)malloc(size * sizeof(int*));
	if (matrix == NULL) {
		printf("�޸𸮰� �����մϴ�.\n");
		exit(1);
	}
	for (int i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(row * sizeof(int));
		if (matrix[i] == NULL) {
			printf("�޸𸮰� �����մϴ�.\n");
			exit(1);
		}
	}
	//��ȯ
	for (int i = 0; i < row; i++) {
		free(matrix[i]);
	}
	free(matrix);
	return 0;
}
*/

/*
int main(int argc, char** argv) {
	int i;
	for (i = 0; i < argc - 1; i++) {
		printf("%s\n", argv[i + 1]);
	}
}
*/


//���� ���� ���� - �Ҽ� ��� ���α׷�


/*
int PrimeNumOrNot(int num);
int main() {
	int num = 0;
	int* ptr;
	int test = 0;
	printf("> ��� �Է� : ");
	scanf("%d", &num);
	ptr = (int*)malloc(num * sizeof(int));

	if (ptr == NULL) {
		printf("�޸𸮰� �����մϴ�.\n");
		exit(1);
	}
	for (int i = 2; i < num; i++) {
		test = PrimeNumOrNot(i);
		if (test == 1) {
			ptr[i - 1] = i;
			printf("%5d", ptr[i-1]);
		}
		else
		{
			ptr[i - 1] = 'X';
			printf("%5c", ptr[i - 1]);
		}
		if (i % 5 == 1) printf("\n");
	}

	free(ptr);
	return 0;
}
//�Ҽ��Ǻ� �Լ�
int PrimeNumOrNot(int num)  {

	for (int i = 2; i < num; i++) {
		if (num % i == 0) return 0; //�Ҽ��ƴ�
	}
	return 1; //�Ҽ���
}
*/

//�ǽ����� 7

/*
void fill_array(double** ptr, int row, int column);
void print_array(double** ptr, int row, int column);
int main() {
	int m = 0, n = 0;
	double** ptr;
	printf("Enter M, N: ");
	scanf("%d%d", &m, &n);
	ptr = (double**)malloc(m * sizeof(double*));
		if (ptr == NULL) {
		printf("�޸𸮰� �����մϴ�.\n");
		exit(1);
		}
	for (int i = 0; i < m; i++) {
		ptr[i] = (double*)malloc(n * sizeof(double));
		if (ptr[i] == NULL) {
			printf("�޸𸮰� �����մϴ�.\n");
			exit(1);
			}
		}
	fill_array(ptr, m, n);
	print_array(ptr, m, n);
	for (int i = 0; i < m; i++) {
		free(ptr[i]);
	}
	free(ptr);
	return 0;
}
void fill_array(double** ptr, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			ptr[i][j] = (i + 1) * (j + 1);
		}
	}
}
void print_array(double** ptr, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%5.1lf", ptr[i][j]);
		}
		printf("\n");
	}
}
*/

/*
int main(int argc, char** argv) {
	int len = (int)strlen(argv[2]);
	if (strcmp(argv[1], "-p") == 0) {
		printf("-p : %s\n", argv[2]);
	}
	else if (strcmp(argv[1], "-u") == 0) {

		printf("-u : ");
		for (int i = 0; i < len; i++) {
			printf("%c", toupper(argv[2][i]));
		}


	}

	else if (strcmp(argv[1], "-l") == 0) {

		printf("-l : ");
		for (int i = 0; i < len; i++) {
			printf("%c", tolower(argv[2][i]));
		}

	}
	else {
		printf("�߸� �Է��Ͽ����ϴ�.\n");
		exit(1);
	}
	return 0;
}
*/


/*
#define MAX 100
#define LINE 10
int getline(char* pt, int max);
void revline(char* pt);
int main(void)
{
	char* line[10];
	char buf[100];
	int num = 0;
	printf("������ �Է��Ͻÿ� (�����Ϸ��� ������ ù���ڷ� ���͸� ĥ ��)...\n");
	while (getline(buf, MAX) != 0) // getline(): �� ������ �о buf�� ������
	{

		line[num] = (char*)malloc((strlen(buf) + 1)*sizeof(char)); // �� ĭ ä���
		strcpy(line[num],buf); // �� ĭ ä���
		num++;
	}
	printf("\n�Է��� ������ ���� ��� ���...\n");
	for (int i = 0; i < num; i++) // �� ĭ ä���
	{
		revline(line[i]); // revline(): �� ������ ������ ������
		printf("%s\n", line[i]);
	}
	return 0;
}
int getline(char* pt, int max) {
	fgets(pt,sizeof(char)*max,stdin);
	if (pt[0] == '\n') return 0;
	else {
		pt[strlen(pt) - 1] = '\0';
		return 1;
	}
}
void revline(char* pt) {
	int strnum = strlen(pt);
	char temp;
	for (int i = 0; i < strnum / 2; i++) {
		temp = pt[i];
		pt[i] = pt[strnum - i - 1];
		pt[strnum - i - 1] = temp;
	}
}
*/

/*
struct marriage
{
	char name[20];
	int age;
	char sex;
	double height;
};
struct marriage m1 = { "Andy",22,'m',187.5 };
struct marriage* mp = &m1;
int main() {
	printf("�̸� : %s\n", mp->name);
	printf("���� : %d\n", mp->age);
	printf("���� : %c\n", mp->sex);
	printf("Ű : %.1lf\n", mp->height);
	return 0;
}
*/

/*
typedef struct train Train;
struct train
{
	int seats;
	Train* next;
};
int main() {
	Train* head = NULL, * tail = NULL;
	int i;
	for (i = 0; i < 5; i++) {
		if (head == NULL)
		{
			head = tail = (Train*)malloc(sizeof(Train));
		}
		else
		{
			tail->next = (Train*)malloc(sizeof(Train));
			tail = tail->next;
		}
	}
	return 0;
}
*/


// ���� ���� ���� - ���� ó�� ���α׷�


/*
typedef struct {
	int stnum;
	char name[20];
	int kor;
	int eng;
	int math;
	int total;
	double ave;
	char score;
} Score;
void SortArray(Score* pt);
int main() {
	Score student[5];
	Score* pt = student;
	for (int i = 0; i < sizeof(student)/sizeof(student[0]); i++) {
		printf("�й� : ");
		scanf("%d", &pt[i].stnum);
		printf("�̸� : ");
		scanf("%s", pt[i].name);
		printf("����, ����, ���� ���� : ");
		scanf("%d%d%d", &pt[i].kor, &pt[i].eng, &pt[i].math);
		(pt + i)->total = (pt + i)->kor + (pt + i)->eng + (pt + i)->math;
		(pt + i)->ave = (double)(pt + i)->total / 3;
		if ((pt + i)->ave >= 90) {
			(pt + i)->score = 'A';
		}
		else if ((pt + i)->ave >= 80) {
			(pt + i)->score = 'B';
		}
		else if ((pt + i)->ave >= 70) {
			(pt + i)->score = 'C';
		}
		else {
			(pt + i)->score = 'F';
		}
	}
	printf("# ���� �� ������...\n");
	for (int i = 0; i < sizeof(student) / sizeof(student[0]); i++) {
		printf("%6d%5s%5d%5d%5d%5d%6.1lf%5c\n", pt[i].stnum, pt[i].name,
			pt[i].kor, pt[i].eng, pt[i].math,
			pt[i].total, pt[i].ave, pt[i].score);
	}

	printf("# ���� �� ������...\n");
	SortArray(pt);
	for (int i = 0; i < sizeof(student) / sizeof(student[0]); i++) {
		printf("%6d%5s%5d%5d%5d%5d%6.1lf%5c\n", pt[i].stnum, pt[i].name,
			pt[i].kor, pt[i].eng, pt[i].math,
			pt[i].total, pt[i].ave, pt[i].score);
	}
	return 0;
}
void SortArray(Score* pt) {
	for (int i = 0; i < 4; i++) {
		Score* max = &pt[i];
		for (int j = i+1; j < 5; j++) {
			if (max->total < pt[j].total) {
				max = pt + j;
			}
		}
		Score temp = pt[i];
		pt[i] = *max;
		*max = temp;
	}
}
*/


// �ǽ����� 8
/*
struct profile {
	char name[20];
	double grade;
	int english;
};
void input_data(struct profile*); //����ü ������ ������ �Է�
void elite(struct profile*); // ����ư ����� ����ϴ� �Լ� ����
int main() {
	struct profile new_staff[5];
	input_data(new_staff);
	elite(new_staff);
	return 0;
}
void input_data(struct profile* pt) {
	printf("�̸�, ����, ���� ������ �Է��ϼ���.\n");
	for (int i = 0; i < 5; i++) {
		scanf("%s%lf%d", pt[i].name, &pt[i].grade, &pt[i].english);
	}
}
void elite(struct profile *pt) {
	printf("-------elite ��� ��� ------\n");
	for (int i = 0; i < 5; i++) {
		if (pt[i].grade >= 4.0 && pt[i].english >= 900) {
			printf("%s, %.1lf, %d\n",pt[i].name,pt[i].grade,pt[i].english);
		}
	}
}
*/

/*
typedef struct train Train;
struct train
{
	int number;
	int seat;
	Train* next;
};
void print_train(Train* pt);
int main() {
	Train* head = NULL, * tail = NULL;
	int i;
	int train_seats[5] = { 20,40,40,40,30 };
	for (i = 0; i < 5; i++) {

		if (head == NULL) {
			head = tail = (Train*)malloc(sizeof(Train));
			if (head == NULL) {
				printf("�޸𸮰� �����մϴ�!!\n");
				exit(1);
			}
			head->number = i + 1; //������ȣ�� 1���� ����
			head->seat = train_seats[i];
		}
		else {
			tail->next = (Train*)malloc(sizeof(Train));
			if (tail->next == NULL) {
				printf("�޸𸮰� �����մϴ�!!\n");
				exit(1);
			}
			tail = tail->next;
			tail->number = i + 1;
			tail->seat = train_seats[i];
			tail->next = NULL;
		}
	}
	print_train(head);
	return 0;
}
void print_train(Train* tp) {
	for (int i = 0; i < 4; i++) {
		printf("[%d������,�¼���:%d]->", i + 1, tp->seat);
		tp = tp->next;
	}
	printf("[5������,�¼���:%d)]\n",tp->seat);
}
*/

// ���� ���� ���� - �ܾ� ���� ���α׷�


/*
int main() {

	FILE* afp, * bfp, * cfp;
	char astr[22];
	char bstr[22];
	int num;

	afp = fopen("a.txt", "r");
	
	if (afp == NULL) {
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	bfp = fopen("b.txt", "w+");

	if (bfp == NULL) {
		printf("����� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	cfp = fopen("c.txt", "w");

	if (cfp == NULL) {
		printf("����� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}


	// b.txt�� �ִ� 10���� ���� �Է�
	for (num = 0; num < 10; num++) { 
		fgets(bstr, sizeof(bstr), stdin);

		if (strcmp(bstr, "end") == 0) { //���� �Է��� �׸��ϰ� ���� ���
			break; 
		}
		fputs(bstr, bfp);

	}

	// a.txt ��� �ܾ�� b.txt �Է´ܾ ���Ͽ� b.txt���� �ִ� �ܾ ����
	fseek(bfp, 0, SEEK_SET);
	for(int i = 0; i < num; i ++) {

		int pivot = 0;

		fgets(bstr, sizeof(bstr), bfp);
		while (1) {
			fgets(astr, sizeof(astr), afp);
			if (strcmp(bstr, astr) == 0) {
				pivot = 1;
				break;
			}
			if (feof(afp)) { 
				fseek(afp, 0, SEEK_SET);
				break; 
			}
		}

		// b.txt���� �����ϴ� �ܾ��ϰ�� c�� �Է�
		if (pivot == 0) {
			fputs(bstr, cfp);
		}

	}


	fclose(afp);
	fclose(bfp);
	fclose(cfp);
	return 0;
}
*/

//�ǽ����� 9

/*
int main() {

	FILE* ifp, * ofp;
	char c;
	int byte_num = 0;

	ifp = fopen("C:\\Windows\\system.ini", "r");
	if (ifp == NULL) {
		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	ofp = fopen("C:\\Temp\\system_ini.txt", "w");
	if (ofp == NULL) {
		printf("��� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	while (1) {

		c = fgetc(ifp);
		if (c == EOF) {
			break;
		}
		byte_num++;
		fputc(c, ofp);
	}
	printf("���� ����Ʈ ���� %d �Դϴ�!\n",byte_num);
	fclose(ifp);
	fclose(ofp);

	return 0;
}
*/

/*
int main() {

	char stnum[20];
	int eng;
	int math;
	int phy;
	int prog;

	FILE* ifp, * ofp;
	ifp = fopen("prob2_data.txt", "r");
	if (ifp == NULL) {

		printf("�Է� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	ofp = fopen("prob2_output.txt", "w");
	if (ofp == NULL) {

		printf("��� ������ ���� ���߽��ϴ�.\n");
		return 1;
	}

	printf("%8s%8s\n", "�й�", "���");
	fprintf(ofp, "%8s%8s\n", "�й�", "���");

	while (1) {
		int res;
		res = fscanf(ifp, "%s%d%d%d%d", stnum, &eng, &math, &phy, &prog);
		if (res == EOF) break;

		int mean;

		mean = (eng + math + phy + prog) / 4;
		printf("%s : %d\n", stnum, mean);
		fprintf(ofp,"%s : %d\n", stnum, mean);
	}

	fclose(ifp);
	fclose(ofp);

	return 0;
}*/

// ���� ���� ���� - ��Ģ���� ���� ���α׷�
/*
#define SUM(a,b) ((a) + (b))
#define SUB(a,b) ((a) - (b))
#define MUL(a,b) ((a) * (b))
#define DIV(a,b) ((a) / (b))
#define SCANF_PRINT(a,s,b) scanf("%d %c %d",&a,&s,&b)



int main() {

	int a = 0;
	int b = 0;
	int res = 0;
	char s;
	

	while (1) {

		printf("���� �Է�(���� Ctrl+Z) :");
		res = SCANF_PRINT(a, s, b);
		if (res == EOF) break;

		switch (s)
		{
		case '+':
			printf("%d %c %d = %d\n", a, s, b, SUM(a, b));
			break;

		case '-':

			printf("%d %c %d = %d\n", a, s, b, SUB(a, b));
			break;

		case '*':

			printf("%d %c %d = %d\n", a, s, b, MUL(a, b));
			break;

		case '/':

			printf("%d %c %d = %d\n", a, s, b, DIV(a, b));

		}
	}
	return 0;
}*/

// �ǽ����� 10

/*
#define DEBUG(num) printf("%d��(��) ���ϴ� ��..\n", num);

double calc_array_avg(int* a, int size);

int main(void) {

	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	double avg = calc_array_avg(a, 10);

	printf("�迭�� ��� : %.1lf\n", avg);

	return 0;
}


double calc_array_avg(int* a, int size)
{
	double sum = 0;

	printf("start of calc_array_avg() ...\n");

	for (int i = 0; i < size; i++) {

		printf("%d ", i + 1);
	}
	printf("\n");


	for (int i = 0; i < size; i++) {
		DEBUG(i + 1);
		sum += a[i];
	}

	double avg = sum / size;
	printf("���=%.1lf\n", avg);
	printf("end of calc_array_avg() ...\n");


	return avg;
}
*/


/*
#include <stdio.h>
#include "array.h"

int main(void)

{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	print_array(a, 10);

	int sum = get_sum_of_array(a, 10);
	printf("�迭 ��� ���� �� : %d\n", sum);

	return 0;

}
*/

