#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> set1, set2;
	for (int it : nums1) {
		set1.insert(it);
	}
	for (int it : nums2) {
		set2.insert(it);
	}

	vector<int> ans1, ans2;
	// find
	for (const auto& elem : set1) {
		if (set2.find(elem) != set2.end()) {
			continue;
		}
		ans1.push_back(elem);
	}
	for (const auto& elem : set2) {
		if (set1.find(elem) != set1.end()) {
			continue;
		}
		ans2.push_back(elem);
	}
	return { move(ans1), move(ans2) };
}

int main() {
	string line1, line2;
	while (getline(cin, line1)) {
		if (line1.empty()) continue;
		getline(cin, line2);

		vector<int> nums1, nums2;

		stringstream ss1(line1), ss2(line2);
		int temp;
		while (ss1 >> temp) {
			nums1.push_back(temp);
		}
		while (ss2 >> temp) {
			nums2.push_back(temp);
		}

		vector<vector<int>> ans = findDifference(nums1, nums2);
		cout << "ANS = [[";
		for (int it : ans[0]) {
			cout << it << " ";
		}
		cout << "], [";
		for (int it : ans[1]) {
			cout << it << " ";
		}
		cout << "]\n";
	}
	return 0;
}