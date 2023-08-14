#include <iostream>

using namespace std;

int RoomN(int number, int k) {
	if (number == 0) return 0;
	else if (number % k == 0) return number / k;
	return number / k + 1;
}

int main() {
	int n, k, s, grade, sum = 0;
	cin >> n >> k;
	int boys[6] = {};
	int girls[6] = {};
	for (int i = 0; i < n; i++) {
		cin >> s >> grade;
		if (s == 0) {
			girls[grade-1]++;
		}
		else boys[grade-1]++;
	}
	for (int i = 0; i < 6; i++) {
		sum += RoomN(girls[i], k);
		sum += RoomN(boys[i], k);
	}
	printf("%d", sum);

}