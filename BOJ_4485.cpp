#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int N;
int map[125][125];
int dist[125][125];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

 void dji(int a, int b) {
	priority_queue <tuple<int,int, int> > pq;
	pq.push(make_tuple(-map[a][b],a,b));
	dist[a][b] = map[a][b];

	while (!pq.empty()) {
		int x, y, w;
		tie(w, x, y) = pq.top();
		w *=-1;
		
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			
			if (dist[nx][ny] > map[nx][ny] + w) {
				dist[nx][ny] = map[nx][ny] + w;
				pq.push(make_tuple(-dist[nx][ny], nx, ny));
			}
		}

	}
}
int main() {

	for (int t = 1;; t++) {
		cin >> N;

		if (N == 0) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				dist[i][j] = 987654321;
			}
		}

		dji(0, 0);

		cout << "Problem "<<t<<":"<<' ' <<dist[N - 1][N - 1] << '\n';
	}
	return 0;
}
