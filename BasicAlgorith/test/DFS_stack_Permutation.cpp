#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//10451 ��, ����, ����ð� : 224ms
//Ǯ�̹�� : ��������Ʈ�� ������ ����� DFS ����
//������ �׷����� N���� ������ ������ �ִ� N ���� ������ ������ ������ Sparse��
//�׷����̹Ƿ� ���� ����� ����ϴ� �� ���� ���� ����Ʈ�� �����ϴ°��� 
//�޸�, �ð������� �̵��� ŭ

void DFS(int v, int n, bool visit[], vector<int> A[]);

int main() {
	int T;
	int n;
	int node[1010];
	int cnt = 0;

	bool visit[1010] = { false };
	vector<int> map[1010];

	cin >> T;

	for (int i = 0;i < T; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> node[j];
			map[j].push_back(node[j]);
		}
		for (int j = 1; j <= n; j++) {
			if (!visit[j]) {
				cnt++;
				DFS(j, n, visit, map);
			}
		}
		cout << cnt << endl;

		cnt = 0;
		//visit[1010] = { false };
		for (int j = 0; j <= n; j++) {
			visit[j] = false;
		}
		//map[1010][1010] = { false };
		for (int j = 0; j <= n; j++) {
			map[j].clear();
		}
	}
}

void DFS(int v, int n, bool visit[], vector<int> A[])
{
	stack<int> tempStack;
	tempStack.push(v);
	visit[v] = true;
	
	while (!tempStack.empty()) {
		int current_node = tempStack.top();
		tempStack.pop();

		for (int i = 0; i < A[current_node].size(); i++) {
			int next_node = A[current_node][i];
			if (!visit[next_node]) {
				
				visit[next_node] = true;
				tempStack.push(current_node);
				tempStack.push(next_node);
				break;
			}
		}
	}
}
