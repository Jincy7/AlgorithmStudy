#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkVPS(string str) {
	stack<char> st;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];

		if (c == '(') {
			st.push(c);			//여는 괄호면 일단 하나씩 스택에 쌓고
		}
		else {					//닫는 괄호면
			if (!st.empty()) {	//스택이 비어있지 않은 경우
				st.pop();			//가장 위에 있는 여는괄호를 지운다 (닫는 괄호와 짝을 이루므로 VPS)
			}
			else {				//스택이 비어있는 경우
				return false;	//짝을 이루는 여는 괄호가 없으므로 VPS 아님
			}
		}
	}
	return st.empty();			//길이만큼 돌았는데도 스택에 뭐가 남으면 짝을 이루지못한 ( 가 있는것!
}

int main() {
	int n = 0;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;

		if (checkVPS(str)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}