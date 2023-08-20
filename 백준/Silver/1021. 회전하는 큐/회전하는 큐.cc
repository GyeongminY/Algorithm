#include <iostream>
#include <deque>

using namespace std;

int main() {
	int n, e, m, cnt = 0, idx;
	cin >> n >> m;
	deque <int> dq; //first가 수, second가 인덱스
	int out;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		cin >> out;
		for (int i = 0; i < n; i++) { //빼낼 수 인덱스 찾기
			if (dq[i] == out ) {
				idx = i;
				break;
			}
		}

		if (idx <= dq.size() / 2) {
			while (dq.front() != out) {
				e = dq.front();
				dq.push_back(e);
				dq.pop_front();
				cnt++;
			}
			dq.pop_front();
		}
		else {
			while (dq.front() != out) {
				e = dq.back();
				dq.push_front(e);
				dq.pop_back();
				cnt++;
			}
			dq.pop_front();
		}
	}
	printf("%d", cnt);
	
}