#include <iostream>
#include <stack>

using namespace std;

int height[500001];
int receive[500001];
int inStackIdx[500001]; //스택에 들어가있는 수의 인덱스 기록

int main() {
	int n, idx = 0;
	cin >> n;
	stack<int> s;
	for (int i = 1; i <= n; i++) {
		cin >> height[i];
	}
	s.push(100000001);
	for (int i = 1; i <=n; i++) {
		while (height[n+1-i] > s.top()) {
			//printf("pop\n");
			s.pop();
			receive[inStackIdx[idx]] = n+1 - i;
			//printf("receive[%d] = %d\n", inStackIdx[idx], n+1 - i);
			idx--;
		}
		idx++;
		s.push(height[n+1 - i]);
		//printf("push %d\n", n+1 - i);
		inStackIdx[idx] = n+1 - i;
		//printf("inStackIdx[%d] = %d\n", idx, n+1 - i);
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", receive[i]);
	}
}