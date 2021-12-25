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

	printf("두 문자열 입력 : ");
	scanf("%s %s", str1, str2);
	printf("바꾸기 전 : %s, %s\n", str1, str2);
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);
	printf("바꾼 후 : %s, %s\n", str1, str2);
	return 0;
}
*/


// 도전 실전 예제 - 대소문자 변환 프로그램


/*
int main() {

	char str[100];
	int ChangedNum = 0;

	printf("문장 입력 : ");
	gets(str);

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			str[i] = str[i] + 32;
			ChangedNum++;
		}

	}
	printf("바뀐 문장: ");
	puts(str);
	printf("바뀐 문자 수 : %d\n", ChangedNum);

	return 0;
}
*/


// 도전 실전 예제 - 미니 정렬 프로그램


/*
void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main() {

	double max, mid, min;

	printf("실수값 3개 입력 : ");
	scanf("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("정렬된 값 출력 : %.1lf, %.1lf, %.1lf\n", max, mid, min);

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


//--실습문제2--

// 1. 피라미드 출력
/*
int main() {

	int n = 0;

	printf("삼각형의 높이는? ==> ");
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


//섭씨 화씨 변환 함수

/*
int TransDegree(int nDegree, int nType);

int main() {

	int degree = 0;
	int type;

	printf("온도(N>0) : ");
	scanf("%d", &degree);
	printf("섭씨(0), 화씨(1) : ");
	scanf("%d", &type);

	int answer = TransDegree(degree, type);

	if (type == 0) {

		printf("섭씨 ==> 화씨 : %d\n",answer);
	}

	else {

		printf("화씨 ==> 섭씨 : %d\n",answer);

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

/* 각자리 숫자 반복횟수 출력 프로그램



int main() {

	unsigned int num = 0;

	int arr[10] = { 0 };
	int remainder = 0;


	printf("숫자 입력: ");
	scanf("%d", &num);


	do {

		remainder = num % 10;
		num = num / 10;
		arr[remainder]++;

	} while (num != 0);


	printf("숫자: %13d", 0);
	for (int i = 1; i < 10; i++) {

		printf("%3d", i);
	}
	printf("\n발생횟수: %9d", arr[0]);
	for (int i = 1; i < 10; i++) {

		printf("%3d",arr[i]);
	}

	return 0;
}*/

// 도전 실전 예제 - 로또 번호 생성 프로그램
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
			printf("번호 입력 : ");
			scanf("%d", lotto_nums + i);

			for (int j = 0; j < i; j++) {

				if (lotto_nums[i] == lotto_nums[j]) ForBreak = 1;
			}

			if (ForBreak == 0) break;
			else {
				printf("같은 번호가 있습니다.\n");
			}
		
		}
	}
}

void print_nums(int* lotto_nums) {

	printf("로또 번호 : ");
	for (int i = 0; i < 6; i++) {

		printf("%-3d",*(lotto_nums+i));
	}

}
*/

//실습문제 3

// 최솟값 출력 프로그램
/*
double ary_min(double* op, int size);

int main() {

	double ary[] = {1.5, 20.1, 16.4, 2.3, 3.5};
	
	double min = ary_min(ary, sizeof(ary) / sizeof(ary[0]));
	printf("배열의 최솟값 : %.1lf", min);

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


// 도전 실전 예제 - 길이가 가장 긴 단어 찾기

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

	printf("가장 긴 단어의 길이 : %d\n", max);

	return 0;
}
*/

// 문자열 입력받고 소문자,대문자,숫자개수 세는 프로그램


/*
void my_gets(char* str, int size);

int main() {

	char str[100];
	int s = 0;
	int b = 0;
	int num = 0;

	printf("문자열 : ");
	my_gets(str, 100);
	for (int i = 0; i < 100; i++) {

		if (str[i] >= 48 && str[i] <= 57) num++;
		if (str[i] >= 65 && str[i] <= 90) b++;
		if (str[i] >= 97 && str[i] <= 122) s++;

	}
	
	printf("\n소문자: %d\n", s);
	printf("대문자: %d\n", b);
	printf("숫자: %d\n", num);


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

//strcpy 함수 구현

/*
char* my_strcpy(char* pd, char* ps);

int main() {

	char str[80] = "strawberry";

	printf("바꾸기 전 문자열 : %s\n", str);
	my_strcpy(str, "apple");
	printf("바꾼 후 문자열 : %s\n", str);
	printf("다른 문자열 대입 : %s\n", my_strcpy(str, "kiwi"));


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


//strcat 함수 구현
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

// strlen 함수 구현
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

//strcmp 함수 구현
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

// 키보드로 입력한 길이가 5자를 넘는 경우 *출력 프로그램
/*
int main() {

	char str[16] = {0};

	printf("단어 입력 : ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';
	printf("입력한 단어 : %s", str);
	
	if (strlen(str) > 5) {

		for (unsigned int i = 5; i < strlen(str); i++) {

			str[i] = '*';
		}
	}
	printf(", 생략한 단어 : %s \n", str);


}

*/

