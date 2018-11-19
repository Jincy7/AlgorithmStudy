#include <iostream>
#include <math.h>

using namespace std;

int findLocation(int n, int y, int x) 
{
	int deter = pow(2, n - 1);
	if (n == 1) 
	{
		return x + 2 * y;
	}
	else 
	{
		if (y < deter)
		{
			if (x < deter) //0 사분면
			{
				return findLocation(n - 1, y, x);
			}
			else // 1 사분면
			{
				return findLocation(n - 1, y, x - deter) + (deter*deter) ;
			}
		}
		else
		{
			if (x < deter) // 2 사분면
			{
				return findLocation(n - 1, y - deter , x ) + (deter*deter) * 2;
			}
			else // 3 사분면
			{
				return findLocation(n - 1, y - deter, x - deter) + (deter*deter) * 3;
			}
		}
	}
}

int main() {
	int n = 0; int r = 0; int c = 0;
	cin >> n >> r >> c;
	cout << findLocation(n, r, c);
}