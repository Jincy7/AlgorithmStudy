#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool map[9][9] = { false };

void check(string location) {
	int x = int(location[0]) - 64;
	int y = int(location[1]) - 48;
	for (int i = 1; i <= 8; i++) {
		if (x - y + i <= 8 && x - y + i >= 1) {
			map[x - y + i][i] = true;
		}
		if (x + y - i <= 8 && x + y - i >= 1) {
			map[x + y - i][i] = true;
		}
	}
}

int solution(vector<string> bishops) {
	int answer = 0;
	for (int i = 0; i < bishops.size(); i++) {
		check(bishops[i]);
	}
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (!map[i][j]) answer++;
		}
	}
	return answer;
}

int main() {
	vector<string> bs = { "D5", "E8", "G2" };
	cout << solution(bs); 
}