#include <iostream>
#include <queue>
using namespace std;

class comp {
public:
	bool operator() (int x, int y) {
		return x > y;
	}
};

priority_queue<int, vector<int>, comp> pq;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k == 0) {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else cout << "0\n";
		}
		else {
			pq.push(k);
		}
	}
}