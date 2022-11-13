// 8. 트리

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>


//프로그램 8.1 링크법으로 생성된 이진트리

/*
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

int main() {

	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 10;
	n1->left = n2;
	n1->right = n3;
	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;
	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;
	free(n1); free(n2); free(n3);

	return 0;
}
*/

// 프로그램 8.3 링크법으로 생성된 이진트리
/*
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//     15
//   4      20
// 1      16    25

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6; // 루트 노드를 가리키는 포인터

// 중위 순회
void inorder(TreeNode* root) {
	if (root != NULL) { // root == NULL 이면 수행 종료
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}


// 전위 순회
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data); //  노드 방문
		preorder(root->left);
		preorder(root->right);
	}
}

// 후위 순회
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main() {

	printf("중위 순회=");
	inorder(root);
	printf("\n");

	printf("전위 순회=");
	preorder(root);
	printf("\n");

	printf("후위 순회=");
	postorder(root);
	printf("\n");


	return 0;
}

*/

// 프로그램 8.4 반복적인 중위 순회
/*
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p) {
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode* pop() {
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

void inorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root)break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}


//      15
//   4      20
// 1      16   25

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6; // 루트 노드를 가리키는 포인터

int main() {
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
	return 0;
}
*/

// 프로그램 8.5 레벨 순회 프로그램 <- 큐로 구현한다

/*
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// ================== 원형 큐 코드 시작 ==========================

#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// 오류 함수
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


//포화 상태 검출 함수
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

void level_order(TreeNode* ptr) { // ptr은 루트 노드를 가리키는 포인터

	QueueType q;

	init_queue(&q);

	if (ptr == NULL) return;
	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);
	}
}

//      15
//   4      20
// 1      16   25

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6; // 루트 노드를 가리키는 포인터

int main() {

	printf("레벨 순회=");
	level_order(root);
	printf("\n");
	return 0;
}

*/

// 프로그램 8.6 수식 트리 계산 프로그램

/*
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//         +
//     *       +
//   1  4   16  25
 

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2};
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5};
TreeNode n7 = { '+', &n3, &n6};
TreeNode* exp = &n7;


// 수식 계산 함수
int evaluate(TreeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d을 계산합니다.\n", op1, root->data, op2);
		switch (root->data) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
		}
	}
	return 0;
}

int main() {
	printf("수식의 값은 %d입니다.\n", evaluate(exp));
	return 0;
}
*/

// 프로그램 8.7 디렉토리 용량 계산 프로그램

/*
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

int calc_dir_size(TreeNode* root) {
	int left_size, right_size;
	if (root == NULL)  return 0;

	left_size = calc_dir_size(root->left);
	right_size = calc_dir_size(root->right);
	return (root->data + left_size + right_size);
}


int main() {


	TreeNode n4 = { 500, NULL, NULL };
	TreeNode n5 = { 200, NULL, NULL };
	TreeNode n3 = { 100, &n4, &n5 };
	TreeNode n2 = { 50, NULL, NULL };
	TreeNode n1 = { 0, &n2, &n3 };

	printf("디렉토리의 크기=%d\n", calc_dir_size(&n1));

	return 0;
}

*/


/*
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//     15
//   4      20
// 1      16    25

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6; // 루트 노드를 가리키는 포인터


// 이진  탐색 트리에서 노드 개수 구하는 알고리즘
int get_node_count(TreeNode* node) {
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

// 이진 탐색 트리에서 리프노드 개수 구하는 알고리즘
int get_leaf_count(TreeNode* node) {
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			count = 1;
		else
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}

	return count;
}

// 이진 탐색 트리에서 높이 구하는 알고리즘
int get_height(TreeNode* node) {
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

// 비단말 노드의 개수를 계산하는 함수
int get_non_leaf_count(TreeNode* node) {

	return get_node_count(node) - get_leaf_count(node);

}

// 두 개의 트리가 같은 구조를 가지며 대응되느 노드당 같은 데이터를 가지는지 비교
int equal(TreeNode* t1, TreeNode* t2) {
	if (t1->data == t2->data) {
		int left_equal = equal(t1->left, t2->left);
		int right_equal = equal(t1->right, t1->right);
		return (left_equal != 0) && (right_equal != 0);
	}
	else return 0;
	
}


int main() {

	int a = get_node_count(root);
	int b = get_leaf_count(root);
	int c = get_height(root);
	int d = get_non_leaf_count(root);
	printf("노드 개수: %d, 리프 노드 개수: %d, 트리 높이: %d\n", a, b, c);
	printf("논 리프 노드 개수: %d\n", d);
	return 0;
}
*/

