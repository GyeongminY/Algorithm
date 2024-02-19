#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
int arr[9];
bool isused[9][10002];
int cnt[10002];

void func(int k) { //st는 arr[0]에 들어갈 수의 v에서의 인덱스, k는 arr의 k번째에 들어갈 차례라는 뜻.
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!isused[k][v[i]] && cnt[v[i]]) {
			arr[k] = v[i];
			isused[k][v[i]] = 1;
			cnt[v[i]]--;
			func(k + 1);
			cnt[v[i]]++;
		}
		for (int j = 0; j < n; j++) {
			if (isused[k + 1][v[j]]) isused[k + 1][v[j]] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
		cnt[a]++;
	}
	sort(v.begin(), v.end());
	func(0);
}