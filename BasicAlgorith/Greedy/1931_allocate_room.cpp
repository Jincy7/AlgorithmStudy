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

	sort(meetings + 1, meetings + n + 1, compFinishTime);	// FinishTime ������ �������� ����	


	for (int i = 1; i <= n; i++) {
		//currStart = meetings[i].start;
		if (prevFinish <= meetings[i].start) {		// ���� ȸ�� ���۽ð��� ���� ȸ�� ���� �ð��̸� ����
			result++;
			prevFinish = meetings[i].finish; // ȸ�ǰ� �����Ȱ��̹Ƿ� ���� ȸ���� ������ �ð��� prevFinish�� ����
		}
	}
	cout << result;
}