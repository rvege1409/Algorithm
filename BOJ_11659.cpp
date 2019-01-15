#include <iostream>
using namespace std;

int num[100001];
int dp[100001];
int main() {
	
	int N, M; scanf("%d %d", &N, &M);

	num[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];

		dp[i] = dp[i - 1] + num[i];
	}

	for (int i = 0; i < M; i++) {
		int x, y; scanf("%d %d", &x, &y);

		printf("%d\n", dp[y] - dp[x - 1]);
	}

	return 0;


}