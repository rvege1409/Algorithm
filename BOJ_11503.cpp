#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int A[1001];
int dp[1001];

int main() {
	
	int N; scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	int ans = 1;
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[j] < A[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
				if (dp[i] > ans) ans = dp[i];
			}
		}
	}
	
	printf("%d\n", ans);

	return 0;
}
