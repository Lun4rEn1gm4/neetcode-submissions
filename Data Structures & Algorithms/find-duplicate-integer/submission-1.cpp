class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int size = nums.size();
        for (int i : nums) {
            if (s.find(i) != s.end())
                return i;
            else
                s.insert(i);
        }
        return 0;
    }
};
