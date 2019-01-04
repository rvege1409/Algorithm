#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int N, M;
int dist[1001][1001];

vector<pair<int, int> >  bfs(vector <vector <int> > &map, vector<pair<int,int> > &t) {
	vector <pair<int, int> > temp;
	for (int i = 0; i < t.size(); i++) {
		queue <pair <int, int > > q;
		q.push({ t[i].first,t[i].second });
		

		while (!q.empty()) {

			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int i = 0; i < 4; i++) {

				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx <0 || nx>=M || ny <0 || ny >= N) continue;
				if (map[nx][ny] == 1) continue;
				if (map[nx][ny] == -1) continue;
				if (dist[nx][ny] > 0) continue;

				dist[nx][ny] = dist[x][y] + 1;
				temp.push_back({ nx,ny });
			}
		}
	}
	return temp;
}
int main() {
	cin >> N >> M;
	vector <vector <int> > map(M, vector<int>(N));
	vector <pair<int, int > > toma;
	bool flag = true;
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) flag = false;
			if (map[i][j] == 1) toma.push_back({ i,j });
		}
	}
	
	if (flag) {
		cout << 0 << '\n';
		return 0;
	}

	while(toma.size() != 0){
		toma = bfs(map,toma);
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && dist[i][j] == 0) {
				cout << -1 << '\n'; return 0;
			}
			if (ans < dist[i][j]) ans = dist[i][j];
		}
	}
	

	cout << ans << '\n';

	return 0;

}