// 도전 실전 예제 -- 단어 정렬 프로그램
/*
int main() {

	char str1[100] = {0};
	char str2[100] = {0};
	char str3[100] = {0};
	char temp[100] = {0};


	printf("세 단어 입력 : ");
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

//실습문제 4

/*
int main() {

	char arr[100] = {0};
	char invert[100] = {0};
	while (1) {
		printf("문자열: ");
		fgets(arr, sizeof(arr), stdin);
		if (arr[0] == 'x') break;
		arr[strlen(arr) - 1] = '\0';

		for (unsigned int i = 0; i < strlen(arr); i++) {

			invert[i] = arr[strlen(arr) - 1 - i];
		}


		printf("거꾸로: %s\n", invert);
	}
	return 0;
} 
*/

//도전 실전 예제 - 전역 변수 교환 프로그램
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

	printf("두 정수 입력 : ");
	scanf("%d%d", pa, pb);

}


void swap_data(void) {

	int temp = 0;

	temp = a;
	a = b;
	b = temp;
}

void print_data(int a, int b) {

	printf("두 정수 출력 : %d, %d\n", a, b);

}
*/

// 도전 실전 예제 - 가로 세로 합 구하기
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


//실습문제 5 문제 1

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

//도전 실전 예제 - 프로필 교환 프로그램


/*
void swap(char* str, void* pta, void* ptb);


int main() {

	int age1, age2;
	double height1, height2;

	printf("첫 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &age1, &height1);
	printf("두 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &age2, &height2);

	swap("int", &age1, &age2);
	swap("double", &height1, &height2);

	printf("첫 번째 사람의 나이와 키 : %d, %.1lf\n", age1, height1);
	printf("두 번째 사람의 나이와 키 : %d, %.1lf\n", age2, height2);

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
		printf("태양계 행성의 이름은? (영문입력, exit는 종료) ==> ");
		gets(temp);
		if (strcmp(temp, "exit") == 0) break;
		for (int i = 0; i < count; i++) {
			if (strcmp(temp, planet[i]) == 0) {
				printf("%s은(는) %d번째 행성입니다!\n",planet[i], i + 1);
				opt = 1;
				break;
			}

		}

		if (opt == 0) {
			printf("%s은(는) 태양계의 행성이 아닙니다!\n",temp);
		}


	}
} 
*/

/*
int main() {
	//생성
	int** matrix;

	int size = 4;
	int row = 5;

	matrix = (int**)malloc(size * sizeof(int*));

	if (matrix == NULL) {
		printf("메모리가 부족합니다.\n");
		exit(1);
	}

	for (int i = 0; i < row; i++) {

		matrix[i] = (int*)malloc(row * sizeof(int));
		if (matrix[i] == NULL) {
			printf("메모리가 부족합니다.\n");
			exit(1);
		}
	}
	//반환

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


//도전 실전 예제 - 소수 계산 프로그램


/*
int PrimeNumOrNot(int num);


int main() {

	int num = 0;
	int* ptr;
	int test = 0;

	printf("> 양수 입력 : ");
	scanf("%d", &num);

	ptr = (int*)malloc(num * sizeof(int));
	
	if (ptr == NULL) {
		printf("메모리가 부족합니다.\n");
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


//소수판별 함수
int PrimeNumOrNot(int num)  {

	
	for (int i = 2; i < num; i++) {
		if (num % i == 0) return 0; //소수아님

	}
	return 1; //소수임
}
*/

//실습문제 7

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
		printf("메모리가 부족합니다.\n");
		exit(1);
		}
	for (int i = 0; i < m; i++) {

		ptr[i] = (double*)malloc(n * sizeof(double));
		if (ptr[i] == NULL) {
			printf("메모리가 부족합니다.\n");
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

		printf("잘못 입력하였습니다.\n");
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
	printf("문장을 입력하시오 (종료하려면 라인의 첫문자로 엔터를 칠 것)...\n");
	while (getline(buf, MAX) != 0) // getline(): 한 라인을 읽어서 buf에 저장함
	{
		
		line[num] = (char*)malloc((strlen(buf) + 1)*sizeof(char)); // 빈 칸 채우기
		strcpy(line[num],buf); // 빈 칸 채우기
		num++;
	}




	printf("\n입력한 문장의 역순 출력 결과...\n");
	for (int i = 0; i < num; i++) // 빈 칸 채우기
	{		
		revline(line[i]); // revline(): 한 라인의 문장을 뒤집음
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