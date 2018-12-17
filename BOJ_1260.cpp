#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n,m,v;
int visit[1001];
vector <int> res;
void dfs(vector <int> node[10001], int v) {

	visit[v] = 1;
	res.push_back(v);

	priority_queue <int> pq;
	for (int i = 0; i < node[v].size(); i++) {
		if (visit[node[v][i]] == 0) {
			pq.push(-node[v][i]);
		}
	}
	
	int size = pq.size();
	for (int i = 0; i < size; i++) {
		int a = -pq.top();
		pq.pop();
		if (visit[a] == 0) {
			dfs(node, a);
		}
	}
}
void bfs(vector<int> node[10001], int v) {
	queue <int> q;
	q.push(v);
	res.push_back(v);
	visit[v] = 1;
	while (!q.empty()) {
		int vv = q.front();
		q.pop();
		priority_queue <int> pq;
		for (int i = 0; i < node[vv].size(); i++) {
			pq.push(-node[vv][i]);
		}

		for (int i = 0; pq.size(); i++) {
			int a = -pq.top();
			pq.pop();
			if (visit[a] == 0) {
				visit[a] = 1;
				res.push_back(a);
				q.push(a);
			}
		}
	}
}
int main() {
	
	cin >> n >> m >> v;

	vector <int> node[10001];
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	memset(visit, 0, sizeof(visit));
	dfs(node, v);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
	memset(visit, 0, sizeof(visit));
	res.clear();
	bfs(node, v);
	

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout <<'\n';

	return 0;
}