class Solution {
public:
    int findAns(vector<int>& nums, vector<int>& dp, int ind) {
        if(ind >= nums.size()) {
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int take = 0, notTake = 0;
        take = nums[ind] + findAns(nums, dp, ind+2);
        notTake = findAns(nums, dp, ind+1);

        return dp[ind] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        // using memoization
        vector<int> dp(nums.size()+1, -1);
        return findAns(nums, dp, 0);
    }
};