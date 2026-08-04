class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0 , right = s.length()-1;
        while(left<right){
            while(!iswalnum(s[left]) && left<right)
                left++;
            while(!iswalnum(s[right]) && left<right )
                right--;
            if( tolower(s[left]) == tolower(s[right]) ){
                left++; right--;
            } else {
                return false;
            }
        }
        return true;
    }
};
