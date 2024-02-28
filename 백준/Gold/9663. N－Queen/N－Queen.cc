#include <iostream>
using namespace std;
int board[16][16];
int n, cnt;
bool isused1[16]; //상하
bool isused2[40]; // 우상향 대각선. idx = x + y
bool isused3[40]; // 좌상향 대각선. idx = n - 1 + x - y

void func(int k) { //k번째 행에 놓을 차례.
	if (k == n) {
		cnt++;
		return;
	}
	
	for (int i = 0; i < n; i++) { //k가 x, i가 y
		if (isused1[i] || isused2[k + i] || isused3[n - 1 + k - i]) continue;
		isused1[i] = 1;
		isused2[k + i] = 1;
		isused3[n - 1 + k - i] = 1;
		func(k + 1);
		isused1[i] = 0;
		isused2[k + i] = 0;
		isused3[n - 1 + k - i] = 0;
	}
}

int main() {
	cin >> n;
	func(0);
	cout << cnt;
}