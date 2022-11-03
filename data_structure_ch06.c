// 6. 연결리스트 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

// 6.1 배열 리스트
# define MAX_LIST_SIZE 100 // 리스트의 최대크기

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 초기화 함수
void init(ArrayListType* L) {
	L->size = 0;
}

int is_empty(ArrayListType* L) {
	return L->size == 0;
}

int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

// 특정위치의 값 반환
element get_entry(ArrayListType* L, int pos) {
	if (pos < 0 ||  pos >= L->size)
		error("위치 오류");
	return L->array[pos];
}

// 리스트 출력
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++)
		printf("%d->", L->array[i]);
	printf("\n");
}

// 항목 추가 연산
void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버플로우");
	}
	L->array[L->size++] = item;
}

// 임의의 위치에 삽입하는 연산
void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) {
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item;
		L->size++;
	}
}

// 항목 삭제 연산
element delete(ArrayListType* L, int pos) {
	element item;

	if (pos < 0 || pos >= L->size)
		error("위치 오류");
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

// 도전문제1. insert_first(list, item) 연산 구현

void insert_first(ArrayListType * L,element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("리스트 오버 플로우");
	}
	for (int i = (L->size-1); i >= 0 ; i--) {
		L->array[i + 1] = L->array[i];
	}
	L->array[0] = item;
	L->size++;

}

//Quiz clear, replace, get_length 연산 구현

//clear 연산 구현
void clear(ArrayListType* L) {
	L->size = 0;
}

//replace 연산 구현
void replace(ArrayListType* L, int pos, element item) {
	if (!is_empty(L) && (pos >= 0) && (pos < L->size - 1)) {
		L->array[pos] = item;
	}
}

//get_length 연산 구현
int get_length(ArrayListType* L) {

	return L->size;
}*/

// 6.7 전체 연결리스트 프로그램

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//오류 처리 함수
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

// 노드 pre 뒤에 새로운 노드 삽입
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

//pre가 가리키는 노드의 다음 노드를 삭제한다.
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

//테스트 프로그램
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

// 도전문제3

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

// 단어들을 저장하는 연결리스트
/*
typedef struct {
	char name[100];
} element;

typedef struct {
	element data;
	struct ListNode* link;
} ListNode;

// 오류 처리 함수
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

//테스트 프로그램
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

// 특정한 값을 탐색하는 함수 

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
	return NULL; // 탐색 실패
}

// 테스트 프로그램
int main() {

	ListNode* head = NULL;

	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);
	if (search_list(head, 30) != NULL)
		printf("리스트에서 30을 찾았습니다. \n");
	else
		printf("리스트에서 30을 찾지 못했습니다. \n");
	return 0;
}
*/


//두 개의 리스트를 하나로 합치는 함수 작성
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

//테스트 프로그램
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


// 리스트를 역순으로 만드는 함수

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
	// 순회 포인터로 p, q, r을 사용
	ListNode* p, * q, * r;

	p = head; // p는 역순으로 만들 리스트
	q = NULL; // q는 역순으로 만들 노드
	while (p != NULL) {
		r = q; // r은 역순으로 된 리스트
			   // r은 q, q는 p를 차례로 따라간다
		q = p;
		p = p->link;
		q->link = r;
	}

	return q; // 뒤집어진 리스트의 head 주소 return
}


//테스트 프로그램
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

//프로그램 6.9 연결 리스트로 구현한 다항식 덧셈 프로그램

/*
typedef struct {
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;

// 연결 리스트 헤더
typedef struct {
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

// 오류함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 헤더 생성 함수
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, expon는 차수
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
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

	// a나 비중 하나가 먼저 끝난게 되면 남아있는 항들을 모두 결과 다항식으로 복사
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

	// 연결리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();

	// 다항식 1을 생성
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	// 다항식 2를 생성
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_print(list1);
	poly_print(list2);

	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1); free(list2); free(list3);

	return 0;
}*/

//연습문제 9~12.

