#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, E;
int dist[801];
vector <pair<int, int > > v[801];

void init() {
	for (int i = 1; i <= N; i++) {
		dist[i] = 987654321;
	}
}
void dji(int a) {
	
	priority_queue <pair <int, int > > pq;

	pq.push({ 0,a });
	dist[a] = 0;

	while (!pq.empty()) {

		int cur = pq.top().second;
		int w = -pq.top().first;

		pq.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int there = v[cur][i].first;
			int nw = v[cur][i].second;

			if (dist[there] > w + nw) {
				dist[there] = w + nw;
				pq.push({ -(w + nw), there });
			}
		}
	}

	
}
int main() {
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	
	int n1, n2;
	int d1=0, d2=0;

	cin >> n1 >> n2;
	//d1
	init();
	dji(1);
	if (dist[n1] == 987654321 && dist[n2] == 987654321) {
		cout << -1 << '\n';
		return 0;
	}
	d1 += dist[n1];
	d2 += dist[n2];

	init();
	dji(n1);
	if (dist[n2] == 987654321) {
		cout << -1 << '\n';
		return 0;
	}
	d1 += dist[n2];
	int temp1 = dist[N];

	init();
	dji(n2);
	if (dist[n1] == 987654321) {
		cout << -1 << '\n';
		return 0;
	}
	d2 += dist[n1];
	int temp2 = dist[N];

	if (temp1 == 987654321 && temp2 == 987654321) {
		cout << -1 << '\n';
		return 0;
	}
	d1 += temp2;
	d2 += temp1;

	int ans = min(d1, d2);

	cout << ans << '\n';

	return 0;
}
