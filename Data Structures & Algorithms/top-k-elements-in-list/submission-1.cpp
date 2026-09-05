class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for (const int& num: nums) {
            ump[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        
        for (const auto& [value, freq] : ump) {
            buckets[freq].push_back(value);
        }

        vector<int> ans;
        ans.reserve(k);

        for (int i = nums.size(); i >= 1; i--) {
            for(const int& it: buckets[i]) {
                ans.push_back(it);
                if (ans.size() == k) return ans;
            }
        }

        return {};
    }
};
