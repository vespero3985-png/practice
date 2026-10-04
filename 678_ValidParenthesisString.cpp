#include <iostream>
#include <string>
using namespace std;

bool checkValidString(string s) {
	int min = 0, max = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			min++; max++;
		}
		else if (s[i] == ')') {
			min--; max--;
		}
		else { // s[i] == '*'
			min--; max++;
		}
		
		if (max < 0) {
			return false;
		}

		if (min < 0) {
			min = 0;
		}
	}

	return min == 0;
}

int main() {
	string s;
	while (cin >> s) {
		cout << checkValidString(s) << endl;
	}
	return 0;
}