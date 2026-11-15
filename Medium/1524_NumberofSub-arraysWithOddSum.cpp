#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

bool is_odd(int& n) {
	return (n % 2) ? true : false;
}

int numOfSubarrays(vector<int>& arr) {
	int n = arr.size(), odd_count = 0, even_count = 1;
	long long ans = 0;
	vector<int> prefixsum(n + 1, 0); // prefix[0] = 0
	for (int i = 0; i < n; i++) {
		prefixsum[i + 1] = prefixsum[i] + arr[i];
		// odd - even || even - odd
		if (is_odd(prefixsum[i + 1])) {
			ans += even_count;
			odd_count++;
		}
		else {
			ans += odd_count;
			even_count++;
		}
	}
	return (int)(ans % 1000000007);
}

int main() {
	string line;
	while (getline(cin, line)) {
		if (line.find_first_not_of(" \t") == string::npos) continue;

		vector<int> arr;
		stringstream ss(line);
		int temp;
		while (ss >> temp) {
			arr.push_back(temp);
		}

		cout << "ANS = " << numOfSubarrays(arr) << "\n";
	}
	return 0;
}