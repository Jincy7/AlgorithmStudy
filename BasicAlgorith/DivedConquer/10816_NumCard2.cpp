#include <stdio.h>

int main() {
	int n = 0; int m = 0;
	int temp = 0;
	//int *a = new int[10000000] �̷� ������ �����Ҵ� �ؾ��� ��� ������ ����
	int pCard[10000010] = { 0 };
	int nCard[10000010] = { 0 };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		if (temp < 0)
		{
			nCard[-temp]++;
		}
		else
		{
			pCard[temp]++;
		}
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		if (temp < 0)
		{
			printf("%d ", nCard[-temp]);
		}
		else
		{
			printf("%d ", pCard[temp]);
		}
	}
}