#include <iostream>
using namespace std;

void Eratos(bool* PrimeArray,int n);

int main() {
	int n = 0;
	bool PrimeArray[1000001] = {true};
	Eratos(PrimeArray, 1000000);
	int testCase[100001];

	for (int i = 0; i < 100001; i++) {
		cin >> testCase[i];
		if (i == 100000) return 0;
		else if (testCase[i] == 0) break;
	}

	while (n < 100000) {
		int temp = testCase[n];
		if (temp == 0) break;
		for (int i = 2; i <= temp;i++) {
			if (PrimeArray[i]) {
				if (PrimeArray[temp - i]) {
					printf("%d = %d + %d\n",temp,i,temp-i);
					//cout << temp << " = " << i << " + " << temp - i << endl;
					break;
				}
			}
		}
		n++;
	}
}

void Eratos(bool* PrimeArray, int n) {
	if (n <= 1)return;

	for (int i = 2; i <= n; i++) {
		PrimeArray[i] = true;
	}

	for (int i = 2; i*i <= n; i++) {
		if (PrimeArray[i]) {
			for (int j = i * i; j <= n; j += i) {
				PrimeArray[j] = false;
			}
		}
	}

}