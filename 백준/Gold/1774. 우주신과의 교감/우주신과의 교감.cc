#include <iostream>
#include <tuple>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>

using namespace std;
int parent[1001];
pair<int, int> pos[1001];
vector<tuple<double, int, int> > edge;

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
//두 점 사이 거리 계산
double cal_dis(int a, int b) {
	int x, y, z, w;
	double dis;
	tie(x, y) = pos[a];
	tie(z, w) = pos[b];
	dis = sqrt(pow(x - z, 2) + pow(y - w, 2));
	return dis;
}

int main() {
	int v, con;
	int a, b;
	double w;
	cin >> v >> con;
	fill(parent, parent + v, -1);
	for (int i = 1; i <= v; i++) {
		cin >> a >> b;
		pos[i] = make_pair(a, b);
	}
	//이미 연결된 통로 (이때 같은 그룹인지 확인하기)
	int real_con = con;
	for (int i = 0; i < con; i++) {
		cin >> a >> b;
		if (!is_diff_group(a, b)) real_con--;
	}
	//좌표 사이 거리 계산해서 edge 채우기
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i < j) {
				double dis = cal_dis(i, j);
				edge.push_back(make_tuple(dis, i, j));
			}
		}
	}
	sort(edge.begin(), edge.end());
	//나머지 edge 연결
	int cnt = 0;
	double total = 0;
	for (int i = 0; i < edge.size(); i++) {
		tie(w, a, b) = edge[i];
		if (is_diff_group(a, b)) {
			total += w;
			cnt++;
		}
		if (cnt == (v - 1 - real_con)) break;
	}
	cout << fixed;
	cout.precision(2);
	cout << total;

}