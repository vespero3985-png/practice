#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
using namespace std;

void moveZeroes(vector<int>& nums) {
	int next = 0, n = nums.size();
	for (int i = 0; i < n; i++) {
		while (next < n && nums[next] == 0) next++;
		// swap
		if (next < n) {
			swap(nums[i], nums[next]);
			next++;
		}
		if (next >= n) break;
	}
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

		moveZeroes(nums);
		cout << "New array = ";
		for (int n : nums) {
			cout << n << " ";
		}
		cout << "\n";
	}

	return 0;
}