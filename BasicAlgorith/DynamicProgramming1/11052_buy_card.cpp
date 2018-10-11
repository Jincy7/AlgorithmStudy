#include <iostream>


using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

//�׳� Ǭ �ڵ�

//int main() {
//	int n;
//	int num = 0, cost = 0;			//���� �� ī���� ��, ���� ���Ұ�
//	float max = -1;
//	int p[1001];			//ī���� ������ ����
//	float ppc[1001];		//ī�庰 ���� ����
//	int s[1001] = {0};		//ī�� �� ������ ���� ������ ����, ���� ī�� ��
//	int buycnt[1001] = { 0 };//�� ī���� ��� ��
//
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		ppc[i] = (float(p[i]) / i);
//	}
//	for (int i = 1; i <= n; i++) {		//ī�庰 ������ ���������� ���� : o(n^2)
//		max = ppc[i];
//		s[i] = i;
//		for (int j = 1; j <= n; j++) {
//			if (max < ppc[j]) {
//				max = ppc[j];
//				s[i] = j;
//			}
//		} //n�� �˻��ϸ� �������� ���� ū ���� index ����
//		ppc[s[i]] = 0;	//�˻��� �� üũ
//	}//ī�庰 ������ ���� ī���� ������� s�� �����
//	
//	int i = 1;
//	while (i < n) {
//		num += s[i];		//ū �� �־��
//		if (num > n) {		//���� �Ұ����ϸ�
//			num -= s[i++];	//�־��� �� ����, ���� ������ ī���� �˻�
//		}
//		else {				//���� �����ϸ� ī���� ���� �߰�
//			cost += p[s[i]];
//			buycnt[s[i]] += 1;
//			if (num == n) break;	//���ϴ� ��ŭ ������ �ߴ�
//		}
//	}
//	cout << cost;
//}

int main() {
	int n;
	int dp[1001] = { 0 };
	int p[1001] = { 0 };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(p[j] + dp[i - j], dp[i]);
		}
	}
	cout << dp[n];
}