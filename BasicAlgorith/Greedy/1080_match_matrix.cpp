#include <iostream>
#include <string>

using namespace std;

void func(bool comp[][51], int x, int y ) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			comp[x + i][y + j] = !comp[x + i][y + j];
		}
	}
}

int main() {
	int n, m;
	int result = 0;
	string tmp;
	int A[51][51], B[51][51];
	bool comp[51][51] = { false };
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			A[i][j] = tmp[j];
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < m; j++) {
			B[i][j] = tmp[j];
			(A[i][j] == B[i][j] ? comp[i][j] = true : comp[i][j] = false); //같으면 true 아니면 flase
		}
	}

	
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (!comp[i][j]) {
				func(comp, i, j);
				result++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!comp[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << result;
	
	}