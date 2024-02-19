#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, s, cnt;
vector<int> v;

void func(int k, int prev) { //k는 탐색할 인덱스를 나타냄. prev는 전까지 더한 수
	prev += v[k]; //일단 v[k]를 더한다. 이게 s보다 크면 더 더하면 안 됨.
	if (prev == s) {
		cnt++;
	}

	for (int i = k+1; i < n; i++) {
		func(i, prev);
	}
	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> s;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		func(i, 0);
	}
	cout << cnt;
}