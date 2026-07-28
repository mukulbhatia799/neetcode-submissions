class Solution {
public:
    int characterReplacement(string s, int k) {
        // sliding window approach - t.c -> O(n) and s.c -> O(n)
        int n = s.size();
        int start = 0;
        int max_freq = 0;
        int maxWindow_size = 0;
        unordered_map<char, int> freq;
        for(int end = 0; end < n; end++) {
            freq[s[end]-'A']++;
            max_freq = max(max_freq, freq[s[end]-'A']);
            int window_size = end-start+1;
            if(window_size - max_freq > k) {
                freq[s[start]-'A']--;
                start++;
            }
            window_size = end-start+1;
            maxWindow_size = max(maxWindow_size, window_size);
        }

        return maxWindow_size;
    }
};