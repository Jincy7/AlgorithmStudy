#include <iostream>

using namespace std;

int main() {
	int n;
	int result = 0;
	int DP[101][10] = { 0 };

	//테이블 초기화
	DP[1][0] = 0;
	for (int i = 1; i < 10; i++) {
		DP[1][i] = 1;
	}

	cin >> n;

	for (int i = 2; i <= n; i++) {
		for (int k = 0; k < 10; k++) {
			if (k == 0) {
				DP[i][k] = DP[i - 1][k + 1];
			}
			else if (k == 9) {
				DP[i][k] = DP[i - 1][k - 1];
			}
			else {
				DP[i][k] = (DP[i - 1][k + 1] + DP[i - 1][k - 1]) % 1000000000;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		result = (result + DP[n][i]) % 1000000000;
	}
	cout << result;
}