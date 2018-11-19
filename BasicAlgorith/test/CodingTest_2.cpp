#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> s) {
	int answer = 0;
	int numberList[5] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		numberList[s[i]]++;
	}
	answer += numberList[4];
	if (numberList[3] < numberList[1]) {
		numberList[1] -= numberList[3];
	}
	else {
		numberList[1] = 0;
	}
	answer += numberList[3];
	if (numberList[2] % 2 == 0) {
		if (numberList[2] != 0)
			answer += int(numberList[2] / 2);
	}
	else {
		answer += int(numberList[2] / 2);
		if (numberList[1] < 3) {
			numberList[1] = 0;
		}
		else {
			numberList[1] -= 2;
		}
		answer++;
	}
	if (numberList[1] != 0) {
		if (numberList[1] % 4 == 0) {
			answer += int(numberList[1] / 4);
		}
		else {
			answer += int(numberList[1] / 4) + 1;
		}
	}
	return answer;
}