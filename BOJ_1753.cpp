#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int V, E, K;
vector <pair<int, int> > g[20001];
int dist[20001];
int flag[20001];

void dijk(int start) {
	priority_queue <pair <int, int> > vertex;

	dist[start] = 0;
	vertex.push({ 0, start });

	while (!vertex.empty()) {

		int w = -vertex.top().first;
		int here = vertex.top().second;

		vertex.pop();
		
			for (int i = 0; i < g[here].size(); i++) {

				int nw = g[here][i].first;
				int there = g[here][i].second;

				if (dist[there] > w + nw) {
					dist[there] = w + nw;
					vertex.push({ -(w + nw), there });
				}

			}
	}
}



int main() {

	cin >> V >> E;
	cin >> K;
	
	for (int i = 1; i <= V; i++) {
		dist[i] = 987654321;
	}

	for (int i = 0; i < E; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		
		g[u].push_back({ w,v });
	}

	dijk(K);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == 987654321) {
			cout << "INF" << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}

	return 0;
	
}