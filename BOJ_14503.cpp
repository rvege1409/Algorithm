#include <iostream>
#include <vector>
using namespace std;

int dx[] = { -1,0,1,0 }; // up right down left
int dy[] = { 0,1,0,-1 };
int clean[51][51];
int N, M;

int solve(vector <vector <int> > &map, int x, int y, int dir, int cnt) {

	if (clean[x][y] == 0) {
		cnt++;
		clean[x][y] = 1;
	}

	bool flag = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		if (map[nx][ny] != 1 && clean[nx][ny] == 0) { flag = true; break; }
	}

	int t = dir;

	if (flag) {

		if (t - 1 < 0) t = 3;
		else t = t - 1;

		int nx = x + dx[t]; int ny = y + dy[t];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
			solve(map, x, y, t, cnt);
		}
		else if (map[nx][ny] == 1 || (clean[nx][ny] == 1 && map[nx][ny] == 0)) {
			solve(map, x, y, t, cnt);
		}
		else if (map[nx][ny] != 1 && clean[nx][ny] == 0) {
			solve(map, nx, ny, t, cnt);
		}
	}
	else {
		int k = dir;
		int nx = x + dx[(k + 2) % 4];
		int ny = y + dy[(k + 2) % 4];
		if (map[nx][ny] == 1) {
			return cnt;
		}
		else {
			solve(map, nx, ny, k, cnt);
		}
	}
}
int main() {
	cin >> N >> M;
	int r, c, dir; cin >> r >> c >> dir;

	vector <vector <int> > map(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int ans = solve(map, r, c, dir, 0);

	cout << ans << '\n';

	return 0;
}