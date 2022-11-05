// 7. 연결리스트 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 7.3 원형 연결 리스트 테스트 프로그램
 
/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head) {
	ListNode* p;

	if (head == NULL) return 0;
	p = head->link;

	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // 마지막 노드 출력
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;

 }

ListNode* insert_last(ListNode* head, element data) {// * 원형 연결리스트 끝에 삽입 
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;

}

int	main() {

	ListNode* head = NULL;
	
	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);

	return 0;
}
*/

// 프로그램 7.4 멀티게임

/*
typedef char element[100]; // element를 char [100]형으로 정의
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy(node->data, data);
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

int main() {

	ListNode* head = NULL;

	head = insert_first(head, "KIM");
	head = insert_first(head, "PARK");
	head = insert_first(head, "CHOI");

	ListNode* p = head;
	for (int i = 0; i < 10; i++) {
		printf("현재 차례= %s \n", p->data);
		p = p->link;
	}
	return 0;
}*/

// 이중 연결 리스트에서 삭제함수

/*
typedef int element;
typedef struct DListNode { // 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결리스트의 노드를 출력
void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// 노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed) {
	
	if (removed == head) return;
	removed->rlink->llink = removed->llink;
	removed->llink->rlink = removed->rlink;
	free(removed);
}

// 이중 연결 리스트 테스트 프로그램
int main() {
	
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {
		// 헤드 노드의 오른쪽에 삽입
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}
*/

// 프로그램 7.8 mp3 플레이어 프로그램

/*
typedef char element[100];
typedef struct DListNode { // 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

DListNode* current;

// 이중 연결 리스트를 초기화
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		if (p == current)
			printf("<-| #%s# |-> ", p->data);
		else
			printf("<-| %s | ->", p->data);
	}
	printf("\n");
}

// 노드 newnode를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// 노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

// 이중 연결 리스트 테스트 프로그램
int main() {
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "Mamamia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");

	current = head->rlink;
	print_dlist(head);

	do {
		printf("\n명령어를 입력하시오(<, >, q): ");
		ch = getchar();
		if (ch == '<') {
			current = current->llink;
			if (current == head)
				current = current->llink;
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head)
				current = current->rlink;
		}
		print_dlist(head);
		getchar();
	} while (ch != 'q');
	// 동적 메모리 해제 코드를 여기에
	return 0;
}*/

// 프로그램 7.9 연결된 스택 프로그램

/*
typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// 초기화 함수
void init(LinkedStackType* s) {
	s->top = NULL;
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

// 포화 상태 검출 함수
int is_full(LinkedStackType* s) {
	return 0;
}

// 삽입 함수
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

void print_stack(LinkedStackType* s) {
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

// 삭제 함수
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

// 피크 함수
element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		return s->top->data;
	}

}

int main() {

	LinkedStackType s;
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);

	return 0;
}
*/


// 프로그램 7.12 연결된 큐 프로그램

/*
typedef int element;
typedef struct { // 큐의 노드의 타입
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	QueueNode* front, * rear;
} LinkedQueueType;

// 큐 초기화 함수
void init(LinkedQueueType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);
}


// 포화 상태 검출 함수
int is_full(LinkedQueueType* q) {
	return 0;
}


// 삽입 함수
void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp; // 순서 중요
		q->rear = temp;
	}
}

// 삭제 함수
element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return data;
	}
}

void print_queue(LinkedQueueType* q) {
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

// 연결 된 큐 테스트 함수
int main() {

	LinkedQueueType queue;

	init(&queue);

	enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);


	return 0;
}*/

// 연습문제 3-4.
/*
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//리스트의 항목출력
void print_list(ListNode* head) {
	ListNode* p;

	if (head == NULL) return;
	p = head->link; // p는 처음부터 시작
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d\n", p->data); // 마지막 노드 출력
}

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}

	return head;
}

// 원형 연결 리스트에서 data를 가지고 있는 노드를 찾아 반환한다
ListNode* search(ListNode* head, element data) {
	ListNode* find;

	if (head == NULL) {
		return NULL;
	}
	find = head->link;

	do {
		if (find->data == data) return find;
		find = find->link;
	} while (find != head);

	if (find->data == data) return find;
	else return NULL;
}

// 원형 연결 리스트에 저장된 데이터의 개수를 반환한다.
int get_size(ListNode* head) {
	ListNode* p;
	int count = 0;
	if (head == NULL) return count;
	p = head->link;
	count++;
	while(p!=head) {
		p = p->link;
		count++;
	} 
	return count;
}

*/

// 연습문제 6-7.

/*
typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}


// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}


// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->rlink = before->rlink;
	newnode->llink = before;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// 노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return;
	removed->rlink->llink = removed->llink;
	removed->llink->rlink = removed->rlink;
	free(removed);
}


void reverse_print() {
	int data_num;
	int element_n;
	DListNode* phead = (DListNode*)malloc(sizeof(DListNode));
	init(phead);
	DListNode* p = phead;
	printf("데이터의 개수를 입력하시오: ");
	scanf("%d", &data_num);

	for (int i = 1; i <= data_num; i++) {
		printf("노드 #%d의 데이터를 입력하시오: ", i);
		scanf("%d", &element_n);
		dinsert(p, element_n);
		p = p->rlink;
	}

	// p는 지금 마지막 노드를 가리킴
	printf("데이터를 역순으로 출력: ");
	while (p != phead) {
		printf("%d ", p->data);
		p = p->llink;
	} 

}

// 이중 연결 리스트에서 data를 가지고 있는 노드를 찾아서 반환한다.
DListNode* search(DListNode* head, element data) {
	DListNode* p = head;
	do {
		if (p->data == data) return p;

		p = p->rlink;
	} while (p != head);
	return NULL;
}

int main() {
	reverse_print();

	return 0;
}
*/