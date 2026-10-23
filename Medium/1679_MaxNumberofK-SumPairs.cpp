#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
	if (nums.size() == 1) return 0;

	int ans = 0;
	sort(nums.begin(), nums.end());
	int l = 0, r = nums.size() - 1;
	while (l < r) {
		if (nums[l] + nums[r] == k) {
			ans++;
			l++;
			r--;
		}
		else if (nums[l] + nums[r] < k) {
			l++;
		}
		else {
			r--;
		}
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

		int k;
		cin >> k;

		cout << "ANS = " << maxOperations(nums, k) << "\n";
	}
	return 0;
}