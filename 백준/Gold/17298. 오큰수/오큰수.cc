#include <stack>
#include <iostream>

#define MAX_NUM 1000001
using namespace std;

stack<pair<int, int> > st;
int nge[MAX_NUM];

void find_nge(int x, int idx, int n) {
	if (idx == 1 && idx != n) { //수열의 처음
		st.push(make_pair(x, idx));
	}
	else if (idx == n) { //수열 마지막
		while(st.empty() == 0) { //스택에 남아있는 원소들 처리
			if (st.top().first < x) { //x가 st.top()보다 클 때
				nge[st.top().second] = x;
			}
			else { //스택의 맨 위 원소가 스택에서 제일 작은 원소. x가 top보다 작으면 나머지 원소의 nge는 다 -1.
				nge[st.top().second] = -1;
			}
			st.pop();
		}
		nge[idx] = -1;
	}
	else { // 수열 중간
		while(st.empty() == 0) { //스택에 x보다 작은 원소가 있는지 본다.
			if (st.top().first < x) { //x가 st.top()보다 클 때
				nge[st.top().second] = x;
				st.pop();
			}
			else { //스택에 x보다 작은 원소가 남아있지 않을 때
				st.push(make_pair(x, idx));
				break;
			}
		}
		st.push(make_pair(x, idx));
	}
}

int main() {
	int n, e;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> e;
		find_nge(e, i + 1, n);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", nge[i]);
	}
}