#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkVPS(string str) {
	stack<char> st;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];

		if (c == '(') {
			st.push(c);			//���� ��ȣ�� �ϴ� �ϳ��� ���ÿ� �װ�
		}
		else {					//�ݴ� ��ȣ��
			if (!st.empty()) {	//������ ������� ���� ���
				st.pop();			//���� ���� �ִ� ���°�ȣ�� ����� (�ݴ� ��ȣ�� ¦�� �̷�Ƿ� VPS)
			}
			else {				//������ ����ִ� ���
				return false;	//¦�� �̷�� ���� ��ȣ�� �����Ƿ� VPS �ƴ�
			}
		}
	}
	return st.empty();			//���̸�ŭ ���Ҵµ��� ���ÿ� ���� ������ ¦�� �̷������� ( �� �ִ°�!
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