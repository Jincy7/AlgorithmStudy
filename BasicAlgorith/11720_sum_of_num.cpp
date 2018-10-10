#include <iostream>

using namespace std;

int main() {
	int n,sum = 0;
	char c[10000] = {};
	cin >> n;
	cin >> c;
	for (int i = 0; i < n; i++) {
		sum += (int(c[i])-48);		//char to int
	}
	cout << sum << endl;
}