#include <iostream>
#include <vector>
using namespace std;


int main() {

	int N;
	cin >> N;


	int i = 2;
	
	for (int i = 2; i <= N; i++) {
		
		if ((N%i) == 0) {

			cout << i << '\n';
			N = N / i;
			i--;
		}
	}


	return 0;
}
