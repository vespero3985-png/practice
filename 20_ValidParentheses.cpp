#include <iostream>
#include <map>
#include <string>
#include <stack>
using namespace std;

int main() {
	string s;
	map<char, char> cor = { {')', '('}, {']', '['}, {'}', '{'} };

	while (cin >> s) {
		stack<char> mystack;
		bool isValid = true;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				mystack.push(s[i]);
				cout << "push " << s[i] << endl;
			}
			else {
				if (mystack.empty() || cor[s[i]] != mystack.top()) {
					cout << s[i] << " has not a corresponding open bracket in the stack." << endl;
					isValid = false;
					break;
				}
				cout << s[i] << " is matching with " << mystack.top() << endl;
				mystack.pop();
			}
		}
		cout << "Final check the stack" << endl;
		if (isValid) {
			isValid = mystack.empty();
			cout << "The stack is (1:empty, 0:not empty) " << mystack.empty() << endl;
		}

		cout << "Ans = " << isValid << endl;
	}

	return 0;
}