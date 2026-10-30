#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
	int n = nums.size();
	if (n == 1) return 0;

	vector<int> leftsum(n), rightsum(n);
	leftsum[0] = 0, rightsum[n - 1] = 0;

	for (int i = 1; i < n; i++) {
		leftsum[i] = leftsum[i - 1] + nums[i - 1];
		rightsum[n - i - 1] = rightsum[n - i] + nums[n - i];
	}
	
	/*cout << "left sum = ";
	for (int it : leftsum) {
		cout << it << " ";
	}
	cout << "\n";

	cout << "right sum = ";
	for (int it : rightsum) {
		cout << it << " ";
	}
	cout << "\n";*/

	for (int i = 0; i < n; i++) {
		if (leftsum[i] == rightsum[i])
			return i;
	}

	return -1;
}
/*
1 7 3 6 5 6
1 2 3
2 1 -1
*/

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

		cout << "ANS = " << pivotIndex(nums) << "\n";
	}
	return 0;
}