#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int h[500001];

int main() {
	int n, inStackNum = 0;
	long long sum = 0;
	int same = 0; //같은 수 개수 저장
	int popNum = 0; //스택에서 빼내는 수 저장
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	stack<pair<int, int>> s;//첫 번째가 키, 두 번째가 같은 것 개수
	for (int i = 0; i < n; i++) {
		popNum = 0;
		same = 0;
		if (s.empty()) {
			s.push({ h[i], 1 });
			//printf("push %d\n", h[i]);
			continue;
		}
		while (!s.empty() && h[i] > s.top().first) {
			same = s.top().second;
			s.pop();
			popNum += same;
			//printf("pop\n");
		}
		if (!s.empty() && h[i] < s.top().first) {
			sum += (popNum + 1);
			s.push({ h[i], 1 });
			//printf("push %d sum = %lld\n", h[i], sum);
			continue;
		}
		if (!s.empty() && h[i] == s.top().first) {
			same = s.top().second;
			s.pop();
			if (s.empty()) {
				sum += (popNum + same);
			}
			else {
				sum += (popNum + same + 1);
			}
			s.push({ h[i], same + 1 });
			//printf("push %d sum = %lld\n", h[i], sum);
		}
		if (s.empty()) {
			s.push({ h[i], 1 });
			sum += popNum;
			//printf("push %d sum = %d\n", h[i], sum);
		}
		
	}
	printf("%lld", sum);
}