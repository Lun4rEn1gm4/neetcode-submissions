class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0 , n=prices.size();
        int res =0;
        for(int r=1; r<n ;r++){
            res = max(prices[r]-prices[l],res);
            if(prices[r]<prices[l])
                l=r;
        }
        return res;
    }
};
