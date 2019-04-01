#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int R, C;
char map[1001][1001];
int dist[1001][1001];
int dist2[1001][1001];
int jx, jy;
int fx, fy;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int a, int b) {
	queue <pair<int, int > >q;
	q.push({ a,b });
	dist[a][b] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > R || ny <= 0 || ny > C) continue;
			if (map[nx][ny] == '#' || map[nx][ny] =='F') continue;
			if (dist[nx][ny] > -1) {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny });
				}
				continue;
			}
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx,ny });
		}
	}
}

int bfs1(int a, int b) {
	queue <pair<int, int> >q;
	q.push({ a,b });
	dist2[a][b] = 0;
	
	int time = 987654321;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > R || ny <= 0 || ny > C) {
				if (time > dist2[x][y] + 1) {
					time = dist2[x][y] + 1;
				}
				break;
			}
			if (map[nx][ny] == '#') continue;
			if (dist2[nx][ny] > -1) continue;
			if (dist[nx][ny] <= dist2[x][y] + 1 && dist[nx][ny] != -1) continue;
			
			dist2[nx][ny] = dist2[x][y] + 1;
			q.push({ nx,ny });

		}
	}

	return time;
}
int main() {
	
	cin >> R >> C;
	
	memset(dist, -1, sizeof(dist));
	vector <pair<int, int > > fire;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				jx = i; jy = j;
			}

			if (map[i][j] == 'F') {
				fire.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < fire.size(); i++) {
		bfs(fire[i].first, fire[i].second);
	}

	/*for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}*/
	
	
	memset(dist2, -1, sizeof(dist2));
	int ans = bfs1(jx, jy);

	/*cout << endl;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << dist2[i][j] << ' ';
		}
		cout << endl;
	}*/
	if (ans == 987654321) {
		cout << "IMPOSSIBLE" << '\n';
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}
