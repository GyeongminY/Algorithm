#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
string board[102];
bool visit[102][102];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int Cnum = 0; //적록색약
	int Nnum = 0; //적록색약 아님
	//적록색약 먼저
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j]) continue;
			visit[i][j] = 1;
			Cnum++;
			queue <pair<int, int>> q;
			q.push({ i, j });
			//printf("push %d %d\n", i, j);
			while (!q.empty()) {
				pair <int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visit[nx][ny]) continue;
					if (board[cur.X][cur.Y] == 'B' && board[nx][ny] == 'B') {
						visit[nx][ny] = 1;
						q.push({ nx, ny });
						//printf("push %d %d\n", nx, ny);
					}
					else if (board[cur.X][cur.Y] == 'R' || board[cur.X][cur.Y] == 'G') {
						if (board[nx][ny] == 'R' || board[nx][ny] == 'G') {
							visit[nx][ny] = 1;
							q.push({ nx, ny });
							//printf("push %d %d\n", nx, ny);
						}
					}
				}
			}
		}
	}
	//적록색약 아님
	for (int i = 0; i < n; i++) {
		fill(visit[i], visit[i] + n, 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j]) continue;
			visit[i][j] = 1;
			Nnum++;
			queue <pair<int, int>> q;
			q.push({ i, j });
			//printf("push %d %d\n", i, j);
			while (!q.empty()) {
				pair <int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (visit[nx][ny]) continue;
					if (board[cur.X][cur.Y] == 'B' && board[nx][ny] == 'B') {
						visit[nx][ny] = 1;
						q.push({ nx, ny });
						//printf("push %d %d\n", nx, ny);
					}
					else if (board[cur.X][cur.Y] == 'R' && board[nx][ny] == 'R') {
						visit[nx][ny] = 1;
						q.push({ nx, ny });
						//printf("push %d %d\n", nx, ny);
					}
					else if (board[cur.X][cur.Y] == 'G' && board[nx][ny] == 'G') {
						visit[nx][ny] = 1;
						q.push({ nx, ny });
						//printf("push %d %d\n", nx, ny);
					}
				}
			}
		}
	}
	printf("%d %d", Nnum, Cnum);
}