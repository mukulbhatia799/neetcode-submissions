class Solution {
public:
    int findAns(int n, vector<int>& nums, vector<int> &dp, int ind) {
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + findAns(n, nums, dp, ind+2);
        int notPick = findAns(n, nums, dp, ind+1);

        return dp[ind] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        // using memoization
        vector<int> dp(nums.size(), -1);
        return findAns(nums.size(), nums, dp, 0);
    }
};