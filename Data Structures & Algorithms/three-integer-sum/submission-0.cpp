class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> sol;        
        unordered_map<int, int> lastIndex;
        for(int i = 0; i < nums.size(); i++){
            lastIndex[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                int tar = -(nums[i] + nums[j]);
                if(lastIndex.count(tar) && lastIndex[tar] > j){
                    vector<int> ans = {nums[i], nums[j], tar};
                    sort(ans.begin(), ans.end());
                    sol.insert(ans);
                }
            }
        }
        vector<vector<int>> result(sol.begin(), sol.end());
        return result;
    }
};