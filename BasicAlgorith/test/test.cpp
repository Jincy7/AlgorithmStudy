#include <iostream>

using namespace std;

void foo(int arr2D[][10]) {
	cout << arr2D[2][2] << endl;
}

void main() {
	int sum = 0;
	for (int i = 1; i < 9; i++) {
		sum += i*(i + 1) / 2;
	}
	cout << sum;
}