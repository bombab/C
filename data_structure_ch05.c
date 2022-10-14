//5. ť

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 5.1 ����ť ���α׷�
/*
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//���� �Լ�
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
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
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

//5.2 ����ť ���α׷�


/*

// ===== ����ť �ڵ� ����======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ť �ʱ�ȸ �Լ�
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ����ť ��� �Լ�
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

// ���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}



// ====== ����ť �ڵ� �� =====
int main() {
	QueueType queue;
	int element;

	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");
	while (!is_full(&queue)) {
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&queue)) {
		element = dequeue(&queue);
		printf("������ ���� : %d \n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");

	return 0;
}

*/

//5.3 ť ���� ���α׷�

/*
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ť �ʱ�ȭ �Լ�
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ����ť ��� �Լ�
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

// ���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
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

// ���α׷� 5.4 ���� ��(deque) ���α׷�

/*
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ����ť ��� �Լ�
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

// ���� �Լ�
void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element delete_front(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ���� �Լ�
element get_front(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
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

// 5.5 ���� ���� �ùķ��̼� ���α׷�

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

// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ť �ʱ�ȸ �Լ�
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


// ���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
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
		printf("����ð�=%d\n", clock);
		if ((rand() % 10) < 3) { // ������ �ð��� ���ο� ���� ����
			element customer;
			customer.id = total_customer++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n", customer.id, customer.arrival_time, customer.service_time);
		}

		if (service_time > 0) {
			printf("�� %d ����ó�����Դϴ�. \n", service_customer);
			service_time--;
		}
		else { // service_time == 0
			if (!is_empty(&queue)) {
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n",
					customer.id, clock, clock - customer.arrival_time);
				total_wait += clock - customer.arrival_time;
			}
		}
	}
	printf("��ü ��� �ð� = %d�� \n", total_wait);

	return 0;
}
*/

// �������� 8.


/*
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ �Լ�
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// �̱� �Լ�
element peek(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}


// ť�� �����ϴ� ����� ������ ��ȯ //1. �ݺ��� Ȱ��
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

// ť�� �����ϴ� ����� ������ ��ȯ 2. ���ǹ� Ȱ�� -> �� ������ ���
/*
int get_count(QueueType* q) {
	if (q->rear >= q->front)
		return q->rear - q->front;
	else
		return MAX_QUEUE_SIZE - (q->front - q->rear);
}

*/

// �������� 9.

/*
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;

} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}


//��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//���� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

//���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

//��ũ �Լ�
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ���� \n");
		exit(1);
	}
	else return s->data[s->top];
}

StackType stack1; // �Է� ����
StackType stack2; // ��� ����

void queue_input(StackType* s, element item) {
	if(is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
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

// �������� 10.

/*

#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

//���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ �Լ�
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// �̱� �Լ�
element peek(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int cal_Fibonacci(int num) { // �Ǻ���ġ ���� num ���� return 

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

// �������� 11.

/*
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element delete_front(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ���� �Լ�
element get_front(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
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
	printf("���ڿ��� �Է��Ͻÿ� : ");
	gets(str);

	for (int i = 0; i < strlen(str); i++) {
		tmp = islower(str[i]);
		if (tmp == 1) add_rear(&deque, str[i]);
		else if (tmp >= 'a' && tmp <= 'z') add_rear(&deque, tmp);
	}

	while (!is_empty(&deque)) {

		if (get_rear(&deque) != delete_front(&deque)) {
			printf("ȸ���� �ƴմϴ�.\n");
			pivot = 0;
			break;
		}

		if (is_empty(&deque)) break;
		delete_rear(&deque);

	}
	if (pivot == 1) printf("ȸ���Դϴ�.\n");


	return 0;
}*/


// �������� 12.

#define MAX_QUEUE_SIZE 10

typedef struct {
	int task_num;
	int task_time;

} task;

typedef struct {
	task data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


// ���� �Լ�
void add_rear(DequeType* q, task item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
task delete_front(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ���� �Լ�
task get_front(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, task val) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

task delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

task get_rear(DequeType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[q->rear];
}

void running_task(DequeType* q) {
	q->data[(q->front + 1) % MAX_QUEUE_SIZE].task_time--;
	if (q->data[(q->front + 1) % MAX_QUEUE_SIZE].task_time == 0) {
		printf("task%d�� ������ �Ϸ�Ǿ����ϴ�.\n", q->data[(q->front + 1) % MAX_QUEUE_SIZE].task_num);
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
		printf("stealer�� victim1�� task%d�� ���ҽ��ϴ�\n", victim1->data[victim1->rear].task_num);
		tmp = delete_rear(victim1);
		add_rear(stealer, tmp);
		return;
	}

	if (task_num_vic1 < 2 && task_num_vic2 >= 2) {
		printf("stealer�� victim2�� task%d�� ���ҽ��ϴ�\n", victim2->data[victim2->rear].task_num);
		tmp = delete_rear(victim2);
		add_rear(stealer, tmp);
		return;
	}

	do {
		tmp_front1 = (tmp_front1 + 1) % MAX_QUEUE_SIZE;
		total_run_time_1 = victim1->data[tmp_front1].task_time;
	} while (tmp_front1 != victim1->rear);

	do {
		tmp_front2 = (tmp_front2 + 1) % MAX_QUEUE_SIZE;
		total_run_time_2 = victim2->data[tmp_front2].task_time;
	} while (tmp_front2 != victim2->rear);

	if (total_run_time_1 >= total_run_time_2) {
		printf("stealer�� victim1�� task%d�� ���ҽ��ϴ�\n",victim1->data[victim1->rear].task_num);
		tmp = delete_rear(victim1);
		add_rear(stealer, tmp);
	}
	else {
		printf("stealer�� victim2�� task%d�� ���ҽ��ϴ�\n", victim2->data[victim2->rear].task_num);
		tmp = delete_rear(victim2);
		add_rear(stealer, tmp);
	}

}



// CPU1, CPU2, CPU3 �� �ִٰ� ����
//  3 ,   5,    7  �� ����ð��� �ɸ��� �۾��� ���� 4���� ��������


int main() {
	DequeType CPU1;
	DequeType CPU2;
	DequeType CPU3;
	task task_arr[12];

	init_deque(&CPU1);
	init_deque(&CPU2);
	init_deque(&CPU3);
	
// Task ����
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

// �۾� ����

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
			printf("��� CPU������ ��� �۾��� �Ϸ�Ǿ����ϴ�!\n");
			break;
		}
	}

}