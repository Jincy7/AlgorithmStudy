#include <iostream>
#include <queue>

using namespace std;

void DFS(int v, int n, bool* visit, bool map[][1010]);
void BFS(int v, int n, bool* visit, bool map[][1010]);

int main() {
	int n, m, v;
	int v1, v2;
	bool visit[1010] = { false };
	bool visit2[1010] = { false };
	bool map[1010][1010] = { false };
	cin >> n >> m >> v;
	for (int i = 0;i < m; i++) {
		cin >> v1 >> v2;
		map[v1][v2] = map[v2][v1] = true;
	}
	DFS(v, n, visit, map);
	printf("\n");
	BFS(v, n, visit2, map);

}

void DFS(int v, int n, bool* visit, bool map[][1010]) {
	visit[v] = true;
	printf("%d", v);
	for (int i = 1; i <= n; i++) {
		if ((map[v][i]) && !visit[i]) {
			printf(" ");
			DFS(i, n, visit, map);
		}
	}
}

void BFS(int v, int n, bool* visit, bool map[][1010]) {
	queue<int> tempQueue;
	visit[v] = true;
	tempQueue.push(v);

	while (!tempQueue.empty()) {
		int temp = tempQueue.front();
		tempQueue.pop();
		printf("%d ", temp);
		for (int i = 1; i <= n; i++) {
			if (map[temp][i] && !visit[i]) {
				visit[i] = true;
				tempQueue.push(i);
			}
		}
	}
}