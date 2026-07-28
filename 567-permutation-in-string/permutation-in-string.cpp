class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size2 = s2.size();

        // Get all freq of s1 chars.
        vector<int> freq(26, 0);
        for(char ch : s1) {
            freq[ch-'a']++;
        }

        // Find the s1 chars freq in s2.
        for(int i = 0; i < size2; i++) {
            if(freq[s2[i]-'a'] > 0) {
                // create a temp freq array so that we don't loose the original one.
                vector<int> tempArr(26, 0);
                for(int i = 0; i < 26; i++) tempArr[i] = freq[i];
                // check valid permutation by traversal
                int j = i;
                while(j < size2 && tempArr[s2[j]-'a'] > 0) {
                    tempArr[s2[j]-'a']--;
                    j++;
                }
                // check tempArr have all 0 values or not
                for(int i = 0; i < 26; i++) {
                    if(tempArr[i] > 0) break;       // not a permutation of s1.
                    else if(i == 25) return true;   // means we found the permutation.
                }
            }
        }

        return false;
    }
};