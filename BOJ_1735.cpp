#include <iostream>
#include <algorithm>
using namespace std;


int gcd(int x, int y) {
	if (x == 0) return y;

	if (x > y) swap(x, y);

	gcd(y%x,x);
}
int main() {
	int x, y, z, e;
	cin >> x >> y >> z >> e; //x 와 z 가 분자

	int child = x*e + y*z;
	int mother = y*e;

	int n = gcd(child, mother);

	cout << child / n << ' ' << mother / n << '\n';

	return 0;
}
