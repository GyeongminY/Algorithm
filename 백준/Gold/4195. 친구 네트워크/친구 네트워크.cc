#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <string, string> m;
map <string, int> siz;

string find(string k) {
	if (m[k].compare(k) == 0) return k;
	return m[k] = find(m[k]);
}

void merge(string str1, string str2) {
	string root1 = find(str1);
	string root2 = find(str2);
	if (root1.compare(root2) == 0) return;
	if (siz[root1] > siz[root2]) { 
		m[root2] = root1; 
		siz[root1] = siz[root1] + siz[root2]; 
	} //root1 < root2
	else {
		m[root1] = root2; 
		siz[root2] = siz[root1] + siz[root2];
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tcN, frndN;
	string f1, f2;
	cin >> tcN;
	for (int i = 0; i < tcN; i++) {
		m.clear();
		siz.clear();
		cin >> frndN;
		for (int j = 0; j < frndN; j++) {
			cin >> f1 >> f2;
			if (m.find(f1) == m.end()) { m[f1] = f1; siz[f1] = 1; } //map에 키가 없으면 자기자신 삽입.
			if (m.find(f2) == m.end()) { m[f2] = f2; siz[f2] = 1; }
			merge(f1, f2);
			cout << siz[find(f1)] << '\n';
		}
	}
}