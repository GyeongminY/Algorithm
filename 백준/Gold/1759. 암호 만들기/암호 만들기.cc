#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
char str[16];
char arr[16];
bool isused[16];

void func(int k) {
	if (k == n) {
		bool a = false, b = false;
		int acnt = 0, bcnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') acnt++;
			else bcnt++;
		}
		if (acnt < 1 || bcnt < 2) return;
		for (int i = 0; i < n; i++) {
			cout << arr[i];
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < m; i++) {
		if (!isused[i]) {
			if (k != 0 && arr[k - 1] > str[i]) continue;
			arr[k] = str[i];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> str[i];
	}
	sort(str, str + m);
	func(0);
}