#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	vector<int> v;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int board[52][52] = {};
		int visit[52][52] = {};
		int n, m, k, x, y, num = 0;
		cin >> m >> n >> k;
		queue<pair<int, int>> q;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			board[y][x] = 1;
		}
		/*for (int j = 0; j < n; j++) {
			for (int p = 0; p < m; p++) {
				printf("%d ", board[j][p]);
			}
			printf("\n");
		}*/
		for (int j = 0; j < n; j++) {
			for (int p = 0; p < m; p++) {
				if (visit[j][p]) continue;
				visit[j][p] = 1;
				if (board[j][p] == 1) {
					num++;
					q.push({ j, p });
					//printf("push %d %d\n", j, p);
					while (!q.empty()) {
						pair <int, int> cur = q.front(); q.pop();
						//printf("cur = %d %d\n", cur.X, cur.Y);
						for (int dir = 0; dir < 4; dir++){
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							//printf("nx = %d ny = %d dir = %d\n", nx, ny, dir);
							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (visit[nx][ny] || !board[nx][ny]) continue;
							visit[nx][ny] = 1;
							q.push({ nx, ny });
							//printf("push %d %d\n", nx, ny);
						}
					}
				}
			}
		}
		v.push_back(num);
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", v[i]);
	}
}