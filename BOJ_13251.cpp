#include <iostream>
#include <cstdio>
using namespace std;

int color[51];

double calc(double ea, double c, double k) {//13 13 8
	if (ea < k) return 0;

	double temp = 1;
	double loop = k;
	for (int i = 0; i < loop; i++) {
		temp *= (ea / c);
		ea--;
		c--;
	}
	return temp;
}
int main() {
	double M, K; // 색상1~M까지 K 개 뽑느다.
	scanf("%lf", &M);
	
	double total = 0;
	for (int i = 0; i < M; i++) {
		int c; scanf("%d", &c);
		color[i] = c;
		total += c;
	}
	scanf("%lf", &K);
	double ans = 0;
	for (int i = 0; i < M; i++) {
		ans += calc(color[i], total, K);
	}

	printf("%0.17f\n", ans);

	return 0;
}