#include <iostream>

using namespace std;

int main() {
	int n = 0;
	long long DP[91] = { 0 };
	cin >> n;
	DP[1] = 1;	DP[2] = 1;
	
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i - 2; j++) {
			DP[i] += DP[j];
		}
		DP[i]++;
	}
	cout << DP[n];
}