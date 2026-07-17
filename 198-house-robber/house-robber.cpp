class Solution {
public:
    int findAns(vector<int>& nums, vector<int>& dp, int ind) {
        if(ind >= nums.size()) {
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int take = nums[ind] + findAns(nums, dp, ind+2);
        int notTake = findAns(nums, dp, ind+1);

        return dp[ind] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        // tabulation approach - O(n) t.c and O(n) s.c for dp array
        vector<int> dp(nums.size()+1, -1);
        return findAns(nums, dp, 0);
    }
};