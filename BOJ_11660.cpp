#include <iostream>
using namespace std;

int map[1025][1025];
int D[1025][1025];

int main() {
	
	int N, M; scanf("%d %d", &N, &M);

	int x1, y1, x2, y2;

	D[1][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
			D[i][j] = D[i][j - 1] + map[i][j];
		}
	}

	
	for (int i = 0; i < M; i++) {
		
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int ans = 0;
		for (int i = x1; i <= x2; i++) {
			ans += D[i][y2] - D[i][y1 - 1];
		}

		printf("%d\n", ans);
	}

	return 0;
}