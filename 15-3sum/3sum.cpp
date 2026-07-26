class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n-1; i++) {
            if(i != 0 && nums[i] == nums[i-1]) continue; // to remove duplicates created using first pointer.

            int j = i+1, k = n-1;
            cout << "i: " << i << " j: " << j << " k: " << k << endl;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
                else if(sum > 0) k--;
                else j++;
            }
        }

        return ans;
    }
};