#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
	int answer = -1;
	int SL = 0, SR = 0;
	int idx = 0;
	bool flag = true;
	for (int i = 0; i < cookie.size(); i++) {
		SL += cookie[i];
	}
	while (flag) {
		if (SL > SR) {
			for (int i = 0;i < cookie.size(); i++) {
				SR += cookie[cookie.size() - i-1];
				SL = SL - cookie[cookie.size() - i-1];
				if (SL < SR) {
					SL = SL + cookie[cookie.size() - i-1];
					SR -= cookie[cookie.size() - i-1];
					idx = cookie.size()-i;
					flag = false;
				}
				else if (SL == SR) {
					return SL;
				}
			}
		}
	}
	//이제 앞에서부터 하나씩 지워보기
	flag = false;
	while (true) {
		for (int i = 0; i < cookie.size(); i++) {
			SL -= cookie[i];
			if (SL == SR) {
				return SL;
			}
			else if (SL < SR) {
				return 0;
			}
		}
	}
	return answer;
}

int main() {
	vector<int> cookie;
	cookie.push_back(1);
	cookie.push_back(1);
	cookie.push_back(2);
	cookie.push_back(3);
	solution(cookie);
}