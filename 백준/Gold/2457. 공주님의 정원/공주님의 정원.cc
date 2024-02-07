#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<pair <pair <int, int>, pair <int, int> > > v;

bool compare(pair <pair <int, int>, pair <int, int> > f1, pair <pair <int, int>, pair <int, int> > f2) {
	//3월 전이나 3월 1일에 시작하는 경우 나중에 끝나는 것이 우선
	if ((f1.first.first < 3 || f1.first.first == 3 && f1.first.second == 1) && (f2.first.first < 3 || f2.first.first == 3 && f2.first.second == 1)) {
		if (f1.second.first == f2.second.first) {
			return f1.second.second > f2.second.second;
		}
		return f1.second.first > f2.second.first;
	}
	//먼저 피는 순으로. 다만 피는 날이 같을 때는 나중에 끝나는 것이 우선.
	if (f1.first.first == f2.first.first) {
		if (f1.first.second == f2.first.second) {
			if (f1.second.first == f2.second.first) {
				return f1.second.second > f2.second.second;
			}
			return f1.second.first > f2.second.first;
		}
		return f1.first.second < f2.first.second;
	}
	return f1.first.first < f2.first.first;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int a, b, c, d;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		v.push_back(make_pair(make_pair(a, b), make_pair(c, d))); //( (a, b), (c, d) )가 벡터에 들어감
	}
	sort(v.begin(), v.end(), compare);

	int cnt = 0;
	int prev_i = -1, mx_i = 0;
	pair <pair <int, int>, pair <int, int> > prev;
	pair <pair <int, int>, pair <int, int> > mx;
	int idx = 0;
	while (idx < n) {
		idx = prev_i + 1;
		//cout << "idx = " << idx << "\n";
		if (idx == 0) {
			if (v[idx].first.first > 3 || (v[idx].first.first == 3 && v[idx].first.second > 1)) {
				cnt = 0;
				break;
			}
			if (n == 1 && v[idx].second.first < 12) { cnt = 0; break; }
			prev = v[idx];
			mx = v[idx];
			prev_i = idx; mx_i = idx;
			cnt++;
			idx++;
			if (mx.second.first > 11) {
				break;
			}
			continue;
		}
		//prev의 끝나는 시점보다 이전에 피는 것 중 가장 늦게 지는 꽃을 찾아야 함.
		for (int i = idx; i < n; i++) {
			//prev와 안 이어지면 불가능.
			if (i == prev_i + 1 && (v[i].first.first > prev.second.first || (v[i].first.first == prev.second.first && v[i].first.second > prev.second.second))) {
				cout << "0";
				return 0;
			}
			//prev 끝나는 시점보다 나중에 피면 이때 prev 갱신
			if (v[i].first.first > prev.second.first || (v[i].first.first == prev.second.first && v[i].first.second > prev.second.second)) {
				prev = mx;
				prev_i = mx_i;
				cnt++;
				break;
			}
			//이전 최댓값보다 현재의 꽃이 더 나중에 지면 최댓값 갱신
			if (mx.second.first < v[i].second.first || mx.second.first == v[i].second.first && mx.second.second < v[i].second.second) {
				mx = v[i];
				mx_i = i;
			}
			if ((i == n - 1) && (mx.second.first <= 11)) {
				cnt = 0;
				cout << cnt;
				return 0;
			}
			//최댓값이 12월에 지면 끝남.
			if (mx.second.first > 11) {
				cnt++;
				cout << cnt;
				return 0;
			}
		}
	}
	cout << cnt;
}