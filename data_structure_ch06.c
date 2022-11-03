// 6. ���Ḯ��Ʈ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

// 6.1 �迭 ����Ʈ
# define MAX_LIST_SIZE 100 // ����Ʈ�� �ִ�ũ��

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE]; // �迭 ����
	int size; // ���� ����Ʈ�� ����� �׸���� ����
} ArrayListType;

// ���� ó�� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType* L) {
	L->size = 0;
}

int is_empty(ArrayListType* L) {
	return L->size == 0;
}

int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

// Ư����ġ�� �� ��ȯ
element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 ||  pos >= L->size)
		error("��ġ ����");
	return L->array[pos];
}

// ����Ʈ ���
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

// �׸� �߰� ����
void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item;
}

// ������ ��ġ�� �����ϴ� ����
void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

// �׸� ���� ����
element delete(ArrayListType* L, int pos) {
	element item;

	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	item = L->array[pos];
	for (int i = pos; i < (L->size-1); i++) {
		L->array[i] = L->array[i + 1];
	}
	L->size--;
	return item;
}

void insert_first(ArrayListType* L, element item);
void clear(ArrayListType* L);
int get_length(ArrayListType* L);
void replace(ArrayListType* L, int pos, element item);

int main() {

	ArrayListType list;
	init(&list);
	insert(&list, 0, 10); print_list(&list);
	insert(&list, 0, 20); print_list(&list);
	insert(&list, 0, 30); print_list(&list);
	insert_last(&list, 40); print_list(&list);
	delete(&list, 0); print_list(&list);
	insert_first(&list, 50); print_list(&list);
	
	ArrayListType* L = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(L);
	insert_last(L, 10); print_list(L);
	insert_last(L, 20); print_list(L);
	insert_last(L, 30); print_list(L);
	free(L);

	return 0;

}

// ��������1. insert_first(list, item) ���� ����

void insert_first(ArrayListType * L,element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("����Ʈ ���� �÷ο�");
	}
	for (int i = (L->size-1); i >= 0 ; i--) {
		L->array[i + 1] = L->array[i];
	}
	L->array[0] = item;
	L->size++;

}

//Quiz clear, replace, get_length ���� ����

//clear ���� ����
void clear(ArrayListType* L) {
	L->size = 0;
}

//replace ���� ����
void replace(ArrayListType* L, int pos, element item) {
	if (!is_empty(L) && (pos >= 0) && (pos < L->size - 1)) {
		L->array[pos] = item;
	}
}

//get_length ���� ����
int get_length(ArrayListType* L) {

	return L->size;
}*/

// 6.7 ��ü ���Ḯ��Ʈ ���α׷�

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//���� ó�� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

//pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {

	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

//�׽�Ʈ ���α׷�
int main() {

	ListNode* head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head,i);
		print_list(head);
	}
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}


	return 0;
}

// ��������3

element get_entry(ListNode* L, int index) {

	for (int i = 0; i < index; i++) {
		L = L->link;		
	}
	return L->data;
}

int get_length(ListNode* L) {
	int list_length = 0;

	while (L!= NULL) {
		list_length++;
		L = L->link;
	}
	return list_length;

}*/

// �ܾ���� �����ϴ� ���Ḯ��Ʈ
/*
typedef struct {
	char name[100];
} element;

typedef struct {
	element data;
	struct ListNode* link;
} ListNode;

// ���� ó�� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%s->", p->data.name);
	}
	printf("NULL \n");
}

//�׽�Ʈ ���α׷�
int main() {

	ListNode* head = NULL;
	element data;

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	print_list(head);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	print_list(head);

	return 0;
}*/

// Ư���� ���� Ž���ϴ� �Լ� 

/*
typedef int element;

typedef struct {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

ListNode* search_list(ListNode* head, element x) {
	ListNode* p = head;

	while (p!= NULL) {
		if (p->data == x) return p;
		p = p->link;
	}
	return NULL; // Ž�� ����
}

// �׽�Ʈ ���α׷�
int main() {

	ListNode* head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);
	if (search_list(head, 30) != NULL)
		printf("����Ʈ���� 30�� ã�ҽ��ϴ�. \n");
	else
		printf("����Ʈ���� 30�� ã�� ���߽��ϴ�. \n");
	return 0;
}
*/


