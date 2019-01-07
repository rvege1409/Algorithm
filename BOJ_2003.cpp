#include <iostream>
#include <vector>
using namespace std;

int main() {

	int N, M;
	cin >> N >> M;

	vector <int> n(N + 1);
	vector <int> sum(N + 1);
	sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> n[i];
		sum[i] = n[i] + sum[i - 1];
	}

	int ans = 0;
	
	for (int i = 0; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if ((sum[j] - sum[i]) == M) ans++;
		}
	}
	cout << ans << '\n';
	return 0;


}