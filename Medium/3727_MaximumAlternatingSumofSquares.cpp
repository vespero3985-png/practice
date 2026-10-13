#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxAlternatingSum(vector<int>& nums) {
	long long score = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		nums[i] *= nums[i];
	}
	sort(nums.begin(), nums.end());

	if (n == 1)
		return nums[0];
	else if (n == 2)
		return nums[1] - nums[0];

	int mod = n % 2;
	for (int i = 0; i < n / 2; i++) {
		score -= nums[i];
		cout << "sub " << i << "-th : " << nums[i] << "\n";
		score += nums[i + n / 2 + mod];
		cout << "add " << i + n / 2 + mod << "-th : " << nums[i + n / 2 + mod] << "\n";
	}
	if (n % 2) {
		cout << "final add " << n / 2 << "-th : " << nums[n / 2] << "\n";
		return score + nums[n / 2];
	}
	return score;
}

int main() {
	vector<int> nums;

	string line;
	while (getline(cin, line)) {
		// 過濾空白行
		if (line.find_first_not_of(" \t") == string::npos) continue;
		stringstream ss(line);
		int temp;
		while (ss >> temp) {
			nums.push_back(temp);
		}

		cout << "Score = " << maxAlternatingSum(nums) << endl;

		nums.clear();
	}

	return 0;
}

/*
* Wrong test!
12 3 16 -1 7
output: 327
expect: 439

*/