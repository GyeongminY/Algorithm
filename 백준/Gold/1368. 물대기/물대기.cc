#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
int n;
int well[301];
tuple<int, int, int> edge[100000];
vector<int> parent(301, -1);

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

bool is_diff_group(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return 0;
	if (parent[x] >= parent[y]) {
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
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> well[i];
	}
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> k;
			if (i == j) continue;
			edge[idx] = make_tuple(k, i, j);
			idx++;
		}	
	}
	for (int i = 1; i <= n; i++) {
		edge[idx + i-1] = make_tuple(well[i], 0, i);
	}
	idx = idx + n;
	sort(edge, edge + idx);
	/*for (int i = 0; i <= idx; i++) {
		cout << get<0>(edge[i]) << get<1>(edge[i]) << get<2>(edge[i]) << '\n';
	}*/
	int cost = 0;
	int cnt = 0;
	for (int i = 0; i < idx; i++) {
		int w, a, b;
		tie(w, a, b) = edge[i];
		if (is_diff_group(a, b)) {
			cost += w;
			cnt++;
		}
		if (cnt == n) break;
	}

	cout << cost;
}