//프로그램 8.8 스레드 이진 트리 순회 프로그램
/*
#define TRUE 1
#define FALSE 0

typedef struct {
	int data;
	struct TreeNode* left, * right;
	int is_thread;

} TreeNode;

//        G
//    C       F
// A    B    D  E

TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode* exp = &n7;

TreeNode* find_successor(TreeNode* p) {
	// q는 p의 오른쪽 포인터
	TreeNode* q = p->right;
	// 만약 오른쪽 포인터가 NULL이거나 스레드이면 오른쪽 포인터를 반환
	if (q == NULL || p->is_thread == TRUE)
		return q;

	// 만약 오른쪽 자식이면 가장 왼쪽 노드로 이동
	while (q->left != NULL) q = q->left;
	return q;
}

void thread_inodrer(TreeNode* t) {
	TreeNode* q;

	q = t;
	while (q->left) q = q->left; // 가장 왼쪽 노드로 간다.
	do {
		printf("%c -> ", q->data); // 데이터 출력
		q = find_successor(q); // 후속자 함수 호출
	} while (q); // NULL이 아니면
}

int main() {

	//스레드 설정
	n1.right = &n3;
	n2.right = &n7;
	n2.right = &n6;
	// 중위 순회
	thread_inorder(exp);
	printf("\n");
	return;
}
*/

// 프로그램 8.13 이진 탐색 트리

/*
typedef int element;
typedef struct {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

// 순환적인 탐색 함수
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key) {
		return search(node->left, key);
	}
	else
		return search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	// 트리가 공백이면 새로운 노드를 반환
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	return node;

}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;

	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}

// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 노드를 반환한다.
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것
	if (root->key > key)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것
	else if (root->key < key)
		root->right = delete_node(root->right, key);
	// 키가 루트 노드와 같다면 이 노드를 삭제
	else {
		// 자식 노드가 1개이거나 0개일 경우
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 자식 노드가 2개일 경우
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

// 중위 순회
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

int main() {

	TreeNode* root = NULL;
	TreeNode* tmp = NULL;
	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");

	return 0;
}
*/

// 프로그램 8.14 이진 탐색 트리를 이용한 영어 사전 프로그램
/*
#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

// 데이터 형식
typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
} element;

// 노드의 구조
typedef struct {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

// 만약 e1 < e2 이면 -1 반환
// 만약 e1 == e2  이면 0 반환
// 만약 e1 > e2 이면 1 반환
int compare(element e1, element e2) {
	return strcmp(e1.word, e2.word);
}


// 이진 탐색 트리 출력 함수
void display(TreeNode* p) {
	if (p!= NULL) {
		printf("(");
		display(p->left);
		printf("%s : %s", p->key.word, p->key.meaning);
		display(p->right);
		printf(")");
	}
}

// 이진 탐색 트리 탐색 함수
TreeNode* search(TreeNode* root, element key) {
	TreeNode* p = root;
	while (p != NULL) {
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
	return p; // 탐색에 실패할 경우 NULL 반환
}

TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, element key) {
	// 트리가 공백이면 새로운 노드를 만든다.
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);
	// 루트 포인터를 반환한다.
	return node;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	// 맨 왼쪽 단말 노드를 찾으려 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}

// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환한다.
TreeNode* delete_node(TreeNode* root, element key) {
	if (root == NULL) return root;
	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (compare(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	else if (compare(key, root->key) > 0)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void help() {
	printf("\n**** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****: ");
}

int main() {
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;

	do {
		help();
		command = getchar();
		getchar();
		switch (command) {
		case 'i':
			printf("단어:");
			gets(e.word);
			printf("의미:");
			gets(e.meaning);
			root = insert_node(root, e);
			break;
		case 'd':
			printf("단어");
			gets(e.word);
			root = delete_node(root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("단어:");
			gets(e.word);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("의미:%s\n", tmp->key.meaning);
			break;
		}

	} while (command != 'q');



	return 0;
}
*/

// 연습문제 13-17

#define MAX -987654321
#define MIN 987654321


typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;


//                        15
//                  4             20
//               1     10       16    25
//                    7  12              41
//                          13              51

TreeNode n12 = { 51, NULL, NULL };
TreeNode n11 = { 41, NULL, &n12 };
TreeNode n10 = { 13, NULL, NULL };
TreeNode n8 = { 7, NULL, NULL };
TreeNode n9 = { 12, NULL, &n10 };
TreeNode n7 = { 10, &n8, &n9 };
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, &n7 };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, &n11 };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };

