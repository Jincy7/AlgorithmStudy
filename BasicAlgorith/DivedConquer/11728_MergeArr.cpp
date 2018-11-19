#include <iostream>
#include <algorithm>

using namespace std;

void mergeArrNSort(long* a, long* b, long* merged, int n, int m) {
	for (int i = 0; i < n + m; i++) {
		if (i < n)
		{
			merged[i] = a[i];
		}
		else
		{
			merged[i] = b[i - n];
		}
	}
	sort(merged, merged + (n + m));
}

void mergeArrNSort2(long* a, long* b, long* merged, int n, int m) {
	int i_a = 0; int i_b = 0;
	for (int i = 0; i < n + m; i++)
	{
		if (i_a == n) 
		{
			merged[i] = b[i_b++];
		}
		else if (i_b == m)
		{
			merged[i] = a[i_a++];
		}
		else
		{
			if (a[i_a] < b[i_b])
			{
				merged[i] = a[i_a++];
			}
			else
			{
				merged[i] = b[i_b++];
			}
		}
	}
}

int main() {
	int n = 0; int m = 0;
	long a[10] = { 0 };
	long b[10] = { 0 };
	long merged[210] = { 0 };
	long temp = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		a[i] = temp;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		b[i] = temp;
	}
	mergeArrNSort2(a, b, merged, n, m);
	for (int i = 0; i < n + m; i++) 
	{
		cout << merged[i] << ' ';
	}
}