#include <iostream>
#include <string>
using namespace std;

int dp[4001][4001];

int main() {

	string a; string b;
	cin >> a >> b;

	int ans = 0;

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			
			if (a[i] == b[j]) {
				if (i - 1 >= 0 && j - 1 >= 0) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
					if (dp[i][j] > ans) ans = dp[i][j];
				}
				else {
					dp[i][j] = 1;
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
