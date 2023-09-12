#include <iostream>
#include <vector>

using namespace std;
vector<long long> result;
long long d[31][31] = {};

/*long long combination(int n, int m) {
	long long res = 1;
	for (int i = 0; i < n; i++) {
		res *= (m - i);
	}
	for (int i = 1; i <= n; i++) {
		res = res / i;
	}
	return res;
}*/

long long combination(int n, int m) {
	if (m == n) return 1;
	if (m == 1) return 1;
	if (n == 1) return m;
	if (d[n][m]) return d[n][m];
	return d[n][m] = combination(n - 1, m-1) + combination(n, m - 1);
}

int main() {
	int n, m, t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		long long num = combination(n, m);
		result.push_back(num);
	}
	for (int i = 0; i < result.size(); i++) {
		printf("%lld\n", result[i]);
	}
}