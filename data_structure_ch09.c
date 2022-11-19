// 9. �켱���� ť

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 9.3 ����Ʈ�� �׽�Ʈ ���α׷�

/*
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// ���� �Լ�
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ �Լ�
void init(HeapType* h) {
	h->heap_size = 0;
}

// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��带 ����
}


// ���� �Լ�
element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ�� �� �� ū �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key) break;
		// temp�� ���� �ڽĳ���� ���� ū ������ ������ �� �ܰ� �Ʒ��� �̵�
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

	// ����
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	// ����
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

// �켱 ���� ť�� ������ �̿��� ����

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

//���α׷� 9.5 LPT ���α׷�

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

// ���� �Լ�
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ �Լ�
void init(HeapType* h) {
	h->heap_size = 0;
}


// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.avail < h->heap[i / 2].avail)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

// ���� �Լ�
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].avail > h->heap[child + 1].avail))
			child++;
		if (temp.avail < h->heap[child].avail) break;
		// �� �ܰ� �Ʒ��� �̵�
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

	int jobs[JOBS] = { 8, 7, 6, 5, 3, 2, 1 }; // �۾��� ���ĵǾ� �ִٰ� ����
	element m = { 0, 0 };
	HeapType* h;
	h = create();
	init(h);

	// ���⼭ avail ���� ��谡 ��� �����ϰ� �Ǵ� �ð��̴�.
	for (int i = 0; i < MACHINES; i++) {
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}

	// �ּ� �������� ��踦 ������ �۾��� �Ҵ��ϰ� ��밡�� �ð��� ���� ��Ų �Ŀ�
	// �ٽ� �ּ� ������ �߰��Ѵ�.
	for (int i = 0; i < JOBS; i++) {
		m = delete_min_heap(h);
		printf("JOB %d�� �ð�=%d���� �ð�=%d���� ��� %d���� �Ҵ��Ѵ�. \n",
			i, m.avail, m.avail + jobs[i] - 1, m.id);
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}
	return 0;
}
*/

// ���α׷� 9.6 ������ �ڵ� ���α׷� (�ּ� ���� ���)

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


// ���� �Լ�
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ �Լ�
void init(HeapType* h) {
	h->heap_size = 0;
}

// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��带 ����
}

// ���� �Լ�
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1; child = 2;

	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key < h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// ���� Ʈ�� ���� �Լ�
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}

// ���� Ʈ�� ���� �Լ�
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

	// 1�� �����ϰ� ��ȯȣ���Ѵ�.
	if (root->left) {
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}

	// 0�� �����ϰ� ��ȯȣ���Ѵ�.
	if (root->right) {
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	}

	// �ܸ�����̸� �ڵ带 ����Ѵ�.
	if (is_leaf(root)) {
		printf("%c: ", root->ch);
		print_array(codes, top);
	}
}

// ������ �ڵ� ���� �Լ�
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

	for (i = 1; i < n; i++) { // n-1 ��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		// �ּҰ��� ������ �� ���� ��带 ����
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
		// �� ���� ��带 ��ģ��.
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d+%d->%d \n", e1.key, e2.key, e.key);
		insert_min_heap(heap, e);
	}
	e = delete_min_heap(heap); // ���� Ʈ��
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

// �������� 9

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
		printf("����(i), ����(d): ");
		scanf("%c", &opt);
		getchar();
		if (opt == 'i') {
			element item;
			printf("����: ");
			gets(item.str); 
			printf("�켱����: ");
			scanf("%d", &item.key);
			getchar();
			insert_max_heap(h, item);
		}
		else if (opt == 'd') {
			element temp = delete_max_heap(h);
			printf("���� �켱 ������ ���� ���� %s\n", temp.str);
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

// �������� 14
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
		printf("ť�� �� á���ϴ�.\n");
		exit(1);
	}
	
	q->data[++(q->queue_size)] = item;
}

element delete(priorityQ* q) {
	if (is_empty(q)) {
		printf("ť�� ������ϴ�.\n");
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
		printf("ť�� ������ϴ�.\n");
		exit(1);
	}
	element temp = q->data[1];
	for (int i = 2; i < q->queue_size; i++) {
		if (temp < q->data[i]) temp = q->data[i];
	}
	return temp;
}
*/

// �������� 15
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
		printf("ť�� ������ϴ�.\n");
		exit(1);
	}

	priorityQ* pre_find_node = t->top;
	priorityQ* pre_delete_node = t->top;
	element temp = t->top->data;
	// �켱������ ���� ���� ���� ã�´�.
	for (int i = 1; i < t->queue_size; i++) {
		if (pre_find_node->node->data > temp) {
			pre_delete_node = pre_find_node;
			temp = pre_find_node->node->data;
		}
		pre_find_node = pre_find_node->node;
	}

	// �켱������ ���� ���� ���� ù��° ����� ��,
	if (temp == t->top->data) {
		priorityQ* removed = t->top;
		t->top = removed->node;
		free(removed);
		return temp;
	}
	// �켱 ������ ���� ���� ���� ù��° ��尡 �ƴ� ��,
	else {
		priorityQ *removed = pre_delete_node->node;
		pre_delete_node->node = removed->node;
		free(removed);
		return temp;
	}


}

element find(priorityQType* t) {
	if (is_empty(t)) {
		printf("ť�� ������ϴ�.\n");
		exit(1);
	}

	priorityQ* find_node = t->top;
	element temp = t->top->data;
	// �켱������ ���� ���� ���� ã�´�.
	for (int i = 0; i < t->queue_size; i++) {
		if (find_node->data > temp) {
			temp = find_node->data;
		}
		find_node = find_node->node;
	}

	return temp;
}
*/

// �������� 16.

/*
#define MAX_ELEMENT 100;

typedef struct {
	int key;
} element;


typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// ���� �Լ�
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ �Լ�
void init(HeapType* h) {
	h->heap_size = 0;
}

// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // ���ο� ��带 ����
}

// ���� �Լ�
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];

	parent = 1; child = 2;

	while (child <= h->heap_size) {
		// ���� ����� �ڽĳ���� �� ���� �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key < h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

// ������ ��� ���� �Լ�
element delete_select_node(HeapType *h, int i) { // i��° �ε��� ��� ����
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







