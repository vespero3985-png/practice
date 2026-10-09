#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums;
    int val;

    string line;
    getline(cin, line);

    stringstream ss(line);
    int temp;
    while (ss >> temp) {
        nums.push_back(temp);
    }

    cin >> val;

    // check
    cout << "nums: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << "\nval: " << val << '\n';

    // answer
    cout << "remain " << removeElement(nums, val) << " element" << endl;
    // check after remove
    cout << "nums: ";
    for (int n : nums) {
        cout << n << " ";
    }

    return 0;
}