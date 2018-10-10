/*
	스택 없이 맘대로 풀이
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int sum = 0, stick = 0;		//sum은 총 조각 개수, stick은 막대 개수
	cin >> str;

	for (int i = 0; i < str.length(); i++) {//주어진 결과 끝까지 탐색
		if (i == str.length() - 1) break;	//다음 문자까지 탐색하므로 메모리 접근위반 제어
		if (str[i] == '(') {				//여는 괄호인 경우
			if (str[i + 1] == '(') {		//다음이 여는 괄호인 경우 막대기 하나 추가, 조각역시 추가
				stick += 1;
				sum += 1;
			}
			else {							//다음이 닫는 괄호인 경우 레이저이므로 막대기 갯수만큼 총 조각에 추가
				sum += stick;
			}
		}
		else {								//닫는 괄호인 경우
			if (str[i + 1] == ')') {		//다음이 닫는 괄호인 경우에는 막대기 하나 제거
				stick -= 1;
			}
		}
	}
	cout << sum;
}