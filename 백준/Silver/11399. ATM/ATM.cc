#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

int main() {
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int total = 0;
	int prev;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			total += v[i];
			prev = v[i];
		}
		else {
			int temp = prev + v[i];
			total += temp;
			prev = temp;
		}
	}
	cout << total;
}