#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool closeStrings(string word1, string word2) {
    if (word1.size() != word2.size()) return false;

    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (int i = 0; i < word1.size(); i++) {
        cnt1[word1[i] - 'a']++;
        cnt2[word2[i] - 'a']++;
    }
    // same character
    for (int i = 0; i < 26; i++) {
        if ((cnt1[i] == 0 && cnt2[i] != 0) || (cnt1[i] != 0 && cnt2[i] == 0))
            return false;
    }

    // frequency
    sort(cnt1.begin(), cnt1.end());
    sort(cnt2.begin(), cnt2.end());

    return cnt1 == cnt2;
}

int main()
{
    string word1, word2;
    while (cin >> word1 >> word2) {
        cout << "ANS = " << closeStrings(word1, word2) << "\n";
    }
    return 0;
}