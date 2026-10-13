#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

bool isValid(string s) {
	int open = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			open++;
		}
		else if (s[i] == ')') {
			if (open > 0)
				open--;
			else
				return false;
		}
	}
	if (open == 0)
		return true;
	else
		return false;
}

vector<string> removeInvalidParentheses(string s) {
	queue<string> q;
	q.push(s);
	unordered_set<string> visited;
	visited.insert(s);
	vector<string> ans;
	string curr, next_str;
	bool found = false;
	
	// bfs
	while (!q.empty() && !found) {
		int level_size = q.size();
		// one level
		for (int j = 0; j < level_size; j++) {
			curr = q.front();
			q.pop();
			if (isValid(curr)) {
				ans.push_back(curr);
				found = true;
			}
			else if (!found){
				// push next level
				for (int i = 0; i < curr.size(); i++) {
					if (curr[i] == '(' || curr[i] == ')') {
						next_str = curr.substr(0, i) + curr.substr(i + 1);
						// not in queue => push
						if (visited.find(next_str) == visited.end()) {
							visited.insert(next_str);
							q.push(next_str);
						}
					}
				}
			}
		}
		if (found)
			break;
	}
	// find answer
	return ans;
}


int main() {
	string s;
	while (cin >> s) {
		vector<string> ans = removeInvalidParentheses(s);
		for (string k : ans) {
			cout << k << " ";
		}
		cout << '\n';
	}
	return 0;
}