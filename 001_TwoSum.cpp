class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            // search
            auto it = hash.find(target - nums[i]);
            if (it != hash.end() && it->second != i) {
                return { it->second, i };
            }
            // insert
            hash[nums[i]] = i;
        }
        return { -1, -1 };
    }
};