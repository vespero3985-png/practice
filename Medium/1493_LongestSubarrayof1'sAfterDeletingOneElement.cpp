#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
	int cnt = 0, maxlen = 0, l = 0;
	for (int r = 0; r < nums.size(); r++) {
		if (nums[r] == 0) {
			cnt++;
		}
		while (cnt > 1) {
			if (nums[l] == 0) {
				cnt--;
			}
			l++;
		}
		maxlen = max(maxlen, r - l + 1);
	}
	
	return maxlen - 1;
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

		cout << "ANS = " << longestSubarray(nums) << "\n";
	}
	return 0;
}