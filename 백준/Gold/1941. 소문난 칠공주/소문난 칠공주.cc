#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>> v;  //7개의 숫자를 뽑아서 저장.
char board[5][5];
bool isused[5][5];
bool visited[5][5];
bool arr[5][5];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int ans;

bool bfs(int x, int y) {
	queue<pair<int, int>> q;
	bool visited[5][5] = { 0 };
	q.push({ x, y });
	visited[x][y] = 1;
	int cnt = 1;
	while (!q.empty()) {
		pair<int, int> a = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a.first + dx[i];
			int ny = a.second + dy[i];
			if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
			if (visited[nx][ny]) continue;
			if (arr[nx][ny]) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				cnt++;
			}
		}
	}
	if (cnt == 7) return true;
	else return false;
}

void func(int k) {
	//일단 7개 뽑았음. 이 7개 중 S가 4개 이상인지 확인한 후, 그게 연결되어 있는지 확인해야 함.
	if (k == 7) {
		int cnt = 0;
		for (int i = 0; i < 7; i++) {
			if (board[v[i].first][v[i].second] == 'S') cnt++;
		}
		if (cnt < 4) return;
		
		//cout << v[0].first << " " << v[0].second << "\n";
		//S가 4개 이상일 때 bfs로 연결되어있는지 확인.
		if (bfs(v[0].first, v[0].second)) ans++;
		return;
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j]) continue;
			if (k != 0 && (v[k - 1].first > i || (v[k - 1].first == i && v[k - 1].second > j))) continue;
			arr[i][j] = 1;
			v.push_back({ i, j });
			func(k + 1);
			arr[i][j] = 0;
			v.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	//25개 중 7개를 뽑은 후, 그 7개 중 S가 4개 이상 있는지 확인.
	func(0);
	cout << ans;
}