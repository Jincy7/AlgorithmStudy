#include <iostream>
#include <queue>

using namespace std;

struct room {
	int x;
	int y;
	int state;
};

int main() {
	int m, n;
	int cnt=0;
	queue<room> myQueue;
	int farm[1010][1010] = { -1, };
	cin >> m >> n;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			farm[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < m; j++) {
			cin >> farm[i][j];
		}
	}

	while (true) {
		for (int i = 0; i <= n;i++) {
			for (int j = 0;j <= m;j++) {
				if (farm[i][j] == 1) {
					room tempRoom;
					tempRoom.x = j;
					tempRoom.y = i;
					tempRoom.state = 1;
					myQueue.push(tempRoom);
				}
			}
		}

		if (!myQueue.empty()) {
			
		}
	}

}