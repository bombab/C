//4. ����

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
// 4.1 ���� �迭 ���� ���α׷�
#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//���� ���� ���� �Լ�
int is_empty() {
	return (top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
	}
	else stack[++top] = item;
}

//�����Լ�
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

// ��ũ �Լ�
element peek() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}

int main() {
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}
*/



// 4.2 ����ü �迭 ���� ���α׷�

/*
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

//���� ���� ���� �Լ�
int is_empty() {
	return (top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

//���� �Լ�
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}

//���� �Լ�
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

// ��ũ�Լ�
element peek() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}


int main() {

	element ie = {
		20190001,
		"Hong",
		"Seoul"
	};

	element oe;

	push(ie);
	oe = pop();

	printf("�й�: %d\n", oe.student_no);
	printf("�̸�: %s\n", oe.name);
	printf("�ּ�: %s\n", oe.address);


	return 0;
}*/




// 4.3 �Ϲ����� �迭 ���� ���α׷�
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
int is_full (StackType* s) {
	return (s->top == (MAX_STACK_SIZE-1));
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

int main() {
	StackType s;

	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	return 0;
}*/




//4.5 ���� �迭 ���� ���α׷�
/*
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element* data;
	int capacity; //���� ũ��
	int top;
} StackType;

//���� ���� �Լ�
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

//���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}
//��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (s->capacity-1));
}

// ���� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data,s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;

}

// ���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main() {

	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	free(s.data);

	return 0;
}*/

/*
// ==== ���� �ڵ��� ���� ====
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}


// ��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}


// �����Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;

}

// �����Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// ��ũ�Լ�
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];

}
// ==== ���� �ڵ��� �� ====
*/
// 4.6 ��ȣ �˻� ���α׷�
/*
#define MAX_STACK_SIZE 100



int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); // n = ���ڿ��� ����
	init_stack(&s);

	for (i = 0; i < n; i++) {
		ch = in[i]; //ch = ���� ����
		switch (ch) {
		case '(': case '[': case'{':
			push(&s, ch);
			break;

		case ')': case ']': case '}':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(') && (ch != ')') ||
					(open_ch == '[') && (ch != ']') ||
					(open_ch == '{') && (ch != '}')) {
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0; // ���ÿ� ���������� ����
	return 1;
}

int main() {
	char* p = "{A[(i+1)] = 0;}";
	if (check_matching(p) == 1)
		printf("%s ��ȣ �˻� ����\n", p);
	else
		printf("%s ��ȣ �˻� ����\n", p);
	return 0;
}*/


// 4.7 ���� ǥ��� ���

/*
int eval(char exp[]) {
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;

	init_stack(&s);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&s, value);
		}
		else {
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) {
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2);
			}
		}

	}

	return pop(&s);
}

int main() {

	int result;
	printf("����ǥ����� 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("������� %d\n", result);
	return 0;
}*/

//4.8 ���� ǥ�� ������ ���� ǥ�� �������� ��ȯ�ϴ� ���α׷�

// �������� �켱���� ��ȯ
/*
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// ���� ǥ�� ���� -> ���� ǥ�� ����

void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': //������
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				printf("%c", pop(&s));
			}
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			// ���� ��ȣ�� ���������� ���
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default: //ch�� �ǿ������� ���
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int main() {

	char* s = "(2+3)*4+9";
	printf("����ǥ������ %s \n", s);
	printf("����ǥ������ ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}*/

//  4.9 �̷�Ž�� ���α׷�

/*
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	short r; //��
	short c; //��
} element ;

element here = { 1,0 }, entry = { 1,0 };

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


char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

//��ġ�� ���ÿ� ����
void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return 0;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

//�̷θ� ȭ�鿡 ���
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {

	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}

}

int main() {

	int r, c;
	StackType s;

	init_stack(&s);
	here = entry;

	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s)) {
			printf("����\n");
			return;
		}
		else
			here = pop(&s);

	}
	printf("����\n");
	return 0;
}
*/
// �������� 10
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
	return (s->top == (MAX_STACK_SIZE)-1);
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
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)];
}

int main() {
	
	StackType s;
	StackType s_inverse;
	init_stack(&s);
	init_stack(&s_inverse);
	int input_size;
	int num;
	printf("���� �迭�� ũ�� : ");
	scanf("%d", &input_size);

	printf("������ �Է��Ͻÿ� : ");
	for (int i = 0; i < input_size; i++) {
		scanf("%d", &num);
		push(&s, (element)num);
	}

	for (int i = 0; i < input_size; i++) {
		push(&s_inverse, pop(&s));
	}

	printf("������ ���� �迭 : ");
	for (int i = 0; i < input_size; i++) {
		printf("%d ", (int)s_inverse.data[i]);
	}

	return 0;
}

