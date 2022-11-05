// 7. ���Ḯ��Ʈ 2

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 7.3 ���� ���� ����Ʈ �׽�Ʈ ���α׷�
 
/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;
} ListNode;

// ����Ʈ�� �׸� ���
void print_list(ListNode* head) {
	ListNode* p;

	if (head == NULL) return 0;
	p = head->link;

	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); // ������ ��� ���
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

ListNode* insert_last(ListNode* head, element data) {// * ���� ���Ḯ��Ʈ ���� ���� 
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

// ���α׷� 7.4 ��Ƽ����

/*
typedef char element[100]; // element�� char [100]������ ����
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
		printf("���� ����= %s \n", p->data);
		p = p->link;
	}
	return 0;
}*/

// ���� ���� ����Ʈ���� �����Լ�

/*
typedef int element;
typedef struct DListNode { // ���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

// ���� ���Ḯ��Ʈ�� ��带 ���
void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

// ���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// ��� removed�� �����Ѵ�.
void ddelete(DListNode* head, DListNode* removed) {
	
	if (removed == head) return;
	removed->rlink->llink = removed->llink;
	removed->llink->rlink = removed->rlink;
	free(removed);
}

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main() {
	
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		// ��� ����� �����ʿ� ����
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n���� �ܰ�\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}
*/

// ���α׷� 7.8 mp3 �÷��̾� ���α׷�

/*
typedef char element[100];
typedef struct DListNode { // ���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

DListNode* current;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

// ���� ���� ����Ʈ�� ��带 ���
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

// ��� newnode�� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// ��� removed�� �����Ѵ�.
void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
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
		printf("\n��ɾ �Է��Ͻÿ�(<, >, q): ");
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
	// ���� �޸� ���� �ڵ带 ���⿡
	return 0;
}*/

// ���α׷� 7.9 ����� ���� ���α׷�

/*
typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// �ʱ�ȭ �Լ�
void init(LinkedStackType* s) {
	s->top = NULL;
}

// ���� ���� ���� �Լ�
int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

// ��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s) {
	return 0;
}

// ���� �Լ�
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

// ���� �Լ�
element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
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

// ��ũ �Լ�
element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
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


// ���α׷� 7.12 ����� ť ���α׷�

/*
typedef int element;
typedef struct { // ť�� ����� Ÿ��
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	QueueNode* front, * rear;
} LinkedQueueType;

// ť �ʱ�ȭ �Լ�
void init(LinkedQueueType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);
}


// ��ȭ ���� ���� �Լ�
int is_full(LinkedQueueType* q) {
	return 0;
}


// ���� �Լ�
void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp; // ���� �߿�
		q->rear = temp;
	}
}

// ���� �Լ�
element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {
		fprintf(stderr, "������ �������\n");
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

// ���� �� ť �׽�Ʈ �Լ�
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

// �������� 3-4.
/*
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//����Ʈ�� �׸����
void print_list(ListNode* head) {
	ListNode* p;

	if (head == NULL) return;
	p = head->link; // p�� ó������ ����
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d\n", p->data); // ������ ��� ���
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

// ���� ���� ����Ʈ���� data�� ������ �ִ� ��带 ã�� ��ȯ�Ѵ�
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

// ���� ���� ����Ʈ�� ����� �������� ������ ��ȯ�Ѵ�.
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

// �������� 6-7.

/*
typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}


// ���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}


// ���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->rlink = before->rlink;
	newnode->llink = before;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// ��� removed�� �����Ѵ�.
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
	printf("�������� ������ �Է��Ͻÿ�: ");
	scanf("%d", &data_num);

	for (int i = 1; i <= data_num; i++) {
		printf("��� #%d�� �����͸� �Է��Ͻÿ�: ", i);
		scanf("%d", &element_n);
		dinsert(p, element_n);
		p = p->rlink;
	}

	// p�� ���� ������ ��带 ����Ŵ
	printf("�����͸� �������� ���: ");
	while (p != phead) {
		printf("%d ", p->data);
		p = p->llink;
	} 

}

// ���� ���� ����Ʈ���� data�� ������ �ִ� ��带 ã�Ƽ� ��ȯ�Ѵ�.
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