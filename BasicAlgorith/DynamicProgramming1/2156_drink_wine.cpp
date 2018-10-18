#include <iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	int T[10001];
	int DP[10001] = { 0 };
	bool D[2] = { false };	//D[0] n-2��° �� ���ø� true. D[1] n-1 ��° �� ���ø� true

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> T[i];
	}

	DP[1] = T[1];
	DP[2] = T[1] + T[2];

	for (int i = 3; i <= n; i++) {
		int result = 0;
		result = max(DP[i - 2] + T[i], DP[i - 1]);
		result = max(DP[i - 3] + T[i - 1] + T[i], result);
		DP[i] = result;
	}

	//������ ����
	//
	//for (int i = 1; i <= n; i++) {
	//	if (D[1]) {	// ���� �� ���� ���
	//		if (D[0]) {		// �ι� �� �ܵ� ���� ���
	//			if (DP[i - 2] + T[i] > DP[i - 1]) {	// ���� ���� �� ���ð� ���� �� ���ô°� �� Ŭ ���
	//				if (DP[i-3]+T[i-1]+T[i] > DP[i-2] + T[i]) {// �ι� �� ���� �ȸ��ð� �����ܰ� ���� ���� ���ô°� �� ū ���
	//					DP[i] = DP[i - 3] + T[i - 1] + T[i];
	//					D[0] = true;	D[1] = true;
	//				}
	//				else {
	//					DP[i] = DP[i - 2] + T[i];
	//					D[0] = false; D[1] = true;	// �������� n-1��° ���� n-2 �̹Ƿ� D[0]�� false��
	//				}
	//				
	//			}
	//			else {	//�׳� �̹� �� �ȸ��ô°� �� Ŭ ���
	//				DP[i] = DP[i - 1];
	//				D[0] = true; D[1] = false;	//�̹��� �ȸ��̴ٰ� ��ŷ
	//			}
	//		}
	//		else {	// �ι� �� �� �ȸ��� ���
	//			DP[i] = DP[i - 1] + T[i];
	//			D[0] = true;	D[1] = true;
	//		}
	//	}
	//	else {		// ���� �� �� ���� ���
	//		DP[i] = DP[i - 1] + T[i];	//���� �� �� �߰�
	//		D[0] = false; D[1] = true;	//���� �� ���Ű� ������ n-1��° ���̹Ƿ� D[1] �� üũ
	//	}
	//}

	cout << DP[n];
}