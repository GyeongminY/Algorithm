#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<int> > pq; //우선순위 큐에 각 강의실에서 마지막에 수업이 끝나는 시간 저장. 그럼 제일 일찍 끝나는 시각을 알 수 있고 강의실을 더해야 하는지 알 수 있음.

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);
	int total = 0;
	for (int i = 0; i < n; i++) {
		if (pq.empty()) {
			pq.push(v[i].second);
			total++;
			continue;
		}
		if (pq.top() > v[i].first) {
			pq.push(v[i].second);
			total++;
		}
		else {
			pq.pop();
			pq.push(v[i].second);
		}
	}
	cout << total;
}