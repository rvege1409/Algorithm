#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector <int> ans;
int map[101];
int visit[101];

void dfs(int index) {
	
	visit[index]++;

	if (visit[index] == 2) {
		ans.push_back(index);
		return;
	}
	
	dfs(map[index]);

}
int main() {
	
	int N; cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> map[i];
	}

	for (int i = 1; i <= N; i++) {

		memset(visit, 0, sizeof(visit));
		dfs(i);

	}
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}
