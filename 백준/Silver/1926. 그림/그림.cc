#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int board[502][502];
int visit[502][502];

int main() {
	int n, m;
	int dirX[4] = { 1, 0, -1, 0 };
	int dirY[4] = { 0, 1, 0, -1 };
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int mx = 0;
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || visit[i][j] == 1) continue;
			num++;
			visit[i][j] = 1;
			queue<pair<int, int>> q; //q를 for문 안에 선언하면 for문 돌 때마다 초기화 안 해도 됨
			q.push({ i, j });
			int area = 0;
			while (!q.empty()) {
				area++; //큐에 추가할 때가 아니라 큐에서 원소를 뺄 때마다 넓이를 1 증가시킴.
				pair<int, int> cur = q.front(); q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dirX[dir];
					int ny = cur.Y + dirY[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (visit[nx][ny] || board[nx][ny] != 1) continue;
					visit[nx][ny] = 1;
					q.push({ nx, ny });
				}
			}
			mx = max(mx, area);
		}
	}
	cout << num << '\n' << mx;
}