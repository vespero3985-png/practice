#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	int n = nums.size();
	vector<int> prifix(n, 0), suffix(n, 0);
	prifix[0] = 1; suffix[n - 1] = 1;
	
	for (int i = 1, j = n - 2; i < n && j >= 0; i++, j--) {
		prifix[i] = prifix[i - 1] * nums[i - 1];
		suffix[j] = suffix[j + 1] * nums[j + 1];
	}

	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i] = prifix[i] * suffix[i];
	}
	return ans;
}

int main() {
	string line;
	while (getline(cin, line)) {
		if (line.find_first_not_of(" \t") == string::npos) continue;
		
		vector<int> nums, ans;
		
		stringstream ss(line);
		int temp;
		while (ss >> temp) {
			nums.push_back(temp);
		}

		ans = productExceptSelf(nums);

		cout << "ANS = [ ";
		for (int s : ans) {
			cout << s << " ";
		}
		cout << "]\n";
	}
	return 0;
}