class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        int i, j, n = nums.size();
        for (j = 0; j < n; j++) {
            if (ump.count(target - nums[j]) != 0) {
                i = ump[target - nums[j]];
                break;
            }
            ump[nums[j]] = j;
        }

        return {i, j};
    }
};
