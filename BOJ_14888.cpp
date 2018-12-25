#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N;
int a, b;
void solve(vector <int> &num, int pl, int mi, int mul, int div, int index, int cal) {
	if (index == N) {
		if (a > cal) { a = cal; }
		if (b < cal) { b = cal; }
		return;
	}

	if (pl > 0) {
		solve(num, pl - 1, mi, mul, div, index + 1, cal + num[index]);
	}
	if (mi > 0) {
		solve(num, pl, mi - 1, mul, div, index + 1, cal - num[index]);
	}
	if (mul > 0) {
		solve(num, pl, mi, mul - 1, div, index + 1, cal * num[index]);
	}
	if (div > 0) {
		solve(num, pl, mi, mul, div - 1, index + 1, cal / num[index]);
	}
}
int main() {
	cin >> N;
	vector <int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	int pl; int mi; int mul; int div;
	cin >> pl >> mi >> mul >> div;
	a = 987654321; b = -987654321;

	solve(num, pl, mi, mul, div, 1, num[0]);

	cout << b << '\n' << a << '\n';

	return 0;
}
