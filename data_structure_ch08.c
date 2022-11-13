// 8. Ʈ��

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>


//���α׷� 8.1 ��ũ������ ������ ����Ʈ��

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

// ���α׷� 8.3 ��ũ������ ������ ����Ʈ��
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
TreeNode* root = &n6; // ��Ʈ ��带 ����Ű�� ������

// ���� ��ȸ
void inorder(TreeNode* root) {
	if (root != NULL) { // root == NULL �̸� ���� ����
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}


// ���� ��ȸ
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data); //  ��� �湮
		preorder(root->left);
		preorder(root->right);
	}
}

// ���� ��ȸ
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

int main() {

	printf("���� ��ȸ=");
	inorder(root);
	printf("\n");

	printf("���� ��ȸ=");
	preorder(root);
	printf("\n");

	printf("���� ��ȸ=");
	postorder(root);
	printf("\n");


	return 0;
}

*/

// ���α׷� 8.4 �ݺ����� ���� ��ȸ
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
TreeNode* root = &n6; // ��Ʈ ��带 ����Ű�� ������

int main() {
	printf("���� ��ȸ=");
	inorder_iter(root);
	printf("\n");
	return 0;
}
*/

// ���α׷� 8.5 ���� ��ȸ ���α׷� <- ť�� �����Ѵ�

/*
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// ================== ���� ť �ڵ� ���� ==========================

#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

// ���� �Լ�
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


//��ȭ ���� ���� �Լ�
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

void level_order(TreeNode* ptr) { // ptr�� ��Ʈ ��带 ����Ű�� ������

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
TreeNode* root = &n6; // ��Ʈ ��带 ����Ű�� ������

int main() {

	printf("���� ��ȸ=");
	level_order(root);
	printf("\n");
	return 0;
}

*/

// ���α׷� 8.6 ���� Ʈ�� ��� ���α׷�

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


// ���� ��� �Լ�
int evaluate(TreeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else {
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d�� ����մϴ�.\n", op1, root->data, op2);
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
	printf("������ ���� %d�Դϴ�.\n", evaluate(exp));
	return 0;
}
*/

// ���α׷� 8.7 ���丮 �뷮 ��� ���α׷�

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

	printf("���丮�� ũ��=%d\n", calc_dir_size(&n1));

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
TreeNode* root = &n6; // ��Ʈ ��带 ����Ű�� ������


// ����  Ž�� Ʈ������ ��� ���� ���ϴ� �˰���
int get_node_count(TreeNode* node) {
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	return count;
}

// ���� Ž�� Ʈ������ ������� ���� ���ϴ� �˰���
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

// ���� Ž�� Ʈ������ ���� ���ϴ� �˰���
int get_height(TreeNode* node) {
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

// ��ܸ� ����� ������ ����ϴ� �Լ�
int get_non_leaf_count(TreeNode* node) {

	return get_node_count(node) - get_leaf_count(node);

}

// �� ���� Ʈ���� ���� ������ ������ �����Ǵ� ���� ���� �����͸� �������� ��
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
	printf("��� ����: %d, ���� ��� ����: %d, Ʈ�� ����: %d\n", a, b, c);
	printf("�� ���� ��� ����: %d\n", d);
	return 0;
}
*/

//���α׷� 8.8 ������ ���� Ʈ�� ��ȸ ���α׷�
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
	// q�� p�� ������ ������
	TreeNode* q = p->right;
	// ���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ
	if (q == NULL || p->is_thread == TRUE)
		return q;

	// ���� ������ �ڽ��̸� ���� ���� ���� �̵�
	while (q->left != NULL) q = q->left;
	return q;
}

void thread_inodrer(TreeNode* t) {
	TreeNode* q;

	q = t;
	while (q->left) q = q->left; // ���� ���� ���� ����.
	do {
		printf("%c -> ", q->data); // ������ ���
		q = find_successor(q); // �ļ��� �Լ� ȣ��
	} while (q); // NULL�� �ƴϸ�
}

int main() {

	//������ ����
	n1.right = &n3;
	n2.right = &n7;
	n2.right = &n6;
	// ���� ��ȸ
	thread_inorder(exp);
	printf("\n");
	return;
}
*/

// ���α׷� 8.13 ���� Ž�� Ʈ��

/*
typedef int element;
typedef struct {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

// ��ȯ���� Ž�� �Լ�
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
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);
	return node;

}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;
	return current;
}

// ���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� ���ο� ��带 ��ȯ�Ѵ�.
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ��
	if (root->key > key)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �ִ� ��
	else if (root->key < key)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ ���� ���ٸ� �� ��带 ����
	else {
		// �ڽ� ��尡 1���̰ų� 0���� ���
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
		// �ڽ� ��尡 2���� ���
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

// ���� ��ȸ
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

	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰߸��� \n");

	return 0;
}
*/

