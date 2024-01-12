#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
int parent[100001];
tuple<int, int, int> edge[1000001];

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

bool is_diff_group(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return 0;
	if (parent[x] < parent[y]) {
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
	int v, e;
	cin >> v >> e;
	int w, a, b;
	fill(parent, parent + v, -1);
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> w;
		edge[i] = make_tuple(w, a, b);
	}
	sort(edge, edge + e);
	int cnt = 0;
	long total = 0;
	for (int i = 0; i < e; i++) {
		tie(w, a, b) = edge[i];
		if (is_diff_group(a, b)) {
			cnt++;
			total += w;
		}
		if (cnt == (v - 2)) break;
	}
	if (v == 2) cout << 0; 
	else cout << total;
}