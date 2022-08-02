#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//Quiz

/*
typedef struct {

	int x;
	int y;

} Point;


double get_distance(Point p1, Point p2) {

	double distance;
	distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	return distance;
}

int main() {

	Point p1 = { 1, 2 };
	Point p2 = { 9, 8};

	return 0;
}
*/


// 예제 3.2 다항식 덧셈 프로그램 1
/*
#define MAX(a,b) (((a)>(b))? (a): (b))
#define MAX_DEGREE 101
typedef struct {
	int degree; // 다항식 최고 차수
	float coef[MAX_DEGREE]; // 다항식의 계수
} polynomical;

// C = A + B 여기서 A와 B는 다항식, 구조체가 반환
polynomical poly_add1(polynomical A, polynomical B) {
	polynomical C;
	int Apos = 0, Bpos = 0, Cpos = 0; // 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
		
	}

	if (C.coef[0] == 0) {
		
		for (int i = 0; i < C.degree; i++) {
			C.coef[i] = C.coef[i + 1];
		}
		C.degree--;
	}
	return C;
}



void print_poly(polynomical p) {
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

float poly_eval(int x, polynomical p) {

	float result = 0;
	float tmp = 1.0f;

	for (int i = p.degree; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			tmp *= x;
		}
		result += p.coef[p.degree - i] * tmp;
		tmp = 1;
	}
	return result;

}


int main() {

	polynomical a = { 3, {1, 0, 2, 3} };
	polynomical b = { 3, {-1 , 0, 4, -1} };
	polynomical c;

	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("---------------------------------------------------------------------------------\n");
	print_poly(c);
	float d = poly_eval(1, a);
	printf("%.1f\n", d);
	return 0;
}
*/

// 예제 3.3 다항식 덧셈 프로그램 2

/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct {
	float coef;
	int expon;

} polynomical; // 자료형 정의

polynomical terms[MAX_TERMS] = { {8,3}, {7,1}, {1,0}, {10, 3}, {3, 2}, {1, 0} }; // 배열
int avail = 6;

//두 개의 정수를 비교
char compare(int a, int b) {
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

//새로운 항을 다항식에 추가
void attach(float coef, int expon) {
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많습니다.\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}


void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
	float tempcoef;
	*Cs = avail;
	while (As <= Ae && Bs <= Be) {
		switch (compare(terms[As].expon, terms[Bs].expon)) {
		case '>': // A의 차수 > B의 차수
			attach(terms[As].coef, terms[As].expon);
			As++;
			break;
		case '=': // A의 차수 == B의 차수
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef) attach(tempcoef, terms[As].expon);
			As++; Bs++;
			break;
		case '<': // A의 차수 < B의 차수
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
		}
	}

	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}

