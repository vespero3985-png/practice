#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int l = 0, r = k;
    double ans = 0.0;
    for (int i = l; i < r; i++) {
        ans += nums[i];
    }
    double sum = ans;
    cout << "From " << l << " to " << r - 1 << " : " << sum << "\n";
    
    while (r < nums.size()) {
        cout << "From " << l + 1 << " to " << r << " : " << sum - nums[l] + nums[r] << "\n";
        sum = sum - nums[l] + nums[r];
        ans = max(ans, sum);
        l++; r++;
        cout << "Max sum = " << ans << "\n";
    }

    return ans / (double)k;
}
/*
1 12 -5 -6 50 3
4
5
1
9 7 3 5 6 2 0 8 1 9
6

*/

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

        cout << "ANS = " << findMaxAverage(nums, k) << "\n";
    }
    return 0;
}

