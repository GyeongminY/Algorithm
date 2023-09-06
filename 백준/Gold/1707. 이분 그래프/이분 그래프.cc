#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[20001];
int color[20001];
vector<string> ans;

void dfs(int cur, int prev) {
	if (color[cur] >= 0) return;
	if (color[prev] == 0)
		color[cur] = 1; 
	else color[cur] = 0;
	for (auto next : adj[cur]) {
		if (color[next] >= 0) continue;
		dfs(next, cur);
	}
}

int main() {
	int k, V, E, u, v;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> V >> E;
		//adj list 초기화
		for (int j = 1; j <= V; j++) {
			while (!adj[j].empty())
				adj[j].pop_back();
		}
		for (int j = 0; j < E; j++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int j = 0; j <= V; j++) {
			color[j] = -1;
		}
		for (int j = 1; j <= V; j++) {
			dfs(j, j - 1);
		}
		bool B = true;
		/*for (int j = 1; j <= V; j++) {
			for (auto k : adj[j]) {
				printf("k = %d\n",k);
				if (color[k] == color[j]) B = false;
				break;
			}
			if (B == false) break;
		}*/
		for (int j = 1; j <= V; j++) {
			for (auto k : adj[j]) {
				//printf("%d ", k);
				if (color[k] == color[j]) B = false;
			}
		}
		if (B == true) ans.push_back("YES");
		else ans.push_back("NO");

		/*for (int j = 1; j <= V; j++) {
			printf("color[%d] = %d\n", j, color[j]);
		}*/
		/*printf("adj list\n");
		for (int j = 1; j <= V; j++) {
			for (auto k : adj[j]) {
				printf("%d ", k);
			}
			printf("\n");
		}*/

	}
	for (int i = 0; i < k; i++) {
		cout << ans[i] << '\n';
	}
}