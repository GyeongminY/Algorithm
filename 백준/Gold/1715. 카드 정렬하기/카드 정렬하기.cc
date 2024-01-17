#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<int> v;

class cmp {
public:
	bool operator() (int x, int y) {
		return x > y;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int, vector<int>, cmp> pq;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
		pq.push(k);
	}
	int total = 0;
	while (pq.size() != 1) {
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		total = a + b;
		pq.push(total);
		v.push_back(total);
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ans += v[i];
	}
	if (n == 1) cout << "0";
	else cout << ans;
}