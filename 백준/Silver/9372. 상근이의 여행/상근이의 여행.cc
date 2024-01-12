#include <iostream>
#include <vector>
#include <utility>

using namespace std;
int parent[1001];
pair<int, int> edge[20005];
int cnt;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	parent[x] = y;
	cnt++;
	return;
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int v, e, a, b;
		cin >> v >> e;
		for (int j = 0; j <= v; j++) {
			parent[j] = j;
		}
		for (int j = 0; j < e; j++) {
			cin >> a >> b;
			edge[j] = make_pair(a, b);
			edge[e + j - 1] = make_pair(b, a);
		}
		cnt = 0;
		for (int j = 0; j < 2*e; j++) {
			a = edge[j].first; b = edge[j].second;
			merge(a, b);
			if (cnt == v - 1) break;
		}
		cout << cnt << '\n';
	}
}