#include <iostream>
using namespace std;

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
	return (ax*by + bx*cy + cx*ay) - (ay*bx + by*cx + cy*ax);
}

int main() {
	int ax, ay, bx, by, cx, cy;
	scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);

	int op = ccw(ax, ay, bx, by, cx, cy);

	if (op > 0) {
		printf("1\n");
	}
	else if (op < 0) {
		printf("-1\n");
	}
	else if (op == 0) {
		printf("0\n");
	}
	return 0;
}
