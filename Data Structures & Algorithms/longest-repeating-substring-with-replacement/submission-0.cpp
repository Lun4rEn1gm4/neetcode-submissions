class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        for(char target = 'A'; target <= 'Z'; target++){
            int l=0 , buff=k;
            for(int r=0;r<s.length();r++){
                if(s[r] != target) 
                    buff--;
                if(buff<0){
                    while(buff<0){
                        if(s[l] != target) 
                            buff++;
                        l++;
                    }
                }
                res = max(res,r-l+1);
            }
        }
        return res;
    }
};
