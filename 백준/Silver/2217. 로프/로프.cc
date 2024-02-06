#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), compare);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int w = v[i] * (i + 1);
		if (mx < w) mx = w;
	}
	cout << mx;
}