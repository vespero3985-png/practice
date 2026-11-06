#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
	stack<int> stk;
	vector<int> ans;
	for (int n : asteroids) {
		if (n > 0) {
			stk.push(n);
		}
		else {
			bool is_alive = true;
			// collisions
			while (!stk.empty() && is_alive) {
				if (stk.top() + n > 0) { // a > b
					is_alive = false;
				}
				else if (stk.top() + n == 0) { // a == b
					stk.pop();
					is_alive = false;
				}
				else { // a < b
					stk.pop();
				}
			}
			// stk.empty()
			if (is_alive)
				ans.push_back(n);
		}
	}
	// put stk into ans
	int l = ans.size();
	while (!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
	}
	reverse(ans.begin() + l, ans.end());

	return ans;
}

int main() {
	string line;
	while (getline(cin, line)) {
		if (line.find_first_not_of(" \t") == string::npos) continue;

		vector<int> asteroids;
		stringstream ss(line);
		int temp;
		while (ss >> temp) {
			asteroids.push_back(temp);
		}

		vector<int> ans = asteroidCollision(asteroids);
		cout << "ANS = ";
		for (int n : ans) {
			cout << n << " ";
		}
		cout << "\n";
	}

	return 0;
}