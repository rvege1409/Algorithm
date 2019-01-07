#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, S;
	cin >> N >> S;

	vector <int> num(N + 1);
	vector <int> sum(N + 1);

	sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		sum[i] = num[i] + sum[i - 1];
	}

	int ans = 9999999999;

	int len = 0;

	int p = 1;
	int i = 0;
	bool flag = false;
	while (p <= N) {

		int a = sum[p] - sum[i];


		if (a < S) {
			p++;
		}
		else {
			flag = true;
			len = p - i;
			if (ans > len) {
				ans = len;
			}

			i++;
		}
	}
	if (!flag) {
		cout << 0 << '\n';
	}
	else {
		cout << ans << '\n';
	}

	return 0;

}