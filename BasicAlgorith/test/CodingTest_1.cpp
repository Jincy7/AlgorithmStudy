#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> paper)
{
	int answer = -1;
	int sum = 0;
	sort(paper.begin(), paper.end(),greater<int>());
	for (int i = 0; i != paper.size(); i++) {
		sum += paper[i];
		if ((i + 1)*(i + 1) > sum) {
			return i;
		}
	}

	return paper.size();
}

int main() {
	vector<int> p1 = { 7, 5, 8, 10, 6, 9, 5 };
	cout << solution(p1);
}