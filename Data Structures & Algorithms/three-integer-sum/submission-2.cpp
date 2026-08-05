class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>sol;
        int n=nums.size();
        int L,R;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i!= 0){
                if(nums[i-1] == nums[i])
                    continue;
            }
            L=i+1; R=n-1;
            while(L<R){
                if(nums[L]+nums[R]+nums[i]==0){
                    vector<int> curr = {nums[i], nums[L], nums[R]};
                    if(sol.size()!=0){
                        if(sol[sol.size()-1]!= curr)
                            sol.push_back(curr);
                        }else{
                        sol.push_back(curr);
                    }
                    L++; R--;
                }
                else if(nums[L]+nums[R]+nums[i]>0)
                    R--;
                else if(nums[L]+nums[R]+nums[i]<0)
                    L++;
            }
        }
        return sol;
    }
};
