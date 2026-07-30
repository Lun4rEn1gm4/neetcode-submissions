class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i =0; i<nums.size(); i++){
            int ToFind = target - nums[i];
            auto it = m.find(ToFind);
            if(it != m.end()){
                ans.push_back(m[ToFind]);
                ans.push_back(i);
                return ans;
            }
            else {
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};
