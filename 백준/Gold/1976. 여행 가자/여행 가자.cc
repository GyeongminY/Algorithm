#include <iostream>
#include <vector>

using namespace std;

int n, m;
int parent[201];
bool road[201][201];
vector<int> v;

int find(int x) {
	if (parent[x] == x) return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

void merge(int x, int y) {
	int root1 = find(x);
	int root2 = find(y);
	if (root1 == root2) return;
	if (root1 < root2) parent[root2] = root1;
	else parent[root1] = root2;
	return;
}

bool check_connect(int x, int y) {
	int root1 = find(x);
	int root2 = find(y);
	if (root1 == root2) return true;
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	int k;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> road[i][j];
			if(road[i][j]) merge(i, j);
		}
	}
	
	for (int i = 0; i < m; i++) {
		cin >> k;
		v.push_back(k);
	}

	bool result = true;
	for (int i = 0; i < m - 1; i++) {
		if (!result) break;
		result = check_connect(v[i], v[i + 1]);
	}
	if (result) cout << "YES";
	else cout << "NO";
}