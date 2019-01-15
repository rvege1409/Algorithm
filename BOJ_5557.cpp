#include <iostream>
#include <cstring>
using namespace std;

long long dp[101][101];
int A[101];

long long go(int n, int Num) {
	if (Num < 0 || n < 1 || Num > 20) return 0;

	if (dp[n][Num] > -1) return dp[n][Num];

	dp[n][Num] = go(n - 1, Num + A[n]) + go(n - 1, Num - A[n]);

	return dp[n][Num];
}
int main() {

	int N; cin >> N;
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		A[i] = a;
	}

	dp[1][A[1]] = 1;

	go(N - 1, A[N]);

	cout << dp[N-1][A[N]] << '\n';

	return 0;
}