//�� ���� ����Ʈ�� �ϳ��� ��ġ�� �Լ� �ۼ�
/*
typedef int element;

typedef struct {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

ListNode* concat_list(ListNode* head1, ListNode* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL) {
			p = p->link;
		}
		p->link = head2;
		return head1;
	}
}

//�׽�Ʈ ���α׷�
int main() {

	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);

	head2 = insert_first(head2, 40);
	head2 = insert_first(head2, 50);
	print_list(head2);

	ListNode* total = concat_list(head1, head2);
	print_list(head1);
	return 0;
}*/


// ����Ʈ�� �������� ����� �Լ�

/*
typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

ListNode* reverse(ListNode* head) {
	// ��ȸ �����ͷ� p, q, r�� ���
	ListNode* p, * q, * r;

	p = head; // p�� �������� ���� ����Ʈ
	q = NULL; // q�� �������� ���� ���
	while (p != NULL) {
		r = q; // r�� �������� �� ����Ʈ
			   // r�� q, q�� p�� ���ʷ� ���󰣴�
		q = p;
		p = p->link;
		q->link = r;
	}

	return q; // �������� ����Ʈ�� head �ּ� return
}


//�׽�Ʈ ���α׷�
int main() {

	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);

	head2 = reverse(head1);
	print_list(head2);
	return 0;

}*/

//���α׷� 6.9 ���� ����Ʈ�� ������ ���׽� ���� ���α׷�

/*
typedef struct {
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;

// ���� ����Ʈ ���
typedef struct {
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

// �����Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ����Ʈ ��� ���� �Լ�
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist�� ���� ����Ʈ�� ����� ����Ű�� ������, coef�� ���, expon�� ����
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("�޸� �Ҵ� ����");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	// a�� ���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ��� ��� ���׽����� ����
	for (; a != NULL; a = a->link) {
		insert_last(plist3, a->coef, a->expon);
	}
	
	for (; b != NULL; b = b->link) {
		insert_last(plist3, b->coef, b->expon);
	}

}


void poly_print(ListType* plist) {
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%dx^%d + ", p->coef, p->expon);
	}
	printf("\n");
}

int main() {

	ListType* list1, * list2, * list3;

	// ���Ḯ��Ʈ ��� ����
	list1 = create();
	list2 = create();
	list3 = create();

	// ���׽� 1�� ����
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	// ���׽� 2�� ����
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	// ���׽� 3 = ���׽� 1 + ���׽� 2
	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1); free(list2); free(list3);

	return 0;
}*/

//�������� 9~12.

/*
typedef int element;
typedef struct {
	element data;
	struct	ListNode* link;
} ListNode;

// ���� ó�� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}


ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = head->link;
	free(removed);
	return head;
}

//pre�� ����Ű�� ����� ���� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}


ListNode* insert_last(ListNode* head, element value) {
	
	ListNode* new_head = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = NULL;
	for (; head->link != NULL; head = head->link)
	;
	head->link= p;
	return new_head;

}


// pre�� ����Ű�� ����� ���� ��� ����
ListNode* delete(ListNode* head, ListNode* pre) {

	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

ListNode * make_node(ListNode *head) {
	int node_num = 0, data_num;
	printf("����� ����: ");
	scanf("%d", &node_num);

	if (node_num == 0) return head;
	printf("��� #1 ������ : ");
	scanf("%d", &data_num);
	head = insert_first(head, data_num);

	for (int i = 2; i <= node_num; i++) {

		printf("��� #%d ������ : ",i);
		scanf("%d", &data_num);
		head = insert_last(head, data_num);

	}
	return head;
}

void print_list1(ListNode* head) {
	printf("������ ���� ����Ʈ: ");
	ListNode* p;
	for (p = head; p->link != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("%d\n", p->data);

}

void count_num(ListNode* head) {
	int node_num = 0;
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		node_num++;
	printf("���Ḯ��Ʈ ����� ����: %d\n", node_num);
}

void node_sum(ListNode* head) {
	int sum = 0;
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		sum += p->data;
	printf("���Ḯ��Ʈ�� �������� ��: %d\n", sum);

}

void find_data_num(ListNode* head) {
	int key, key_num = 0;
	printf("Ž���� ������ ���� �Է��Ͻÿ�: ");
	scanf("%d", &key);
	ListNode* p;
	for (p = head; p != NULL; p = p->link) {
		if (p->data == key) key_num++;
	}

	printf("%d�� ���Ḯ��Ʈ���� %d�� ��Ÿ���ϴ�.\n", key, key_num);
		
}

int main() {
	ListNode* head = NULL;
	head = make_node(head);
	print_list1(head);
	count_num(head);
	node_sum(head);
	find_data_num(head);
	return 0;
}*/

