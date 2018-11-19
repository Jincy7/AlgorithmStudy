#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>

using namespace std;

bool CheckBomb(string c, string a, int* index) {
	int check = 0;
	bool flag = true;

	while (check != a.size() - 1 && flag) {
		(*index) += 1;
		check++;
		if (c[*index] == a[0])
		{
			flag = CheckBomb(c, a, index);
			if (!flag) return false;
			else (*index)++;
		}
		if (c[*index] != a[check]) return false;
	}
	return true;
}

int main() {
	string target;
	string bomb;
	queue<char> resultQ;

	cin >> target >> bomb;
	for (int i = 0; i < target.size(); i++) {
		if (target[i] != bomb[0]) {
			resultQ.push(target[i]);
		}
		else {
			int tmp = i;
			if (!CheckBomb(target,bomb,&i))
			{
				for (int j = tmp; j <= i; j++) {
					resultQ.push(target[j]);
				}
			}
		}
	}
	if (resultQ.empty()) {
		printf("FRULA");
	}
	else {
		while (!resultQ.empty()) {
			printf("%c", resultQ.front());
			resultQ.pop();
		}
	}
}


/*
#include <iostream>
#include <string>

using namespace std;

bool isExploded[1000000] = { false };

struct info {
	int index;
	bool isBomb;
};

info CheckBomb(string c,string a,int i) {
	int checkCount = 0;
	int start = i;
	bool flag = true;
	info tmp;
	tmp.index = i;

	while (i < c.size() && flag) {
		i++;
		checkCount++;
		if (c[i] == a[0]) {
			tmp = CheckBomb(c, a, i);
			i = tmp.index;
		}
		else
		{
			if (c[i] == a[checkCount])
			{

			}
			else
			{
				flag = false;
				tmp.index = i;
				tmp.isBomb = flag;
				return tmp;
			}

			if (checkCount == a.size() - 1) {
				tmp.index = i;
				tmp.isBomb = flag;
				for (int j = start; j <= i; j++) {
					isExploded[j] = true;
				}
				return tmp;
			}
		}
	}

}


info CheckBomb(string c, string a, int i) {
	int checkCount = 0;
	int start = i;
	bool flag = true;
	info tmp;
	tmp.index = i;

	while (i < c.size() && flag) {
		i++;
		checkCount++;
		if (c[i] == a[checkCount])
		{
			tmp = CheckBomb(c, a, i);
			i = tmp.index;
		}
		else
		{
			flag = false;
			tmp.index = i;
			tmp.isBomb = flag;
			return tmp;
		}

		if (checkCount == a.size() - 1) {
			tmp.index = i;
			tmp.isBomb = flag;
			for (int j = start; j <= i; j++) {
				isExploded[j] = true;
			}
			return tmp;
		}
	}
}

int main() {
	string target;
	string bomb;
	info tmp;

	cin >> target >> bomb;
	for (int i = 0; i < target.size(); i++) {
		if (target[i] == bomb[0]) {
			tmp = CheckBomb(target, bomb, i);
			i = tmp.index;
		}
	}
	for (int i = 0; i < target.size(); i++) {
		if (!isExploded[i]) {
			cout << target[i];
		}
	}
}
*/