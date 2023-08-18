#include <iostream>
#include <stack>

using namespace std;

int arr[100001]; //스택에 들어가 있거나 나왔으면 1, 스택에 아직 안 들어갔으면 0
char op[200002]; //연산자

int main() {
	int n, e, idx = 0, j = 1;
	cin >> n;

	stack<int> s;
	s.push(0);
	bool ifPossible = true;

	for (int i = 0; i < n; i++) {
		cin >> e;
		//printf("e = %d arr[e] = %d\n", e, arr[e]);
		if(!arr[e]) { //아직 스택에 안 들어간 경우
			while (s.top() != e) { 
				s.push(j);
				//printf("push %d\n", j);
				arr[j] = 1;
				op[idx] = '+';
				idx++;
				j++;
			}
		}
		if (s.top() != e) {
			ifPossible = false;
		}
		s.pop();
		//printf("pop\n");
		op[idx] = '-';
		idx++;
	}

	if (ifPossible) {
		for (int i = 0; i < idx; i++) {
			printf("%c\n", op[i]);
		}
	}
	else printf("NO");
}