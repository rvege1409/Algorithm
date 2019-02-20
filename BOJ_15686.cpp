#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int map[51][51];
vector <pair <int, int > > c;
vector <pair<int, int > > h;
vector <pair<int, int > > temp;
int ans = 987654321;
void solve(int cnt, int index) {
	if (cnt == M) {

		int len = 0;
		for (int i = 0; i < h.size(); i++) {
			int tmp = 987654321;
			for (int j = 0; j < temp.size(); j++) {
				tmp = min(tmp, abs(h[i].first - temp[j].first) + abs(h[i].second - temp[j].second));
			}
			len += tmp;
		}

		ans = min(ans, len);
		return;
	}

	for (int i = index; i < c.size(); i++) {
		temp.push_back(c[i]);
		solve(cnt + 1, i+1);
		temp.pop_back();
	}
}
int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				c.push_back({ i,j });
			}
			if (map[i][j] == 1) {
				h.push_back({ i,j });
			}
		}
	}

	solve(0, 0);

	cout << ans << '\n';

	return 0;
}
