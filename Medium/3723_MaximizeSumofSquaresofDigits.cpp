#include <iostream>
#include <string>
using namespace std;

string maxSumOfSquares(int num, int sum) {
	long long score = 0;
	int digit = 0;
	string ans;
	ans.reserve(num);

	while (num && sum) {
		digit = min(9, sum);
		score += digit * digit;
		num--;
		sum -= digit;
		ans += to_string(digit);
	}

	if (num == 0 && sum != 0)
		return "";
	for (int i = 0; i < num; i++) {
		ans.push_back('0');
	}

	cout << "Score = " << score << "\n";
	return ans;
}

int main() {
	int num, sum;
	while (cin >> num >> sum) {
		cout << "Max = " << maxSumOfSquares(num, sum) << "\n";
	}
	return 0;
}