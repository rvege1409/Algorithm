#include <iostream>
using namespace std;

int e[1001][1001];

int main() {
	int N, K; cin >> N >> K;

	

	for (int i = 0; i <= N; i++) {
		e[i][0] =1;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) e[i][j] = 1;
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			e[j][i] = (e[j - 1][i - 1]%10007) + (e[j - 1][i]%10007);
		}
	}


	cout << e[N][K]%10007 << '\n';

	return 0;

}