/*
	스택사용해서 풀이
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	stack<char> st;
	int sum = 0;		//sum은 총 조각 개수
	cin >> str;

	for (int i = 0; i < str.length(); i++) {//주어진 결과 끝까지 탐색
		if (str[i] == '(') {		//일단 스택에 담고
			st.push(str[i]);
		}
		else {					//닫는 괄호인경우 파이프의 끝인지 레이저인지 검사
			st.pop();			
			if (str[i - 1] == '(') {	//원래 스트링에서 전 문자가 ( 이면 레이저
				sum += st.size();	//막대기 갯수만큼 더하기 위해 스택의 크기 덧셈
			}
			else {		//아니면 파이프의 끝
				sum++;	//잘리고 남은 파이프 꼭다리 더해주기
			}
		}
	}
	cout << sum;
}