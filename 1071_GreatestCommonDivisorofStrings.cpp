#include <iostream>
#include <string>
using namespace std;

int findMaxFactor(int a) {
	for (int i = a / 2; i > 0; i--) {
		if (a % i == 0) {
			return i;
		}
	}
	return 1;
}

int gcd(int a, int b) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

string gcdOfStrings(string str1, string str2) {
	if (str1[0] != str2[0]) return "";
	int n1 = str1.size(), n2 = str2.size();
	int ans_len = gcd(n1, n2);
	// cout << "n1: " << n1 << "\nn2: " << n2 << "\ngcd: " << ans_len << endl;
	
	while (1) {
		bool isgcd = true;
		string ans = str1.substr(0, ans_len);
		cout << "check substr = " << ans << endl;
		int d1 = n1 / ans_len, d2 = n2 / ans_len;
		// d1 * ans = str1, d2 * ans = str2
		for (int j = 0, k = 0; j < d1 || k < d2 ; j++, k++) {
			for (int i = 0; i < ans_len; i++) {
				if (j < d1 && ans[i] != str1[i + j * ans_len]) {
					isgcd = false;
					break;
				}
				if (k < d2 && ans[i] != str2[i + k * ans_len]) {
					isgcd = false;
					break;
				}
			}
			if (!isgcd) break;
		}
		if (isgcd)
			return ans;
		if (ans_len == 1)
			return "";
		ans_len = findMaxFactor(ans_len);
	}
	
	return "";
}

int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		cout << gcdOfStrings(str1, str2) << endl;
	}
	return 0;
}