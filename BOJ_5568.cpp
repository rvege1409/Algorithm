#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int e[11][11];
vector <string> card;
vector <string> ans;
int visit[11];
void dfs(int n, string s, int target, int cnt) {
	
	if (cnt == target) { ans.push_back(s); return; }



	for (int i = 0; i < n; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dfs(n, s + card[i], target, cnt + 1);
			visit[i] = 0;
		}
	}
}

int main() {

	int n, k; scanf("%d %d", &n, &k);

	for (int i = 0; i <= n; i++) {
		e[i][0] = 1;
		e[i][i] = 1;

		for (int j = 1; j <= n; j++) {
			if (i < j) break;

			e[i][j] = e[i - 1][j - 1] + e[i - 1][j];
		}
	}

	for (int i = 0; i < n; i++) {
		string a; cin >> a;
		card.push_back(a);
	}

	string s = "";
	

	dfs(n, s, k, 0);
		
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	/*
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	*/
	printf("%d", ans.size());



	return 0;

}