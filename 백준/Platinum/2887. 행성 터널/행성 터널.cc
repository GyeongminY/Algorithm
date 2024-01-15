#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <cstdlib>
using namespace std;

#define X first
#define Y second

const int MX = 100'000;

int parent[MX + 2];
pair<int, int> x[MX + 2];
pair<int, int> y[MX + 2];
pair<int, int> z[MX + 2];

vector<tuple<int, int, int> > edge; //e = {cost, u, v}

int find(int cur) {
	if (parent[cur] < 0) return cur;
	return parent[cur] = find(parent[cur]);
}

bool is_diff_group(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0; 
	if (parent[u] > parent[v]) swap(u, v);
	parent[u] += parent[v];
	parent[v] = u;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(parent, parent + MX + 2, -1);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int cx, cy, cz;
		cin >> cx >> cy >> cz;
		x[i] = { cx, i }; //i+1번째 행성의 x좌표 저장
		y[i] = { cy, i };
		z[i] = { cz, i };
	}

	sort(x, x + n);
	sort(y, y + n);
	sort(z, z + n);

	for (int i = 1; i < n; i++) {
		edge.push_back({ abs(x[i - 1].first - x[i].first), x[i - 1].second, x[i].second});
		edge.push_back({ abs(y[i - 1].first - y[i].first), y[i - 1].second, y[i].second });
		edge.push_back({ abs(z[i - 1].first - z[i].first), z[i - 1].second, z[i].second });
	}
	sort(edge.begin(), edge.end());

	int cnt = 0, sum = 0;
	for (int i = 0; i < edge.size(); i++) {
		int cost, u, v;
		tie(cost, u, v) = edge[i];
		if (!is_diff_group(u, v)) continue;
		sum += cost;
		cnt++;
		if (cnt == n - 1) break;
	}
	cout << sum;
}
