#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
string board[1002];
int dist[1002][1002][11];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int r, c, m;

int bfs() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			for (int k = 0; k <= m; k++)
				dist[i][j][k] = -1;
	queue <tuple<int, int, int>> q;
	dist[0][0][0] = 1;
	q.push({ 0, 0, 0 });
	while (!q.empty()) {
		int x, y, broken;
		tie(x, y, broken) = q.front();
		if (x == r - 1 && y == c - 1) return dist[x][y][broken];
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int nextdist = dist[x][y][broken] + 1;
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (dist[nx][ny][broken] >= 1) continue;
			//벽 안 부술 때
			if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
				dist[nx][ny][broken] = nextdist;
				q.push({ nx, ny, broken });
			}
			//벽 부술 때
			if (broken < m && board[nx][ny] == '1' && dist[nx][ny][broken + 1] == -1) {
				dist[nx][ny][broken + 1] = nextdist;
				q.push({ nx, ny, broken + 1 });
			}
		}
	}
	return -1;

}

int main() {
	cin >> r >> c >> m;
	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}
	cout << bfs();
	return 0;
}
