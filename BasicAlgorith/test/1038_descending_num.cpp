#include <iostream>

using namespace std;

int factorial(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

int main() {
	int n;
	int temp = 0;
	int idx;
	int Num[11][10] = { 0 };
	int descendingNum[11] = { 0 };
	for (int i = 1; i <= 10; i++) {
		descendingNum[i] = factorial(10) / (factorial(10 - i) * factorial(i));
	}

	for (int i = 0; i < 10; i++) {
		Num[1][i] = 1;
	}

	for (int N = 2; N <= 10; N++) {
		for (int j = 0;j < 10; j++) {
			for (int k = 0; k < j; k++) {
				Num[N][j] += Num[N - 1][k];
			}
		}
	}

	cin >> n;

	if (n > 1024) {
		cout << -1;
		return 0;
	}

	for (int i = 0; i < 11; i++) {
		temp += descendingNum[i];
		if (temp > n) {
			idx = i;
			break;
		}
	}
	
	for (int i = 0; i < idx; i++) {
		n -= descendingNum[i];
	}// 이 시점에서 idx 자리 n+1 번째 숫자임을 알 수 있다.
	temp = 0;
	if (n == 0) {
		for (int i = 0; i < idx; i++) {
			cout << idx - i -1;
		}
	}
	while (n != 0) {
		for (int i = 0; i < 10; i++) {
			temp += Num[idx][i];
			if (temp > n) {
				cout << i;
				n = n - temp + Num[idx--][i];
				temp = 0;
				break;
			}if (temp == n) {
				cout << i + 1;
				for (int j = 0; j < i; j++) {
					cout << i - j - 1;
				}
				n = 0;
				break;
			}
		}
	}
}