#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, e;
	cin >> n;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while(q.size() > 1) {
		q.pop();
		if (q.size() == 1) break;
		e = q.front();
		q.pop();
		q.push(e);
	}
	printf("%d", q.front());
}