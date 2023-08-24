#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;
#define X first
#define Y second
int dist1[1002][1002];
int dist2[1002][1002];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int main() {
	int t;
	string result[100] = {};
	cin >> t;
	for (int i = 0; i < t; i++) {
		int w, h;
		bool ifPossible = false;
		pair <int, int> sg;
		cin >> w >> h;
		string board[1002];
		for (int j = 0; j < h; j++) {
			fill(dist1[j], dist1[j] + w, -1);
			fill(dist2[j], dist2[j] + w, -1);
		}
		queue <pair<int, int>> q;
		for (int j = 0; j < h; j++) {
			cin >> board[j];
			for (int k = 0; k < w; k++) {
				if (board[j][k] == '*') {
					dist1[j][k] = 0;
					q.push({ j, k });
				}
				if (board[j][k] == '@') {
					sg = { j, k };
				}
			}
		}
		//불에 대한 bfs
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			//printf("pop! cur = %d %d\n", cur.X, cur.Y);
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				//printf("nx ny = %d %d\n", nx, ny);
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
				//printf("push %d %d\n", nx, ny);
			}
		}
		/*printf("\n");
		for (int p = 0; p < h; p++) {
			for (int q = 0; q < w; q++) {
				printf("%d ", dist1[p][q]);
			}
			printf("\n");
		}
		printf("\n");*/
		//지훈이에 대한 bfs
		dist2[sg.X][sg.Y] = 0;
		q.push({ sg.X, sg.Y });
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			//printf("pop cur = %d %d\n", cur.X, cur.Y);
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
					//printf("%d %d end\n", nx, ny);
					result[i] = to_string(dist2[cur.X][cur.Y] + 1);
					ifPossible = true;
					break;
				}
				if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				if (dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1 && dist1[nx][ny] != -1) continue;
				dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
				q.push({ nx, ny });
				//printf("push %d %d\n", nx, ny);
			}
			if (ifPossible == true) break;
		}
		/*printf("\n");
		for (int p = 0; p < h; p++) {
			for (int q = 0; q < w; q++) {
				printf("%d ", dist2[p][q]);
			}
			printf("\n");
		}
		printf("\n");*/
		while (!q.empty()) q.pop();
		if (ifPossible == false) {
			result[i] = "IMPOSSIBLE";
		}
	}
	for (int i = 0; i < t; i++) {
		cout << result[i] << '\n';
	}
}