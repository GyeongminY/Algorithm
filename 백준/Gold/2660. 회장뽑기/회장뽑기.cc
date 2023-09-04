#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> adj[55];
int dis[55];
int score[55];

bool compare(int i, int j) {
	return i > j;
}

int main() {
	int n, u = 1, v = 1;
	int mn = 100;
	cin >> n;
	while (1) {
		cin >> u >> v;
		if (u < 0 && v < 0) break;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//거리 초기화
	for (int i = 1; i <= n; i++) {
		dis[i] = -1;
	}
	//각 정점을 시작점으로 하는 bfs 한 번씩 총 n번의 bfs를 돈다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[j] = -1;
		}
		queue<int> q;
		dis[i] = 0;
		int mx = dis[i];
		q.push(i);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto next : adj[cur]) {
				if (dis[next] >= 0) continue;
				dis[next] = dis[cur] + 1;
				mx = dis[next];
				q.push(next);
			}
		}
		score[i] = mx;
		/*printf("score[%d] = %d\n", i, mx);*/
		if (score[i] < mn) mn = score[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (score[i] == mn) cnt++;
	}
	printf("%d %d\n", mn, cnt);
	for (int i = 1; i <= n; i++) {
		if (score[i] == mn) printf("%d ", i);
	}
}