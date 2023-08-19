#include <iostream>
#include <stack>

using namespace std;

int height[80001];

int main() {
	int inStackNum = 0;
	long long sum = 0;
	int n;
	stack<int> s;
	s.push(1000000001);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}
	for (int i = 0; i < n; i++) {
		while (height[i] >= s.top()) {
			s.pop();
			inStackNum--;
			//printf("pop inStackNum = %d\n", inStackNum);
		}
		sum += inStackNum;
		s.push(height[i]);	
		inStackNum++;
		//printf("push %d inStackNum = %d sum = %d\n", height[i], inStackNum, sum);
	}
	cout << sum;
}