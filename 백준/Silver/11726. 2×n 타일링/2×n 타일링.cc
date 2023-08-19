#include <iostream>

#define K 10007

using namespace std;

int d[1001];

int tile(int x) {
	if(x==1) return 1;
	if(x==2) return 2;
	if(d[x] != 0) return d[x];
	return d[x] = (tile(x-1) + tile(x-2))%K;
}

int main() {
	int n;
	cin >> n;
	if(n<1 || n>1000) exit(1);
	cout << tile(n);
	return 0;
}