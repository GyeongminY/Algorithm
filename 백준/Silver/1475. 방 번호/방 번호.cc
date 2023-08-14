#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int arr[10] = {};
	int n, maxN, k, need;
	cin >> n;
	k = n / pow(10, 6);
	arr[k]++;
	for (int i = 0; i < 6; i++) {
		k = n % (int)pow(10, 6 - i) / (int)pow(10, 5 - i);
		arr[k]++;
	}
	for (int i = 0; i < 7; i++) {
		maxN = n / (int)pow(10, 6 - i);
		if (maxN != 0) {
			maxN = i;
			break;
		}
	}
	arr[0] = arr[0] - maxN;	//방 숫자 개수 파악 완료
	/*for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");*/
	arr[6] = arr[6] + arr[9];
	arr[9] = 0;
	need = arr[0];
	maxN = 0;
	for (int i = 1; i < 10; i++) {
		if (arr[i] > need) {
			need = arr[i];
			maxN = i;
			if (maxN == 6) {
				if (need % 2 == 0)
					need = need / 2;
				else
					need = need / 2 + 1;
			}
		}
	}
	/*if (maxN == 9) {
		for (int i = 0; i < 9; i++) {
			if (arr[i] > need) {
				need = arr[i];
				maxN = i;
				if (maxN == 6) {
					if (arr[6] == arr[9]) need = need;
					else if (need % 2 == 0)
						need = need / 2;
					else
						need = need / 2 + 1;
				}
			}
		}
	}*/
	printf("%d", need);
}