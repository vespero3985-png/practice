#include <iostream>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2) {
	int n1 = word1.size(), n2 = word2.size();
	// cout << "N1 = " << n1 << ", N2 = " << n2 << endl;
	string merged;
	merged.reserve(n1 + n2);

	for (int i = 0, j = 0; i < n1 && j < n2; i++, j++) {
		merged += word1[i];
		merged += word2[j];
	}
	if (n1 > n2) {
		merged += word1.substr(n2);
		// cout <<"ADD " << word1.substr(n2) << endl;
	}
	else {
		merged += word2.substr(n1);
		// cout << "ADD " << word2.substr(n1) << endl;
	}
	return merged;
}

int main() {
	string word1, word2;
	while (cin >> word1 >> word2) {
		cout << mergeAlternately(word1, word2) << endl;
	}
	return 0;
}