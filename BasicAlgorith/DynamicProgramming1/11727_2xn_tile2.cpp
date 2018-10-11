#include <iostream>

using namespace std;

int main() {
	int DPtable[1010];
	int n;

	cin >> n; 

	DPtable[1] = 1;
	DPtable[2] = 3;

	for (int i = 3; i <= n; i++) {
		DPtable[i] = (2 * DPtable[i - 2] + DPtable[i-1]) % 10007;
	}
	cout << DPtable[n];
}