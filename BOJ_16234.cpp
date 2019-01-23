#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int map[51][51];
int visit[51][51];
int N, L, R;
int cnt;

void bfs(int a, int b) {
	queue<pair<int, int> > q;
	queue<pair<int, int > > q2;
	q.push({ a,b });
	q2.push({ a,b });
	visit[a][b] = 1;
	int sum = map[a][b];
	cnt = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx <= 0 || nx > N || ny <= 0 || ny > N) continue;
			if (visit[nx][ny] == 1) continue;
			
			int c = abs(map[x][y] - map[nx][ny]);

			if (c >= L && c <= R) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
				sum += map[nx][ny];
				cnt++;
				q2.push({ nx,ny });
			}
		}
	}
	int avg = sum / cnt;
	while (!q2.empty()) {
		
		int x = q2.front().first;
		int y = q2.front().second;
		q2.pop();
		map[x][y] = avg;

	}
}
int main() {

	cin >> N >> L >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	
	int lap = 0;
	while (1) {
		
		bool flag = true;
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (visit[i][j] == 0) {
					bfs(i, j);

					if (cnt >= 2) flag = false;
				}
			}
		}
		if (flag) {
			cout << lap << '\n';
			break;
		}
		lap++;
	}

	return 0;
}
