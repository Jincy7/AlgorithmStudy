#include <iostream>

using namespace std;

int main() {
	int n = 0; int k = 0; int result = 0;

	int tmp = 0;
	int A[15] = { 0 };
	bool flag = false;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	for (int i = n; i > 0; i--) {
		result += k / A[i];
		k = k % A[i];
	}
	cout << result;
}