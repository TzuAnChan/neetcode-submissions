class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 1. 解除 I/O 緩衝區同步
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (nums.empty()) return 0;

        // 2. 預先分配空間，避免動態擴容 Rehashing 的巨大開銷
        unordered_set<int> num_set;
        num_set.reserve(nums.size());
        for (int num : nums) {
            num_set.insert(num);
        }

        int max_streak = 0;
        for (const int& num: num_set) {
            if (!num_set.count(num - 1)) {
                int cur_streak = 1;
                int cur_num = num;

                while (num_set.count(cur_num + 1)) {
                    cur_streak++;
                    cur_num++;
                }

                max_streak = max(max_streak, cur_streak);
            }
        }

        return max_streak;
    }
};
