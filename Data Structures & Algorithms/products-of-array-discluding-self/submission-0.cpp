class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int sum = 1;
        vector<int> result(n, 1);

        for (int i = 0; i < n; i++) {
            result[i] = sum;
            sum *= nums[i];
        }

        sum = 1;
        for (int i = n - 1;i >= 0; i--) {
            result[i] *= sum;
            sum *= nums[i];
        }

        return result;
    }
};