// �������� 13

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//���� ó�� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

//pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {

	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

ListNode* delete_num(ListNode* head, element num) {
	ListNode* pre = NULL;
	ListNode* p = head;
	while(p != NULL) {
		if (p->data == num && p == head) {
			p = p->link;
			head = delete_first(head);
			continue;
		}
		else if (p->data == num) {
			p = p->link;
			head = delete(head, pre);
			continue;
		}
		pre = p;
		p = p->link;
	}

	return head;
}


int main() {
	ListNode* head = NULL;
	head = insert_first(head, 1);
	head = insert_first(head, 2);
	head = insert_first(head, 3);
	head = insert_first(head, 2);
	head = insert_first(head, 1);
	head = insert_first(head, 4);
	print_list(head);
	head = delete_num(head, 2);
	print_list(head);
	return 0;
}*/

//�������� 14.
/*
typedef struct {
	char name[10];
	int age;
	double height;
} element;

typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//���� ó�� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

//pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
*/

// �������� 15.

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//���� ó�� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

//pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {

	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

void find_max_min(ListNode* head) {

	if (head == NULL) {
		printf("�ִ񰪰� �ּڰ��� �����ϴ�.\n");
		return;
	}
	int max = head->data, min = head->data;
	
	for (; head != NULL; head = head->link) {
		if (max < head->data) max = head->data;
		if (min > head->data) min = head->data;
	}
	printf("�ִ� : %d, �ּڰ� : %d\n", max, min);

}


int main() {

	ListNode* head = NULL;
	head = insert_first(head, 1);
	head = insert_first(head, 2);
	head = insert_first(head, 3);
	head = insert_first(head, 4);
	head = insert_first(head, 5);
	head = insert_first(head, 6);
	print_list(head);
	find_max_min(head);

	return 0;
}*/

// �������� 16.

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//���� ó�� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

//pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {

	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

ListNode* delete_odd_node(ListNode* head) {
	head = delete_first(head);
	ListNode* p = head;
	ListNode* pre = NULL;
	int pivot = 0;
	while (p != NULL) {
		if (pivot == 1) {
			p = p->link;
			pivot = 0;
			head = delete(head, pre);
			continue;
		}
		pre = p;
		p = p->link;
		pivot = 1;
	}
	return head;
}

int main() {

	ListNode* head = NULL;
	head = insert_first(head, 1);
	head = insert_first(head, 2);
	head = insert_first(head, 3);
	head = insert_first(head, 4);
	head = insert_first(head, 5);
	head = insert_first(head, 6);
	print_list(head);
	head = delete_odd_node(head);
	print_list(head);
	return 0;
}*/

// �������� 17.

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//���� ó�� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

//pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {

	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

ListNode* alternate(ListNode* head1, ListNode* head2) {

	ListNode* head3 = head1; ListNode* head_3 = head1;
	ListNode* head_1 = head1->link; ListNode* head_2 = head2;
	int pivot = 2; // pivot �� 2�̸� head2 ����Ʈ �ű��, �ƴϸ� head1 ����Ʈ �ű��


	while (head_1 != NULL && head_2 != NULL) {
		if (pivot == 2) { // head2 ����Ʈ �ű��
			head_3->link = head_2;
			head_2 = head_2->link;
			head_3 = head_3->link;
			pivot = 1;
		}

		else { // head1 ����Ʈ �ű��
			head_3->link = head_1;
			head_1 = head_1->link;
			head_3 = head_3->link;
			pivot = 2;
		}
	}
	
	if (head_1 == NULL) head_3->link = head_2;
	else head_3->link = head_1;

	return head3;

}


int main() {

	ListNode* head1 = NULL;
	head1 = insert_first(head1, 1);
	head1 = insert_first(head1, 2);
	head1 = insert_first(head1, 3);
	head1 = insert_first(head1, 4);
	head1 = insert_first(head1, 5);
	head1 = insert_first(head1, 6);
	print_list(head1);


	ListNode* head2 = NULL;
	head2 = insert_first(head2, 7);
	head2 = insert_first(head2, 8);
	head2 = insert_first(head2, 9);
	head2 = insert_first(head2, 10);
	head2 = insert_first(head2, 11);
	head2 = insert_first(head2, 12);
	print_list(head2);


	ListNode* head3 = NULL;
	head3 = alternate(head1, head2);
	print_list(head3);

	return 0;

}*/


