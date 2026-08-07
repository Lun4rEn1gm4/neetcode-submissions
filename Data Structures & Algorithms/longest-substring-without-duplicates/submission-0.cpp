class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>win;
        int l=0 , res=0;
        for(int r=0;r< s.length();r++){
            while(win.count(s[r])){
                win.erase(s[l]);l++;
            }
            win.insert(s[r]);
            res = max(res, r-l+1);
        }
        return res;
    }
};
