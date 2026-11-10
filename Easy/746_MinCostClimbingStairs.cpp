#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
	vector<int> dp(n + 2, 0);
	for (int i = n - 1; i >= 0; i--) {
		dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
	}
	return min(dp[0], dp[1]);
}

int main() {
	string line;
	while (getline(cin, line)) {
		if (line.find_first_not_of(" \t") == string::npos) continue;

		vector<int> cost;
		stringstream ss(line);
		int temp;
		while (ss >> temp) {
			cost.push_back(temp);
		}

		cout << "ANS = " << minCostClimbingStairs(cost) << "\n";
	}

	return 0;
}
