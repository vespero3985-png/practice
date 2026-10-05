#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> toInt = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000}
};

int romanToInt(string s) {
    int n = s.size();
    int ans = toInt[s[n - 1]];
    for (int i = n - 2; i >= 0; i--) {
        if (toInt[s[i]] < toInt[s[i + 1]])
            ans -= toInt[s[i]];
        else
            ans += toInt[s[i]];
        cout << "round " << i << ", ans = " << ans << endl;
    }
    return ans;
}

int main()
{
    string s;
    while (cin >> s) {
        cout << romanToInt(s) << endl;
    }

    return 0;
}