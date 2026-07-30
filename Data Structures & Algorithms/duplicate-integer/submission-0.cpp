class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set <int> s;
        int l = nums.size();
        for(int i =0; i< l; i++){
            auto it = s.find(nums[i]); 
            if( it != s.end())
                return true;
            else
                s.insert(nums[i]);
        }
        return false;
    }
};