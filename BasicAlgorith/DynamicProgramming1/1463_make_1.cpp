//백준 : 1463
//문제
//정수 x에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
//
//x가 3으로 나누어 떨어지면, 3으로 나눈다.
//x가 2로 나누어 떨어지면, 2로 나눈다.
//1을 뺀다.
//정수 n이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.연산을 사용하는 횟수의 최솟값을 출력하시오.

#include <iostream>

using namespace std;

int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	int n = 0;
	int DPtable[1000001];
	DPtable[1] = 0;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		DPtable[i] = DPtable[i - 1] + 1;
		if (i % 2 == 0) { //i가 2의 배수이면
			DPtable[i] = min(DPtable[i / 2] + 1, DPtable[i]);
		}
		if (i % 3 == 0) {
			DPtable[i] = min(DPtable[i / 3] + 1, DPtable[i]);
		}
	}
	cout << DPtable[n];
}