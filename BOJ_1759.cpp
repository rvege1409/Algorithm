#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
vector <string> v;

bool check(string s) {
	int a=0, b=0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i') {
			a++;
		}
		else {
			b++;
		}
	}

	if (a >= 1 && b >= 2) return true;

	return false;
}
void go(string s, int index) {
	if (s.length() == L) {
		if (check(s)) {
			cout << s << '\n';
		}
		return;
	}
	
	for (int i = index; i < C; i++) {
		s += v[i];
		go(s, i+1);
		s.pop_back();
	}
}
int main() {
	
	cin >> L >> C;
	string a;
	for (int i = 0; i < C; i++) {
		cin >> a;
		v.push_back(a);
	}
	string s = "";
	sort(v.begin(), v.end());
	go(s,0);

	return 0;

}
