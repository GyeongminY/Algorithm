#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;

int main() {
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	int mx = v[n-1];
	int ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (v[i] >= mx) {
			ans += v[i] - (mx - 1);
			v[i] = mx - 1;
		}
		mx = v[i];
	}
	cout << ans;
}