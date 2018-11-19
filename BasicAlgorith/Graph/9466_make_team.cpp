#include <iostream>

using namespace std;

void DFS(int v,bool* inTeam, int* Map);

int main() {
	int t;
	cin >> t;
	for (int idx = 0; idx < t; idx++) {
		int n;
		int Map[100010] = {0};
		bool inTeam[100010] = { false };
		bool inGraph[100010] = { false };
		bool visit[100010] = { false };

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> Map[i];
			if (i == Map[i]) {
				inTeam[i] = true;	//입력과 동시에 본인 가리키는 원소는 팀으로 표기
				visit[i] = true;
			}
		}
		for (int i = 1; i <= n;i++) {
			if (!inTeam[i] && !visit[i]) {	//팀 안이루고 검사 안했으면
				int next = Map[i];
				inGraph[i] = true;			//일단 그래프에 넣고
				visit[i] = true;
				if (!inGraph[next]) {		//다음 원소가 그래프에 없으면
					while (!inGraph[next]) {//다음 원소가 그래프에 있을때 까지 돌림
						if (!inTeam[next]) {
							inGraph[next] = true;
							visit[next] = true;
							next = Map[next];
							continue;
						}
						else {
							break;
						
						}
					}
					DFS(next, inTeam, Map);//DFS next에서부터 실행해서 스택 빌 때까지 inTeam 배열 true로 변경
					for (int j = 1; j <= n; j++) {
						inGraph[j] = false;
					}
				}
			}
			else {
				continue;
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (!inTeam[i]) cnt++;
		}
		cout << cnt << endl;
	}
}

void DFS(int v, bool * inTeam, int * Map)
{
	inTeam[v] = true;
	if (!inTeam[Map[v]]) {	//다음원소가 팀에 없으면
		DFS(Map[v], inTeam, Map);
	}
	else {
		return;
	}
}
