#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

int N, M;
int map[301][301];
int visit[301][301];
vector <pair <int, int > > v;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool flag = true;

void dfs(int x, int y) {
	
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
		if (map[nx][ny] > 0 && visit[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}

int check() {
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		
		if (visit[v[i].first][v[i].second] == 0) {
			dfs(v[i].first, v[i].second); cnt++;
		}
	}
	if (cnt >=2) {
		flag = false;
	}
	return cnt;
}

int find(int x, int y) {
	int temp = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx > N || ny < 1 || ny > M) continue;

		if (map[nx][ny] == 0) {
			temp++;
		}
	}
	return temp;
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] > 0) {
				v.push_back({ i,j });
			}
		}
	}
	int lap = 0;
	while(check() <2 && v.size()!=0){
		memset(visit, 0, sizeof(visit));
		vector <pair<int, int> > tmp;
		vector <int > v2(10001);
		
		for (int i = 0; i < v.size(); i++) {
			v2[i] = find(v[i].first, v[i].second);
		}
		
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first; int y = v[i].second;
			map[x][y] -= v2[i];
			if (map[x][y] > 0) {
				tmp.push_back({ x,y });
			}
			else if(map[x][y] <0) {
				map[x][y] = 0;
			}
		}
		lap++;
		v = tmp;
	}
	if (flag) {
		printf("0\n");
	}
	else {
		printf("%d\n", lap);
	}
	return 0;
}
