#include <iostream>

using namespace std;

int DFS(int v, int* Map, int* visit, int depth);

int main() {
	int t;
	cin >> t;
	for (int idx = 0; idx < t; idx++) {
		int n;
		int cnt = 0;
		int Map[100010] = { 0 };
		int visit[100010] = { 0 };

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> Map[i];
		}
		for (int i = 1; i <= n;i++) {
			if (visit[i] != 0) {
				continue;
			}
			else {
				cnt += DFS(i, Map, visit, 0);
			}
		}
		
		cout << cnt << endl;
	}
}

int DFS(int v, int * Map, int* visit, int depth)
{
	depth++;
	if (visit[v] != 0) {
		return depth - visit[v];
	}
	else {
		visit[v] = depth;
		DFS(Map[v], Map, visit, depth);
	}
}
