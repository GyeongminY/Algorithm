#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	stack<char> s;
	string str;
	int cnt = 0;
	bool ifGood = true;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (!s.empty() && str[j] == s.top()) {
				s.pop();
			}
			else s.push(str[j]);
		}
		if (s.empty()) cnt++;
		while (!s.empty()) s.pop();
	}
	printf("%d", cnt);
}