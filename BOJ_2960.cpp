#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int map[1001];
bool b[1001];
int N, K;
int ans = 0;
int cnt = 0;

int main() {


	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		map[i] = i;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (b[j] == 0) {
				b[j] = 1;
				cnt++;
				if (cnt == K) { ans = j; break; }
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