// �������� 18.

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

//pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {

	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

ListNode* merge(ListNode* head1, ListNode* head2) {

	ListNode* head_1 = head1; ListNode* head_2 = head2; ListNode* head3 = NULL;
	ListNode* head_3;
	if (head_1->data > head_2->data) {
		head3 = head_2;
		head_2 = head_2->link;
		head_3 = head3;
	}
	else {
		head3 = head_1;
		head_1 = head_1->link;
		head_3 = head3;
	}

	while (head_1 != NULL && head_2 != NULL) {
		if (head_1->data > head_2->data) {
			head_3->link = head_2;
			head_2 = head_2->link;
			head_3 = head_3->link;
		}
		else {
			head_3->link = head_1;
			head_1 = head_1->link;
			head_3 = head_3->link;
		}
	}

	if (head_1 == NULL) head_3->link = head_2;
	else head_3->link = head_1;

	return head3;

}


int main() {

	ListNode* head1 = NULL;
	head1 = insert_first(head1, 9);
	head1 = insert_first(head1, 7);
	head1 = insert_first(head1, 5);
	head1 = insert_first(head1, 3);
	head1 = insert_first(head1, 1);
	print_list(head1);


	ListNode* head2 = NULL;
	head2 = insert_first(head2, 6);
	head2 = insert_first(head2, 4);
	head2 = insert_first(head2, 2);
	print_list(head2);

	ListNode* head3 = NULL;
	head3 = merge(head1, head2);
	print_list(head3);

	return 0;
}*/

// �������� 19

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

//pre�� ����Ű�� ����� ���� ��带 �����Ѵ�.
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

void print_list(ListNode* head) {

	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}

void split(ListNode* head) {
	
	ListNode* head_p = head;
	
	ListNode* a = NULL; ListNode* a_pre = NULL;
	ListNode* b = NULL; ListNode* b_pre = NULL;
	int pivot = 0;

	a = insert_first(a, head_p->data);
	a_pre = a;
	head_p = head_p->link;
	b = insert_first(b, head_p->data);
	b_pre = b;
	head_p = head_p->link;

	while (head_p != NULL) {
		if (pivot == 0) {
			a = insert(a, a_pre, head_p->data);
			a_pre = a_pre->link;
			head_p = head_p->link;
			pivot = 1;
		}

		else {
			b = insert(b, b_pre, head_p->data);
			b_pre = b_pre->link;
			head_p = head_p->link;
			pivot = 0;
		}
	}


	print_list(a);
	print_list(b);
}


int main() {

	ListNode* head = NULL;
	head = insert_first(head, 9);
	head = insert_first(head, 8);
	head = insert_first(head, 7);
	head = insert_first(head, 6);
	head = insert_first(head, 5);
	head = insert_first(head, 4);
	head = insert_first(head, 3);
	head = insert_first(head, 2);
	head = insert_first(head, 1);
	print_list(head);
	split(head);

	return 0;
}*/

// �������� 20~21

/*
typedef struct {
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;

// ���� ����Ʈ ���
typedef struct {
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

// �����Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ����Ʈ ��� ���� �Լ�
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist�� ���� ����Ʈ�� ����� ����Ű�� ������, coef�� ���, expon�� ����
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("�޸� �Ҵ� ����");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	// a�� ���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ��� ��� ���׽����� ����
	for (; a != NULL; a = a->link) {
		insert_last(plist3, a->coef, a->expon);
	}

	for (; b != NULL; b = b->link) {
		insert_last(plist3, b->coef, b->expon);
	}

}


void poly_print(ListType* plist) {
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%dx^%d + ", p->coef, p->expon);
	}
	printf("\n");
}

void poly_eval(ListType* plist, int x_num) {
	int sum = 0;
	int temp = 1;
	ListNode* ptr = plist->head;
	while (ptr != NULL) {
		for (int i = 0; i < ptr->expon; i++) {
			temp *= x_num;
		}
		sum += (ptr->coef) * temp;
		temp = 1;
		ptr = ptr->link;
	}

	printf("�� : %d\n", sum);

}

int main() {
	ListType* plist_A = create();
	ListType* plist_B = create();
	ListType* plist_C = create();
	//����Ʈ A ����
	insert_last(plist_A, 3, 6);
	insert_last(plist_A, 7, 3);
	insert_last(plist_A, -2, 2);
	insert_last(plist_A, -9, 0);
	poly_print(plist_A);
	poly_eval(plist_A, 2);

	// ����Ʈ B ����
	insert_last(plist_B, -2, 6);
	insert_last(plist_B, -4, 4);
	insert_last(plist_B, 6, 2);
	insert_last(plist_B, 6, 1);
	insert_last(plist_B, 1, 0);
	poly_print(plist_B);
	poly_eval(plist_B, 2);


	poly_add(plist_A, plist_B, plist_C);
	poly_print(plist_C);


	return 0;
}

*/

