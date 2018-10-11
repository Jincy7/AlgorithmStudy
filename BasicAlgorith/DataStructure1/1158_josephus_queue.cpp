//���� : 1158
//����
//�����۽� ������ ������ ����.
//
//1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� M(�� N)�� �־�����.���� ������� M��° ����� �����Ѵ�.�� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������.�� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�.������ ������� ���ŵǴ� ������(N, M) - �����۽� �����̶�� �Ѵ�.���� ���(7, 3) - �����۽� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.
//
//N�� M�� �־�����(N, M) - �����۽� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> people, result;
	int n, m;
	int cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {	//���� �ʱ�ȭ
		people.push(i + 1);
	}

	while (!people.empty()) {
		if (cnt == m-1) {
			result.push(people.front());
			people.pop();
			cnt = 0;
		}
		else {
			people.push(people.front());
			people.pop();
			cnt++;
		}
	}
	cout << '<';
	while (!result.empty()) {
		if (result.size() != 1) {
		cout << result.front() << ", ";
		result.pop();
		}
		else {
			cout << result.front() << '>';
			result.pop();
		}
	}
}

// people: 1 2 3 4 5 6 7

// people : 4 5 6 7 1 2
// result : 3

// people : 7 1 2 4 5
// result ; 3 6