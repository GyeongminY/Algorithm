#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> parent(10005, -1);
tuple<int, int, int> edge[100005];

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

bool is_diff_group(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return 0;
	if (parent[x] >= parent[y]) { //음수라 y가 더 덩치 큼
		parent[y] = parent[x] + parent[y];
		parent[x] = y;
	}
	else {
		parent[x] = parent[x] + parent[y];
		parent[y] = x;
	}
	return 1;
}

int main() {
	int v, e;
	cin >> v >> e;
	int w, a, b;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> w;
		edge[i] = make_tuple(w, a, b);
	}
	sort(edge, edge + e);
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < e; i++) {
		tie(w, a, b) = edge[i];
		if (is_diff_group(a, b)) {
			ans += w;
			cnt++;
		}
		if (cnt == v - 1) break;
	}
	cout << ans;
}