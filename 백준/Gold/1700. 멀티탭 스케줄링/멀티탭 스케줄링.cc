#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> v[101];
vector<int> sq;
bool on[101]; //현재 멀티탭에 있으면 true

struct cmp { //가장 나중에 쓰이는 것을 빼야 함. 그럼 가장 나중에 쓰이는 것, second가 큰 것의 우선순위가 높다.
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		if (a.second == b.second) {
			return a.first < b.first;
		}
		return a.second < b.second; //두 번째 인자 기준으로 내림차순 정렬
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp > pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	int mt = 0;
	cin >> m >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		sq.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		int temp = sq[n - 1 - i]; //끝에서부터
		v[temp].push_back(n - 1 - i);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		//cout << "mt = " << mt << "\n";
		if (on[sq[i]]) {
			v[sq[i]].pop_back();
			if (v[sq[i]].empty()) {
				pq.push(make_pair(sq[i], 200));
			}
			else {
				pq.push(make_pair(sq[i], v[sq[i]][v[sq[i]].size() - 1]));
			}
			continue;
		}
		if(mt >= m) { //멀티탭에 남은 자리 없을 때
			int del = pq.top().first;
			on[del] = 0;
			pq.pop();
			cnt++;
			mt--;
		}
		v[sq[i]].pop_back();
		mt++;
		if (v[sq[i]].empty()) {
			pq.push(make_pair(sq[i], 200));
		}
		else {
			pq.push(make_pair(sq[i], v[sq[i]][v[sq[i]].size() - 1]));
		}
		on[sq[i]] = 1;
	}
	cout << cnt;
}