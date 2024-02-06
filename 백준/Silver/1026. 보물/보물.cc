#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
vector<int> B;
int n;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> b;
		B.push_back(b);
	}
	sort(A.begin(), A.end(), compare);
	sort(B.begin(), B.end());
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += A[i] * B[i];
	}
	cout << total;
}