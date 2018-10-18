#include <iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n;
	int T[10001];
	int DP[10001] = { 0 };
	bool D[2] = { false };	//D[0] n-2번째 잔 마시면 true. D[1] n-1 번째 잔 마시면 true

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

	//삽질의 흔적
	//
	//for (int i = 1; i <= n; i++) {
	//	if (D[1]) {	// 이전 잔 마신 경우
	//		if (D[0]) {		// 두번 전 잔도 마신 경우
	//			if (DP[i - 2] + T[i] > DP[i - 1]) {	// 이전 잔을 안 마시고 지금 잔 마시는게 더 클 경우
	//				if (DP[i-3]+T[i-1]+T[i] > DP[i-2] + T[i]) {// 두번 전 잔을 안마시고 이전잔과 지금 잔을 마시는게 더 큰 경우
	//					DP[i] = DP[i - 3] + T[i - 1] + T[i];
	//					D[0] = true;	D[1] = true;
	//				}
	//				else {
	//					DP[i] = DP[i - 2] + T[i];
	//					D[0] = false; D[1] = true;	// 다음번엔 n-1번째 잔이 n-2 이므로 D[0]를 false로
	//				}
	//				
	//			}
	//			else {	//그냥 이번 잔 안마시는게 더 클 경우
	//				DP[i] = DP[i - 1];
	//				D[0] = true; D[1] = false;	//이번잔 안마셨다고 마킹
	//			}
	//		}
	//		else {	// 두번 전 잔 안마신 경우
	//			DP[i] = DP[i - 1] + T[i];
	//			D[0] = true;	D[1] = true;
	//		}
	//	}
	//	else {		// 이전 잔 안 마신 경우
	//		DP[i] = DP[i - 1] + T[i];	//이전 잔 값 추가
	//		D[0] = false; D[1] = true;	//현재 잔 마신게 다음엔 n-1번째 잔이므로 D[1] 에 체크
	//	}
	//}

	cout << DP[n];
}