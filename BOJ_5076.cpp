#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool go(string s) {

	stack <string> stk;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '<') {
			if (s[i + 1] == '/') {
				string a = "";
				int j = i + 2;
				while (s[j] != '>') {
					a += s[j];
					j++;
				}
				if (stk.size() == 0) return false;
				
				if (a != stk.top()) return false;
				else {
					stk.pop();
				}
			}
			else {

				if (s[i + 1] == 'b' && s[i + 2] == 'r') continue;
				if (s[i + 1] == 'a') { stk.push("a"); continue; }
				
				int j = i+1;
				string a = "";
				while (s[j] != '>') {
					a += s[j];
					j++;
				}
				stk.push(a);
			}
		}
	}
	if (stk.size() > 0) {
		return false;
	}
	return true;
}
int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s == "#") {
			break;
		}

		if (go(s)) {
			cout << "legal" << '\n';
		}
		else {
			cout << "illegal" << '\n';
		}
	}
	return 0;
}
