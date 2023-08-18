#include <iostream>
#include <stack>

using namespace std;

int main() {
	int k, e, sum = 0;
	cin >> k;
	stack<int> s;
	for (int i = 0; i < k; i++) {
		cin >> e;
		if (e) {
			s.push(e);
		}
		else {
			s.pop();
		}
	}
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	printf("%d", sum);
}