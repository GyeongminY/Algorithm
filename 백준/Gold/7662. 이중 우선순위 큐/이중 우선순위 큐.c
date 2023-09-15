#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int empty;
	int x;
	int n;
	struct node* link;
}node;

typedef struct element {
	int data;
	int idx;
}element; //element에는 실제 값이랑 value 배열의 인덱스.

typedef struct value {
	int valid;
	int value;
}value; //value에는 실제 값이랑 유효한 값인지

element MinHeap[1000001];
element MaxHeap[1000001];
value D[1000001];
int vidx = 0;

int find_node(int n);
void insert_MinHeap(int n, int* size);
void insert_MaxHeap(int n, int* size);
void delete_MinHeap(int* size, element* mn);
void delete_MaxHeap(int* size, element* mx);


node* insert_node(node* ptr, bool e, int a, int b) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->empty = e;
	newnode->x = a;
	newnode->n = b;
	if (ptr) ptr->link = newnode;
	newnode->link = NULL;
	return newnode;
}

int main() {
	int t, k, n;
	char cmd;
	node* head = (node*)malloc(sizeof(node));
	node* prev = head;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &k);
		int minSize = 0;
		int maxSize = 0;
		int datacnt = 0;
		vidx = 0;
		getchar();
		for (int i = 0; i < k; i++) {
			scanf("%c", &cmd);
			scanf("%d", &n);
			getchar();
			if (cmd == 'I') {
				insert_MaxHeap(n, &maxSize);
				insert_MinHeap(n, &minSize);
				D[vidx].value = n;
				D[vidx].valid = 1;
				vidx++;
				datacnt++;
				/*for (int i = 0; i <= datacnt; i++) {
					printf("MaxHeap[%d] data = %d idx = %d\n", i, MaxHeap[i].data, MaxHeap[i].idx);
				}*/
			}
			if (cmd == 'D') {
				if (datacnt == 0) continue;
				datacnt--;
				if (n > 0) {
					element mx;
					while (D[MaxHeap[1].idx].valid == 0 && maxSize > 1) {
						delete_MaxHeap(&maxSize, &mx); //불필요한 것 없애기
					}
					delete_MaxHeap(&maxSize, &mx);
					/*for (int i = 0; i <= datacnt; i++) {
						printf("MaxHeap[%d] data = %d idx = %d\n", i, MaxHeap[i].data, MaxHeap[i].idx);
					}
					printf("delete %d\n", mx.data);*/
					D[mx.idx].valid = 0;
					//minSize--;

				}
				else {
					element mn;
					while (D[MinHeap[1].idx].valid == 0 && minSize > 1) {
						//printf("while D[MinHeap[1].idx].data = %d\n", D[MinHeap[1].idx].value);
						delete_MinHeap(&minSize, &mn); //불필요한 것 없애기
						//printf("while delete %d\n", mn.data);
					}
					delete_MinHeap(&minSize, &mn);
					//printf("delete %d\n", mn.data);
					D[mn.idx].valid = 0;
					/*for (int i = 0; i < vidx; i++) {
						printf("D[%d].data = %d valid = %d\n", i, D[i].value, D[i].valid);
					}*/
					//maxSize--;
				}
			}
		}
		/*for (int i = 0; i < vidx; i++) {
			printf("D[%d].data = %d valid = %d\n", i, D[i].value, D[i].valid);
		}
		printf("datacnt = %d\n", datacnt);*/
		if (datacnt > 1) {
			element mn, mx;
			while (D[MaxHeap[1].idx].valid == 0 && maxSize > 1) {
				delete_MaxHeap(&maxSize, &mx); //불필요한 것 없애기
			}
			delete_MaxHeap(&maxSize, &mx);
			while (D[MinHeap[1].idx].valid == 0 && minSize > 1) {
				delete_MinHeap(&minSize, &mn); //불필요한 것 없애기
			}
			delete_MinHeap(&minSize, &mn);
			node* temp = insert_node(prev, 1, mx.data, mn.data);
			prev = temp;
		}
		else if (datacnt == 1) {
			element mx;
			//printf("D[MaxHeap[1].idx].valid = %d\n", D[MaxHeap[1].idx].valid);
			while (D[MaxHeap[1].idx].valid == 0 && maxSize > 1) {
				//printf("MaxHeap[1].idx = %d\n", MaxHeap[1].idx);
				delete_MaxHeap(&maxSize, &mx); //불필요한 것 없애기
				//printf("delete %d\n", mx.data);
			}
			delete_MaxHeap(&maxSize, &mx);
			/*printf("mx = %d\n", mx.data);
			printf("MaxHeap\n");
			for (int i = 0; i <= 6; i++) {
				printf("data %d idx %d\n", MaxHeap[i].data, MaxHeap[i].idx);
			}
			printf("D\n");
			for (int i = 0; i <= 6; i++) {
				printf("value %d valid %d\n", D[i].value, D[i].valid);
			}*/
			node* temp = insert_node(prev, 1, mx.data, mx.data);
			prev = temp;
		}
		else {
			node* temp = insert_node(prev, 0, 0, 0);
			prev = temp;
		}
	}
	node* cur = head->link;
	while (cur) {
		//printf("cur->empty = %d\n", cur->empty);
		if (cur->empty == 0) printf("EMPTY\n");
		else {
			printf("%d %d\n", cur->x, cur->n);
		}
		cur = cur->link;
	}
}

void insert_MinHeap(int n, int* size) {
	int i = ++(*size);
	while (i != 1 && n < MinHeap[i / 2].data) {
		MinHeap[i] = MinHeap[i / 2];
		i /= 2;
	}
	element e;
	e.data = n;
	e.idx = vidx;
	MinHeap[i] = e;
}

void insert_MaxHeap(int n, int* size) {
	int i = ++(*size);
	while (i != 1 && n > MaxHeap[i / 2].data) {
		MaxHeap[i] = MaxHeap[i / 2];
		i /= 2;
	}
	element e;
	e.data = n;
	e.idx = vidx;
	MaxHeap[i] = e;
}

void delete_MinHeap(int* size, element* mn) {
	int parent, child;
	element item, temp;
	if (!(*size)) {
		return;
	}
	item = MinHeap[1];
	temp = MinHeap[(*size)--];
	parent = 1;
	child = 2;
	while (child <= *size) {
		if (child < *size && MinHeap[child].data > MinHeap[child + 1].data) child++;
		if (temp.data <= MinHeap[child].data) break;
		MinHeap[parent] = MinHeap[child];
		parent = child;
		child *= 2;
	}
	MinHeap[parent] = temp;
	*mn = item;
	return;
}

void delete_MaxHeap(int* size, element* mx) {
	int parent, child;
	element item, temp;
	if (!(*size)) {
		return;
	}
	item = MaxHeap[1];
	temp = MaxHeap[(*size)--];
	parent = 1;
	child = 2;
	while (child <= *size) {
		if (child < *size && MaxHeap[child].data < MaxHeap[child + 1].data) child++;
		if (temp.data >= MaxHeap[child].data) break;
		MaxHeap[parent] = MaxHeap[child];
		parent = child;
		child *= 2;
	}
	MaxHeap[parent] = temp;
	*mx = item;
	return;
}