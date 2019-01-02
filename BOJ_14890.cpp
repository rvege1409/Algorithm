#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;

bool check(vector <int> &n, int L) {
	vector <bool> c(N, false);

	for (int i = 0; i < N - 1; i++) {
		if (n[i] == n[i + 1]) continue;

		if (abs(n[i] - n[i + 1]) != 1) return false;

		if (n[i] > n[i + 1]) {
			for (int j = 1; j <= L; j++) {
				if (i + j >= N) return false;

				if (n[i + j] != n[i + 1]) return false;

				if (c[i + j]) return false;

				c[i + j] = true;
			}
		}
		else {
			for (int j = 1; j <= L; j++) {
				if (i + 1 - j < 0) return false;

				if (n[i + 1 - j] != n[i]) return false;

				if (c[i + 1 - j]) return false;

				c[i + 1 - j] = true;
			}
		}
	}
	return true;
}
int main() {
	cin >> N;
	int L;
	cin >> L;

	vector <vector <int> > map(N, vector <int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		vector <int> garo;
		for (int j = 0; j < N; j++) {
			garo.push_back(map[i][j]);
		}
		if (check(garo, L)) ans++;
	}

	for (int j = 0; j < N; j++) {
		vector <int> sero;
		for (int i = 0; i < N; i++) {
			sero.push_back(map[i][j]);
		}
		if (check(sero, L)) ans++;
	}


	cout << ans << '\n';
	return 0;
}
