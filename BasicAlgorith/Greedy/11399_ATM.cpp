#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n = 0;
	int tmp = 0;
	int result = 0;
	int prev_wait = 0;
	vector<int> P;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		P.push_back(tmp);
	}

	sort(P.begin(), P.end());
	for (int i = 0; i != P.size(); i++) {
		prev_wait += P[i];
		result += prev_wait;
	}
	cout << result;
}