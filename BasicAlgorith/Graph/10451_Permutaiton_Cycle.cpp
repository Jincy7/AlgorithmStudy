#include <iostream>
#include <queue>

using namespace std;

//DFS로 했을때는 시간 초과 안뜨고 BFS 로 했을때는 시간초과 뜸!... 왜?


void DFS(int v, int n, bool* visit, bool map[][1010]) {
	visit[v] = true;
	for (int i = 1; i <= n; i++) {
		if (map[v][i] && !visit[i]) {
			DFS(i, n, visit, map);
		}
	}
}

void BFS(int v, int n, bool* visit, bool map[][1010]) {
	visit[v] = true;
	queue<int> tempQueue;
	tempQueue.push(v);

	while (!tempQueue.empty()) {
		int temp = tempQueue.front();
		tempQueue.pop();
		for (int i = 1; i <= n; i++) {
			if (map[temp][i] && !visit[i]) {
				tempQueue.push(i);
				visit[i] = true;
			}
		}
	}
}

int main() {
	int T;
	int n;
	int node[1010];
	int cnt = 0;

	bool visit[1010] = { false };
	bool map[1010][1010] = { false };

	cin >> T;

	for (int i = 0;i < T; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> node[j];
			map[j][node[j]] =  true;
		}
		for (int j = 1; j <= n; j++) {
			if (!visit[j]) {
				cnt++;
				BFS(j, n, visit, map);
			}
		}
		cout << cnt<<endl;
		
		cnt = 0;
		//visit[1010] = { false };
		for (int j = 0; j <= n; j++) {
			visit[j] = false;
		}
		//map[1010][1010] = { false };
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				map[j][k] = false;
			}
		}
	}
}