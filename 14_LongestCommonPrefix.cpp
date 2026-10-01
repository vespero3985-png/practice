#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> strs;

    // get input
    string input;
    getline(cin, input);

    stringstream ss(input);
    string temp;

    while (ss >> temp) {
        strs.push_back(temp);
    }

    // sort
    sort(strs.begin(), strs.end());
    // compare first and last
    string first = strs[0], last = strs[strs.size() - 1];
    string prefix;
    int len = min(first.size(), last.size());
    for (int i = 0; i < len; i++) {
        if (first[i] == last[i]) {
            prefix += first[i];
        }
        else {
            break;
        }
    }

    cout << "Longest common prifix = " << prefix << endl;

    return 0;
}