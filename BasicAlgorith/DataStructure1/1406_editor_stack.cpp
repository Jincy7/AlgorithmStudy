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

	for (int i = 0; i < c.length(); i++) {	//�Է¹����� ���ÿ� �ֱ�
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
		case 'L':	//Ŀ�� �������� �ű�� -> left ���ÿ��� right��
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
			break;
		case 'D':	//Ŀ�� ���������� �ű�� -> right ���ÿ��� left��
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