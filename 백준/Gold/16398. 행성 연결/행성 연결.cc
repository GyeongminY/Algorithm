#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
int parent[1001];
tuple<int, int, int> edge[500005];
int v;

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
	cin >> v;
	int idx = 0;
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			int w;
			cin >> w;
			if (i < j) {
				edge[idx] = make_tuple(w, i + 1, j + 1); //중복이니까 한 번만 edge에 추가
				idx++;
			}
		}
	}
	fill(parent, parent + v, -1); //parent 배열을 -1로 초기화
	int e = v * (v - 1) / 2;
	sort(edge, edge + e);
	int cnt = 0;
	long total = 0;
	for (int i = 0; i < e; i++) {
		int w, a, b;
		tie(w, a, b) = edge[i];
		if (is_diff_group(a, b)) {
			cnt++;
			total += w;
		}
		if (cnt == v - 1) break;
	}
	cout << total;
	
}