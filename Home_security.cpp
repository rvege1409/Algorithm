#include <iostream>
#include <queue>
#include <cstring>
#include <stdio.h>
using namespace std;

int N, M;
int map[21][21];
int visit[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;



void bfs(int x, int y) {
	visit[x][y] = 1;
	queue <pair<int, int> > q;

	q.push({ x,y });
	int cnt = map[x][y];

	for (int k = 1;; k++) {
		if (q.empty()) { break; }
		int size = q.size();
		int price = M * cnt - (k*k + (k - 1)*(k - 1));

		//cout << x << ' ' << y << ' ' << k <<' '<< temp << endl;
		if (price >= 0 && cnt > ans) { ans = cnt; }


		for (int i = 0; i < size; i++) {
			int a = q.front().first, b = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int aa = a + dx[j]; int bb = b + dy[j];
				if (visit[aa][bb] == 0 && aa >= 0 && aa < N && bb >= 0 && bb < N) {
					q.push({ aa,bb });
					if (map[aa][bb] == 1) { cnt++; }
					visit[aa][bb] = 1;
				}
			}
		}

	}
}


int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		memset(map, 0, sizeof(map));
		ans = -1;
		cin >> N >> M; //N : 도시의 크기, M : 하나의 집이 지불할 수 있는 비용
		for (int a = 0; a < N; a++) {
			for (int b = 0; b < N; b++) {
				cin >> map[a][b];
			}
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				memset(visit, 0, sizeof(visit));
				bfs(i, j);
			}
		}



		printf("#%d %d\n", i, ans);
	}
	return 0;
}