//4. 스택

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
// 4.1 정수 배열 스택 프로그램
#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//공백 상태 검출 함수
int is_empty() {
	return (top == -1);
}

// 포화 상태 검출 함수
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
	}
	else stack[++top] = item;
}

//삭제함수
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}

// 피크 함수
element peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
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



// 4.2 구조체 배열 스택 프로그램

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

//공백 상태 검출 함수
int is_empty() {
	return (top == -1);
}

//포화 상태 검출 함수
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;
}

//삭제 함수
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}

// 피크함수
element peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
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

	printf("학번: %d\n", oe.student_no);
	printf("이름: %s\n", oe.name);
	printf("주소: %s\n", oe.address);


	return 0;
}*/




// 4.3 일반적인 배열 스택 프로그램
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
int is_full (StackType* s) {
	return (s->top == (MAX_STACK_SIZE-1));
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




//4.5 동적 배열 스택 프로그램
/*
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element* data;
	int capacity; //현재 크기
	int top;
} StackType;

//스택 생성 함수
void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}
//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (s->capacity-1));
}

// 삽입 함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data,s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;

}

// 삭제 함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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
// ==== 스택 코드의 시작 ====
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}


// 포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}


// 삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;

}

// 삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// 피크함수
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];

}
// ==== 스택 코드의 끝 ====
*/
// 4.6 괄호 검사 프로그램
/*
#define MAX_STACK_SIZE 100



int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); // n = 문자열의 길이
	init_stack(&s);

	for (i = 0; i < n; i++) {
		ch = in[i]; //ch = 다음 문자
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
	if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류
	return 1;
}

int main() {
	char* p = "{A[(i+1)] = 0;}";
	if (check_matching(p) == 1)
		printf("%s 괄호 검사 성공\n", p);
	else
		printf("%s 괄호 검사 실패\n", p);
	return 0;
}*/


// 4.7 후위 표기식 계산

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
	printf("후위표기식은 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("결과값은 %d\n", result);
	return 0;
}*/

//4.8 중위 표기 수식을 후위 표기 수식으로 변환하는 프로그램

// 연산자의 우선순위 반환
/*
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// 중위 표기 수식 -> 후위 표기 수식

void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': //연산자
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
			// 왼쪽 괄호를 만날때까지 출력
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default: //ch가 피연산자인 경우
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}

int main() {

	char* s = "(2+3)*4+9";
	printf("중위표현수식 %s \n", s);
	printf("후위표현수식 ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}*/

//  4.9 미로탐색 프로그램

/*
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	short r; //행
	short c; //열
} element ;

element here = { 1,0 }, entry = { 1,0 };

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


char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

//위치를 스택에 삽입
void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return 0;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

//미로를 화면에 출력
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
			printf("실패\n");
			return;
		}
		else
			here = pop(&s);

	}
	printf("성공\n");
	return 0;
}
*/
// 연습문제 10
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
	return (s->top == (MAX_STACK_SIZE)-1);
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
		fprintf(stderr, "스택 공백 에러\n");
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
	printf("정수 배열의 크기 : ");
	scanf("%d", &input_size);

	printf("정수를 입력하시오 : ");
	for (int i = 0; i < input_size; i++) {
		scanf("%d", &num);
		push(&s, (element)num);
	}

	for (int i = 0; i < input_size; i++) {
		push(&s_inverse, pop(&s));
	}

	printf("반전된 정수 배열 : ");
	for (int i = 0; i < input_size; i++) {
		printf("%d ", (int)s_inverse.data[i]);
	}

	return 0;
}

*/

// 연습문제 11.

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
	return (s->top == (MAX_STACK_SIZE)-1);
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
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)];
}

int main() {
	StackType s;
	init_stack(&s);
	char arr[MAX_STACK_SIZE] = {'\0'};

	printf("수식 : ");
	scanf("%s", arr);
	
	printf("괄호 수 : ");

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

//연습문제 12

/*
define MAX_STACK_SIZE 100
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
	return (s->top == (MAX_STACK_SIZE)-1);
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
		fprintf(stderr, "스택 공백 에러\n");
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
	printf("문자열을 입력하시오 : ");
	scanf("%s", str);
	printf("압축된 문자열: ");
	
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

// 연습문제 13

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
	return (s->top == (MAX_STACK_SIZE)-1);
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
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)];
}


int main() {

	StackType s;
	init_stack(&s);
	char str[100] = { '\0' };
	printf("정수를 입력하시오 : ");
	scanf("%s", str);

	printf("출력 : ");
	for (int i = 0; i < strlen(str); i++) {
		if (is_empty(&s) || peek(&s) != str[i]) {
			push(&s, str[i]);
			printf("%c", str[i]);
		}
	}

	

	return 0;
}
*/

// 연습문제 14
/*
#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

//공백 상태 검출 함수
int is_empty() {
	return (top == -1);
}

// 포화 상태 검출 함수
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
	}
	else stack[++top] = item;
}

//삭제함수
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}

// 피크 함수
element peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top];
}


// 배열로 구현된 스택에 저장된 요소의 수를 반환하는 size 연산 

int element_num() {

	return top + 1;
}

*/

/*
//연습문제 15

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct {
	short r; //행
	short c; //열
} element ;

element here = { 1,0 }, entry = { 1,0 };

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


char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'},
};

//위치를 스택에 삽입
void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return 0;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

//미로를 화면에 출력
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
			printf("실패\n");
			return;
		}
		else {
			here = pop(&s);
			push(&route, here);
		}
	}
	printf("성공\n");
	printf("경로 출력 \n");
	for (int i = 0; i < route.top + 1; i++) {
		printf("(%d, %d) ",route.data[i].r,route.data[i].c);
	}

	return 0;
}*/

//연습문제 16


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
	return (s->top == (MAX_STACK_SIZE)-1);
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
		fprintf(stderr, "스택 공백 에러\n");
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
	printf("문자열을 입력하시오 : ");
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
				printf("회문이 아닙니다.\n");
				is_palindrome = 0;
				break;
		}
			}
	}

	if (is_palindrome == 1) printf("회문입니다.\n");

	return 0;
}