class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        long long mul = 1;
        int checkZero = 0;
        for(int val : nums) {
            if(val == 0) checkZero++;
            else mul *= val;
        }
        if(checkZero == 1) {
            for(int val : nums) {
                if(val == 0) ans.push_back(mul);
                else ans.push_back(0);
            }
        }
        else if(checkZero > 1) {
            for(int i = 0; i < n; i++) ans.push_back(0);
        }
        else {
            for(int i = 0; i < n; i++) {
                ans.push_back(mul/nums[i]);
            }
        }

        return ans;
    }
};