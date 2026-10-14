#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

string reverseVowels(string s) {
	vector<int> pos;
	// find vowels position
	for (int i = 0; i < s.size(); i++) {
		if (vowels.count(s[i])) {
			pos.push_back(i);
			cout << i << "-th is vowel\n";
		}
	}
	// swap
	char temp;
	for (int i = 0, j = pos.size() - 1; i < j; i++, j--) {
		cout << "swap " << i << " & " << j << ": " << s[pos[i]] << " & " << s[pos[j]] << "\n";
		temp = s[pos[i]];
		s[pos[i]] = s[pos[j]];
		s[pos[j]] = temp;
	}

	return s;
}

int main() {
	string s;
	while (cin >> s) {
		cout << "Re = " << reverseVowels(s) << "\n";
	}
	return 0;
}

/*
IceCreAm
leetcode
O
K
OA
HOA

*/