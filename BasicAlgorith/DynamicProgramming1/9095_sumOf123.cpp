#include <iostream>

using namespace std;

int main() {
	int DPtable[15];
	int n , num;

	DPtable[1] = 1; DPtable[2] = 2; DPtable[3] = 4;
	for (int i = 4; i < 12; i++) {
		DPtable[i] = DPtable[i - 3] + DPtable[i - 2] + DPtable[i - 1];
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cout << DPtable[num] << endl;
	}
}