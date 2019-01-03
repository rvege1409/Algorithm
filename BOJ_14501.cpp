#include <iostream>
#include <vector>
using namespace std;

int N;
int ans;

void solve(vector <pair <int, int> > &v, int day, int pay) {
	if (day > N) {
		return;
	}

	if (day == N) {
		if (ans < pay) ans = pay;
		return;
	}

	solve(v, day + v[day].first, pay + v[day].second);
	solve(v, day + 1, pay);
}
int main() {
	cin >> N;
	vector <pair<int, int> > v(N);

	ans = 0;
	for (int i = 0; i < N; i++) {
		int T; int P;
		cin >> T >> P;
		v[i].first = T;
		v[i].second = P;
	}

	solve(v, 0, 0);

	cout << ans << '\n';

	return 0;

}
