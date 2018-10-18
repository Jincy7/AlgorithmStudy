#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void DFS(int v, int n,bool visit[],vector<int> A[] );

int main() {
	vector<int> A[1010];	//인접리스트
	bool visit[1010] = {false};
	int n,m,v;
	int v1, v2;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++){
		cin >> v1 >> v2;
		A[v1].push_back(v2);
		A[v2].push_back(v1);
	}
	DFS(v, n, visit, A);
}

void DFS(int v, int n, bool visit[], vector<int> A[])
{
	stack<int> tempStack;
	tempStack.push(v);
	visit[v] = true;
	printf("%d", v);
	while (!tempStack.empty()) {
		int current_node = tempStack.top();
		tempStack.pop();

		for (int i = 0; i < A[current_node].size(); i++) {
			int next_node = A[current_node][i];
			if (!visit[next_node]) {
				printf("%d", next_node);
				visit[next_node] = true;
				tempStack.push(current_node);
				tempStack.push(next_node);
				break;
			}
		}
	}
}
