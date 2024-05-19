#include <iostream>
using namespace std;

int d[1000005];
int n;

int make_one(int k) {
	if (d[k]) {
		return d[k];
	}
	else if (k == 1) return 0;
	else {
		int ans;
		if (k % 3 == 0 && k % 2 == 0) {
			int a = make_one(k / 3);
			int b = make_one(k / 2);
			int s = a < b ? a : b;
			int c = make_one(k - 1);
			ans = (c < s ? c : s) + 1;
		}
		else if (k % 3 == 0) {
			int a = make_one(k / 3);
			int b = make_one(k - 1);
			int s = a < b ? a : b;
			ans = s + 1;
		}
		else if (k % 2 == 0) {
			int a = make_one(k / 2);
			int b = make_one(k - 1);
			int s = a < b ? a : b;
			ans = s + 1;
		}
		else {
			ans = make_one(k - 1) + 1;
		}
		d[k] = ans;
		return ans;
	}
}

int main() {
	cin >> n;
	d[2] = 1;
	d[3] = 1;
	int res = make_one(n);
	cout << res;
}