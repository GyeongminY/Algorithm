#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int arr[5001] = {};
	int yos[5000] = {};
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	int countK = 0, idx = 1, idxY = 0;
	while (idxY < n) { //순열에 들어가는 숫자 n개
		if (arr[idx] == 0) {
			if (idx + 1 > n) {
				idx = 0;
			}
			else idx++;
			continue;
		}
		countK++;
		if (countK == k) {
			yos[idxY] = idx;
			idxY++;
			arr[idx] = 0;
			countK = 0;
		}
		if (idx + 1 > n) {
			idx = 0;
		}
		else idx++;
	}
	printf("<");
	for (int i = 0; i < n-1; i++) {
		printf("%d, ", yos[i]);
	}
	printf("%d>", yos[n - 1]);
}