#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> >  v;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);
	int st, ed, total;
	st = v[0].first; ed = v[0].second; total = v[0].second - v[0].first;
	for (int i = 1; i < n; i++) {
		if (v[i].second <= ed) continue;
		if (v[i].first <= ed && v[i].second > ed) {
			total += v[i].second - ed;
			ed = v[i].second;
		}
		if (v[i].first > ed) {
			st = v[i].first;
			ed = v[i].second;
			total += ed - st;
		}
	}
	cout << total;
}