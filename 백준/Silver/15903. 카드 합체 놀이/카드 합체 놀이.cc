#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	long long a, b, c;
	cin >> n >> m;
	priority_queue < long long, vector<long long>, greater<long long> > pq;
	for (int i = 0; i < n; i++) {
		cin >> a;
		pq.push(a);
	}
	for (int i = 0; i < m; i++) {
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		c = a + b;
		pq.push(c); pq.push(c);
	}
	long long total = 0;
	while (!pq.empty()) {
		total += pq.top(); pq.pop();
	}
	cout << total;
}