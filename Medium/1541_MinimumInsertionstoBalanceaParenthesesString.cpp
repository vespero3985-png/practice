#include <iostream>
#include <string>
using namespace std;

int minInsertions(string s) {
	int ans = 0, pair = 0;
	int i = s.size() - 1;
	while (i >= 1) {
		if (s[i] == ')' && s[i - 1] == ')') {
			pair++;
			i -= 2;
		}
		else if (s[i] == ')' && s[i - 1] == '(') {
			ans++;
			i -= 2;
		}
		else {
			if (pair >= 1) {
				pair--;
				i--;
			}
			else {
				ans += 2;
				i--;
			}
		}
	}
	// s[0]
	if (i == 0) {
		if (s[i] == '(' && pair >= 1) {
			pair--;
		}
		else {  // pair == 0 || s[0] == ')'
			ans += 2;
		}
	}

	return ans + pair;
}

int main()
{
	string s;

	while (cin >> s) {
		cout << "ans: " << minInsertions(s) << endl;
		// (()))(()))()()))) => should be 4
		// (()((()(( => should be 12 
	}

	return 0;
}