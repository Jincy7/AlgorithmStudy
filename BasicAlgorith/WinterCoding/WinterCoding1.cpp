#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 스킬 트리의 각 원소에 대해 순서와 관련없는 문자들 모두 지워버린후 선행 스킬트리와 같은지만 비교


int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	bool flag = true;
	for (int i = 0; i < skill_trees.size(); i++) {		// 각각의 스킬트리
		for (int j = 0; j < skill_trees[i].length(); j++) {	// 스킬트리 문자 하나하나
			if (skill.find(skill_trees[i][j]) == string::npos) {	//스킬에서 못찾으면
				skill_trees[i][j] = '*';	//별로 치환
			}
		}
	}
	for (int i = 0; i < skill_trees.size(); i++){// 별 다 지우기
		skill_trees[i].erase(std::remove(skill_trees[i].begin(), skill_trees[i].end(),'*'), skill_trees[i].end());
		flag = true;
		for (int j = 0; j < skill_trees[i].length(); j++) {
			if (skill[j] != skill_trees[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			answer++;
			cout << skill_trees[i] << endl;
		}
	}
	return answer;
}

int main() {
	string skill = "CBD";
	vector<string> skill_trees;
	skill_trees.push_back("BACDE");
	skill_trees.push_back("CBADF");
	skill_trees.push_back("AECB");
	skill_trees.push_back("BDA");
	
	cout << solution(skill, skill_trees);

}