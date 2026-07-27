class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // brute-force approach - t.c -> O(n^2) , s.c -> o(128 or 256 or n)
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            unordered_set<char> st;
            int count = 0;
            for(int j = i; j < n; j++) {
                if(st.find(s[j]) == st.end()) {
                    count++;
                    st.insert(s[j]);
                }
                else break;
            }
            ans = max(ans, count);
        }

        return ans;
        
    }
};