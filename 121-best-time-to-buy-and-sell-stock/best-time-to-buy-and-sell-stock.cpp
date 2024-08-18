class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currLow=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<=currLow){
                currLow=prices[i];
            }else{
                ans=max(ans,prices[i]-currLow);
            }
        }
        return ans;
    }
};