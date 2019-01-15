#include <iostream>
using namespace std;

long long e[31][31];

int main() {
	int T; cin >> T;

	

	for (int i = 0; i <= 30; i++) {
		e[i][0] =1;
	}
	
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			if (i == j) e[i][j] = 1;
		}
	}


	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= 30; j++) {
			e[j][i] = e[j - 1][i - 1] + e[j - 1][i];
		}
	}

	for (int i = 0; i < T; i++) {
		int N, M; cin >> N >> M;
		cout << e[M][N] << '\n';
	}

	return 0;

}