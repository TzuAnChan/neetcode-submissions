class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for (const int& num: nums) {
            ump[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, 
            std::greater<>> minHeap;
        
        for (const auto& [value, freq] : ump) {
            minHeap.emplace(freq, value);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> ans;
        ans.reserve(k);
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return ans;
    }
};
