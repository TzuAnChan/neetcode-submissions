class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for (const auto & num: nums) {
            if (uset.count(num) != 0) return true; 
            uset.insert(num);
        }

        return false;
    }
};