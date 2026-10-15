#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

string reverseWords(string s) {
	string temp;
	stack<string> stk;
	stringstream ss(s);
	
	// put into stack
	while (ss >> temp) {
		stk.push(temp);
	}

	// pop from stack
	string re;
	while (!stk.empty()) {
		re += stk.top();
		re += ' ';
		stk.pop();
	}

	// delete last ' '
	if (!re.empty() && re[re.size() - 1] == ' ') {
		re.pop_back();
	}

	return re;
}

int main() {
	string s;
	while (getline(cin, s)) {
		cout << "Reverse = " << reverseWords(s) << "\n";
	}
	return 0;
}