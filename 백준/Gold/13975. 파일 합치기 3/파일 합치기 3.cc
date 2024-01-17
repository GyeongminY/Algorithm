#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class cmp {
public:
	bool operator() (long long x, long long y) {
		return x > y;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		priority_queue<long long, vector<long long>, cmp> pq;
		vector<long long> v;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			pq.push(k);
		}
		while (pq.size() > 1) {
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();
			long long total = a + b;
			pq.push(total);
			v.push_back(total);
		}
		long long ans = 0;
		for (int i = 0; i < v.size(); i++) {
			ans += v[i];
		}
		if (n < 2) cout << "0\n"; 
		else cout << ans << '\n';
	}
}