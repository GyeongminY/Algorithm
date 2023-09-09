#include <iostream>

using namespace std;

typedef struct node {
	int data;
	node* lchild, * rchild;
}node;

node* create_node(int e) {
	node* ptr = (node*)malloc(sizeof(node));
	ptr->data = e;
	ptr->lchild = ptr->rchild = NULL;
	return ptr;
}

void insert_node(node* parent, node* child) {
	if (parent->data > child->data && !parent->lchild) {
		parent->lchild = child;
		return;
	}
	if (parent->data < child->data && !parent->rchild) {
		parent->rchild = child;
		return;
	}
	if (parent->data > child->data) {
		insert_node(parent->lchild, child);
	}
	if (parent->data < child->data) {
		insert_node(parent->rchild, child);
	}
}

void print_post_order(node* n) {
	if (!n) return;
	print_post_order(n->lchild);
	print_post_order(n->rchild);
	printf("%d\n", n->data);
}

int main() {
	char t;
	int e;
	cin >> e;
	node* root = create_node(e);
	node* prev = root;
	getchar(); //cin 후 남아있는 개행문자 없애기
	while(cin >> e) {
		node* ptr = create_node(e);
		insert_node(root, ptr);
	} //트리 만들기 완료
	print_post_order(root);
}