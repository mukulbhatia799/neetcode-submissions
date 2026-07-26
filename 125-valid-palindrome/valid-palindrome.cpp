class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string phrase = "";
        for(int i = 0; i < n; i++) {
            if(isalnum(s[i])) phrase.push_back(tolower(s[i]));
        }
        cout << "phrase: " << phrase << endl;
        int i = 0, j = phrase.size()-1;
        while(i < j) {
            if(phrase[i] != phrase[j]) return false;
            i++; j--;
        }
        return true;
    }
};