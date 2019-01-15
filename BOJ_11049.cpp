#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector <pair<int, int> >n(501);
int dp[501][501];

int go(int x, int y) {

	if (dp[x][y] > -1) return dp[x][y];

	int temp = 987654321;
	for (int i = x+1; i <= y; i++) {
		temp = min(temp, go(x,i-1) + go(i,y) + (n[x].first * n[i].first * n[y].second));
	}
	dp[x][y] = temp;
	return dp[x][y];

}
int main() {
	
	int N;

	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++) {
		int a, b;
		dp[i][i] = 0;
		scanf("%d %d", &n[i].first, &n[i].second);
		
	}

	 

	go(1, N);

	
	
	printf("%d\n", dp[1][N]);

	return 0;

}