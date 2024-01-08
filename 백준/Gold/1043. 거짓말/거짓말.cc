#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> v[51];
queue <int> q;
int parent[51];
vector <int> truth;
int n, m, truthN;

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



int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cin >> truthN;
	int k, peopleN, cnt = 0;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < truthN; i++) { 
		cin >> k;
		truth.push_back(k);
	}

	for (int i = 0; i < m; i++) { //파티 같이 가는 사람들끼리 union
		cin >> peopleN;
		for (int j = 0; j < peopleN; j++) {
			cin >> k;
			v[i].push_back(k);
		}
		for (int j = 0; j < peopleN-1; j++) {
			merge(v[i][j], v[i][j + 1]);
		}
	}
	/*printf("party union\n");
	for (int i = 0; i <= n; i++) {
		printf("%d ", parent[i]);
	}
	printf("\n");*/

	if (truthN > 1) { //진실을 아는 사람들끼리 union
		for (int i = 0; i < truthN-1; i++) {
			merge(truth[i], truth[i + 1]);
		}
	}
	/*printf("truth union\n");
	for (int i = 0; i <= n; i++) {
		printf("%d ", parent[i]);
	}
	printf("\n");*/

	if (truthN > 0) { //진실을 아는 사람이 파티에 있다면 거짓말 못함.
		int truth_root = find(truth[0]);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				if (find(v[i][j]) == truth_root) {
					cnt++;
					break;
				}
			}
		}
	}

	cout << m - cnt;
}