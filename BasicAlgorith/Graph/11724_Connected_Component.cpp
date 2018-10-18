#include <iostream>

using namespace std;

void DFS(int v,int n,bool* visit, bool map[][1010]);

int main() {
	int n, m;
	int v1, v2;
	int cnt = 0;
	int idx = 0;

	bool visit[1010] = { false };
	bool map[1010][1010]{ false };
	
	cin >> n >> m;
	for (int i = 1; i <= m;i++) {
		cin >> v1 >> v2;
		map[v1][v2] = map[v2][v1] = true;
	}

	//한번 탐색 돌리면서 cnt 증가시킨 후 방문 안된노드 있으면
	//방문 안된 노드중 한번 더 탐색

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cnt++;
			DFS(i, n, visit, map);
		}
	}
	printf("%d", cnt);
}

void DFS(int v, int n, bool* visit, bool map[][1010]) {
	visit[v] = true;
	for (int i = 1; i <= n; i++) {
		if (map[v][i] && !visit[i]) {
			DFS(i, n, visit, map);
		}
	}
}