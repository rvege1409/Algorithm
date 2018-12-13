#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int w, h;
int visit[51][51];

int dx[8] = { -1,1,0,0,-1,1,-1,1};
int dy[8] = { 0,0,-1,1,-1,-1,1,1 };
void bfs(vector < vector<int> > &map, int a, int b) {

	queue <pair <int, int> > q;
	q.push({ a, b });

	while (!q.empty()) {
		int x = q.front().first; int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (visit[nx][ny] == 1) continue;
			if (map[nx][ny] == 0) continue;
				
			visit[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}
int main() {
	while (1) {
		
		cin >> w >> h;
		memset(visit, 0, sizeof(visit));

		if (w == 0 && h == 0) break;
		
		vector <vector <int> > map(h, vector <int> (w));
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		int cnt = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visit[i][j] == 0 && map[i][j] == 1) {
					visit[i][j] = 1;
					bfs(map, i, j); cnt++;
				}
			}
		}
		cout <<"cnt : " << cnt << '\n';
	}
	
	return 0;
}