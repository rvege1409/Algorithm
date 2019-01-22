#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int A[10005];
long long dp1[10002];
long long dp2[10002];

int main() {

	int N; scanf("%d", &N);


	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}


	int turn = 1;
	int T = N;
	int p = 1;


	dp1[0] = 1;

	if (A[p] != -1) {
		for (int i = 0; i <= 10000; i++) {
			if (i != A[p]) dp1[i] = 0;
		}
	}
	p++;
	while (T) {


		if (turn == 1) {

			for (int i = 0; i <= 10000; i++) {
				long long temp = 0;
				if (i - 1 >= 0) {
					temp += dp1[i - 1];
				}
				temp += dp1[i];
				if (i + 1 <= 10001) {
					temp += dp1[i+1];
				}
				dp2[i] = temp % 1000000007;
			}
			if (A[p] != -1) {
				for (int i = 0; i <= 10000; i++) {
					if (i != A[p]) dp2[i] = 0;
				}
			}
		}
		else {

			for (int i = 0; i <= 10000; i++) {
				long long temp = 0;
				if (i - 1 >= 0) {
					temp += dp2[i - 1];
				}
				temp += dp2[i];
				if (i + 1 <= 10001) {
					temp += dp2[i+1];
				}
				dp1[i] = temp % 1000000007;
			}
			if (A[p] != -1) {
				for (int i = 0; i <= 10000; i++) {
					if (i != A[p]) dp1[i] = 0;
				}
			}
		}
		p++;
		turn *= -1;
		T--;
	}

	if (turn == 1) {
		//dp2[0] %= 1000000007;
		printf("%lld\n", dp2[0] % 1000000007);
	}
	else {
		//dp1[0] %= 1000000007;
		printf("%lld\n", dp1[0] % 1000000007);
	}

	return 0;
}
