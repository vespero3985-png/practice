class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = 0;
            while (nums[i] != 0) {
                sum += nums[i] % 10;
                nums[i] = nums[i] / 10;
            }
            // compare equal
            if (sum == i)
                return i;
        }
        return -1;
    }
};