#include <iostream>

using namespace std;

//ascii a:97 z:122  A:65 Z:90
// 원래값이 97이상 122 이하인경우
// 122-13 = 109 이니까 110 이상인 경우 c[i] 값에 13 더해서 122 뺴고 97에 더하기
// 97-1 < x && x < 109 + 1, 109 < x < 123
// 65 -1           77 + 1, 77         90

int main() {
	char charray[100] = {'\0'};
	int i = 0;
	cin.getline(charray,100);	

	while (true) {
		if (charray[i] == '\0') {
			break;
		}
		if ((96 < charray[i] && charray[i] < 110) | (64 < charray[i] && charray[i] < 78))
			charray[i] = char(int(charray[i]) + 13);
		else if ((109 < charray[i] && charray[i] < 123) | (77 < charray[i] && charray[i] < 90)) {
			charray[i] = char(int(charray[i]) - 13);
		}
		else {
			i++;
			continue;
		}
		i++;
	}

	for (int i = 0; i < 100; i++) {
		if (charray[i] == '\0') { cout << '\0'; break; }
		cout << charray[i];
	}
}