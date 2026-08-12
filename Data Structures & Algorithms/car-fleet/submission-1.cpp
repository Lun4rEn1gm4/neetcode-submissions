class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>time;
        for(int i=0;i<speed.size();i++){
            time.push_back({position[i],(target-position[i])/(double)speed[i]});
        }
        sort(time.begin(),time.end());
        int cnt=0;
        double prev=0;
        for(int i=time.size()-1;i>=0;i--){
            if(time[i].second>prev){
                cnt++; prev =time[i].second; 
            }
        }
        return cnt;
    }
};
