#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;

int main() {
	int n;
	cin >> n;
	int a;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	//일단 작은 수부터 훑음
	int idx = 0;
	while (idx < n) {
		if (v[idx] >= 0) break;
		if (idx == n - 1) {
			ans += v[idx];
			break;
		}
		//v[i]가 음수일 때
		if (v[idx + 1] <= 0) {
			ans += v[idx] * v[idx + 1];
			idx += 2;
		}
		else {
			ans += v[idx];
			idx++;
		}
	}
	//큰 수부터 훑음
	idx = n - 1;
	while (idx >= 0) {
		if (v[idx] <= 0) break;
		//v[i]가 양수일 때
		if (idx == 0) {
			ans += v[idx];
			break;
		}
		if (v[idx - 1] > 1) {
			ans += v[idx] * v[idx - 1];
			idx -= 2;
		}
		else {
			ans += v[idx];
			idx--;
		}
	}
	//수 하나일 때
	if (n == 1) {
		cout << v[0];
		return 0;
	}
	cout << ans;
}