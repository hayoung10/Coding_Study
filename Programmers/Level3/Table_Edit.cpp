#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	set<int> table;
	stack<int> deleteNums;

	for (int i = 0; i < n; i++)
		table.insert(i);
	auto cur = table.find(k);
	
	int num = 0;
	for (int i = 0; i < cmd.size(); i++) {
		switch (cmd[i][0]) {
		case 'U':
			num = stoi(cmd[i].substr(2));
			while (num > 0) { cur--; num--; }
			break;
		case 'D':
			num = stoi(cmd[i].substr(2));
			while (num > 0) { cur++; num--; }
			break;
		case 'C':
			deleteNums.push(*cur);
			cur = table.erase(cur);
			if (cur == table.end()) cur--;
			break;
		case 'Z':
			table.insert(deleteNums.top());
			deleteNums.pop();
			break;
		}
	}

	for (int i = 0; i < n; i++) answer += 'X';
	for (int t : table) answer[t] = 'O';

	return answer;
}

int main()
{
	cout << "n \tk \tcmd \t\t\t\t\t\tresult" << endl;
	cout << "8 \t2 \t[\"D 2\",\"C\",\"U 3\",\"C\",\"D 4\",\"C\",\"U 2\",\"Z\",\"Z\"] \t";
	string ans = solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" });
	cout << ans << endl;

	return 0;
}