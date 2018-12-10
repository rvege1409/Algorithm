#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int N, M;

void dfs(vector <vector <int> > &map, int x, int y) {
	
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
	int cheese = 0;
	vector <vector <int> > map(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) cheese++;
		}
	}

	int lap = 0;
	
	while (1) {
		
		dfs(map, 0, 0);
		

		int k = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == -1) map[i][j] = 0;
				else if (map[i][j] > 1) map[i][j] = 0;
				else if (map[i][j] == 1) k++;
			}
		}
		lap++;
		if (k == 0) break;
		cheese = k;
	}
	cout << lap << '\n';
	cout << cheese << '\n';

	return 0;
}