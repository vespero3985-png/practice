#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cctype>
using namespace std;

string decodeString(string s) {
	stack<char> stk;
	stack<int> number;
	string num;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '[') {
			stk.push(s[i]);
			number.push(stoi(num));
			num.clear();
		}
		else if (s[i] == ']') {
			string temp;
			while (stk.top() != '[') {
				temp.push_back(stk.top());
				stk.pop();
			}
			stk.pop(); // pop '['
			// repeat number times
			string repeat = temp;
			repeat.reserve(temp.size() * number.top());
			for (int j = 1; j < number.top(); j++) {
				repeat += temp;
			}
			number.pop();
			// push into stk
			for (int j = repeat.size() - 1; j >= 0; j--) {
				stk.push(repeat[j]);
			}
		}
		else if (isdigit(s[i])) {
			num.push_back(s[i]);
		}
		else {
			stk.push(s[i]);
		}
	}

	string ans;
	ans.reserve(stk.size());
	while (!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	string s;
	while (cin >> s) {
		cout << decodeString(s) << "\n";
	}
	return 0;
}