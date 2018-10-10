//น้มุ : 10950
#include <iostream>
using namespace std;

int main() {
	int T = 0;
	int A[5], B[5] = {};
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A[i] >> B[i];
	}
	for (int i = 0; i < T; i++) {
		cout << A[i] + B[i] << endl;
	}
}