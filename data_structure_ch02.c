//순환

#include <stdio.h>

//2.1. 순환적인 팩토리얼 계산 프로그램
/*
int factorial(int n) {

	if (n < 2) {
		return 1;
	}
	else {

		return n * factorial(n - 1);
	}
}
*/

//2.2 출력문이 추가된 순환적인 팩토리얼 계산 프로그램
/*
int factorial(int n) {

	printf("factorial(%d)\n", n);
	if (n <= 1) return 1;
	else return n * factorial(n - 1);

}
*/

// 2.3 반복적인 팩토리얼 계산 프로그램

/*
int factorial_iter(int n) {

	int result = 1;

	for (int i = 1; i < n + 1; i++) {
		result = result * i;
	}
	
	return result;

}
*/

//2.4 반복적인 거듭제곱 계산 프로그램4
/*
double slow_power(double x, int n) {

	double result = 1.0;
	for (int i = 1; i < n + 1; i++) {

		result = result * x;
	}
	return result;

}
*/

//2.5 순환적인 거듭제곱 계산 프로그램
/*
double power(double x, int n) {

	if (n == 0) return 1;
	else if (n % 2 == 0) {

		return power(x * x, n / 2);
	}
	else {

		return x * power(x * x, (n - 1) / 2);
	}
}
*/

// Quiz
/*
int sub(int n) {

	int result = 0;

	while (n >= 0) {

		result += n;
		n = n - 3;
	}

	return result;
}
*/

//2.6 순환적인 피보나치 수열 계산 프로그램
/*
int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));

}
*/

//2.7 반복적인 피보나치 수열 계산 프로그램

/*
int fib_iter(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int pp = 0;
	int p = 1;
	int result = 0;

	for (int i = 2; i < n + 1; i++) {
		result = p + pp;
		pp = p;
		p = result;
	}

	return result;
}
*/


//2.8 하노이의 탑 문제 프로그램

/*
void hanoi_tower(int n, char from, char tmp, char to) {

	if (n == 1) printf("%c의 원판 1개를 %c로 옮긴다.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("%c의 원판 1개를 %c로 옮긴다.\n", from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}


}

int main() {

	hanoi_tower(3, 'A', 'B', 'C');
	return 0;
}
*/

// 연습문제 13.

/*
int sum(int n);

int main() {

	int a = sum(5);

	printf("%d\n", a);


}

int sum(int n) {

	if (n == 1) {
		return 1;
	}

	return n + sum(n - 1);
}
*/

// 연습문제 14
/*
double sum(int n);

int main() {
	
	double a = sum(3);

	printf("%.1f\n", a);

	return 0;
}

double sum(int n) {

	if (n == 1) return 1;

	return (double)1 / n + sum(n - 1);

}
*/

// 연습문제 15
/*
int fib (int n) {
	printf("fib(%d) is called\n", n);
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));

}

int main() {

	printf("%d\n", fib(6));

	return 0;
}
*/

// 연습문제 16
/*
int main() {
	int n = 0, sum = 0;
	printf("숫자 입력: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		sum += i;
	}

	printf("합: %d\n", sum);

	return 0;
}
*/

// 연습문제 17
/*
int bino_coef_sum1(int n, int k) {

	if (k == 0 || k == n) return 1;

	return bino_coef_sum1(n - 1, k - 1) + bino_coef_sum1(n - 1, k);

}

int bino_coef_sum2(int n, int k) {

	int p1 = 1, p2 = 1, p3 = 1;

	for (int i = 1; i <= n; i++) {
		p1 *= i;
	}

	for (int i = 1; i <= k; i++) {
		p2 *= i;
	}

	for (int i = 1; i <= n-k; i++) {
		p3 *= i;
	}

	return p1 / (p2 * p3);

}*/

//연습문제 18

/*
int Ackermann(int m, int n) {

	if (m == 0) return n + 1;
	if (n == 0) return Ackermann(m - 1, 1);

	if (m >= 1 && n >= 1) return Ackermann(m - 1, Ackermann(m, n - 1));
}

int Ackermann2(int m, int n) {
	while (m != 0) {

		if (n == 0) {
			m = m - 1;
			n = 1;
		}
		else {
			n = Ackermann2(m, n - 1);
			m = m - 1;
		}
	}

	return n + 1;

}

int main() {

	int a, b;

	a = Ackermann(3, 2);
	b = Ackermann(2, 3);

	printf("각각의 값 : %d , %d \n", a, b);


	return 0;
}
*/

// 연습문제 21
/*
#define WHITE 0
#define BLACK 1
#define YELLOW 2

int screen[10][10] = {
	{2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2},
	{2,2,2,0,0,0,0,2,2,2},
	{2,2,2,2,0,0,0,2,2,2},
	{2,2,2,2,0,0,0,2,2,2},
	{2,2,2,2,0,0,0,0,2,2},
	{2,2,2,2,0,2,2,2,2,2},
	{2,2,2,2,0,2,2,2,2,2},
	{2,2,2,2,0,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2,2}

};

char read_pixel(int x, int y) {
	return screen[x][y];
}

void write_pixel(int x, int y, int color) {

	screen[x][y] = color;
	printf("[%d][%d] 위치를 BLACK으로 칠했습니다.\n", x, y);
}

void flood_fill(int x, int y) {
	if (read_pixel(x, y) == WHITE) {
		write_pixel(x, y, BLACK);
		flood_fill(x + 1, y);
		flood_fill(x - 1, y);
		flood_fill(x, y + 1);
		flood_fill(x, y - 1);
	}

}


int main() {

	flood_fill(5, 4);


	return 0;
}*/

// 프로그래밍 프로젝트 

//01

/*
#define MAX_LEVEL 50
#define MAX_WIDTH 40
char screen[MAX_LEVEL][MAX_WIDTH];

void init() {

	for (int i = 0; i < MAX_LEVEL; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			screen[i][j] = '-';
		}
	}

}

void display() {

	for (int i = 0; i < MAX_LEVEL; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			printf("%c", screen[i][j]);
		}
		printf("\n");
	}
}

void draw_tree(int row, int left, int right) {

	int mid;
	printf("draw_tree 함수 호출, 매개변수 row - %d, left - %d, right - %d \n",row, left, right);

	if ((right - left) < 3) {
		return;
	}

	mid = (right + left) / 2;
	screen[row][mid] = 'X';
	draw_tree(row+1,left,mid-1);
	draw_tree(row+1,mid+1,right);

}

void draw_tree1() {

	char screen_ex[MAX_WIDTH];
	int left = 0, right = 0, mid, i;

	for (i = 0; i < MAX_WIDTH; i++) {
		screen_ex[i] = '-';
	}


	for (i = 0; i < MAX_LEVEL; i++) {

		while(right != MAX_WIDTH - 1) {
			if (screen_ex[right] == 'X') {
				mid = (left + right - 1) / 2;
				screen[i][mid] = 'X';
				screen_ex[mid] = 'X';
				left = right + 1;
			}
			right++;
		}
		mid = (left + right) / 2;
		screen[i][mid] = 'X';
		screen_ex[mid] = 'X';
		left = mid + 1;
		if ((right - left) < 3) return;
		left = 0;
		right = 0;
	}
}



int main() {

	init();
	draw_tree1();
	display();

	return 0;
}

*/



