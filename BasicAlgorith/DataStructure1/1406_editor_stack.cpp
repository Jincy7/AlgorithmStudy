#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	string c;
	int n;
	char command;
	char tmpchar;
	stack<char> left;
	stack<char> right;

	cin >> c;
	cin >> n;

	for (int i = 0; i < c.length(); i++) {	//입력받은값 스택에 넣기
		left.push(c[i]);
	}
	
	for (int i = 0; i < n; i++){
		cin >> command;
		switch (command)
		{
		case 'P':
			cin >> tmpchar;
			left.push(tmpchar);
			break;
		case 'L':	//커서 왼쪽으로 옮기기 -> left 스택에서 right로
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
			break;
		case 'D':	//커서 오른쪽으로 옮기기 -> right 스택에서 left로
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
			break;
		case 'B':
			if (!left.empty()) {
				left.pop();
			}
			break;
		default:
			break;
		}
	}
	
	int left_size = left.size();
	for (int i = 0; i < left_size; i++) {
		right.push(left.top());
		left.pop();
	}

	int right_size = right.size();
	for (int i = 0; i < right_size; i++) {
		cout << right.top();
		right.pop();
	}
}