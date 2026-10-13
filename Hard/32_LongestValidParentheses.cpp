#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;

int longestValidParentheses(string s) {
	int ans = 0;
	stack<int> mystack;
	mystack.push(-1);
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			mystack.push(i);
		}
		else {
			mystack.pop();

			if (mystack.empty()) {
				mystack.push(i);
			}
			else {
				ans = max(ans, i - mystack.top());
			}
		}
	}
	return ans;
}

int main() {
	string s;
	while (cin >> s) {
		cout << longestValidParentheses(s) << endl;
	}

	return 0;
}