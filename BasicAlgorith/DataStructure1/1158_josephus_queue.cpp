//백준 : 1158
//문제
//조세퍼스 문제는 다음과 같다.
//
//1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 M(≤ N)이 주어진다.이제 순서대로 M번째 사람을 제거한다.한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.이 과정은 N명의 사람이 모두 제거될 때까지 계속된다.원에서 사람들이 제거되는 순서를(N, M) - 조세퍼스 순열이라고 한다.예를 들어(7, 3) - 조세퍼스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
//
//N과 M이 주어지면(N, M) - 조세퍼스 순열을 구하는 프로그램을 작성하시오.

#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int> people, result;
	int n, m;
	int cnt = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {	//순열 초기화
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