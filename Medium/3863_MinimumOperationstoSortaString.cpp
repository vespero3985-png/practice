#include <iostream>
#include <string>
using namespace std;

int minOperations(string s) {
    int n = s.size();
    if (n == 1)
        return 0;
    // check whether s is sorted or not
    bool isSorted = true;
    char min = s[0], max = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] < s[i - 1]) {
            isSorted = false;
        }
        if (s[i] < min) {
            min = s[i];
        }
        if (s[i] > max) {
            max = s[i];
        }
    }
    if (isSorted)
        return 0;
    // length = 2
    if (n == 2)
        return -1;
    // case 1
    if (s[0] == min || s[n - 1] == max) {
        return 1;
    }
    // case 3
    if (s[0] == max && s[n - 1] == min) {
        // check max & min are both one and only
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == max || s[i] == min)
                return 2;
        }
        return 3;
    }
    return 2;
}

int main()
{
    string s;
    while (cin >> s) {
        cout << "ANS = " << minOperations(s) << endl;
    }
    return 0;
}