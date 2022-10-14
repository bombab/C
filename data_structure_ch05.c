//5. 큐

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 5.1 선형큐 프로그램
/*
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}

void queue_print(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear) {
			printf(" | ");
		}
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType* q) {
	if (q->front == q->rear) {
		return 1;
	}
	else return 0;
}

void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main() {

	int item = 0;
	QueueType q;

	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);


	return 0;
}*/

//5.2 원형큐 프로그램


/*

// ===== 원형큐 코드 시작======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//큐 초기회 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}



// ====== 원형큐 코드 끝 =====
int main() {
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--데이터 추가 단계--\n");
	while (!is_full(&queue)) {
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");

	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("꺼내진 정수 : %d \n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.\n");

	return 0;
}

*/

//5.3 큐 응용 프로그램

/*
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//큐 초기화 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}


int main() {
	QueueType queue;
	int element;

	init_queue(&queue);
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		if (rand() % 5 == 0) {
			enqueue(&queue, rand() % 100);
		}
		queue_print(&queue);
		if (rand() % 10 == 0) {
			int data = dequeue(&queue);
		}
		queue_print(&queue);
	}
	return 0;
}*/

// 프로그램 5.4 원형 덱(deque) 프로그램

/*
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void deque_print(DequeType* q) {
	printf("DEQUE(front=%d, rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element delete_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 추출 함수
element get_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}

int main() {
	DequeType queue;

	init_deque(&queue);
	for (int i = 0; i < 3; i++) {
		add_front(&queue, i);
		deque_print(&queue);
	}

	for (int i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
}*/

// 5.5 은행 서비스 시뮬레이션 프로그램

/*
#define MAX_QUEUE_SIZE 5
typedef struct {
	int id;
	int arrival_time;
	int service_time;
} element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//큐 초기회 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


// 삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main() {

	int minutes = 60;
	int total_wait = 0;
	int total_customer = 0;
	int service_time = 0;
	int service_customer;
	QueueType queue;
	init_queue(&queue);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("현재시각=%d\n", clock);
		if ((rand() % 10) < 3) { // 랜덤한 시각에 새로운 고객이 들어옴
			element customer;
			customer.id = total_customer++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n", customer.id, customer.arrival_time, customer.service_time);
		}

		if (service_time > 0) {
			printf("고객 %d 업무처리중입니다. \n", service_customer);
			service_time--;
		}
		else { // service_time == 0
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다.\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("전체 대기 시간 = %d분 \n", total_wait);

	return 0;
}
*/

// 연습문제 8.


/*
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 뽑기 함수
element peek(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}


// 큐에 존재하는 요소의 개수를 반환 //1. 반복문 활용
int get_count(QueueType* q) {
	int num = 0;
	int i = q->front;
	while (i != q->rear) {
		i = (q->front + 1) % MAX_QUEUE_SIZE;
		num++;
	}
	return num;
}
*/

// 큐에 존재하는 요소의 개수를 반환 2. 조건문 활용 -> 더 성능이 우수
/*
int get_count(QueueType* q) {
	if (q->rear >= q->front)
		return q->rear - q->front;
	else
		return MAX_QUEUE_SIZE - (q->front - q->rear);
}

*/

// 연습문제 9.

/*
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;

} StackType;

//스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}


//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

//삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

//피크 함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러 \n");
		exit(1);
	}
	else return s->data[s->top];
}

StackType stack1; // 입력 스택
StackType stack2; // 출력 스택

void queue_input(StackType* s, element item) {
	if(is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}

	push(&stack1, item);
}

element queue_output(StackType* s) {
	element item;
	if (is_empty(s)) {
		while (!is_empty(&stack1)) {
			item = pop(&stack1);
			push(&stack2, item);
		}
	}

	return pop(&stack2);
}

int main() {

	init_stack(&stack1);
	init_stack(&stack2);
	return 0;
}*/

// 연습문제 10.

/*

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 뽑기 함수
element peek(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int cal_Fibonacci(int num) { // 피보나치 수열 num 항을 return 

	QueueType queue;
	init_queue(&queue);

	enqueue(&queue, 0);
	enqueue(&queue, 1);

	if (num == 0) return 0;
	if (num == 1) return 1;


	int tmp1;
	int tmp2;
	for (int i = 2; i <= num; i++) {
		tmp1 = dequeue(&queue);
		tmp2 = tmp1 + peek(&queue);
		enqueue(&queue, tmp2);
	}

	return peek(&queue);

}

int main() {

	printf("%d\n", cal_Fibonacci(10));

	return 0;
}

*/

// 연습문제 11.

/*
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element delete_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 추출 함수
element get_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}


int islower(int chr) {
	
	if (chr >= 'a' && chr <= 'z') {
		return 1;
	}

	else if (chr >= 'A' && chr <= 'Z') {
		return chr + 'a' - 'A';
	}


	else return 0;

}

int main() {

	char str[100] = { '\0' };
	char tmp = 0;
	int pivot = 1;
	DequeType deque;
	init_deque(&deque);
	printf("문자열을 입력하시오 : ");
	gets(str);

	for (int i = 0; i < strlen(str); i++) {
		tmp = islower(str[i]);
		if (tmp == 1) add_rear(&deque, str[i]);
		else if (tmp >= 'a' && tmp <= 'z') add_rear(&deque, tmp);
	}

	while (!is_empty(&deque)) {

		if (get_rear(&deque) != delete_front(&deque)) {
			printf("회문이 아닙니다.\n");
			pivot = 0;
			break;
		}

		if (is_empty(&deque)) break;
		delete_rear(&deque);

	}
	if (pivot == 1) printf("회문입니다.\n");


	return 0;
}*/


