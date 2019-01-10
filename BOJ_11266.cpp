#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int order[10001];
vector <int> g[10001];
int cut[10001];
int dep = 0;

int dfs(int here, bool root) {

	order[here] = ++dep;
	
	int ret = order[here];
	int child = 0;

	for (int there = 0; there < g[here].size(); there++) {
		if (order[g[here][there]] == 0) { // 방문 안했으면
			child++;

			
				int newret = dfs(g[here][there], 0);

				if (!root && order[here] <= newret) {
					cut[here] = 1;
				}

				ret = min(newret, ret);
		}
		else {
			ret = min(ret, order[g[here][there]]);
		}
	}

	if (root && child > 1) {
		cut[here] = 1;
	}

	return ret;
}

int main() {
	
	cin >> V >> E;

	for (int i = 0; i < E; i++) {

		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);

	}

	for (int i = 1; i <= V; i++) {
		if (order[i] == 0) {
			dfs(i, 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= V; i++) {
		if (cut[i]) ans++;
	}

	cout << ans << '\n';
	for (int i = 1; i <= V; i++) {
		if (cut[i]) cout << i << ' ';
	}
	cout << '\n';
	

	return 0;
}
