#include iostream
#include algorithm
using namespace std;

int n, m;
int f[101][101];

int main() {
	
	cin  n  m;
	for (int i = 1; i = n; i++) {
		for (int j = 1; j = n; j++) {
			if (i == j) f[i][j] = 0;
			else { f[i][j] = 987654321; }
		}
	}


	for (int i = 0; i  m; i++) {
		int A, B, C; 
		cin  A  B  C;
		
		if (f[A][B]  C) {
			f[A][B] = C;
		}
	}

	
	for (int k = 1; k = n; k++) {
		for (int i = 1; i = n; i++) {
			for (int j = 1; j = n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}	
		}
	}

	for (int i = 1; i = n; i++) {
		for (int j = 1; j = n; j++) {
			if (f[i][j] == 987654321) {
				cout  0  ' ';
			}
			else {
				cout  f[i][j]  ' ';
			}
		}
		cout  'n';
	}

	return 0;


}