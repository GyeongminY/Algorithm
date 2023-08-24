#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int board[200001];
int dist[200001];

int main() {
	int n, k;
	cin >> n >> k;
	fill(dist, dist + 200000, -1);
	queue <int> q;
	dist[n] = 0;
	q.push(n);
	//printf("push %d\n", n);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		//printf("pop! cur = %d\n", cur);
		if (cur == k) {
			cout << dist[cur];
			return 0;
		}
		int i = 0;
		while (i < 3) {
			if (i == 0) {
				int nx = cur + 1;
				if (dist[nx] >= 0 || nx >= 200000) { i++; continue; }
				dist[nx] = dist[cur] + 1;
				q.push(nx);
				//printf("push %d\n", nx);
				i++;
			}
			else if (i == 1) {
				int nx = cur - 1;
				if (dist[nx] >= 0 || nx < 0) { i++; continue; }
				dist[nx] = dist[cur] + 1;
				q.push(nx);
				//printf("push %d\n", nx);
				i++;
			}
			else if (i == 2) {
				int nx = cur * 2;
				if (dist[nx] >= 0 || nx >= 200000) { i++; continue; }
				dist[nx] = dist[cur] + 1;
				q.push(nx);
				//printf("push %d\n", nx);
				i++;
			}
		}
		
	}
}