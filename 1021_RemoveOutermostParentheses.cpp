#include <iostream>
#include <string>
using namespace std;

string removeOuterParentheses(string s) {
    int count = 0, start = 0;
    string ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            count++;
        else
            count--;

        // one valid
        if (count == 0) {
            for (int j = start + 1; j < i; j++) {
                ans += s[j];
            }
            start = i + 1;
        }
    }
    return ans;
}

int main()
{
    string s;
    while (cin >> s) {
        cout << removeOuterParentheses(s) << endl;
    }
    return 0;
}