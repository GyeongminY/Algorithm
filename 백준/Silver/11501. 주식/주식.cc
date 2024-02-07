#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	while (N--) {
		int n;
		cin >> n;
		long long ans = 0;
		vector<int> v;
		int a, mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a;
			v.push_back(a);
		}
		for (int i = n - 1; i >= 0; i--) {
			if (v[i] > mx) {
				mx = v[i];
			}
			if (v[i] < mx) {
				ans += mx - v[i];
			}
		}
		cout << ans << "\n";
	}
}