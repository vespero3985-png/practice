#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

int sumCounts(vector<int>& nums) {
	int ans = 0;
	for (int i = 0; i < nums.size(); i++) {
		unordered_set<int> myset;
		for (int j = i; j < nums.size(); j++) {
			myset.insert(nums[j]);
			ans += myset.size() * myset.size();
			cout << "[" << i << "," << j << "] count = " << myset.size() << '\n';
		}
	}
	return ans;
}

int main() {
	string line;
	vector<int> nums;
	while (getline(cin, line)) {
		stringstream ss(line);
		int temp;
		while (ss >> temp) {
			nums.push_back(temp);
		}

		cout << "Sum = " << sumCounts(nums) << "\n";

		nums.clear();
	}

	return 0;
}

/*
1 2 1
1 1
1 2 1 1 3
1
1 2

output:
15
3
52
1
6
*/