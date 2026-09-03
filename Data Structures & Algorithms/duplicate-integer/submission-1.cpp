class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for (const auto & num: nums) {
            if (!uset.insert(num).second) return true;
        }

        return false;
    }
};