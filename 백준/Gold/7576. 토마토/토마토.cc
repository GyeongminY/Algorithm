#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002];

int main() {
	int n, m;
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	cin >> m >> n;
	queue<pair<int, int>> q;
	for (int i = 0; i < 1002; i++)
		for (int j = 0; j < 1002; j++)
			dist[i][j] = -1;
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) { 
				dist[i][j] = 0;
				q.push({ i, j }); 
			}
		}
	}
	while (!q.empty()) {
		pair <int, int> cur = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] < 0 || dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}
	
	bool ifPossible = true;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] < 0 && board[i][j] >= 0) {
				ifPossible = false;
				break;
			}
			if (dist[i][j] > mx) mx = dist[i][j];
		}
	}
	if (!ifPossible) printf("-1");
	else printf("%d", mx);
}