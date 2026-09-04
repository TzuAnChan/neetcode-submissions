class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        int j, n = nums.size();
        for (j = 0; j < n; j++) {
            auto it = ump.find(target - nums[j]);
            if (it != ump.end()) return {it->second, j};
            ump[nums[j]] = j;
        }

        return {};
    }
};
