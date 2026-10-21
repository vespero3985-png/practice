#include <iostream>
#include <string>
using namespace std;

bool isSubsequence(string s, string t) {
    if (s.size() > t.size()) return false;
    if (s.size() == 0) return true;

    int j = 0;  // s pointer
    for (int i = 0; i < t.size(); i++) { // i = t pointer
        if (j >= s.size()) return true;
        else if (s[j] == t[i]) j++;
    }
    if (j >= s.size()) return true;
    else return false;
}

int main()
{
    string s, t;
    while (cin >> s >> t) {
        cout << "ANS = " << isSubsequence(s, t) << endl;
    }

    return 0;
}