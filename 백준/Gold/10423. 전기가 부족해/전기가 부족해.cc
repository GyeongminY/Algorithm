#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;
tuple<int, int, int> edge[100001];
int parent[1001];

//가상의 노드 0이 있고 발전소가 있는 노드들은 가상의 노드 0과 모두 연결되어 있는 상태라고 하자.
int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}
bool is_diff_group(int x, int y) {
	//printf("is diff %d %d\n", x, y);
	x = find(x); y = find(y);
	//printf("find %d %d\n", x, y);
	if (x == y) return 0;
	if (x == 0) {
		parent[x] = parent[x] + parent[y];
		parent[y] = x;
	}
	else if(y == 0) {
		parent[y] = parent[x] + parent[y];
		parent[x] = y;
	}
	else if (parent[x] < parent[y]) {
		parent[x] = parent[x] + parent[y];
		parent[y] = x;
	}
	else {
		parent[y] = parent[x] + parent[y];
		parent[x] = y;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int v, e, root, p;
	cin >> v >> e >> root;
	fill(parent, parent + v+1, -1);
	parent[0] = (-1) * root;
	for (int i = 0; i < root; i++) {
		cin >> p;
		parent[p] = 0; 
	}
	int a, b, w;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> w;
		edge[i] = make_tuple(w, a, b);
	}
	sort(edge, edge + e);
	//간선 개수가 정점 개수 - 발전소 개수가 돼야 함
	int cnt = 0;
	int total = 0;
	for (int i = 0; i < e; i++) {
		tie(w, a, b) = edge[i];
		if (is_diff_group(a, b)) {
			//printf("add %d %d\n", a, b);
			cnt++;
			total += w;
		}
		if (cnt == (v - root)) break;
	}
	cout << total;
}