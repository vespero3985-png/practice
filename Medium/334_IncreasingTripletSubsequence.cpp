#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
	int first = 2147483647, second = 2147483647, n = nums.size();
	for (int i = 0; i < n; i++) {
		if (nums[i] <= first)
			first = nums[i];
		if (nums[i] <= second && nums[i] > first)
			second = nums[i];
		if (nums[i] > first && nums[i] > second) {
			cout << "Triple nums = " << first << " " << second << " " << nums[i] << "\n"; // ?
			return true;
		}
	}
	return false;
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

		cout << "ANS = " << increasingTriplet(nums) << "\n";
	}
	return 0;
}

/*
1 2 3 4 5
5 4 3 2 1
2 1 5 0 4 6
0
1
1 5 0 4 1 3
20 100 10 12 5 13
0 4 2 1 0 -1 -3
*/