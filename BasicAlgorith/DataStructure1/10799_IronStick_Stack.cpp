/*
	���û���ؼ� Ǯ��
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	stack<char> st;
	int sum = 0;		//sum�� �� ���� ����
	cin >> str;

	for (int i = 0; i < str.length(); i++) {//�־��� ��� ������ Ž��
		if (str[i] == '(') {		//�ϴ� ���ÿ� ���
			st.push(str[i]);
		}
		else {					//�ݴ� ��ȣ�ΰ�� �������� ������ ���������� �˻�
			st.pop();			
			if (str[i - 1] == '(') {	//���� ��Ʈ������ �� ���ڰ� ( �̸� ������
				sum += st.size();	//����� ������ŭ ���ϱ� ���� ������ ũ�� ����
			}
			else {		//�ƴϸ� �������� ��
				sum++;	//�߸��� ���� ������ ���ٸ� �����ֱ�
			}
		}
	}
	cout << sum;
}