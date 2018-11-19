#include <iostream>
#include <algorithm>

using namespace std;

struct timetable {
	int start;
	int finish;
};

bool compFinishTime(timetable A, timetable B) {
	if (A.finish == B.finish) {
		return A.start < B.start;
	}
	else
	{
		return A.finish < B.finish;
	}
}

int main() {
	int n = 0;
	int result = 0;
	int currStart = 0;
	int prevFinish = 0;
	timetable meetings[100010];

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> meetings[i].start >> meetings[i].finish;
	}

	sort(meetings + 1, meetings + n + 1, compFinishTime);	// FinishTime 순으로 오름차순 정렬	


	for (int i = 1; i <= n; i++) {
		//currStart = meetings[i].start;
		if (prevFinish <= meetings[i].start) {		// 현재 회의 시작시간이 지난 회의 끝난 시간이면 배정
			result++;
			prevFinish = meetings[i].finish; // 회의가 배정된것이므로 현재 회의의 끝나는 시간을 prevFinish에 저장
		}
	}
	cout << result;
}