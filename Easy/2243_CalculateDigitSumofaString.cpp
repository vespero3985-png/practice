#include <iostream>
#include <string>
using namespace std;

string digitSum(string s, int k) {
	while (s.size() > k) {
		int n = 0;
		string new_s;
		while (n < s.size()) {
			int temp = 0;
			for (int i = n; i < n + k && i < s.size(); i++) {
				temp += s[i] - '0';
			}
			new_s += to_string(temp);
			n += k;
		}
		s = new_s;
	}
	return s;
}

int main() {
	string s;
	while (cin >> s) {
		int k;
		cin >> k;
		cout << "ANS = " << digitSum(s, k) << "\n";
	}
	return 0;
}