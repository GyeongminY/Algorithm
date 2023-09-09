#include <iostream>

using namespace std;
char str[3];
typedef struct node {
	char data;
	node* lchild, *rchild;
}node;

node* create_node(char c) {
	node* ptr = (node*)malloc(sizeof(node));
	ptr->data = c;
	ptr->lchild = ptr->rchild = NULL;
	return ptr;
}

void find_node(node* n, char d, node** result) {
	if (!n) return;
	if (n->data == d) {
		*result = n;
		return;
	}
	find_node(n->lchild, d, result);
	find_node(n->rchild, d, result);
}

void make_tree(char str[3], node* root) { //이미 트리에 있는 노드인지 확인하기 위해 root 필요
	node* ptr1 = NULL; //str[0]이 있는 노드를 가리키는 포인터
	node* ptr2 = NULL;
	node* ptr3 = NULL;
	find_node(root, str[0], &ptr1);
	if (!ptr1) {
		ptr1 = create_node(str[0]);
	}
	if (str[1] != '.') {
		find_node(root, str[1], &ptr2);
		if (!ptr2) ptr2 = create_node(str[1]);
		ptr1->lchild = ptr2;
	}
	if (str[2] != '.') {
		find_node(root, str[2], &ptr3);
		if (!ptr3) ptr3 = create_node(str[2]);
		ptr1->rchild = ptr3;
	}
}

void print_preorder(node* n) {
	if (!n) return;
	printf("%c", n->data);
	print_preorder(n->lchild);
	print_preorder(n->rchild);
 }

void print_inorder(node* n) {
	if (!n) return;
	print_inorder(n->lchild);
	printf("%c", n->data);
	print_inorder(n->rchild);
}

void print_postorder(node* n) {
	if (!n) return;
	print_postorder(n->lchild);
	print_postorder(n->rchild);
	printf("%c", n->data);
}

int main() {
	int n;
	cin >> n;
	node* root = create_node('A');
	while (n--) {
		for (int i = 0; i < 3; i++) {
			cin >> str[i];
		}
		make_tree(str, root);
	}
	print_preorder(root);
	printf("\n");
	print_inorder(root);
	printf("\n");
	print_postorder(root);
}