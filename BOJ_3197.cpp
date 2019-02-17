#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

char map[1501][1501];
int dist[1501][1501];
int visit[1501][1501];
int visit2[1501][1501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int R, C;
int lap = 0;
int lx, ly;
queue <pair<int, int > > temp;

queue<pair<int, int > > bfs(queue <pair<int, int > > &temp) {

	queue<pair<int, int > >q;


	while (!temp.empty()) {
		int x = temp.front().first;
		int y = temp.front().second;

		visit[x][y] = 1;

		temp.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<1 || nx>R || ny <1 || ny > C) continue;
			if (visit[nx][ny] == 1) continue;
			if (dist[nx][ny] > dist[x][y]) continue;

			if (map[nx][ny] == 'X') {

				dist[nx][ny] = dist[x][y] + 1;
				visit[nx][ny] = 1;
				q.push({ nx,ny });
				continue;
			}

			dist[nx][ny] = dist[x][y];
		}

	}
	return q;
}

bool meet(int a, int b) {
	queue <pair<int, int > > q;
	q.push({ a,b });
	visit2[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx<1 || nx>R || ny <1 || ny > C) continue;
			if (visit2[nx][ny] == 1) continue;
			if (dist[nx][ny] > lap) continue;
			if (map[nx][ny] == 'L') return true;

			q.push({ nx,ny });
			visit2[nx][ny] = 1;
		}
	}
	return false;
}
int main() {

	scanf("%d %d", &R, &C);

	for (int i = 1; i <= R; i++) {
		scanf("\n");
		for (int j = 1; j <= C; j++) {

			scanf("%1c", &map[i][j]);

			if (map[i][j] == 'L') {
				lx = i; ly = j;
				temp.push({ i,j });
			}

			if (map[i][j] == '.') {
				temp.push({ i,j });
			}
		}
	}

	

	while (!temp.empty()) {
		temp = bfs(temp);
	}
	/*
	cout << temp.size() << endl;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << dist[i][j]<<' ';
		}
		cout << endl;
	}
	*/

	int L = 0; int R = 2000;

	int ans = 0;
	while (L <= R) {
		 lap = (L + R) / 2;
		 memset(visit2, 0, sizeof(visit2));
		if (meet(lx, ly)) {
			ans = lap;
			R = lap - 1;
		}
		else {
			L = lap + 1;
		}
	}	
	printf("%d\n", ans);
	

	return 0;
}
