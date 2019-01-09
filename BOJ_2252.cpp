#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> v[32001];
vector <int> ans;
int inDegree[32001];
int N, M;

void topo() {
	queue <int> q;

	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int go = q.front();
		ans.push_back(go);
		q.pop();

		for (int i = 0; i < v[go].size(); i++) {
			
			inDegree[v[go][i]]--;

			if (inDegree[v[go][i]] == 0) {
				q.push(v[go][i]);
			}
		}
	}
}

int main() {
	
	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		inDegree[y]++;
	}

	topo();

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}