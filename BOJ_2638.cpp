#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void dfs(vector<vector<int> > &map, int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (map[nx][ny] == -1) continue;
		
		if (map[nx][ny] == 0) {
			map[nx][ny] = -1;
			dfs(map, nx, ny);
		}
		else {
			map[nx][ny]++;
		}
	}
}
int main() {
	cin >> N >> M;

	vector <vector <int> > map(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	int lap = 0;
	
	while (1) {
		
		dfs(map, 0, 0);
		
		bool c = false;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == -1 || map[i][j] == 0) map[i][j] = 0;
				else if (map[i][j] >= 3) map[i][j] = 0;
				else { map[i][j] = 1; c = true; }
			}
		}
	
		lap++;
		if (!c) { break; }
	}
	cout << lap << '\n';
	return 0;
}