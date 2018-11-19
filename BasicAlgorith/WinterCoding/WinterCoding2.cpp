#include <string>
#include <iostream>
using namespace std;
struct box {
	bool U = false;
	bool D = false;
	bool R = false;
	bool L = false;
};
box cordinates[11][11];
int x = 5;
int y = 5;

int solution(string dirs)
{
	int answer = 0;
	for (int i = 0; i < dirs.size(); i++)
	{
		if (dirs[i] == 'U') {
			if (y < 10) {
				y++;
				if (!cordinates[x][y].D) {
					cordinates[x][y - 1].U = true;
					cordinates[x][y].D = true;
					answer++;
				}

			}
		}
		else if (dirs[i] == 'D') {
			if (y > 0)
			{
				y--;
				if (!cordinates[x][y].U)
				{
					cordinates[x][y + 1].D = true;
					cordinates[x][y].U = true;
					answer++;
				}
			}
		}
		else if (dirs[i] == 'R') {
			if (x < 10) {
				x++;
				if (!cordinates[x][y].L)
				{

					cordinates[x - 1][y].R = true;
					cordinates[x][y].L = true;
					answer++;
				}
			}
		}
		else if (dirs[i] == 'L') {
			if (x > 0) {
				x--;
				if (!cordinates[x][y].R)
				{

					cordinates[x + 1][y].L = true;
					cordinates[x][y].R = true;
					answer++;
				}
			}
		}


	}
	cout << answer << endl;
	return answer;
}

int main()
{
	string a;
	cin >> a;
	solution(a);

}