// ���α׷� 8.14 ���� Ž�� Ʈ���� �̿��� ���� ���� ���α׷�
/*
#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

// ������ ����
typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
} element;

// ����� ����
typedef struct {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

// ���� e1 < e2 �̸� -1 ��ȯ
// ���� e1 == e2  �̸� 0 ��ȯ
// ���� e1 > e2 �̸� 1 ��ȯ
int compare(element e1, element e2) {
	return strcmp(e1.word, e2.word);
}


// ���� Ž�� Ʈ�� ��� �Լ�
void display(TreeNode* p) {
	if (p!= NULL) {
		printf("(");
		display(p->left);
		printf("%s : %s", p->key.word, p->key.meaning);
		display(p->right);
		printf(")");
	}
}

// ���� Ž�� Ʈ�� Ž�� �Լ�
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
	return p; // Ž���� ������ ��� NULL ��ȯ
}

TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, element key) {
	// Ʈ���� �����̸� ���ο� ��带 �����.
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������.
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);
	// ��Ʈ �����͸� ��ȯ�Ѵ�.
	return node;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;
	return current;
}

// ���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ� ���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
TreeNode* delete_node(TreeNode* root, element key) {
	if (root == NULL) return root;
	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �ִ� ����
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
	printf("\n**** i: �Է�, d: ����, s: Ž��, p: ���, q: ���� ****: ");
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
			printf("�ܾ�:");
			gets(e.word);
			printf("�ǹ�:");
			gets(e.meaning);
			root = insert_node(root, e);
			break;
		case 'd':
			printf("�ܾ�");
			gets(e.word);
			root = delete_node(root, e);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("�ܾ�:");
			gets(e.word);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("�ǹ�:%s\n", tmp->key.meaning);
			break;
		}

	} while (command != 'q');



	return 0;
}
*/

// �������� 13-17

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

TreeNode* root = &n6; // ��Ʈ ��带 ����Ű�� ������



// ���� ���ϱ�
int get_height(TreeNode* root) {
	if (root == NULL) return 0;
	else {
		int height = max(get_height(root->left), get_height(root->right));
		height = height + 1;
		return height;
	}
}

// ���� Ʈ�� �Ǻ� 
int is_balanced(TreeNode* root) {
	if (root == NULL) return 1;
	if (!(is_balanced(root->left) && is_balanced(root->right))) return 0;

	int get_lheight = get_height(root->left);
	int get_rheight = get_height(root->right);

	int dif = get_lheight - get_rheight;
	if (dif <= 1 && dif >= -1) return 1;
	else return 0;

}

// Ʈ�� ����� ��
int sum_tree(TreeNode* root) {
	if (root == NULL) return 0;
	return root->data + sum_tree(root->left) + sum_tree(root->right);
}

// ���� ��� �� ���:
void find_small(TreeNode* root, int data) {
	if (root == NULL) return;
	if (root->data < data) printf("%d���� ���� ���: %d\n", data, root->data);
	find_small(root->left, data); find_small(root->right, data);
}

// �ڽ��� �ϳ��� �ִ� ��� ����
int count_one_sub_tree(TreeNode* root) {
	int count = 0;
	if (root == NULL) return 0;
	else if (root->left != NULL && root->right != NULL);
	else if (root->left == NULL && root->right == NULL);
	else count++;
	return count + count_one_sub_tree(root->left) + count_one_sub_tree(root->right);

}


// �ּҰ� ����

int find_small_data(TreeNode* root) {
	
	if (root == NULL) return MIN;
	int smallest = root->data;

	int smallest_l = find_small_data(root->left);
	int smallest_r = find_small_data(root->right);

	if (smallest > smallest_l) smallest = smallest_l;
	if (smallest > smallest_r) smallest = smallest_r;

	return smallest;

}

// �ִ밪 ����
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

	printf("Ʈ���� ����:%d\n", get_height(root));
	printf("���� Ʈ���ΰ���? 1�̸� ��, 0�̸� �ƴϿ�: %d\n", is_balanced(root));
	printf("Ʈ�� ����� ��: %d\n", sum_tree(root));
	//printf("���� �Է��Ͻÿ�: ");
	//scanf("%d", &data);
	//find_small(root, data);
	printf("�ڽ��� �ϳ��� �ִ� ��� ����: %d\n", count_one_sub_tree(root));
	printf("�ּҰ�=%d\n", find_small_data(root));
	printf("�ִ밪=%d\n", find_big_data(root));

	return 0;
}
*/

// �������� 18-19

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

// �������� 22 -> ���α׷� 8.14�� ������ ��ġ�Ƿ� ����















