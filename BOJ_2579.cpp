#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[301];
int A[301];

int go(int n) {

	if (n <= 0) return 0;

	if (dp[n] > -1) return dp[n];

	dp[n] =  max(A[n] + go(n - 2), A[n]+A[n-1]+go(n-3));

	return dp[n];
}

int main() {
	
	int N; scanf("%d", &N);
	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	dp[0] = 0;
	dp[1] = A[1];
	
	go(N);
	
	
	printf("%d\n", dp[N]);
	return 0;
}