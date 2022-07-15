#include <stdio.h>
#include <time.h>
#define SIZE 5

// 1번

/* 
float farray[SIZE];

void store(int i, int item) {
	farray[i] = (float)item;
}

int retrieve(int i) {
	return (int)farray[i];
}

int main() {

	int i, sum = 0;
	
	for (i = 0; i < SIZE; i++) {
		
			store(i, i + 1);
	}

	for (i = 0; i < SIZE; i++) {
		sum += retrieve(i);
	}
}
*/



// 2번

// 알고리즘 A

/*
int main() {
	int n;
	int sum;
	clock_t start, end;
	float res;

	printf("n 입력 : ");
	scanf("%d", &n);


	start = clock();

	sum = n * (n + 1) / 2;

	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;

	printf("실행 시간: %.2f\n", res);

	return 0;
}
*/

/*
// 알고리즘 B

int main() {
	int n;
	int sum = 0;
	clock_t start, end;
	float res;

	printf("n 입력 : ");
	scanf("%d", &n);

	start = clock();

	for (int i = 1; i < n + 1; i++) {
		sum += i;
	}

	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;

	printf("실행 시간: %.6f\n", res);
	return 0;
}
*/

// 알고리즘 C
/*
int main() {
	int n;
	int sum = 0;
	clock_t start, end;
	float res;

	printf("n 입력 : ");
	scanf("%d", &n);

	start = clock();

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < i + 1; j++)
			sum += j;

	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;
	
	printf("실행 시간: %.6f\n", res);
	return 0;
}*/

// 3번


int main() {
	int n = 0;
	int mul;
	clock_t start1, end1, start2, end2;
	float res1, res2;
	while (1) {


		// 프로그램 A
		mul = 1;
		start1 = clock();
		for (int i = 0; i < n; i++)
			for (int j = 1; j < 1000; j++)
				mul = mul * j;
		end1 = clock();

		res1 = (float)(end1 - start1)/ CLOCKS_PER_SEC;

		// 프로그램 B
		mul = 1;
		start2 = clock();
		for (int i = 0; i < n; i++)
			for (int j = 1; j < n; j++)
				mul = mul * j;

		end2 = clock();

		res2 = (float)(end2 - start2) / CLOCKS_PER_SEC;

		if (res1 < res2) break;
		else n++;


	}

	printf("n이 %d 이상이어야 프로그램 B가 시간이 더 걸린다.\n", n);

	return 0;
}
