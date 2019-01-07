#include <iostream>
#include <cmath>
using namespace std;

int N, M;
long long wood[1000001];

long long calc(long long m) {

	long long temp = 0;

	for (int i = 0; i < N; i++) {
		if (wood[i] > m) {
			temp += wood[i] - m;
		}
	}

	return temp;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> wood[i];
	}

	long long L = 1; long long R = 1000000000;
	long long ans = 0;

	while (L <= R) {

		long long m = (L + R) / 2;

		long long tmp = calc(m);
		
		if (tmp >= M) {
			if (ans < m) ans = m;
			L = m+1;
		}
		else if(tmp < M){
			R = m-1;
		}

	}

	cout << ans << '\n';

	return 0;
}