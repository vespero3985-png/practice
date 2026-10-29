#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int largestAltitude(vector<int>& gain) {
	int highest = max(0, gain[0]);
	for (int i = 1; i < gain.size(); i++) {
		gain[i] = gain[i] + gain[i - 1];
		highest = max(highest, gain[i]);
	}
	return highest;
}

int main() {
	string line;
	while (getline(cin, line)) {
		if (line.find_first_not_of(" \t") == string::npos) continue;

		vector<int> gain;

		stringstream ss(line);
		int temp;
		while (ss >> temp) {
			gain.push_back(temp);
		}

		cout << "ANS = " << largestAltitude(gain) << "\n";
	}
	return 0;
}