/*
typedef int element;
typedef struct {
	element data;
	struct	ListNode* link;
} ListNode;

// 오류 처리 함수
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

//pre가 가리키는 노드의 다음 노드 삽입
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


// pre가 가리키는 노드의 다음 노드 삭제
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
	printf("노드의 개수: ");
	scanf("%d", &node_num);

	if (node_num == 0) return head;
	printf("노드 #1 데이터 : ");
	scanf("%d", &data_num);
	head = insert_first(head, data_num);

	for (int i = 2; i <= node_num; i++) {

		printf("노드 #%d 데이터 : ",i);
		scanf("%d", &data_num);
		head = insert_last(head, data_num);

	}
	return head;
}

void print_list1(ListNode* head) {
	printf("생성된 연결 리스트: ");
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
	printf("연결리스트 노드의 개수: %d\n", node_num);
}

void node_sum(ListNode* head) {
	int sum = 0;
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		sum += p->data;
	printf("연결리스트의 데이터의 합: %d\n", sum);

}

void find_data_num(ListNode* head) {
	int key, key_num = 0;
	printf("탐색할 데이터 값을 입력하시오: ");
	scanf("%d", &key);
	ListNode* p;
	for (p = head; p != NULL; p = p->link) {
		if (p->data == key) key_num++;
	}

	printf("%d는 연결리스트에서 %d번 나타납니다.\n", key, key_num);
		
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

// 연습문제 13

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//오류 처리 함수
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

// 노드 pre 뒤에 새로운 노드 삽입
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

//pre가 가리키는 노드의 다음 노드를 삭제한다.
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

//연습문제 14.
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

//오류 처리 함수
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

// 노드 pre 뒤에 새로운 노드 삽입
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

//pre가 가리키는 노드의 다음 노드를 삭제한다.
ListNode* delete(ListNode* head, ListNode* pre) {
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}
*/

// 연습문제 15.

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//오류 처리 함수
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

// 노드 pre 뒤에 새로운 노드 삽입
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

//pre가 가리키는 노드의 다음 노드를 삭제한다.
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
		printf("최댓값과 최솟값은 없습니다.\n");
		return;
	}
	int max = head->data, min = head->data;
	
	for (; head != NULL; head = head->link) {
		if (max < head->data) max = head->data;
		if (min > head->data) min = head->data;
	}
	printf("최댓값 : %d, 최솟값 : %d\n", max, min);

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

// 연습문제 16.

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//오류 처리 함수
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

// 노드 pre 뒤에 새로운 노드 삽입
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

//pre가 가리키는 노드의 다음 노드를 삭제한다.
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

// 연습문제 17.

/*
typedef int element;
typedef struct {
	element data;
	struct ListNode* link;

} ListNode;

//오류 처리 함수
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

// 노드 pre 뒤에 새로운 노드 삽입
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

//pre가 가리키는 노드의 다음 노드를 삭제한다.
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
	int pivot = 2; // pivot 이 2이면 head2 리스트 옮기기, 아니면 head1 리스트 옮기기


	while (head_1 != NULL && head_2 != NULL) {
		if (pivot == 2) { // head2 리스트 옮기기
			head_3->link = head_2;
			head_2 = head_2->link;
			head_3 = head_3->link;
			pivot = 1;
		}

		else { // head1 리스트 옮기기
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


// 연습문제 18.

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

// 노드 pre 뒤에 새로운 노드 삽입
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

//pre가 가리키는 노드의 다음 노드를 삭제한다.
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

// 연습문제 19

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

// 노드 pre 뒤에 새로운 노드 삽입
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

//pre가 가리키는 노드의 다음 노드를 삭제한다.
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

// 연습문제 20~21

/*
typedef struct {
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;

// 연결 리스트 헤더
typedef struct {
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;

// 오류함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 헤더 생성 함수
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, expon는 차수
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
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

	// a나 비중 하나가 먼저 끝난게 되면 남아있는 항들을 모두 결과 다항식으로 복사
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

	printf("합 : %d\n", sum);

}

int main() {
	ListType* plist_A = create();
	ListType* plist_B = create();
	ListType* plist_C = create();
	//리스트 A 생성
	insert_last(plist_A, 3, 6);
	insert_last(plist_A, 7, 3);
	insert_last(plist_A, -2, 2);
	insert_last(plist_A, -9, 0);
	poly_print(plist_A);
	poly_eval(plist_A, 2);

	// 리스트 B 생성
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

// 연습문제 22
/*
# define MAX_LIST_SIZE 100 // 리스트의 최대크기

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE]; // 배열 정의
	int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType;

// 오류 처리 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 리스트 초기화 함수
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

//연습문제 23
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


// 연습문제 24.
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

