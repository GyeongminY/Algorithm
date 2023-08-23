#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int board[102][102];
int dist[102][102];

int main() {
	int n, m;
	cin >> n >> m;
	string str;
	int dy[4] = { 0, 1, 0, -1 };
	int dx[4] = { 1, 0, -1, 0 };
	for (int i = 0; i < 102; i++)
		for (int j = 0; j < 102; j++)
			dist[i][j] = -1;
	
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			board[i][j] = (int)(str[j] - '0');
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}*/
	queue<pair<int, int>> q;
	int num = 1;
	dist[0][0] = 0;
	q.push({ 0, 0 }); //첫 번째 칸은 항상 지나가야 하니까
	pair <int, int> cur;

		while (cur.X != n - 1 || cur.Y != m - 1) {
			//printf("cur = {%d %d}, pop\n", q.front().X, q.front().Y);
			cur = q.front(); q.pop();
			if (cur.X == n - 1 && cur.Y == m - 1) break;
			for (int k = 0; k < 4; k++) {
				int nx = cur.X + dx[k];
				int ny = cur.Y + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (board[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
				//printf("push {%d %d}\n", nx, ny);
			}
		}
	printf("%d", dist[n-1][m-1]+1);
}