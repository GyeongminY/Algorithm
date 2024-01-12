#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
int parent[1005];
tuple<int, int, int> min_edge[500005];
tuple<int, int, int> max_edge[500005];

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

bool is_diff_group(int x, int y) {
;	x = find(x); y = find(y);
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
	//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int v, e;
	cin >> v >> e;
	int a, b, w;
	cin >> a >> b >> w;
	if (w) w = 0; else w = 1;
	int min_total = w;
	int max_total = w;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> w;
		if (w) w = 0; else w = 1;
		min_edge[i] = make_tuple(w, a, b);
		if (w) max_edge[i] = make_tuple(0, a, b);
		else max_edge[i] = make_tuple(1, a, b);
	}
	fill(parent, parent + v, -1);
	//min_total 구하기
	sort(min_edge, min_edge + e);
	int cnt = 0;
	for (int i = 0; i < e; i++) {
		tie(w, a, b) = min_edge[i];
		if (is_diff_group(a, b)) {
			min_total += w;
			cnt++;
		}
		if (cnt == (v - 1)) break;
	}
	//max_total 구하기
	for (int i = 0; i < 1005; i++) parent[i] = -1;
	sort(max_edge, max_edge + e);
	cnt = 0;
	for (int i = 0; i < e; i++) {
		tie(w, a, b) = max_edge[i];
		if (is_diff_group(a, b)) {
			if (w) max_total += 0;
			else max_total += 1;
			cnt++;
		}
		if (cnt == (v - 1)) {  break; }
	}
	min_total = min_total * min_total;
	max_total = max_total * max_total;
	cout << max_total - min_total;
}