void print_poly(int s, int e) {
	for (int i = s; i < e; i++) {
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main() {
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("------------------------------------------------------------------------\n");
	print_poly(Cs, Ce);
	return 0;
}

*/

// 예제 3.5 matrix2 행렬 프로그램 

/*
#define MAX_TERMS 100
typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct{
	element data[MAX_TERMS];
	int rows; // 행의 개수
	int cols; // 열의 개수
	int terms; // 항의 개수
} SparseMatrix;


SparseMatrix matrix_transpose2(SparseMatrix a) {
	SparseMatrix b;

	int bindex;
	b.rows = a.rows;
	b.cols = a.cols;
	b.terms = a.terms;

	if (a.terms > 0) {
		bindex = 0;
		for (int c = 0; c < a.cols; c++) {
			for (int i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) {
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;

				}
			}
		}
	}

	return b;
}

void matrix_print(SparseMatrix a) {

	printf("====================================\n");
	for (int i = 0; i < a.terms; i++) {

		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}


	printf("====================================\n");

}

int main() {

	SparseMatrix m = {
		{{0, 3, 7}, {1, 0, 9}, {1, 5, 8}, {3, 0, 6}, {3, 1, 5}, {4, 5, 1}, {5, 2, 2}},6,6,7
	};
	SparseMatrix result;

	result = matrix_transpose2(m);
	matrix_print(result);

	return 0;
}

#define ROWS 3
#define COLS 3

void add_matrix(int A[ROWS][COLS], int B[ROWS][COLS]) {

	int C[ROWS][COLS];

	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			C[i][j] = A[i][j] + B[i][j];
}*/

// 예제 3.7

/*
#define SIZE 6

void get_integers(int list[]) {
	printf("6개의 정수를 입력하시오: ");
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &list[i]);
	}
}

int cal_sum(int list[]) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += *(list + i);
	}
	return sum;
}

int main() {

	int list[SIZE];
	get_integers(list);
	printf("합 = %d \n", cal_sum(list));
	
	return 0;
}*/

// 연습문제 04
/*
int main() {

	int two[10];
	int num = 1;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < i; j++) {
			num *= 2;
		}
		two[i] = num;
		num = 1;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", two[i]);
	}

	return 0;
}*/

// 연습문제 05
/*
typedef struct {
	char name[100];
	int age;
	float salary;
} person; */

// 연습문제 06
/*
typedef struct {
	float real;
	float imaginary;

} complex;

complex c1, c2;

// 연습문제 07

complex complex_add(complex a, complex b) {

	complex result;

	result.real = a.real + b.real;
	result.imaginary = a.imaginary + b.imaginary;

	return result;
}*/

//연습문제 08
/*
int items;

void insert(int array[], int loc, int value) {

	for (int i = items - 1; i >= loc; i--) {
		array[i + 1] = array[i];
	}
	array[loc] = value;
	items++;
}*/

// 연습문제 10
/*
int items;

int delete(int array[], int loc) {

	int temp = array[loc];

	for (int i = loc; i <= items - 2; i++) {
		array[i] = array[i + 1];
	}
	items--;

	return temp;
}
*/

// 연습문제 12
/*
typedef struct {
	int a;
	char arr[21];
} temp;

int main() {

	temp* pt = (temp*)malloc(sizeof(temp));
	if (pt == NULL) {
		printf("메모리가 부족합니다.\n");
		exit(1);
	}

	pt->a = 100;
	
	strcpy(pt->arr, "just testing");

	free(pt);
	return 0;
} */

// 프로그래밍 프로젝트

// 01 -1
/*
int main() {

	int day[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31 };

	for (int i = 1; i < 13; i++) {
		printf("%d월은 %d까지 있습니다.\n", i, day[i - 1]);
	}

	return 0;
}
*/

// 01 -2
/*
#define SIZE 10
void matrix_diff(int a[], int b[], int c[]) {

	for (int i = 0; i < SIZE; i++) {
		c[i] = a[i] - b[i];
	}

}


int main() {

	int a[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[SIZE] = { 10,9,8,7,6,5,4,3,2,1 };
	int c[SIZE];




	return 0;
}*/

// 01-3
/*
#define SIZE 10
int main() {

	double a[10];
	
	for (int i = 0; i < SIZE; i++) {
		a[i] = rand();
	}

	double max = a[0];
	double min = a[0];

	for (int i = 1; i < SIZE; i++) {
		if (max < a[i]) max = a[i];
		if (min > a[i]) min = a[i];
	}

	printf("최댓값: %.1f, 최솟값: %.1f\n", max, min);
	return 0;
}
*/
// 01-4
/*
int search(int name[],int result) {

	int index;

	for (int i = 0; i < 10; i++) {
		if (result == name[i]) {
			index = i;
			break;
		}
	}


	return index;
}


int main() {
	int a[10] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };

	int random = 0;
	random = rand() % 10;
	
	int index = search(a, a[random]);
	
	return 0;
}*/

// 01-5
/*
#define LIST_SIZE 10

int list[LIST_SIZE] = { 23, 45, 12, 34, 65, 25, 89, 61, 26, 11 };

int main() {
	int i;
	for (i = 0; i < LIST_SIZE; i++) {
		printf("list[%d]의 주소 = %p\n", i, &list[i]);
	}

}*/

//01-6
// 같은 행이 먼저 출력됨
/*
void printArrayAddress(int a[][3]);

void main(void) {
	int array[2][3] = { {1,2,3}, {4,5,6} };
	printf("배열 array의 출력:\n");
	printArrayAddress(array);
}
void printArrayAddress(int a[][3]) {
	int i, j;
	for (i = 0; i <= 1; i++) {
		for (j = 0; j < 2; j++)
			printf("%p ", &a[i][j]);
		printf("\n");
	}
}*/

//02
/*
#define SIZE 100;
typedef struct {
	char name[100]; //이름
	int student_number; //학번
	int score; //성적

} student;


double get_mean(student students[]) {
	int result = 0;
	double mean;
	for (int i = 0; i < 100; i++) {
		result += students[i].score;
	}
	mean = (double)result / 100;
	return mean;
}

double get_deviation(student students[], double mean) {
	double temp = 0;
	double deviation;
	double mean;
	for (int i = 0; i < 100; i++) {
		temp += students[i].score;
	}
	mean = temp / 100;
	temp = 0.0;
	for (int i = 0; i < 100; i++) {
		temp += pow(students[i].score - mean, 2);
	}
	temp /= 100;
	deviation = pow(temp, 0.5);
	return deviation;
}

int main() {

	student students[100];

	return 0;
}
*/
// 04
/*
#define M 20
#define N 20

int tile[N][M] = { 0 };
void random_walk(start_x, start_y);

int main() {
	
	
	int start_x = 10, start_y = 10;
	
	random_walk(start_x, start_y);

	return 0;
}

void random_walk(present_x, present_y) {

	int walk_max = 100000;
	tile[present_x][present_y] = 1;
	int is_all_one = 1;
	int random;
	int walk_count = 0;
	clock_t start, end;
	start = clock();

	for (int i = 0; i <walk_max ; i++) {
		int cons = 0;
		random = rand() % 8;
		switch (random)
		{
		case 0:
			if (present_y == 19) {
				cons = 1;
				break;
			}
			present_y++;
			tile[present_x][present_y] = 1;
			walk_count++;
			break;
		case 1:
			if (present_x == 19 || present_y == 19) {
				cons = 1;
				break;
			}
			present_x++;
			present_y++;
			tile[present_x][present_y] = 1;
			walk_count++;
			break;
		case 2:
			if (present_x == 19) {
				cons = 1;
				break;
			}
			present_x++;
			tile[present_x][present_y] = 1;
			walk_count++;
			break;
		case 3:
			if (present_x == 19 || present_y == 0)
			{
				cons = 1;
				break;
			}present_x++;
			present_y--;
			tile[present_x][present_y] = 1;
			walk_count++;
			break;
		case 4:
			if (present_y == 0) {
				cons = 1;
				break;
			}
			present_y--;
			tile[present_x][present_y] = 1;
			walk_count++;
			break;
		case 5:
			if (present_x == 0 || present_y == 0) {
				cons = 1;
				break;
			}
			present_x--;
			present_y--;
			tile[present_x][present_y] = 1;
			walk_count++;
			break;
		case 6:
			if (present_x == 0) {
				cons = 1;
				break;
			}
			present_x--;
			tile[present_x][present_y] = 1;
			walk_count++;
			break;
		case 7:
			if (present_x == 0 || present_y == 19) {
				cons = 1;
				break;
			}
			present_x--;
			present_y++;
			tile[present_x][present_y] = 1;
			walk_count++;
			break;
		}

		if (cons == 1) continue;

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (tile[i][j] == 0) {
					is_all_one = 0;
					break;
				}
			}
			if (is_all_one == 0) break;

		}
		if (is_all_one == 0) continue;
		else break;
	}
	end = clock();
	printf("총 이동 거리: %d, 수행 시간: %.8lf\n",walk_count,(double)(end-start)/CLOCKS_PER_SEC);

}*/

// 05
/*
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
	float tempcoef;
	*Cs = avail;

	for (int i = Bs; i <= Be; i++) {
		terms[i].coef = -terms[i].coef;
	}

	while (As <= Ae && Bs <= Be) {
		switch (compare(terms[As].expon, terms[Bs].expon)) {
		case '>': // A의 차수 > B의 차수
			attach(terms[As].coef, terms[As].expon);
			As++;
			break;
		case '=': // A의 차수 == B의 차수
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef) attach(tempcoef, terms[As].expon);
			As++; Bs++;
			break;
		case '<': // A의 차수 < B의 차수
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;
		}
	}

	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}*/

// 06
#define MAX_TERMS 100
typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;

} SparseMatrix;

SparseMatrix sparse_matrix_sub2(SparseMatrix a, SparseMatrix b) {
	SparseMatrix c; // c = a - b
	int aindex = 0, bindex = 0, cindex = 0;
	c.rows = a.rows;
	c.cols = a.cols;
	c.terms = 0;
	
	int a_more = 0, b_more = 0;

	while (1) {
		if (a.data[aindex].row == b.data[bindex].row) {
			if (a.data[aindex].col == b.data[bindex].col) {
				c.data[cindex] = a.data[aindex];
				c.data[cindex].value = a.data[aindex].value - b.data[bindex].value;
				if (c.data[cindex].value == 0) {
					aindex++; bindex++;
				}
				else {
					cindex++; aindex++; bindex++; c.terms++;
				}
			}
			else if (a.data[aindex].col > b.data[bindex].col) {
				c.data[cindex] = b.data[bindex];
				c.data[cindex].value = -b.data[bindex].value;
				cindex++; bindex++; c.terms++;
			}

			else {
				c.data[cindex] = a.data[bindex];
				cindex++; aindex++; c.terms++;
			}
		}
		else if (a.data[aindex].row > b.data[bindex].row) {
			c.data[cindex] = b.data[bindex];
			c.data[cindex].value = -b.data[bindex].value;
			cindex++; bindex++; c.terms++;
		}
		else {
			c.data[cindex] = a.data[bindex];
			cindex++; aindex++; c.terms++;
		}

		if (aindex >= a.terms || bindex >= b.terms) break;

	}

	for (; aindex < a.terms; aindex++, cindex++) {
		c.data[cindex] = a.data[aindex];
		c.terms++;
	}
	for (; bindex < b.terms; bindex++, cindex++) {
		c.data[cindex] = b.data[bindex];
		c.terms++;
	}
}
	
