class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>count;
        for(char c :t)
            count[c]++;
        int l=0 , init =0 , len=INT_MAX;
        int lmin=0;
        for(int i=0;i<s.length();i++){
            if(count.find(s[i])!= count.end()){
                if(count[s[i]]>0) init++;
                count[s[i]]--; 
                if(init >= t.length()){
                    while(init == t.length()){
                        if(len>i-l+1){
                            lmin=l;
                            len = i-l+1;    
                        }
                        if(count.find(s[l])!= count.end()){
                            count[s[l]]++;
                            if(count[s[l]]>0) init--;
                        }
                        l++;
                    }
                }
            }
        }
        if(len==INT_MAX){
            return "";
        } 
        return s.substr(lmin,len);
    }
};
