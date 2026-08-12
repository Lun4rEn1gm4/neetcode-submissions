class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>s;
        vector<int>res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            if(!s.empty()){
                while(s.top().first<temperatures[i]){
                    res[s.top().second] = i-s.top().second;
                    s.pop();
                    if(s.empty()) break; 
                }
            }
            s.push({temperatures[i],i});
        }
        return res;
    }
};