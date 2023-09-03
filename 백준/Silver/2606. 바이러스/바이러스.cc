#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> adj[105];
bool visit[105];

int main() {
	int n, e, u, v, num = 0;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		if (visit[cur]) continue;
		visit[cur] = true;
		num++;
		for (auto next : adj[cur]) {
			if (visit[next]) continue;
			q.push(next);
		}
	}
	cout << num - 1;
}