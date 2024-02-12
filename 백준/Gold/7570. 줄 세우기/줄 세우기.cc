#include <iostream>
using namespace std;
int location[1000002];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		location[a] = i;
	}
	int mx = 0;
	int temp = 0;
	for (int i = 1; i <= n-1; i++) {
		if (location[i] < location[i + 1]) {
			temp++;
		}
		if (location[i] > location[i + 1]) {
			if (mx < temp) {
				mx = temp;
			}
			temp = 0;
		}
	}
	int ans = n - (mx + 1);
	cout << ans;
}