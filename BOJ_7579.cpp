#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int D[101][10001];
int A[101];
int C[101];
int ans = 987654321;
int N, M;

int go(int x, int y) {

	if (x < 1) return 0;

	if (D[x][y] > 0) {
		if (D[x][y] >= M) {
			if (y < ans) ans = y;
		}
		return D[x][y];
	}
	
	if (y - C[x] < 0) {
		D[x][y] = max(0,go(x - 1, y));
	}
	else {
		D[x][y] = max(go(x - 1, y), go(x - 1, y - C[x]) + A[x]);
	}
	if (D[x][y] >= M) {
		if (y < ans) ans = y;
	}
	return D[x][y];
}

int main() {

	scanf("%d %d", &N, &M);

	memset(D, 0, sizeof(D));

	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	int maxsum = 0;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &C[i]);
		maxsum += C[i];
	}
	D[1][C[1]] = A[1];

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= maxsum; j++) {
				go(i, j);
		}
	}
	
	
	printf("%d\n", ans);
	return 0;
}
