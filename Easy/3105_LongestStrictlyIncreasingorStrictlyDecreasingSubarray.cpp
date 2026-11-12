#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int longestMonotonicSubarray(vector<int>& nums) {
	int in = 0, de = 0, max_len = 1;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] > nums[i - 1]) {
			de = i;
			max_len = max(max_len, i - in + 1);
		}
		else if (nums[i] < nums[i - 1]) {
			in = i;
			max_len = max(max_len, i - de + 1);
		}
		else {
			in = i; de = i;
		}
		cout << "increasing = [" << in << ", " << i << "]\n";
		cout << "decreasing = [" << de << ", " << i << "]\n";
		cout << "max len = " << max_len << "\n";
	}
	return max_len;
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

		cout << "ANS = " << longestMonotonicSubarray(nums) << "\n";
	}

	return 0;
}
