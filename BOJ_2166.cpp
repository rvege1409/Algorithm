#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long ccw(double ax, double ay, double bx, double by, double cx, double cy) {
	return (ax*by + bx*cy + cx*ay) - (ay*bx + by*cx + cy*ax);
}

int main() {
	
	int N; scanf("%d", &N);

	vector <pair<double, double> > point;

	for (int i = 0; i < N; i++) {
		double a, b; scanf("%lf %lf", &a, &b);

		point.push_back({ a,b });
	}
	
	double size = 0;

	for (int i = 0; i < point.size()-1; i++) {
		size += ccw(100001, 100001, point[i].first, point[i].second, point[i + 1].first, point[i + 1].second);
	}
	size += ccw(100001, 100001, point[point.size()-1].first, point[point.size() - 1].second, point[0].first, point[0].second);
	
	size = abs(size);

	printf("%.1lf", size/2);

	return 0;
}
