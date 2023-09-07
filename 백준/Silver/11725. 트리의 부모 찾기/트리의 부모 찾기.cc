#include <iostream>
#include <vector>

using namespace std;

int parent_node[100002];
int n;
vector<int> adj[100002];
bool vis[100002];


void dfs(int n) {
	if (vis[n]) return;
	vis[n] = true;
		for (auto cur : adj[n]) {
			if (vis[cur]) continue;
			parent_node[cur] = n;
			dfs(cur);
		}
}

int main() {
	int u, v;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	parent_node[1] = 1;
	dfs(1);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent_node[i]);
	}
}