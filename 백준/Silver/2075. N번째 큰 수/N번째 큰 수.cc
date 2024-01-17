#include <iostream>
#include <queue>
using namespace std;

class cmp {
public:
	bool operator() (int x, int y) {
		return x > y;
	}
};

priority_queue<int, vector<int>, cmp> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int k;
	//첫 줄은 min heap에 다 넣는다.
	for (int i = 0; i < n; i++) {
		cin >> k; pq.push(k);
	}
	//두 번째 줄부터는 top보다 크면 pq에 넣는다.
	for (int i = 0; i < (n-1)*n; i++) {
		cin >> k;
		if (k > pq.top()) {
			pq.pop();
			pq.push(k);
		}
	}
	cout << pq.top();
}