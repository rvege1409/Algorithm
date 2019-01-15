#include <iostream>
#include <cstdio>
using namespace std;


int map[1003][1003];
int t[1003][1003];
int main() {
	
	int H, W, N; cin >> H >> W >> N;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			int op; scanf("%d", &op);
			map[i][j] = op;
		}
	}

	t[1][1] = N-1;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			int p, r;
			p = t[i][j] / 2; r = t[i][j] % 2;
			if (t[i][j] % 2 == 0) {
				t[i + 1][j] += p;
				t[i][j + 1] += p;
			}
			else {
				t[i + 1][j] += p;
				t[i][j + 1] += p;
				if (map[i][j] == 1) {
					t[i][j + 1] += r;
				}
				else {
					t[i + 1][j] += r;
				}
			}
		}
	}
	

	int x = 1;
	int y = 1;
	

	while (x < H+1 && y < W+1) {
		if (t[x][y]%2 != 0) {
			if (map[x][y] == 1) {
				x = x + 1;
			}
			else {
				y = y + 1;
			}
		}
		else {
			if (map[x][y] == 1) {
				y = y + 1;
			}
			else {
				x = x + 1;
			}
		}
	}
	
	cout << x << ' ' << y << '\n';

	return 0;

}