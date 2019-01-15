#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int num[501][501];
int D[501][501];


int main() {
	
	int n; scanf("%d", &n);

	int p = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= p; j++) {
			scanf("%d", &num[i][j]);
		}
		p++;
	}
	
	memset(D, -1, sizeof(D));

	D[1][1] = num[1][1];
	p = 2;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= p; j++) {
			D[i][j] = max(D[i - 1][j] + num[i][j], D[i - 1][j - 1] + num[i][j]);
		}
		p++;
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (D[n][i] > ans) ans = D[n][i];
	}

	cout << ans << '\n';

	return 0;
}