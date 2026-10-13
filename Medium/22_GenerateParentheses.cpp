#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<string> generateParenthesis(int n) {
	if (n == 1) {
		vector<string> ans = { "()" };
		return ans;
	}
	vector<unordered_set<string>> set_vector(n + 1);
	set_vector[1] = {"()"};
	for (int level = 2; level <= n; level++) {
		unordered_set<string> temp;
		// ( + f(level-1) + ) 
		for (const auto& s : set_vector[level - 1]) {
			cout << "check 1, s = " << s << endl;
			temp.insert( "(" + s + ")" );
		}
		// f(level-i) x f(i)
		for (int i = 1; i < level; i++) {
			for (const auto& first : set_vector[level - i]) {
				cout << "check first = " << first << endl;
				for (const auto& second : set_vector[i]) {
					cout << "check second = " << second << " ";
					temp.insert(first + second);
				}
				cout << endl;
			}
			// put into set_vector 
			set_vector[level] = temp;
		}
	}
	// return
	vector<string> ans(set_vector[n].begin(), set_vector[n].end());
	return ans;
}

int main() {
	int n;
	while (cin >> n) {
		if (n > 0 && n <= 8) {
			vector<string> result = generateParenthesis(n);
			for (auto s : result) {
				cout << s << " ";
			}
			cout << endl;
		}
	}

	return 0;
}