// 9. 우선순위 큐

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 9.3 히프트리 테스트 프로그램

/*
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 생성 함수
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h) {
	h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입
}


// 삭제 함수
element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		// 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key) break;
		// temp의 값이 자식노드의 가장 큰 값보다 작으면 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;


}
*/
/*
int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;

	heap = create();
	init(heap);

	// 삽입
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	// 삭제
	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key); 
	e6 = delete_max_heap(heap);
	printf("< %d >\n", e6.key);

	free(heap);
	return 0;

}
*/

// 우선 순위 큐인 히프를 이용한 정렬

/*
void heap_sort(element a[], int n) {

	int i;
	HeapType* h;

	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}

	for (i = n - 1; i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
void insert_min_heap(HeapType* h, element item) {
	int i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h) {
	element item, temp;
	int parent, child;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1; child = 2;

	while (child <= h->heap_size) {

		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key < h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;

	return item;
}

void heap_sort_inverse(element a[], int n) {
	int i;
	HeapType* h;

	h = create();
	init(h);

	for (i = 0; i < n; i++) {
		insert_min_heap(h, a[i]);
	}

	for (i = 0; i < n; i++) {
		delete_min_heap(h);
	}

	free(h);
}

#define SIZE 8
int main() {
	element list[SIZE] = { 23, 56, 11, 9, 56, 99, 27, 34 };
	heap_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}*/

//프로그램 9.5 LPT 프로그램

/*

#define MAX_ELEMENT 200
typedef struct {
	int id;
	int avail;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// 생성 함수
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h) {
	h->heap_size = 0;
}


// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.avail < h->heap[i / 2].avail)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

// 삭제 함수
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		// 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].avail > h->heap[child + 1].avail))
			child++;
		if (temp.avail < h->heap[child].avail) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

# define JOBS 7
# define MACHINES 3

int main() {

	int jobs[JOBS] = { 8, 7, 6, 5, 3, 2, 1 }; // 작업은 정렬되어 있다고 가정
	element m = { 0, 0 };
	HeapType* h;
	h = create();
	init(h);

	// 여기서 avail 값은 기계가 사용 가능하게 되는 시간이다.
	for (int i = 0; i < MACHINES; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}

	// 최소 히프에서 기계를 꺼내서 작업을 할당하고 사용가능 시간을 증가 시킨 후에
	// 다시 최소 히프에 추가한다.
	for (int i = 0; i < JOBS; i++) {
		m = delete_min_heap(h);
		printf("JOB %d을 시간=%d부터 시간=%d까지 기계 %d번에 할당한다. \n",
			i, m.avail, m.avail + jobs[i] - 1, m.id);
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}
	return 0;
}
*/

// 프로그램 9.6 허프만 코드 프로그램 (최소 히프 사용)

/*
#define MAX_ELEMENT 200

typedef struct TreeNode {
	int weight;
	char ch;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

typedef struct {
	TreeNode* ptree;
	char ch;
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// 생성 함수
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h) {
	h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입
}

// 삭제 함수
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1; child = 2;

	while (child <= h->heap_size) {
		// 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key < h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// 이진 트리 생성 함수
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}

// 이진 트리 제거 함수
void destroy_tree(TreeNode* root) {
	if (root == NULL) return;
	destroy_tree(root->right);
	destroy_tree(root->left);
	free(root);
}

int is_leaf(TreeNode* root) {
	return !(root->left) && !(root->right);
}

void print_array(int codes[], int n) {
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

void print_codes(TreeNode* root, int codes[], int top) {

	// 1을 저장하고 순환호출한다.
	if (root->left) {
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}

	// 0을 저장하고 순환호출한다.
	if (root->right) {
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	}

	// 단말노드이면 코드를 출력한다.
	if (is_leaf(root)) {
		printf("%c: ", root->ch);
		print_array(codes, top);
	}
}

// 허프만 코드 생성 함수
void huffman_tree(int freq[], char ch_list[], int n) {

	int i;
	TreeNode* node, * x;
	HeapType* heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;

	heap = create();
	init(heap);
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap, e);
	}

	for (i = 1; i < n; i++) { // n-1 번                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		// 최소값을 가지는 두 개의 노드를 삭제
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
		// 두 개의 노드를 합친다.
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d+%d->%d \n", e1.key, e2.key, e.key);
		insert_min_heap(heap, e);
	}
	e = delete_min_heap(heap); // 최종 트리
	print_codes(e.ptree, codes, top);
	destroy_tree(e.ptree);
	free(heap);
}

int main() {

	char ch_list[] = { 's', 'i', 'n', 't', 'e' };
	int freq[] = { 4, 6, 8, 12, 15 };
	huffman_tree(freq, ch_list, 5);
	return 0;
}
*/

// 연습문제 9

