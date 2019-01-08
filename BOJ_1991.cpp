#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int tree[100][2];
vector <char> v;
void preorder(int root) { //1

	if (root == -1) {
		return;
	}
	
	cout << char(root + 'A');
	

	preorder(tree[root][0]);
	preorder(tree[root][1]);
}

void inorder(int root) {
	
	if (root == -1) {
		return;
	}

	inorder(tree[root][0]);
	cout << char(root + 'A');
	inorder(tree[root][1]);
}

void postorder(int root) {
	if (root == -1) {
		return;
	}

	postorder(tree[root][0]);
	postorder(tree[root][1]);
	cout << char(root + 'A');
}

int main() {
	
	

	int N; cin >> N;
	memset(tree, -1, sizeof(tree));

	for (int i = 0; i < N; i++) {
		char R, left, right;
		cin >> R >> left >> right;

		if (left != '.') {
			tree[R - 'A'][0] = left - 'A';
		}
		if (right != '.') {
			tree[R - 'A'][1] = right - 'A';
		}
	}

	

	
	

	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0); cout << '\n';

	

	return 0;

}