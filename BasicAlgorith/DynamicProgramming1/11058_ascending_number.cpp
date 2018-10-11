#include <iostream>

using namespace std;

int main() {
	int N = 0, result = 0;
	int DP[1001][10] = { 0 };

	for (int i = 0; i < 10; i++) {	//1자리 오르막수 갯수 초기화
		DP[1][i] = 1;
	}

	cin >> N;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j;k++) {
				DP[i][j] = (DP[i - 1][k] + DP[i][j])%10007;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		result += DP[N][i];
	}
	result = result % 10007;
	cout << result;
}