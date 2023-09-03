#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
vector<int> adj[1005];
bool vis[1005];

void dfs(int k) {
	if (!vis[k]) {
		vis[k] = true;
		printf("%d ", k);
		for (auto next : adj[k]) {
			dfs(next);
		}
		return;
	}
	else
		return;
}
int main() {
	int n, m, start;
	cin >> n >> m >> start;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//adj list에 있는 수 오름차순 정렬
	for (int i = 1; i <= n; i++) { 
		sort(adj[i].begin(), adj[i].end());
	}
	//DFS
	dfs(start);
	/*stack<int> s;
	s.push(start);
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		if (vis[cur]) continue;
		vis[cur] = true;
		printf("%d ", cur);
		for (auto next : adj[cur]) {
			if (vis[next]) continue;
			s.push(next);
			break;
		}
	}*/
	printf("\n");
	//visited 배열 초기화
	for (int i = 0; i <= n; i++) {
		vis[i] = false;
	}
	//BFS
	queue <int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (vis[cur]) continue;
		vis[cur] = true;
		printf("%d ", cur);
		for (auto next : adj[cur]) {
			if (vis[next]) continue;
			q.push(next);
		}
	}
}