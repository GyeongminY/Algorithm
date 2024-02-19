#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> v;
int arr[9];
bool isused[9];

void func(int k) { //st는 arr[0]에 들어갈 수의 v에서의 인덱스, k는 arr의 k번째에 들어갈 차례라는 뜻.
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (temp != v[i] && !isused[i]) {
			if (k != 0 && arr[k - 1] > v[i]) continue;
			arr[k] = v[i];
			isused[i] = 1;
			temp = arr[k];
			func(k + 1);
			isused[i] = 0;
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
	}
	sort(v.begin(), v.end());
	func(0);
}