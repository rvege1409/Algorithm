#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct rule {
	string x;
	string y;
};
int n;
rule R[10];
string y; string res;
bool flag = true;
int ans = 0;

void bfs() {
	
	queue <pair<string, int> > q;

	q.push({ y,0 });

	while (!q.empty()) {
		
		string temp = q.front().first;
		int t = q.front().second;
		
		if (temp == res) {
			ans = t;
			return;
		}
		
		q.pop();

		for (int i = 0; i < n; i++) {

			int p = temp.find(R[i].x, 0);
			if (p != -1) {
				string a = temp;
				while (p != -1) {
					a = a.replace(p, R[i].x.size(), R[i].y);
					p = a.find(R[i].x, p + R[i].y.size());
				}
				if (a.length() <= 10) {
					q.push({ a, t + 1 });
				}
			}
		}
	}
	flag = false;
}
int main() {
	while (1) {
		cin >> n;
		flag = true;
		if (n == 0)break;

		for (int i = 0; i < n; i++) {
			string a, b; cin >> a >> b;
			R[i].x = a; R[i].y = b;
		}
		cin >> y >> res;
		 
		bfs();

		if (!flag) {
			cout << -1 << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}
	return 0;
}
