#include <iostream>
using namespace std;

int e[11][11];

int main() {
	int N, K; cin >> N >> K;

	e[0][0] = 1;

	for (int i = 1; i <= N; i++) {
		e[i][0] =1;
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			e[j][i] = e[j - 1][i - 1] + e[j - 1][i];
		}
	}


	cout << e[N][K] << '\n';

	return 0;

}