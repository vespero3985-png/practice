#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector<bool> ans;
    int max = *max_element(candies.begin(), candies.end());
    // cout << "MAX = " << max << endl;

    for (int i = 0; i < candies.size(); i++) {
        if (candies[i] + extraCandies >= max)
            ans.push_back(true);
        else
            ans.push_back(false);
    }

    return ans;
}

int main()
{
    vector<int> candies;
    int extraCandies;

    // get candies
    string line;
    getline(cin, line);
    stringstream ss(line);
    int temp;
    while (ss >> temp) {
        candies.push_back(temp);
    }
    // get extraCandies
    cin >> extraCandies;

    vector<bool> ans = kidsWithCandies(candies, extraCandies);
    cout << "ANSWER = ";
    for (bool s : ans) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}