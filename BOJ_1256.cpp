#include <iostream>
#include <string>
using namespace std;

long long e[201][201];
int N, M, K;
int INF = 1000000000;

void find(int n, int m, int k) {
	if (n == 0 && m == 0) {
		return;
	}

	int a = e[n + m - 1][n - 1];
	int z = e[n + m - 1][n];

	if (k <= a) {
		printf("a");
		find(n - 1, m, k);
	}
	else if (k > a) {
		printf("z");
		find(n, m - 1, k - a);
	}
}
int main() {

	for (int i = 0; i <= 200; i++) {

		e[i][0] = 1;
		e[i][i] = 1;

		for (int j = 1; j <= 200; j++) {

			if (i < j) break;

			e[i][j] = e[i - 1][j - 1] + e[i - 1][j];

			if (e[i][j] > INF) e[i][j] = INF + 1;
		}
	}

	cin >> N >> M >> K; // N: aÀÇ °¹¼ö, M : zÀÇ °¹¼ö

	if (e[N + M][N] < K) { cout << -1 << '\n'; return 0; }

	find(N, M, K);

	

	return 0;
}