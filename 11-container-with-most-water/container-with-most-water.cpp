class Solution {
public:
    int maxArea(vector<int>& height) {
        // Two pointers approach - t.c: O(n)
        int n = height.size();
        int max_water = 0;
        int i = 0, j = n-1;
        while(i < j) {
            int width = j-i;
            int minHeight = min(height[i], height[j]);
            int curr_water = minHeight * width;
            max_water = max(max_water, curr_water);
            if(height[i] < height[j]) i++;
            else j--;
        }

        return max_water;
    }
};