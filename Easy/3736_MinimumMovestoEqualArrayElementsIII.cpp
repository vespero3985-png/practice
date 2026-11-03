#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int minMoves(vector<int>& nums) {
	auto it = max_element(nums.begin(), nums.end());
	int max_val = *it;

	int ans = 0;
	for (int n : nums) {
		ans += (max_val - n);
	}
	return ans;
}


int main() {
	string line;
	while (getline(cin, line)) {
		if (line.find_first_not_of(" \t") == string::npos) continue;

		vector<int> nums;

		stringstream ss(line);
		int temp;
		while (ss >> temp) {
			nums.push_back(temp);
		}

		cout << "ANS = " << minMoves(nums) << "\n";
	}

	return 0;
}