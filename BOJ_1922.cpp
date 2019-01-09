#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int N, M;
int group[1001];


int find(int x) {
	if (group[x] == x) return x;
	else return group[x] = find(group[x]);
}

void uni(int x, int y) {

	int xRoot = find(x);
	int yRoot = find(y);

	if (xRoot == yRoot) return;

	group[yRoot] = xRoot;
	
}



int main() {
	
	cin >> N >> M;

	vector <tuple<int, int, int> > edge;

	
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edge.push_back(make_tuple(c, a, b));
	}
	//cout << endl;
	
	
	sort(edge.begin(), edge.end());

	/*for (int i = 0; i < edge.size(); i++) {
		cout << get<0>(edge[i]) << ' ' << get<1>(edge[i]) << ' ' << get<2>(edge[i]) << '\n';
	}*/
	for (int i = 1; i <= N; i++) {
		group[i] = i;
	}
	
	int cost = 0;

	for (int i = 0; i < edge.size(); i++) {
		
		int x = get<1>(edge[i]); int y = get<2>(edge[i]);
		
		if (find(x) != find(y)) { //연결되어 있지 않다면
			uni(x, y);
			cost += get<0>(edge[i]);
		}
	}

	cout << cost << '\n';

	return 0;
}