*/

// �������� 11.

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
	return (s->top == (MAX_STACK_SIZE)-1);
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
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)];
}

int main() {
	StackType s;
	init_stack(&s);
	char arr[MAX_STACK_SIZE] = {'\0'};

	printf("���� : ");
	scanf("%s", arr);
	
	printf("��ȣ �� : ");

	int num = 0;

	for (int i = 0; i < strlen(arr); i++) {
		if (arr[i] == '(') {
			num++;
			push(&s, (element)num);
			printf("%d ", s.data[s.top]);
		}

		else if (arr[i] == ')') {
			printf("%d ", pop(&s));
		}
	}
	return 0;
}
*/

//�������� 12

/*
define MAX_STACK_SIZE 100
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
	return (s->top == (MAX_STACK_SIZE)-1);
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
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)];
}

char lower(char chr) {
	if (chr < 'a') {
		return chr + ('a' - 'A');
	}
	else return chr;
}


int main() {
	
	StackType s;
	init_stack(&s);
	int count = 0;

	char str[100] = { '\0' };
	printf("���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", str);
	printf("����� ���ڿ�: ");
	
	for (int i = 0; i < strlen(str); i++) {
		if (is_empty(&s) == 1 || peek(&s) == lower(str[i])) {
			push(&s, lower(str[i]));
			count++;
		}
		else {
			printf("%d%c", count, peek(&s));
			count = 0;
			push(&s, lower(str[i]));
			count++;
		}
	}

	if (count != 0) {
		printf("%d%c", count, peek(&s));
	}


	return 0;
}
*/

// �������� 13

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
	return (s->top == (MAX_STACK_SIZE)-1);
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
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)];
}


int main() {

	StackType s;
	init_stack(&s);
	char str[100] = { '\0' };
	printf("������ �Է��Ͻÿ� : ");
	scanf("%s", str);

	printf("��� : ");
	for (int i = 0; i < strlen(str); i++) {
		if (is_empty(&s) || peek(&s) != str[i]) {
			push(&s, str[i]);
			printf("%c", str[i]);
		}
	}

	

	return 0;
}
*/

// �������� 14
/*
#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//���� ���� ���� �Լ�
int is_empty() {
	return (top == -1);
}

// ��ȭ ���� ���� �Լ�
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

// ���� �Լ�
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
	}
	else stack[++top] = item;
}

//�����Լ�
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}

// ��ũ �Լ�
element peek() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}


// �迭�� ������ ���ÿ� ����� ����� ���� ��ȯ�ϴ� size ���� 

int element_num() {

	return top + 1;
}

*/

/*
//�������� 15

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	short r; //��
	short c; //��
} element ;

element here = { 1,0 }, entry = { 1,0 };

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


char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

//��ġ�� ���ÿ� ����
void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return 0;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

//�̷θ� ȭ�鿡 ���
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {

	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}

}

int main() {

	int r, c;
	StackType s;
	StackType route;
	init_stack(&route);
	init_stack(&s);
	push(&route, entry);
	here = entry;

	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s)) {
			printf("����\n");
			return;
		}
		else {
			here = pop(&s);
			push(&route, here);
		}
	}
	printf("����\n");
	printf("��� ��� \n");
	for (int i = 0; i < route.top + 1; i++) {
		printf("(%d, %d) ",route.data[i].r,route.data[i].c);
	}

	return 0;
}*/

//�������� 16


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
	return (s->top == (MAX_STACK_SIZE)-1);
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
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)];
}

char lower(char chr) {

	if ('A' <= chr && chr <= 'Z') {
		chr = chr + 'a' - 'A';
		return chr;
	}
	else return chr;

}

int main() {

	StackType s;
	init_stack(&s);
	char str[200] = { '\0' };
	int is_palindrome = 1;
	int i = 0;
	printf("���ڿ��� �Է��Ͻÿ� : ");
	gets(str);

	for (int i = 0; i < strlen(str); i++) {
		str[i] = lower(str[i]);
		if ('a' <= str[i] && str[i] <= 'z') {
			push(&s, str[i]);
		}
	}

	for (int i = 0; i < strlen(str);i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			if(pop(&s) != str[i]) {
				printf("ȸ���� �ƴմϴ�.\n");
				is_palindrome = 0;
				break;
		}
			}
	}

	if (is_palindrome == 1) printf("ȸ���Դϴ�.\n");

	return 0;
}