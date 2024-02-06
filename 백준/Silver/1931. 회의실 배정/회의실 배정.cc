#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int n;
	cin >> n;
	vector<pair <int, int> > v;
	pair<int, int> prev;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), compare);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		a = v[i].first; b = v[i].second;
		if (i == 0) { 
			prev = make_pair(a, b); 
			cnt++;
		}
		else {
			if (a >= prev.second) {
				prev = make_pair(a, b);
				cnt++;
			}
		}
	}
	cout << cnt;

}