/*
typedef struct {
	int key;
	char str[100];
} element;

typedef struct{
	element heap[100];
	int heap_size;
} HeapType;

HeapType * create() {
	HeapType* temp = (HeapType*)malloc(sizeof(HeapType));
	return temp;
}

void init(HeapType* temp) {
	temp->heap_size = 0;
}

void insert_max_heap(HeapType* h, element temp) {
	
	int i = ++(h->heap_size);

	while ((i != 1) && (h->heap[i].key > h->heap[i/2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = temp;
}

element delete_max_heap(HeapType* h) {

	element item = h->heap[1];
	element temp = h->heap[(h->heap_size)--];

	int parent = 1, child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key)) {
			child++;
		}

		if (temp.key > h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}

	h->heap[parent] = temp;
	return item;
}

void heap_priority(HeapType* h) {

	while (1) {
		char opt;
		printf("삽입(i), 삭제(d): ");
		scanf("%c", &opt);
		getchar();
		if (opt == 'i') {
			element item;
			printf("할일: ");
			gets(item.str); 
			printf("우선순위: ");
			scanf("%d", &item.key);
			getchar();
			insert_max_heap(h, item);
		}
		else if (opt == 'd') {
			element temp = delete_max_heap(h);
			printf("제일 우선 순위가 높은 일은 %s\n", temp.str);
		}
		else return;
	}


}

int main() {

	HeapType* h = create();
	init(h);
	heap_priority(h);
	free(h);
	return 0;
}
*/

// 연습문제 14
/*
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE+1];
	int queue_size;
} priorityQ;

priorityQ* create() {
	priorityQ* temp = (priorityQ*)malloc(sizeof(priorityQ));
	return temp;
}

void init(priorityQ* q) {
	q->queue_size = 0;
}

int is_empty(priorityQ* q) {
	return q->queue_size == 0;
}

int is_full(priorityQ* q) {
	return q->queue_size == MAX_QUEUE_SIZE;
}

void insert(priorityQ* q, element item) {
	if (is_full(q)) {
		printf("큐가 꽉 찼습니다.\n");
		exit(1);
	}
	
	q->data[++(q->queue_size)] = item;
}

element delete(priorityQ* q) {
	if (is_empty(q)) {
		printf("큐가 비었습니다.\n");
		exit(1);
	}
	element temp = q->data[1];
	for (int i = 2; i < q->queue_size; i++) {
		if (temp < q->data[i]) temp = q->data[i];
	}
	(q->queue_size)--;
	return temp;
}

element find(priorityQ* q) {
	if (is_empty(q)) {
		printf("큐가 비었습니다.\n");
		exit(1);
	}
	element temp = q->data[1];
	for (int i = 2; i < q->queue_size; i++) {
		if (temp < q->data[i]) temp = q->data[i];
	}
	return temp;
}
*/

// 연습문제 15
/*
typedef int element;
typedef struct priorityQ {
	element data;
	priorityQ* node;
} priorityQ;

typedef struct {
	int queue_size;
	priorityQ* top;
} priorityQType;

void init(priorityQType* t) {
	t->queue_size = 0;
	t->top = NULL;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
int is_empty(priorityQType* t) {
	return t->queue_size == 0;
}

int is_full(priorityQType* t) {
	return 0;
}

void insert(priorityQType* t, element item) {
	priorityQ* new_node = (priorityQ*)malloc(sizeof(priorityQ));
	new_node->data = item;
	new_node->node = t->top;
	t->top = new_node;
	t->queue_size++;
}

element delete(priorityQType* t) {
	element temp;
	if (is_empty(t)) {
		printf("큐가 비었습니다.\n");
		exit(1);
	}

	priorityQ* pre_find_node = t->top;
	priorityQ* pre_delete_node = t->top;
	element temp = t->top->data;
	// 우선순위가 가장 높은 것을 찾는다.
	for (int i = 1; i < t->queue_size; i++) {
		if (pre_find_node->node->data > temp) {
			pre_delete_node = pre_find_node;
			temp = pre_find_node->node->data;
		}
		pre_find_node = pre_find_node->node;
	}

	// 우선순위가 가장 높은 것이 첫번째 노드일 때,
	if (temp == t->top->data) {
		priorityQ* removed = t->top;
		t->top = removed->node;
		free(removed);
		return temp;
	}
	// 우선 순위가 가장 높은 것이 첫번째 노드가 아닐 때,
	else {
		priorityQ *removed = pre_delete_node->node;
		pre_delete_node->node = removed->node;
		free(removed);
		return temp;
	}


}

element find(priorityQType* t) {
	if (is_empty(t)) {
		printf("큐가 비었습니다.\n");
		exit(1);
	}

	priorityQ* find_node = t->top;
	element temp = t->top->data;
	// 우선순위가 가장 높은 것을 찾는다.
	for (int i = 0; i < t->queue_size; i++) {
		if (find_node->data > temp) {
			temp = find_node->data;
		}
		find_node = find_node->node;
	}

	return temp;
}
*/

// 연습문제 16.

/*
#define MAX_ELEMENT 100;

typedef struct {
	int key;
} element;


typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// 생성 함수
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h) {
	h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // 새로운 노드를 삽입
}

// 삭제 함수
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1; child = 2;

	while (child <= h->heap_size) {
		// 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key < h->heap[child].key) break;
		// 한 단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// 임의의 요소 삭제 함수
element delete_select_node(HeapType *h, int i) { // i번째 인덱스 노드 삭제
	element item = h->heap[i];
	element temp = h->heap[(h->heap_size)--];
	int parent = i, child = 2 * i;
	while (child <= h->heap_size) {
		if((child < h->heap_size) && (h->heap[child].key > h->heap[child+1].key))
			child++;
		if (temp.key < h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;

	return item;
}
*/







