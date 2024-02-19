#include <iostream>
using namespace std;
int arr[7];
int num[50];
int isused[50];
int n;

void func(int k) {
	if (k == 6) {
		for (int i = 0; i < 6; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			if (k != 0 && arr[k - 1] > num[i]) continue;
			arr[k] = num[i];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
		
	}
}

int main() {
	while (1) {
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		func(0);
		cout << "\n";
	}
}