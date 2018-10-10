#include <iostream>

using namespace std;

int main() {
	char c[100] = {};
	char con[10][10] = {};
	int i=0, j = 0;
	cin >> c;
	while (1) {

		if (c[i] == '\0') {
			break;
		}
		else {
			con[j][i%10] = c[i++];
			if (i % 10 == 0) j++;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << con[i][j];
			if (con[i][j] == '\0') { 
				cout << "!eof!";
				return 0; 
			}
		}
		cout << endl;
	}
}