TreeNode* root = &n6; // 루트 노드를 가리키는 포인터



// 높이 구하기
int get_height(TreeNode* root) {
	if (root == NULL) return 0;
	else {
		int height = max(get_height(root->left), get_height(root->right));
		height = height + 1;
		return height;
	}
}

// 균형 트리 판별 
int is_balanced(TreeNode* root) {
	if (root == NULL) return 1;
	if (!(is_balanced(root->left) && is_balanced(root->right))) return 0;

	int get_lheight = get_height(root->left);
	int get_rheight = get_height(root->right);

	int dif = get_lheight - get_rheight;
	if (dif <= 1 && dif >= -1) return 1;
	else return 0;

}

// 트리 노드의 합
int sum_tree(TreeNode* root) {
	if (root == NULL) return 0;
	return root->data + sum_tree(root->left) + sum_tree(root->right);
}

// 작은 노드 값 출력:
void find_small(TreeNode* root, int data) {
	if (root == NULL) return;
	if (root->data < data) printf("%d보다 작은 노드: %d\n", data, root->data);
	find_small(root->left, data); find_small(root->right, data);
}

// 자식이 하나만 있는 노드 개수
int count_one_sub_tree(TreeNode* root) {
	int count = 0;
	if (root == NULL) return 0;
	else if (root->left != NULL && root->right != NULL);
	else if (root->left == NULL && root->right == NULL);
	else count++;
	return count + count_one_sub_tree(root->left) + count_one_sub_tree(root->right);

}


// 최소값 리턴

int find_small_data(TreeNode* root) {
	
	if (root == NULL) return MIN;
	int smallest = root->data;

	int smallest_l = find_small_data(root->left);
	int smallest_r = find_small_data(root->right);

	if (smallest > smallest_l) smallest = smallest_l;
	if (smallest > smallest_r) smallest = smallest_r;

	return smallest;

}

// 최대값 리턴
int find_big_data(TreeNode* root) {

	if (root == NULL) return MAX;
	int biggest = root->data;

	int biggest_l = find_big_data(root->left);
	int biggest_r = find_big_data(root->right);

	if (biggest < biggest_l) biggest = biggest_l;
	if (biggest < biggest_r) biggest = biggest_r;

	return biggest;
}

/*
int main() {

	// int data;

	printf("트리의 높이:%d\n", get_height(root));
	printf("균형 트리인가요? 1이면 예, 0이면 아니오: %d\n", is_balanced(root));
	printf("트리 노드의 합: %d\n", sum_tree(root));
	//printf("값을 입력하시오: ");
	//scanf("%d", &data);
	//find_small(root, data);
	printf("자식이 하나만 있는 노드 개수: %d\n", count_one_sub_tree(root));
	printf("최소값=%d\n", find_small_data(root));
	printf("최대값=%d\n", find_big_data(root));

	return 0;
}
*/

// 연습문제 18-19

/*
TreeNode* insert_node(TreeNode* root,int data) {
	if (root == NULL) {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
	}

	if (root->data > data) {
		root->left = insert_node(root->left, data);
	}
	else if (root->data < data) {
		root->right = insert_node(root->right, data);

	}
	return root;
}

TreeNode* insert_inverse_node(TreeNode* root, int data) {
	if (root == NULL) {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
	}

	if (root->data > data) {
		root->right = insert_inverse_node(root->right, data);
	}
	else if (root->data < data) {
		root->left = insert_inverse_node(root->left, data);

	}
	return root;
}

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d -> ", root->data);
		inorder(root->right);
	}
}

void inverse_inorder(TreeNode* root) {
	if (root != NULL) {
		inverse_inorder(root->right);
		printf("%d -> ", root->data);
		inverse_inorder(root->left);
	}
}
/*
int main() {

	TreeNode* root = NULL;

	int arr[11] = { 11, 3, 4, 1, 56, 5, 6, 2, 98, 32, 23 };

	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
		root = insert_node(root, arr[i]);
	}
	inorder(root);
	printf("\n");
	inverse_inorder(root);
	

	return 0;
}*/

/*
void tree_plus(TreeNode* root) {
	if (root != NULL) {
		tree_plus(root->left);
		root->data++;
		printf("%d->", root->data);
		tree_plus(root->right);
	}
}


int main() {
	inorder(root);
	printf("\n");
	tree_plus(root);
}*/

// 연습문제 22 -> 프로그램 8.14와 완전히 겹치므로 생략















