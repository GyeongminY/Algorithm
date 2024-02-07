#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	char c;
	int change = 0;
	for (int i = 0; i < s.size()-1; i++) {
		if (s[i] != s[i + 1]) change += 1;
	}
	cout << (change+1) / 2;
}