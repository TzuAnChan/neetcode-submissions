class Solution {
public:    
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> result(n);

        int lprod = 1;
        for (int i = 0; i < n; i++) {
            result[i] = lprod;
            lprod *= nums[i];
        }

        int rprod = 1;
        for (int i = n - 1;i >= 0; i--) {
            result[i] *= rprod;
            rprod *= nums[i];
        }

        return result;
    }
};
