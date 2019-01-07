#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long F[100];
long long fibo(int n) {

	F[0] = 0;
	F[1] = 1;
	for (int i = 2; i <= n; i++) {
		F[i] = F[i - 1] + F[i - 2];
	}

	return F[n];
}
int main() {
	int n;
	cin >> n;
	long long ans = 0;

	ans = fibo(n);

	cout << ans << '\n';

	return 0;
}