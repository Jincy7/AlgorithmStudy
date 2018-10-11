#include <iostream>

using namespace std;

int main() {
	int DPtable[1001];
	int n;

	cin >> n;

	DPtable[1] = 1;
	DPtable[2] = 2;

	for (int i = 3;i <= n; i++) {
		DPtable[i] = (DPtable[i - 1] + DPtable[i - 2])%10007;
	}
	cout << (DPtable[n] % 10007);
}