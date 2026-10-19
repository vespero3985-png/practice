#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<int> targetIndices(vector<int>& nums, int target) {
	int less_count = 0, equal_count = 0;
	for (int n : nums) {
		if (n < target)
			less_count++;
		else if (n == target)
			equal_count++;
	}
	vector<int> ans(equal_count);
	for (int i = 0; i < equal_count; i++) {
		ans[i] = less_count + i;
	}
	return ans;
}

int main() {
	string line;
	while (getline(cin, line)) {
		if (line.find_first_not_of(" \t") == string::npos) continue;
		stringstream ss(line);
		int temp;
		vector<int> nums;
		while (ss >> temp) {
			nums.push_back(temp);
		}
		int target;
		cin >> target;
		vector<int> ans = targetIndices(nums, target);
		cout << "ANS = [";
		for (int n : ans) {
			cout << n << ", ";
		}
		cout << "]\n";
	}
	return 0;
}