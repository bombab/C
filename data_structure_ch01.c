#include <stdio.h>
#include <time.h>
#define SIZE 5

// 1��

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



// 2��

// �˰��� A

/*
int main() {
	int n;
	int sum;
	clock_t start, end;
	float res;

	printf("n �Է� : ");
	scanf("%d", &n);


	start = clock();

	sum = n * (n + 1) / 2;

	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;

	printf("���� �ð�: %.2f\n", res);

	return 0;
}
*/

/*
// �˰��� B

int main() {
	int n;
	int sum = 0;
	clock_t start, end;
	float res;

	printf("n �Է� : ");
	scanf("%d", &n);

	start = clock();

	for (int i = 1; i < n + 1; i++) {
		sum += i;
	}

	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;

	printf("���� �ð�: %.6f\n", res);
	return 0;
}
*/

// �˰��� C
/*
int main() {
	int n;
	int sum = 0;
	clock_t start, end;
	float res;

	printf("n �Է� : ");
	scanf("%d", &n);

	start = clock();

	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < i + 1; j++)
			sum += j;

	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;
	
	printf("���� �ð�: %.6f\n", res);
	return 0;
}*/

// 3��


int main() {
	int n = 0;
	int mul;
	clock_t start1, end1, start2, end2;
	float res1, res2;
	while (1) {


		// ���α׷� A
		mul = 1;
		start1 = clock();
		for (int i = 0; i < n; i++)
			for (int j = 1; j < 1000; j++)
				mul = mul * j;
		end1 = clock();

		res1 = (float)(end1 - start1)/ CLOCKS_PER_SEC;

		// ���α׷� B
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

	printf("n�� %d �̻��̾�� ���α׷� B�� �ð��� �� �ɸ���.\n", n);

	return 0;
}
