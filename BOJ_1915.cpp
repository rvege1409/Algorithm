#include <iostream>
#include <algorithm>
using namespace std;

int map[1005][1005];
int dp[1005][1005];

int main() {
	
	int n, m; cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 1) {

				dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
				ans = max(ans, dp[i][j]);

			}
		}
	}
	
	printf("%d\n", ans*ans);
	return 0;
}