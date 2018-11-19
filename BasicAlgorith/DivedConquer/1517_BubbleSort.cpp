//머지소트 사용하기!
#include <iostream>
#include <algorithm>

using namespace std;

int arr[500010] = { 0 };

int bs(int n) {
	int result = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) result++;
		}
	}
	return result;
}

long countswap(int n) {
	long result = 0;
	int sorted_arr[500010] = { 0 };
	for (int i = 0; i < n; i++) {
		sorted_arr[i] = arr[i];
	}
	sort(sorted_arr, sorted_arr + n);
	for (int i = 0; i < n; i++) {
		int tmp = (*find(sorted_arr, sorted_arr + n, arr[i]));
		if ( tmp - i > 0) 
		{
			result += (tmp-i-1);
		}
	}
	return result;
}

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << countswap(n);
}