class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        // using space optimization
        // just track the previous two and rest will follow-up while traversing.
        int f = nums[0];
        int s = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++) {
            int take = nums[i] + f;
            int notTake = s;
            f = s;
            s = max(take, notTake);
        }

        return s;
    }
};