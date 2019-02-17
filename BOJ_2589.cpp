#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int dist[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, M;

int bfs(vector <vector<char> > &map, int a, int b) {
	queue<pair<int, int > > q;
	q.push({ a,b });
	int m = 0;
	dist[a][b] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (map[nx][ny] == 'W') continue;
			if (dist[nx][ny] > -1) continue;

			dist[nx][ny] = dist[x][y] + 1;
			if (dist[nx][ny] > m) { m = dist[nx][ny]; }
			q.push({ nx,ny });
		}
	}
	return m;
}

int main() {
	
	cin >> N >> M;
	vector <vector <char> > map(N + 1, vector<char>(M + 1));
	vector <pair<int, int > > land;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') land.push_back({ i,j });
		}
	}
	int ans = 0;
	
	for (int i = 0; i < land.size(); i++) {
		memset(dist, -1, sizeof(dist));
		ans = max(ans, bfs(map,land[i].first, land[i].second));
	}

	cout << ans << '\n';
	

	return 0;
}
