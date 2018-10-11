//���� : 1463
//����
//���� x�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
//
//x�� 3���� ������ ��������, 3���� ������.
//x�� 2�� ������ ��������, 2�� ������.
//1�� ����.
//���� n�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�.������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.

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
		if (i % 2 == 0) { //i�� 2�� ����̸�
			DPtable[i] = min(DPtable[i / 2] + 1, DPtable[i]);
		}
		if (i % 3 == 0) {
			DPtable[i] = min(DPtable[i / 3] + 1, DPtable[i]);
		}
	}
	cout << DPtable[n];
}