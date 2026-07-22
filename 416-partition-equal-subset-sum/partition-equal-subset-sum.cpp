class Solution {
public:
    bool findAns(vector<int>& nums, int target, vector<vector<int>> &dp, int ind) {
        if(target == 0) return true;
        if(ind >= nums.size() || target < 0) return false;

        if(dp[ind][target] != -1) return dp[ind][target];
        bool take = findAns(nums, target-nums[ind], dp, ind+1);
        if(take) return take;       // for optimization
        bool notTake = findAns(nums, target, dp, ind+1);

        return dp[ind][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        // Memoization approach: Intution -> If the sum of the array ele is odd, then we can't find the two subsets with equal sum. If it's even, then just half the sum and find it in the array.
        int sum = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum&1) return false;

        int target = sum / 2;
        
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return findAns(nums, target, dp, 0);
    }
};