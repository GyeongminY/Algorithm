#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strC[26];
int ranC[26];

bool ifPossible(string str, string ranstr) {
	for (int j = 0; j < 26; j++) {
		strC[j] = 0;
		ranC[j] = 0;
	}

	for (int j = 0; j < str.length(); j++) {
		strC[str[j] - 0x61]++;	//str에 있는 알파벳 개수 세기
	}
	for (int j = 0; j < ranstr.length(); j++) {
		ranC[ranstr[j] - 0x61]++;	//ranstr에 있는 알파벳 개수 세기
	}
	for (int j = 0; j < 26; j++) {
		if (strC[j] != ranC[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	string str, ranstr;
	vector<string> strv, ranv;
	bool poss = 1;
	for (int i = 0; i < n; i++) {
		cin >> str;
		strv.push_back(str);
		cin >> ranstr;
		ranv.push_back(ranstr);
	}
	for (int i = 0; i < n; i++) {
		poss = ifPossible(strv[i], ranv[i]);
		if (poss) printf("Possible\n");
		else printf("Impossible\n");
	}
		
}