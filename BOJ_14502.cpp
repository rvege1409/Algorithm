#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int N, M;
vector <pair<int, int> > z;
vector <pair<int, int> > v;
int ans;
void bfs(vector <vector <int> > &temp, int x, int y) {

	queue <pair <int, int> > q;

	q.push({ x,y });

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (temp[nx][ny] == 2 || temp[nx][ny] == 1) continue;

			temp[nx][ny] = 2; q.push({ nx, ny });
		}
	}
}

void solve(vector <vector <int> > &map, int cnt, int index) {
	if (cnt == 3) {
		vector <vector <int> > temp(map);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 2) bfs(temp, i, j);
			}
		}
		int sum = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 0) sum++;
			}
		}

		if (ans < sum) ans = sum;

		return;
	}

	for (int i = index; i < z.size(); i++) {
		map[z[i].first][z[i].second] = 1;
		solve(map, cnt + 1, i + 1);
		map[z[i].first][z[i].second] = 0;
	}
}
int main() {
	cin >> N >> M;

	vector <vector <int> > map(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) z.push_back({ i,j });
		}
	}
	ans = 0;
	solve(map, 0, 0);

	cout << ans << '\n';

	return 0;
}