// 연습문제 12.

#define MAX_QUEUE_SIZE 10

typedef struct {
	int task_num;
	int task_time;

} task;

typedef struct {
	task data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


// 삽입 함수
void add_rear(DequeType* q, task item) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
task delete_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 추출 함수
task get_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, task val) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

task delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

task get_rear(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}

void running_task(DequeType* q) {
	q->data[(q->front + 1) % MAX_QUEUE_SIZE].task_time--;
	if (q->data[(q->front + 1) % MAX_QUEUE_SIZE].task_time == 0) {
		printf("task%d의 수행이 완료되었습니다.\n", q->data[(q->front + 1) % MAX_QUEUE_SIZE].task_num);
		delete_front(q);
	}
}


int task_run_num(DequeType* q) {

	if (q->rear >= q->front) return (q->rear - q->front);
	else return MAX_QUEUE_SIZE - (q->front - q->rear);
	
}

void A_steal_algorithm(DequeType *stealer, DequeType *victim1, DequeType *victim2) {
	
	int total_run_time_1 = 0;
	int total_run_time_2 = 0;
	int task_num_vic1 = task_run_num(victim1);
	int task_num_vic2 = task_run_num(victim2);

	task tmp;
	int tmp_front1 = victim1->front;
	int tmp_front2 = victim2->front;

	if (task_num_vic1 < 2 && task_num_vic2 < 2) return;
	if (task_num_vic1 >= 2 && task_num_vic2 < 2) {
		printf("stealer가 victim1의 task%d를 빼았습니다\n", victim1->data[victim1->rear].task_num);
		tmp = delete_rear(victim1);
		add_rear(stealer, tmp);
		return;
	}

	if (task_num_vic1 < 2 && task_num_vic2 >= 2) {
		printf("stealer가 victim2의 task%d를 빼았습니다\n", victim2->data[victim2->rear].task_num);
		tmp = delete_rear(victim2);
		add_rear(stealer, tmp);
		return;
	}

	do {
		tmp_front1 = (tmp_front1 + 1) % MAX_QUEUE_SIZE;
		total_run_time_1 += victim1->data[tmp_front1].task_time;
	} while (tmp_front1 != victim1->rear);

	do {
		tmp_front2 = (tmp_front2 + 1) % MAX_QUEUE_SIZE;
		total_run_time_2 += victim2->data[tmp_front2].task_time;
	} while (tmp_front2 != victim2->rear);

	if (total_run_time_1 >= total_run_time_2) {
		printf("stealer가 victim1의 task%d를 빼았습니다\n",victim1->data[victim1->rear].task_num);
		tmp = delete_rear(victim1);
		add_rear(stealer, tmp);
	}
	else {
		printf("stealer가 victim2의 task%d를 빼았습니다\n", victim2->data[victim2->rear].task_num);
		tmp = delete_rear(victim2);
		add_rear(stealer, tmp);
	}

}



// CPU1, CPU2, CPU3 이 있다고 가정
//  3 ,   5,    7  의 수행시간이 걸리는 작업을 각각 4개씩 배정받음


int main() {
	DequeType CPU1;
	DequeType CPU2;
	DequeType CPU3;
	task task_arr[12];

	init_deque(&CPU1);
	init_deque(&CPU2);
	init_deque(&CPU3);
	
// Task 삽입
	for (int i = 0; i < 12; i++) {
		switch (i / 4) {
		case 0:
			task_arr[i].task_num = i;
			task_arr[i].task_time = 3;
			add_rear(&CPU1, task_arr[i]);
			break;
		case 1:
			task_arr[i].task_num = i;
			task_arr[i].task_time = 5;
			add_rear(&CPU2, task_arr[i]);
			break;
		case 2:
			task_arr[i].task_num = i;
			task_arr[i].task_time = 7;
			add_rear(&CPU3, task_arr[i]);
			break;

		}	
	}

// 작업 시작

	for (int i = 0; i < 100; i++) {
		running_task(&CPU1);
		running_task(&CPU2);
		running_task(&CPU3);

		
		if (is_empty(&CPU1)) {
			A_steal_algorithm(&CPU1, &CPU2, &CPU3);
		}
		if (is_empty(&CPU2)) {
			A_steal_algorithm(&CPU2, &CPU1, &CPU3);
		}
		if (is_empty(&CPU3)) {
			A_steal_algorithm(&CPU3, &CPU1, &CPU2);
		}
		

		if (is_empty(&CPU1) && is_empty(&CPU2) && is_empty(&CPU3)) {
			printf("모든 CPU에서의 모든 작업이 완료되었습니다!\n");
			break;
		}
	}

}
