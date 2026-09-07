class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());

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
