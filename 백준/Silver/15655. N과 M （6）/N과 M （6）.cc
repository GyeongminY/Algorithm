#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
int arr[9];
bool isused[10001];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!isused[v[i]]) {
			if (k != 0 && arr[k - 1] > v[i]) continue;
			arr[k] = v[i];
			isused[v[i]] = 1;
			func(k + 1);
			isused[v[i]] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	func(0);
}