#include <iostream>


using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

//그냥 푼 코드

//int main() {
//	int n;
//	int num = 0, cost = 0;			//현재 산 카드의 수, 현재 지불값
//	float max = -1;
//	int p[1001];			//카드팩 갯수별 가격
//	float ppc[1001];		//카드별 가격 저장
//	int s[1001] = {0};		//카드 별 가격이 높은 순으로 정렬, 값은 카드 수
//	int buycnt[1001] = { 0 };//각 카드팩 몇번 샀나
//
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> p[i];
//		ppc[i] = (float(p[i]) / i);
//	}
//	for (int i = 1; i <= n; i++) {		//카드별 가격이 높은순으로 정렬 : o(n^2)
//		max = ppc[i];
//		s[i] = i;
//		for (int j = 1; j <= n; j++) {
//			if (max < ppc[j]) {
//				max = ppc[j];
//				s[i] = j;
//			}
//		} //n번 검사하면 남은것중 가장 큰 값의 index 나옴
//		ppc[s[i]] = 0;	//검사한 값 체크
//	}//카드별 가격이 높은 카드팩 순서대로 s에 저장됨
//	
//	int i = 1;
//	while (i < n) {
//		num += s[i];		//큰 값 넣어보고
//		if (num > n) {		//구매 불가능하면
//			num -= s[i++];	//넣었던 값 빼고, 다음 유망한 카드팩 검사
//		}
//		else {				//구매 가능하면 카드팩 가격 추가
//			cost += p[s[i]];
//			buycnt[s[i]] += 1;
//			if (num == n) break;	//원하는 만큼 샀으면 중단
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