#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;


int pan[101][101][101];
int dist[101][101][101];
int visit[101][101][101];
int N, M, H;
int dx[6] = {0,1,0,-1,0,0};
int dy[6] = {1,0,-1,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

vector<tuple<int,int,int> > bfs(vector <tuple<int, int, int> > &well) {
	vector <tuple<int, int, int> > temp;
	for (int i = 0; i < well.size(); i++) {
		
		queue <tuple<int, int, int > > q;
		q.push(make_tuple(get<0>(well[i]), get<1>(well[i]), get<2>(well[i])));

		if (!q.empty()) {

			int x, y, z;
			tie(x, y, z) = q.front();
			q.pop();

			for (int i = 0; i < 6; i++) {

				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];

				if (nx <0 || nx >=N || ny<0 || ny>=M || nz<0 || nz>=H) continue;
				if (pan[nx][ny][nz] == -1 || pan[nx][ny][nz] == 1) continue;
				if (dist[nx][ny][nz] > 0) continue;

				dist[nx][ny][nz] = dist[x][y][z] + 1;
				temp.push_back(make_tuple(nx, ny, nz));

			}
		}
	}
	return temp;
}

int main() {
	
	cin >> M >> N >> H;
	bool flag = false;
	vector <tuple<int, int,int> > well;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> pan[i][j][k];
				if (pan[i][j][k] == 1) well.push_back(make_tuple(i, j, k));

				if (pan[i][j][k] == 0) flag = true;
			}
		}
	}
	if (!flag) {
		cout << 0 << '\n';
		return 0;
	}
	
	memset(dist, 0, sizeof(dist));

	while (well.size()!=0) {
		well = bfs(well);
	}
	
	int ans = 0;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (dist[i][j][k] == 0 && pan[i][j][k] == 0) {
					cout << -1 << '\n'; return 0;
				}
				if (dist[i][j][k] > ans) { ans = dist[i][j][k]; }
			}
		}
	}
	cout << ans << '\n';

	return 0;
	
}