/*
	���� ���� ����� Ǯ��
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	int sum = 0, stick = 0;		//sum�� �� ���� ����, stick�� ���� ����
	cin >> str;

	for (int i = 0; i < str.length(); i++) {//�־��� ��� ������ Ž��
		if (i == str.length() - 1) break;	//���� ���ڱ��� Ž���ϹǷ� �޸� �������� ����
		if (str[i] == '(') {				//���� ��ȣ�� ���
			if (str[i + 1] == '(') {		//������ ���� ��ȣ�� ��� ����� �ϳ� �߰�, �������� �߰�
				stick += 1;
				sum += 1;
			}
			else {							//������ �ݴ� ��ȣ�� ��� �������̹Ƿ� ����� ������ŭ �� ������ �߰�
				sum += stick;
			}
		}
		else {								//�ݴ� ��ȣ�� ���
			if (str[i + 1] == ')') {		//������ �ݴ� ��ȣ�� ��쿡�� ����� �ϳ� ����
				stick -= 1;
			}
		}
	}
	cout << sum;
}