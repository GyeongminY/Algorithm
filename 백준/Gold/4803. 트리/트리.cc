#include <iostream>

using namespace std;

typedef struct node {
	int data;
	node* link;
}node;

node* ptr[501];
int treeNum[501];
bool vis[501];
bool cycle;
bool finish[501];

node* create_node(int n) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = n;
	newnode->link = NULL;
	return newnode;
}

void make_graph(node* ptr1, node* ptr2) {
	node* newnode = create_node(ptr2->data);
	node* temp = ptr1;
	while (temp->link) temp = temp->link;
	temp->link = newnode;
	node* newnode2 = create_node(ptr1->data);
	temp = ptr2;
	while (temp->link) temp = temp->link;
	temp->link = newnode2;
}

void dfs(node* n, int start, int prev) {
	if (!n) {
		return;
	}
	//printf("dfs(%d, %d, %d)\n", n->data, start, prev);
	if (vis[n->data]) {
		//printf("compare %d %d\n", n->data, prev);
		if (!finish[start] && n->data != prev)
			cycle = true;
			//printf("cycle = true\n");
		return;
	}
	vis[n->data] = true;
	node* cur = n;
	while (cur->link) {
		cur = cur->link;
		if (cur->data == prev) continue;
		/*if (vis[cur->data]) {
			continue;
		}*/
		dfs(ptr[cur->data], start, n->data);
	}
	finish[n->data] = true;
}

int main() {
	int v, e, a, b, num = 0;
	while (1) {
		cin >> v >> e;
		if (v == 0 && e == 0) break;
		//vis 배열 초기화
		for (int i = 0; i <= v; i++)
			vis[i] = false;
		for (int i = 0; i <= v; i++)
			finish[i] = false;
		num++; //num 1부터 시작.
		for (int i = 1; i <= v; i++) {
			ptr[i] = create_node(i);
		}
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			make_graph(ptr[a], ptr[b]);
		} //그래프 만들기 완료.

		/*for (int i = 1; i <= v; i++) {
			node* cur = ptr[i];
			while (cur) {
				printf("%d ", cur->data);
				cur = cur->link;
			}
			printf("\n");
		}*/

		for (int i = 1; i <= v; i++) {
			if (vis[i]) continue;
			cycle = false;
			dfs(ptr[i], i, i);
			if (!cycle) treeNum[num]++;
		}
		//매 테스트케이스마다 초기화 필요
		for (int i = 1; i <= v; i++) {
			node* cur = ptr[i];
			while (cur) {
				node* temp = cur;
				cur = cur->link;
				free(temp);
			}
		}
	}
	for (int i = 1; i <= num; i++) {
		if (treeNum[i] == 0) printf("Case %d: No trees.\n", i);
		else if (treeNum[i] == 1) printf("Case %d: There is one tree.\n", i);
		else printf("Case %d: A forest of %d trees.\n", i, treeNum[i]);
	}
}