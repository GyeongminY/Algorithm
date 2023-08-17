#include <iostream>

using namespace std;

int d[31];

int tile(int x) {
	if(x%2 != 0) return 0;
	if(x == 0) return 0;
	if(x == 2) return 3;
	if(x == 4) return 11;
	if(d[x] != 0) return d[x];
	int i;
	for(i=2; i < x-2; i+=2) {
		d[x] += 2*tile(i);
	}
	d[x] += 3*tile(x-2)+2;
	return d[x];
}

int main() {
	int n;
	cin >> n;
	if(n<1 || n>30) exit(1);
	cout << tile(n);
	return 0;
}