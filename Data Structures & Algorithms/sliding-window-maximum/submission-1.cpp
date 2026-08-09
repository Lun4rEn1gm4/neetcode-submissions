class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int cur = -10001;
        for (int i = 0; i < k; i++) 
            cur = max(cur, nums[i]);
        res.push_back(cur);
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > cur)
                cur = nums[i];
            else {
                if (cur == nums[i - k]) {
                    cur = -10001;
                    for (int j = i - k + 1; j < i + 1; j++) {
                        cur = max(cur, nums[j]);
                    }
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};
