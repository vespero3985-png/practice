#include <iostream>
#include <string>
#include <queue>
using namespace std;

string predictPartyVictory(string senate) {
	queue<int> rad, dir;
	int n = senate.size();
	for (int i = 0; i < n; i++) {
		if (senate[i] == 'R')
			rad.push(i);
		else
			dir.push(i);
	}

	while (!rad.empty() && !dir.empty()) {
		if (rad.front() < dir.front()) {
			rad.push(n);
		}
		else {
			dir.push(n);
		}
		n++;
		rad.pop(); dir.pop();
	}

	if (rad.empty())
		return "Dire";
	else
		return "Radiant";
}

int main() {
	string senate;
	while (cin >> senate) {
		cout << "ANS = " << predictPartyVictory(senate) << "\n";
	}
	return 0;
}