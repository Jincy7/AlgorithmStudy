#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// ��ų Ʈ���� �� ���ҿ� ���� ������ ���þ��� ���ڵ� ��� ���������� ���� ��ųƮ���� �������� ��


int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	bool flag = true;
	for (int i = 0; i < skill_trees.size(); i++) {		// ������ ��ųƮ��
		for (int j = 0; j < skill_trees[i].length(); j++) {	// ��ųƮ�� ���� �ϳ��ϳ�
			if (skill.find(skill_trees[i][j]) == string::npos) {	//��ų���� ��ã����
				skill_trees[i][j] = '*';	//���� ġȯ
			}
		}
	}
	for (int i = 0; i < skill_trees.size(); i++){// �� �� �����
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