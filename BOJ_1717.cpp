#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector <int> num(1000001);


int find(int x) {
	if (num[x] == x) return x;
	else return num[x] = find(num[x]);
}

void uni(int x, int y) {

	int xRoot = find(x);
	int yRoot = find(y);

	if (xRoot == yRoot) {
		return;
	}

	num[yRoot] = xRoot;
	return;
}


int main() {


	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N; i++) {
		num[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int op; int a; int b;
		scanf("%d %d %d", &op, &a, &b);

		if (op == 0) { // union
			uni(a, b);
		}
		else if (op == 1) { // find
			int A = find(a); int B = find(b);

			if (A == B) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
	/*
	for (int i = 0; i <= N; i++) {
	cout << num[i] << ' ';
	}
	cout << endl;
	*/


	return 0;

}