// �������� 22
/*
# define MAX_LIST_SIZE 100 // ����Ʈ�� �ִ�ũ��

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE]; // �迭 ����
	int size; // ���� ����Ʈ�� ����� �׸���� ����
} ArrayListType;

// ���� ó�� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ����Ʈ �ʱ�ȭ �Լ�
void init(ArrayListType* L) {
	L->size = 0;
}

void add(ArrayListType* L, element item) {
	int i = L->size-1;
	while (L->array[i] > item && i < MAX_LIST_SIZE && i > 0) {
		L->array[i + 1] = L->array[i];
		i = i - 1;
	}
	if (i < 0) {
		L->array[0] = item;
		L->size++;
	}
	else if(i>= 0 && i<MAX_LIST_SIZE -1) {
		L->array[i+1] = item;
		L->size++;
	}
}


void delete(ArrayListType* L, element item) {
	int i = 0;

	while (i <= L->size - 1) {
		if (L->array[i] == item) {
			for (int j = i; j < L->size-1; j++) {
				L->array[j] = L->array[j + 1];
			}
			L->size--;
		}
	}
}

void clear(ArrayListType* L) {
	L->size = 0;
}

int is_in_list(ArrayListType* L, int item) {
	for (int i = 0; i < L->size; i++) {
		if (L->array[i] == item) return 1;
	}

	return 0;
}

int get_length(ArrayListType* L) {
	return L->size;
}

int is_empty(ArrayListType* L) {
	return L->size == 0;
}

int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

void display(ArrayListType* L) {
	for (int i = 0; i < L->size - 1; i++) {
		printf("%d->", L->array[i]);
	}
}

int main() {

	return 0;
}*/

//�������� 23
/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* add(ListNode* head, element item) {
	ListNode* head_p = head;
	ListNode* pre = head;
	ListNode* p = (ListNode *)malloc(sizeof(ListNode));
	p->data = item;

	if (head_p == NULL) {
		head = p;
		return head;
	}

	while (head_p != NULL && p->data > head_p->data) {
		pre = head_p;
		head_p = head_p->link;
	}
	pre->link = p;
	p->link = head_p;
	
	return head;
}

ListNode* delete(ListNode* head, element item) {
	ListNode* pre = NULL; ListNode* head_p = head;
	while (head_p != NULL) {
		if (head_p->data == item) {
			ListNode* removed;
			removed = head_p;
			pre->link = removed->link;
			removed->link = NULL;
			free(removed);
			head_p = pre->link;
		}
		else {
			pre = head_p;
			head_p = head_p->link;
		}
	}

	return head;
}

void clear(ListNode* head) {
	ListNode* removed = NULL;
	while (head != NULL) {
		removed = head;
		head = head->link;
		removed->link = NULL;
		free(removed);
	}
}

int is_in_list(ListNode* head, element item) {
	
	ListNode* head_p = head;
	while (head_p!= NULL) {
		if (head_p->data == item) return 1;
		head_p = head_p->link;
	}

	return 0;
}

int get_length(ListNode* head) {
	ListNode* head_p = head;
	int num = 0;
	while (head_p!= NULL) {
		num++;
		head_p = head_p->link;
	}
	return num;
}

int is_empty(ListNode* head) {
	return head == NULL;
}

void display(ListNode* head) {
	for (ListNode* head_p = head; head_p != NULL; head_p = head_p->link) {
		printf("%d->", head_p->data);
	}
	printf("NULL\n");
}*/


// �������� 24.
/*
typedef struct {
	int col;
	int row;
	int num;
	matrix_element* link;
}matrix_element;

typedef struct {
	int total_col;
	int total_row;
	matrix_element* head;
} sparse_matrix;
*/

