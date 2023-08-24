#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int board[102][102][102];
int dist[102][102][102];
int main() {
	int m, n, h;
	cin >> m >> n >> h;
	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			fill(dist[i][j], dist[i][j] + m, -1);
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					dist[i][j][k] = 0;
					q.push(make_pair(i, make_pair(j, k)));
					//printf("push %d %d %d\n", i, j, k);
				}
			}
		}
	}
	int mx = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		//printf("pop! cur = %d %d %d\n", cur.X, cur.Y.X, cur.Y.Y);
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y.X + dy[dir];
			int nz = cur.Y.Y + dz[dir];
			if (nx < 0 || nx >= h || ny < 0 || ny >= n || nz < 0 || nz >= m) continue;
			if (dist[nx][ny][nz] >= 0 || board[nx][ny][nz] < 0) continue;
			dist[nx][ny][nz] = dist[cur.X][cur.Y.X][cur.Y.Y] + 1;
			if (dist[nx][ny][nz] > mx) mx = dist[nx][ny][nz];
			//printf("mx = %d\n", mx);
			q.push(make_pair(nx, make_pair(ny, nz)));
			//printf("push %d %d %d\n", nx, ny, nz);
		}
	}
	/*printf("\n");
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				printf("%d ", dist[i][j][k]);
			}
			printf("\n");
		}
	printf("\n");*/
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++) 
			for (int k = 0; k < m; k++) 
				if (dist[i][j][k] < 0 && board[i][j][k] >= 0) {
					printf("-1");
					return 0;
				}
			
	printf("%d", mx);

}