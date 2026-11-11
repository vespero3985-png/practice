#include <iostream>
using namespace std;

long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
	long long c1 = cost1, c2 = cost2, cBoth = costBoth;
	long long n1 = need1, n2 = need2;
	
	long long ans = 0;
	ans += min(cBoth, c1 + c2) * min(n1, n2);
	if (n1 > n2) {
		ans += min(cBoth, c1) * (n1 - n2);
	}
	else {
		ans += min(cBoth, c2) * (n2 - n1);
	}

	return ans;
}

int main() {
	int cost1, cost2, costBoth, need1, need2;
	while (cin >> cost1 >> cost2 >> costBoth >> need1 >> need2) {
		cout << "ANS = " << minimumCost(cost1, cost2, costBoth, need1, need2) << "\n";
	}
	return 0;
}