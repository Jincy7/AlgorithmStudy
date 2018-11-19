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
				inTeam[i] = true;	//�Է°� ���ÿ� ���� ����Ű�� ���Ҵ� ������ ǥ��
				visit[i] = true;
			}
		}
		for (int i = 1; i <= n;i++) {
			if (!inTeam[i] && !visit[i]) {	//�� ���̷�� �˻� ��������
				int next = Map[i];
				inGraph[i] = true;			//�ϴ� �׷����� �ְ�
				visit[i] = true;
				if (!inGraph[next]) {		//���� ���Ұ� �׷����� ������
					while (!inGraph[next]) {//���� ���Ұ� �׷����� ������ ���� ����
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
					DFS(next, inTeam, Map);//DFS next�������� �����ؼ� ���� �� ������ inTeam �迭 true�� ����
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
	if (!inTeam[Map[v]]) {	//�������Ұ� ���� ������
		DFS(Map[v], inTeam, Map);
	}
	else {
		return;
	}
}
