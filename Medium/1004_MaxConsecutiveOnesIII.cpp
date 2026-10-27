#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int l = 0, r = 0, cnt = 0; // [l, r), len = r - l
    int n = nums.size(), maxlen = 0;

    while (r < n) {
        if (nums[r] == 0) {
            cnt++;
        }
        // move left
        while (cnt > k) {
            if (nums[l] == 0) {
                cnt--;
            }
            l++;
        }
        // update maxlen
        maxlen = max(maxlen, r - l + 1);
        r++;
    }

    return maxlen;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        if (line.find_first_not_of(" \t") == string::npos) continue;

        vector<int> nums;

        stringstream ss(line);
        int temp;
        while (ss >> temp) {
            nums.push_back(temp);
        }

        int k;
        cin >> k;

        cout << "ANS = " << longestOnes(nums, k) << endl;
    }

    return 0;
}