class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1=0,p2=numbers.size()-1;
        vector<int> sol;
        while(p1<p2){
            int sum = numbers[p1] + numbers[p2];
            if(sum==target){
                sol.push_back(p1+1);
                sol.push_back(p2+1);
                return sol;
            }
            if(sum<target){
                p1++;   
            }
            if(sum>target){
                p2--;
            }
        }
    }
};
