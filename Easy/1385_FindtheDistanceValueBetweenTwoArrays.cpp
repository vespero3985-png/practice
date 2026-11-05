#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
	int cnt = 0;
	sort(arr2.begin(), arr2.end());
	for (int a1 : arr1) {
		for (int a2 : arr2) {
			if (abs(a1 - a2) <= d) {
				cout << a1 << " - " << a2 << " <= " << d << "\n";
				cnt++;
				break;
			}
		}
	}

	return arr1.size() - cnt;
}

/*
-3 -3 4 -1 -10
7 10
12
*/

int main() {
	string line;
	while (getline(cin, line)) {
		if (line.find_first_not_of(" \t") == string::npos) continue;

		vector<int> arr1;
		stringstream ss1(line);
		int temp;
		while (ss1 >> temp) {
			arr1.push_back(temp);
		}

		getline(cin, line);
		vector<int> arr2;
		stringstream ss2(line);
		while (ss2 >> temp) {
			arr2.push_back(temp);
		}

		int d;
		cin >> d;

		cout << "ANS = " << findTheDistanceValue(arr1, arr2, d) << "\n";
	}

	return 0;
}