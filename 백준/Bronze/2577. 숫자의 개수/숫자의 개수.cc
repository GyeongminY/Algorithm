#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b, c, mp = 0, z = 0;
	cin >> a >> b >> c;

	int arr[10] = {};

	mp = a * b * c;
	if (mp / (int)pow(10, 9) != 0) z = 0;
	else if (mp / (int)pow(10, 8) != 0) z = 1;
	else if (mp / (int)pow(10, 7) != 0) z = 2;
	else if (mp / (int)pow(10, 6) != 0) z = 3;
	for (int i = 0; i < 10; i++) {
		int k = (int)pow(10, 9 - i);
			arr[mp / k]++;
			mp = mp % k;
	}
	arr[0] = arr[0] - z;
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
}