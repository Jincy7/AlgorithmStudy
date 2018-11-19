#include <iostream>

using namespace std;

int _x = 0; int _y = 0;

struct happymap {
	int x[1010];
	int y[1010];
	int point[1010][1010];
};

int main() {
	int r; int c;
	happymap map;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map.point[i][j];
		}
	}
}