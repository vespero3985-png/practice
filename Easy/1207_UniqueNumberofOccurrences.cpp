#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
	unordered_map<int, int> count;
	for (int n : arr) {
		if (count.find(n) == count.end()) {
			count[n] = 1;
		}
		else {
			count[n] = count[n] + 1;
		}
		cout << "count[" << n << "] = " << count[n] << endl;
	}

	unordered_set<int> unrepeat;
	for (const auto& n : count) {
		if (unrepeat.find(n.second) != unrepeat.end()) {
			return false;
		}
		unrepeat.insert(n.second);
	}
	return true;
}

int main() {
	string line;
	while (getline(cin, line)) {
		if (line.find_first_not_of(" \t") == string::npos) continue;

		vector<int> arr;

		stringstream ss(line);
		int temp;
		while (ss >> temp) {
			arr.push_back(temp);
		}

		cout << "ANS = " << uniqueOccurrences(arr) << "\n";
	}

	return 0;
}