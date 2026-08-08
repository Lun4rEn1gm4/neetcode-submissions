class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>s1len(27,0);
        vector<int>s2len(27,0);
        for(char hh : s1){
            s1len[hh-'a']++;
        }
        for(int i=0;i<s2.length();i++){
            s2len[s2[i]-'a']++;
            if(!(i<s1.length())) s2len[s2[i-s1.length()]-'a']--;
            if(s1len == s2len)
                return true;
        }
        return false;
    }
};
