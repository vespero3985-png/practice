#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string removeStars(string s) {
	stack<char> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '*') {
			stk.pop();
		}
		else {
			stk.push(s[i]);
		}
	}

	string ans;
	while(!stk.empty()) {
		ans += stk.top();
		stk.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	string s;
	while (cin >> s) {
		cout << removeStars(s) << "\n";
	}
	return 0;
}